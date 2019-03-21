// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "stdafx.h"
#include "Shader.h"
#include "Mesh.h"


Shader::Shader(QObject *parent)
	: QObject(parent)
{
}

Shader::~Shader()
{
}

QVector<float> Shader::ConvertMatrixStackToArray(QVector<QMatrix4x4> stack)
{
	QVector<float> d;

	for (auto &it : stack)
	{
		QMatrix4x4 m = it;

		//m = m.transposed();

		for (int j = 0; j < 4; j++)
		{
			QVector4D vec = m.row(j);

			d << vec[0];
			d << vec[1];
			d << vec[2];
			d << vec[3];
		}
	}
	return d;
}

bool Shader::CreateVertexShader(QString filename)
{
	// Initialize the pointers this function will use to null.
	errorMessage = 0;
	vertexShaderBuffer = 0;
	//pixelShaderBuffer = 0;

	QFile *file = new QFile(filename, this);
	file->open(QFile::ReadOnly);

	data = file->readAll();

	file->close();

	// Create the vertex shader from the buffer.
	result = device->CreateVertexShader(data.data(), data.size(), NULL, &vertex_shader);

	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool Shader::CreatePixelShader(QString filename)
{
	// Initialize the pointers this function will use to null.
	errorMessage = 0;
	vertexShaderBuffer = 0;
	//pixelShaderBuffer = 0;

	QFile *file = new QFile(filename, this);
	file->open(QFile::ReadOnly);

	data = file->readAll();

	file->close();

	// Create the vertex shader from the buffer.
	result = device->CreatePixelShader(data.data(), data.size(), NULL, &pixel_shader);

	if (FAILED(result))
	{
		return false;
	}

	return true;
}

void Shader::CreateConstantBuffer()
{
	// Setup the description of the dynamic matrix constant buffer that is in the vertex shader.
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(float) * stack_matrix_count * 16;
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	result = device->CreateBuffer(&matrixBufferDesc, NULL, &constants);
}

void Shader::CreateLayout()
{
	// Now setup the layout of the data that goes into the shader.
	// This setup needs to match the VertexType stucture in the ModelClass and in the shader.
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "COLOR";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	// Get a count of the elements in the layout.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	// Create the vertex input layout.
	result = device->CreateInputLayout(polygonLayout, numElements, data.data(),
		data.size(), &layout);
}

bool Shader::SetMatrixStack(QVector<QMatrix4x4> stack)
{
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	unsigned int bufferNumber;

	QVector<float> data = ConvertMatrixStackToArray(stack);


	// Lock the constant buffer so it can be written to.
	result = context->Map(constants, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		return false;
	}

	// Get a pointer to the data in the constant buffer.
	auto dataPtr = mappedResource.pData;

	memcpy(dataPtr, data.data(), sizeof(float) * data.size());

	// Unlock the constant buffer.
	context->Unmap(constants, 0);

	// Set the position of the constant buffer in the vertex shader.
	bufferNumber = 0;

	// Finanly set the constant buffer in the vertex shader with the updated values.
	context->VSSetConstantBuffers(bufferNumber, 1, &constants);

	return true;
}
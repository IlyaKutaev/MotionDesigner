#pragma once

#include <QObject>
#include <d3d11_1.h>
#include <dxgi.h>

class Shader : public QObject
{
	Q_OBJECT
public:
	ID3D11Device *device = nullptr;
	ID3D11DeviceContext *context = nullptr;
	HRESULT result;
	ID3D10Blob* errorMessage		= nullptr;
	ID3D10Blob* vertexShaderBuffer	= nullptr;
	ID3D10Blob* pixelShaderBuffer	= nullptr;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;
	ID3D11VertexShader *vertex_shader = nullptr;
	ID3D11PixelShader *pixel_shader = nullptr;
	ID3D11InputLayout *layout = nullptr;
	ID3D11Buffer *constants = nullptr;

	int stack_matrix_count = 3;
private:
	QByteArray data;
public:
	Shader(QObject *parent);
	~Shader();
private:
	QVector<float> ConvertMatrixStackToArray(QVector<QMatrix4x4> stack);
public:
	bool CreateVertexShader(QString filename);
	bool CreatePixelShader(QString filename);
	void CreateConstantBuffer();
	void CreateLayout();
	bool SetMatrixStack(QVector<QMatrix4x4> stack);
};

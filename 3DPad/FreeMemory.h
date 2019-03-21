#ifndef FreeMemory_h__
#define FreeMemory_h__
#include <QVector>
#include <string>
#pragma once

class FreeMemory
{
public:
	struct intdata
	{
		char *data = nullptr;
	};
	QVector<intdata> idata;

	enum AppVersion
	{
		pad_lite = 6,
		pad_home = 12,
		pad_extended = 24,
		pad_professional = 32,
		pad_ultimate = 50
	};

	AppVersion app_version = pad_lite;
public:
	static FreeMemory& Instance()
	{
		static FreeMemory singleton;
		return singleton;
	}

	// Other non-static member functions
private:
	FreeMemory() {}                                  // Private constructor
	~FreeMemory() {}
	FreeMemory(const FreeMemory&) {}                 // Prevent copy-construction
	FreeMemory& operator=(const FreeMemory&) 
	{
		return *this;
	};      // Prevent assignment
public:
	std::string LockMemory();
	bool FreeMyMemory();
private:
	size_t GetMemorySize();
};

#endif // FreeMemory_h__

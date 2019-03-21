#pragma once

#include <QObject>

class Random : public QObject
{
	Q_OBJECT
	uint64_t *state = nullptr;
public:
	Random(QObject *parent);
	~Random();
public:
	uint64_t GetRandomValue();
private:
	uint64_t xorshift64();
};

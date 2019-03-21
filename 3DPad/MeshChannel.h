#ifndef IncludeGuard_3DPad_MeshChannel
#define IncludeGuard_3DPad_MeshChannel

#include <QObject>

template <class T>
class MeshChannel : public QObject
{
private:
	struct Block
	{
		QVector<T> position;
	};
	QVector<Block> blocks;
	const int max_vert_count = 1024 * 50;
public:
	MeshChannel(QObject *parent) : QObject(parent) {}
	~MeshChannel(){}
	MeshChannel(QObject *parent);
	: QObject(parent)
	{
		Block block;
		blocks << block;
	}
	~MeshChannel() {}

	template <class T>
	void AddItem(T pos);

	template <class T>
	T GetItem(int id);

public:
};

template <class T>
inline void AddItem(T pos)
{
	int count = blocks.last().position.count() + 1;
	if (count > max_vert_count)
	{
		Block block;
		block.position << pos;
		blocks << block;
	}
	else
	{
		blocks.last().position << pos;
	}
}

template<class T>
inline T GetItem(int id)
{
	int block_id = id / blocks.count();
	T pos = blocks.at(block_id).position.at(id % blocks.count());

	return pos;

}

#endif // MeshChannel_h__

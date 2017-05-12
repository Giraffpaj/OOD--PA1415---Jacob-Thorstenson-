#ifndef ILIST_H
#define ILIST_H

template<typename T>
class IList
{
public:
	virtual ~IList() = 0 {};
	virtual void add(T data) = 0;
	virtual void remove(T &data) = 0;
	virtual int getSize() const = 0;
};

#endif //ILIST_H
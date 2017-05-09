#ifndef ILIST_H
#define ILIST_H

template<typename T>
class IList
{
	virtual ~IList() = 0 {};
	virtual void add(T data) = 0;
	virtual void remove(T data) = 0;
	virtua int size() const = 0;
};

#endif //ILIST_H
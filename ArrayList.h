#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "IList.h"

template <typename T>
class ArrayList : IList<T>
{
private:
	T*data;
	int nrOfData;
	int cap;
	int increment; //variabel som ökar cap vid expand varje gång
	void expand();
	void deepCopy(const ArrayList & other);
public:
	ArrayList(int cap);
	~ArrayList();
	void add(T data);
	void remove(T data);
	bool find(T data) const;
	int getSize() const;
	void clearAll();

};
#endif //ARRAYLIST

template<typename T>
inline void ArrayList<T>::expand()
{
	this->cap += this->increment;
	T * temp = new T[this->cap];
	for (int a = 0; a < this->nrOfData; a++)
	{
		temp[a] = this->data[a]
	}
	delete[] this->data;
	this->data = temp;
}

template<typename T>
inline void ArrayList<T>::deepCopy(const ArrayList & other)
{
	if (this->nrOfData > 0)
	{
		this->cap = other.cap;
		this->increment = other.increment;
		this->nrOfData = other.nrOfData;
		this->data = new T[this->cap];
		for (int a = 0; a < this->nrOfData; a++)
		{
			this->data = other.data[a];
		}
	}
}

template<typename T>
inline ArrayList<T>::ArrayList(int cap)
{
	this->cap = this->increment = cap;
	this->data = new T[this->cap];
	this->nrOfData = 0;
}

template<typename T>
inline ArrayList<T>::~ArrayList()
{
	delete[] this->data;
}

template<typename T>
inline void ArrayList<T>::add(T data)
{
	if (this->nrOfData == this->cap)
	{
		this->expand();
	}
	this->data[this->nrOfData++] = data;
}

template<typename T>
inline void ArrayList<T>::remove(T data)
{
	for (int a = 0; a < this->nrOfData; a++) {
		if (this->data[a] == data)
		{
			this->data[a] = this->data[this->nrOfData];
			a = this->nrOfData;
			this->nrOfData--;
		}
	}
}

template<typename T>
inline bool ArrayList<T>::find(T data) const
{
	bool find = false;
	for (int a = 0; a < this->nrOfData; a++)
	{
		if (this->data[a] == data)
		{
			this->find = true;
			a = this->nrOfData;
		}
	}
	return find;
}

template<typename T>
inline int ArrayList<T>::getSize() const
{
	return this->nrOfData;
}

template<typename T>
inline void ArrayList<T>::clearAll()
{
	this->nrOfData = 0;
	delete[] this->data;
	this->cap = this->increment;
	this->data = new T[this->cap];
}

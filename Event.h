#ifndef EVENT_H
#define EVENT_H
#include <string>
template<typename T>
class Event
{
private:
	T*data;
	std::string*action; //possible extension for Handler Information to help interpret following actions to take,  
	std::string*handler; // enter the handler that should recive this data; // if two handlers need it, make two events instead
	void deepCopy(const Event & other);
	void clearAll();
public:
	Event(T*data = nullptr, std::string*handler = nullptr, std::string*action = nullptr);
	Event(const Event& other);
	Event& operator=(const Event&other);
	~Event();
};

#endif //EVENT_H

template<typename T>
inline void Event<T>::deepCopy(const Event & other)
{
	if (other.data != nullptr)
		this->data = new T(*other.data);
	else
		this->data = nullptr;
	if (other.handler != nullptr)
		this->handler = new std::string(*other.handler);
	else
		this->handler = nullptr;
	if (other.action != nullptr)
		this->action = new std::string(*other.action);
	else
		this->action = nullptr;
}

template<typename T>
inline void Event<T>::clearAll()
{
	if (this->data != nullptr)
	{
		delete this->data;
	}
	if (this->handler != nullptr)
	{
		delete this->handler;
	}
	if (this->action != nullptr)
	{
		delete this->action;
	}
}

template<typename T>
inline Event<T>::Event(T * data, std::string * handler, std::string * action)
{
	if (data != nullptr)
		this->data = new T(*data);
	else
		this->data = nullptr;
	if (handler != nullptr)
		this->handler = new std::string(*handler);
	else
		this->handler = nullptr;
	if (action != nullptr)
		this->action = new std::stringT(*action);
	else
		this->action = nullptr;
}

template<typename T>
inline Event<T>::Event(const Event & other)
{
	this->deepCopy(other);
}

template<typename T>
inline Event & Event<T>::operator=(const Event & other)
{
	if (this != &other)
	{
		this->clearAll();
		this->deepCopy();
	}
	return *this;
	
}

template<typename T>
inline Event<T>::~Event()
{
	if(this->data != nullptr)
		delete this->data;
	if (this->handler != nullptr)
		delete this->handler;
	if (this->action != nullptr)
		delete this->action;
}

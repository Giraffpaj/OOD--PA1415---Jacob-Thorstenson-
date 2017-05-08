#include "Event.h"

void Event::deepCopy(const Event & other)
{
	if (other.dataNum != nullptr)
		this->dataNum = new int(*other.dataNum);
	else
		this->dataNum = nullptr;
	if (other.dataTxt != nullptr)
		this->dataTxt = new std::string(*other.dataTxt);
	else
		this->dataTxt = nullptr;
	if (other.handler != nullptr)
		this->handler = new std::string(*other.handler);
	else
		this->handler = nullptr;
	if (other.action != nullptr)
		this->action = new std::string(*other.action);
	else
		this->action = nullptr;
}

void Event::clearAll()
{
	if (this->dataNum != nullptr)
	{
		delete this->dataNum;
	}
	if (this->dataTxt != nullptr)
	{
		delete this->dataNum;
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

Event::Event(std::string * dataTxt, int * dataNum, std::string * handler, std::string * action)
{
	if (dataNum != nullptr)
		this->dataNum = new int(*dataNum);
	else
		this->dataNum = nullptr;
	if (dataTxt != nullptr)
		this->dataTxt = new std::string(*dataTxt);
	else
		this->dataTxt = nullptr;
	if (handler != nullptr)
		this->handler = new std::string(*handler);
	else
		this->handler = nullptr;
	if (action != nullptr)
		this->action = new std::string(*action);
	else
		this->action = nullptr;
}

Event::Event(const Event & other)
{
	this->deepCopy(other);
}

Event & Event::operator=(const Event & other)
{
	if (this != &other)
	{
		this->clearAll();
		this->deepCopy(other);
	}
	return *this;
}

Event::~Event()
{
	this->clearAll();
}

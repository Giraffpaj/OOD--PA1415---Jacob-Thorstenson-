#include "Event.h"

void Event::deepCopy(const Event & other)
{
	this->dataNum = other.dataNum;
	this->dataTxt = other.dataTxt;
	this->handler = other.handler;
	this->action = other.action;
}

void Event::clearAll()
{

}

Event::Event(std::string dataTxt, int dataNum, std::string handler, std::string action)
{
	this->dataNum = dataNum;
	this->dataTxt = dataTxt;
	this->handler = handler;
	this->action = action;
}

Event::Event(const Event & other)
{
	this->deepCopy(other);
}

bool Event::operator==(const Event & other)
{
	bool valid = true;
	if (this->action != other.action)
	{
		valid = false;
	}
	if (this->dataNum != other.dataNum)
	{
		valid = false;
	}
	if (this->dataTxt != other.dataTxt)
	{
		valid = false;
	}
	if (this->handler != other.handler)
	{
		valid = false;
	}
	return valid;
}

int Event::getDataNum() const
{
	return this->dataNum;
}

std::string Event::getDataTxt() const
{
	return this->dataTxt;
}

std::string Event::getHandler() const
{
	return this->handler;
}

std::string Event::getAction() const
{
	return this->action;
}

Event::~Event()
{
	this->clearAll();
}

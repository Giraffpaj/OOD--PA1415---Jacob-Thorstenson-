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

bool Event::operator==(const Event & other)
{
	bool valid = true;
	if (this->action != nullptr && other.action != nullptr)
	{
		if (!(*this->action == *other.action))
		{
			valid = false;
		}
	}
	if (this->dataNum != nullptr && other.dataNum != nullptr)
	{
		if (!(*this->dataNum == *other.dataNum))
		{
			valid = false;
		}
	}
	if (this->dataTxt != nullptr && other.dataTxt != nullptr)
	{
		if (!(*this->dataTxt == *other.dataTxt))
		{
			valid = false;
		}
	}
	if (this->dataNum != nullptr && other.dataNum != nullptr)
	{
		if (!(*this->handler == *other.handler))
		{
			valid = false;
		}
	}
	
	return valid;
}

std::string Event::getToString() const
{
	std::string ha = "None";
	std::string ac = "None";
	std::string dn = "None";
	std::string dt = "None";
	if (this->handler != nullptr)
	{
		ha = *this->handler;
	}
	if (this->action != nullptr)
	{
		ac = *this->action;
	}
	if (this->dataNum != nullptr)
	{
		dn = std::to_string(*this->dataNum);
	}
	if (this->dataTxt != nullptr)
	{
		dt = *this->dataTxt;
	}
	return "The data is menat for: " + ha + "\n The action to perform is: " + ac
		+ "Number data included: " + dn + "\nText data included: " + dt;
}

int Event::getDataNum() const
{
	int myReturn = -1;
	if (this->dataNum != nullptr)
	{
		myReturn = *this->dataNum;
	}
	return myReturn;
}

std::string Event::getDataTxt() const
{
	std::string myReturn = "None";
	if (this->dataTxt != nullptr)
	{
		myReturn = *this->dataTxt;
	}
	return myReturn;
}

std::string Event::getHandler() const
{
	std::string myReturn = "None";
	if (this->handler != nullptr)
	{
		myReturn = *this->handler;
	}
	return myReturn;
}

std::string Event::getAction() const
{
	std::string myReturn = "None";
	if (this->action != nullptr)
	{
		myReturn = *this->action;
	}
	return myReturn;
}

Event::~Event()
{
	this->clearAll();
}

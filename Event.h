#ifndef EVENT_H
#define EVENT_H
#include <string>
class Event
{
private:
	int dataNum;
	std::string dataTxt;
	std::string action; //possible extension for Handler Information to help interpret following actions to take,  
	std::string handler; // enter the handler that should recive this data; // if two handlers need it, make two events instead
	void deepCopy(const Event & other);
public:
	Event(std::string dataTxt = "?", int dataNum = -1, std::string handler = "?", std::string action = "?");
	Event(const Event& other);
	bool operator==(const Event&other);
	~Event();
	int getDataNum()const;
	std::string getDataTxt()const;
	std::string getHandler()const;
	std::string getAction()const;
	void clearAll();
};

#endif //EVENT_H
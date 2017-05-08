#ifndef EVENT_H
#define EVENT_H
#include <string>
class Event
{
private:
	int*dataNum;
	std::string*dataTxt;
	std::string*action; //possible extension for Handler Information to help interpret following actions to take,  
	std::string*handler; // enter the handler that should recive this data; // if two handlers need it, make two events instead
	void deepCopy(const Event & other);
	void clearAll();
public:
	Event(std::string*dataTxt = nullptr, int*dataNum = nullptr, std::string*handler = nullptr, std::string*action = nullptr);
	Event(const Event& other);
	Event& operator=(const Event&other);
	~Event();
};

#endif //EVENT_H
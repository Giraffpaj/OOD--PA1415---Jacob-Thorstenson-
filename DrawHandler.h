#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H
#include "ArrayList.h"
#include "Object.h"

class DrawHandler
{
	private:
		ArrayList<Object> objectList;
	public:
		DrawHandler();
		~DrawHandler();
		void draw(sf::RenderWindow & window);
		bool addObject(Object object);
		bool removeObject(Object object);
		void updateSprite(Object object);
};



#endif //DRAWHANDLER_H
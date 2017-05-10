#include <iostream>
#include "MapGenerator.h"
#include <ctime>
using namespace std;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(static_cast<unsigned>(time(0)));
	for (int a = 0; a < 28; a++)
	{
		
		for (int b = 0; b < 50; b++)
		{
			cout << "#0";
		}
		cout << endl;
	}

	cout << endl << endl << endl;
	cout << endl << endl << endl;
	MapGenerator mG(50, 28);
	mG.createMapDesign();
	mG.drawMap();

	return 0;
}
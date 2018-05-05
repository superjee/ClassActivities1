#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Monster.h"
#include "zombie.h"
#include "Orc.h"
using namespace std;
int main()
{
	//Test
	srand(time(NULL));
	Monster *monster = new Monster();
	monster->init();


	/*for (int i = 0; i < 100; i++)
	{
		int ran = rand() % 2 + 1;
		if (ran == 1)
		{
			
		}
		else if (ran == 2)
		{

		}
		//int ranA = rand() % 10 + 1;
		//cout << ran << endl;
	}*/

	cout << "a";
	getchar();
	return 0;
}
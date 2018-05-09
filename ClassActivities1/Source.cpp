#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Monster.h"
#include "zombie.h"
#include "Orc.h"
using namespace std;
//Test up in Visual // can not push by Visual??? ,but can push by GitHub Desktop.

const int MaxNumberOfMonster = 100; //ค่าคงที่

int main()
{	
	cout << "///////////   Links To Fantasy   ////////////" << endl;
	cout << "/            by Tanapat Yatana              /" << endl;
	cout << "/                                           /" << endl;
	cout << "/    Zombie base Attack  : 7 - 13 (10,3)    /" << endl;
	cout << "/    Orc    base Attack  : 23 - 37 (30,7)   /" << endl;
	cout << "/                                           /" << endl;
	cout << "///////////   Links To Fantasy   ////////////" << endl;
	cout << endl;
	cout << endl;

	srand(time(NULL));
	int ran = -1;

	Monster *monster[MaxNumberOfMonster];

	for (int i = 0; i < MaxNumberOfMonster; i++)
	{
		ran = rand() % 2 + 1;
		monster[i]->initiation(ran, i, monster);
	}

	/*cout << monster[0]->get_HP() << endl;
	monster[0]->set_HP(5000);
	cout << monster[0]->get_HP() << endl;
	cout << monster[0]->get_Atk() << endl;
	cout << monster[0]->get_Atk() << endl;
	cout << monster[0]->get_Atk() << endl;*/


	/*monster[0] = new zombie();
	cout << monster[0]->get_HP() <<endl;
	monster[0]->set_HP(1333333);
	cout << monster[0]->get_HP() << endl;;*/


	getchar();
	return 0;
}


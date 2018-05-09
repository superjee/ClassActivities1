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

{	srand(time(NULL));
	int ran = -1;

	Monster *monster[MaxNumberOfMonster];

	for (int i = 0; i < MaxNumberOfMonster; i++)
	{
		monster[i] = new Monster();
		ran = rand() % 2 + 1;
		monster[i]->initiation(ran, i);
	}

	getchar();
	return 0;
}
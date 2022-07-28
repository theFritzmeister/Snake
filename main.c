//    OR LEVY
//    206263352

#include"Snake.h"

int main()
{
	int again = 1;
	greeting();
	while (again == 1)
	{
		game();
		printf("Want to play again?  press:\n Play again --> '1'\n Quit --> any other key\n");
		if (1 != scanf_s("%d", &again))
			again = 0;
	}
	
		
	system("pause");
}

void init(void) {
	system("cls");
}

void gotoxy(int x, int y) {
	printf("\x1b[%d;%df", x, y);
}

void sleep(float secs) {
	clock_t clocks_start = clock();

	while (clock() - clocks_start < secs * CLOCKS_PER_SEC);
}


void InitBoard()
{

	int i = 0, j = 0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (i == 0 || i == 24 || j == 0 || j == 74)
			{
				gotoxy(i, j);
				printf("#");
			}
		}
	}
}


Snake* createNewNode(int row, int col, Snake* next)
{
	Snake* node = (Snake*)malloc(sizeof(Snake));

	node->x = row;
	node->y = col;
	node->next = next;
	return node;
}



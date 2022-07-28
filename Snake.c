#include "Snake.h"


void printsnake(Snake* head)
{
	while (head != NULL)
	{
		gotoxy(head->x, head->y);
		printf("@");
		head = head->next;
	}
}


bool iscorrectmove(char m)
{
	if (m == 'a' || m == 's' || m == 'd' || m == 'w')
		return true;
	else
		return false;
}

bool GameOver(Snake* head)
{
	if (head->x == X - 1 || head->x == 1 || head->y == 1 || head->y == Y - 1)
		return true;
	if (selfbite(head))
		return true;
	return false;
}


void updatemove(char move, int* row, int* col)
{
	switch (move)
	{
	case 'w':
		*row = *row - 1;
		break;
	case 's':
		*row = *row + 1;
		break;
	case 'd':
		*col = *col + 1;
		break;
	case 'a':
		*col = *col - 1;
		break;
	default:
		move;
	}
}


Snake* insertNodeToHead(Snake* head, Snake* newHead)
{
	newHead->next = head;
	return newHead;
}

void printspace(Snake* head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	gotoxy(head->x, head->y);
	printf(" ");
}

void updatesnakebody(Snake* head, int row, int col)
{
	if (head == NULL)
		return;
	else
	{
		updatesnakebody(head->next, head->x, head->y);
		head->x = row;
		head->y = col;
	}
}

bool selfbite(Snake* head)
{
	Snake* current = head->next;
	while (current != NULL)
	{
		if (head->x == current->x && head->y == current->y)
			return true;
		current = current->next;
	}
	return false;
}


bool pairproblem(Snake* head, char move, char lastmove)
{
	Snake* second = head->next;
	if (second != NULL && second->next == NULL)
	{
		if (move == 'd' && lastmove == 'a')
			return true;
		if (move == 'a' && lastmove == 'd')
			return true;
		if (move == 'w' && lastmove == 's')
			return true;
		if (move == 's' && lastmove == 'w')
			return true;
	}
	return false;
}

void freeSnake(Snake* head)
{
	Snake* next;
	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

void game() {

	init();
	InitBoard();
	bool check = false;
	int loop = 0;
	float sec = 1.0;
	char move = 'd', lastmove = 'd';
	int row = X / 2;
	int col = Y / 2;
	Snake* head = createNewNode(row, col, NULL);
	while (!GameOver(head) && !check)
	{
		loop++;

		printsnake(head);
		sleep(sec);
		printspace(head);
		if (_kbhit())
			move = _getch();
		check = pairproblem(head, move, lastmove);
		if (!iscorrectmove(move))
			move = lastmove;
		else
			lastmove = move;
		updatemove(move, &row, &col);
		if (loop == 5)
		{
			loop = 0;
			head = insertNodeToHead(head, createNewNode(row, col, head));
			if (sec > 0.1)
				sec = sec - 0.03;
		}
		else
			updatesnakebody(head, row, col);
	}
	gotoxy(0, 0);
	init();
	InitBoard();
	gotoxy(X / 2, (Y / 2) - 5);
	printf("Game Over");
	gotoxy(X + 1, 0);
	freeSnake(head);
}

void greeting() {

	printf("              Welcom to SNAKE! Get ready to play\n\n\n");
	printf("Keys:                        UP (W)\n");
	printf("              Right (A)    Down (S)    Left (D)\n\n\n");
	printf("Ready? Press ENTER to continue...\n");
	getchar();
}
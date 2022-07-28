#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



#define X 25
#define Y 75
typedef struct snake
{
	int x;
	int y;
	struct snake* next;
}Snake;

// Turn escape codes ON.
void init(void);

// this function initialize the board.
void InitBoard();

// Moves the cursor to position (x,y) on screen.
// Parameters:
//     x: the row of the posiiton.
//     y: the column of the posiiton.
void gotoxy(int x, int y);

// Delays the execution of the program.
// Parameters:
//     secs: the length of the delay in seconds. 
void sleep(float secs);

// this function initialize the board's borders.
void InitBoard();

//this function creats a node.
Snake* createNewNode(int row, int col, Snake* next);

//this function insert new node to the head of the list.
Snake* insertNodeToHead(Snake* head, Snake* newHead);

// this function free the node's memory.
void freeSnake(Snake* head);

//this function prints the whole body of the snake.
void printsnake(Snake* head);

//this function return true if the char entered is a valid char.
bool iscorrectmove(char m);

//this function return true if the game is over:
// if the snake bite himself or touch the border.
bool GameOver(Snake* head);

//this function returns true if the snake bite himself. 
bool selfbite(Snake* head);

// this function cover the case where the snake's body length 
// is 2 and the player press the opposit side
// which un thus case the game is over and the function returns true.
bool pairproblem(Snake* head, char move, char lastmove);

//this function update the coordinates for the next step.
void updatemove(char move, int* row, int* col);

//this function eraze the snake's tail each turn.
void printspace(Snake* head);

//thins function update the location of the snake on the board.
void updatesnakebody(Snake* head, int row, int col);

void game();
void greeting();

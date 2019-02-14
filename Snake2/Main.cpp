#include<iostream>
#include<conio.h>
using namespace std;
bool gameOver;
int x, y, xFruit, yFruit, height, weight, nTail;
enum En { STOP = 0, UP, DOWN, LEFT, RIGHT};
En Enumiration;
int tailX[100], tailY[100];


void SetUp() {
	gameOver = false;
	Enumiration = STOP;
	height = 20;
	weight = 20;
	x = height / 2 -1;
	y = weight / 2 -1;
	xFruit = rand() % height;
	yFruit = rand() % weight;
}
void Drow() {
	system("cls");
	for (int i = 0; i < height+1; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int j = 0; j < height; j++)
	{

		for (int i = 0; i < weight; i++)
		{
			if (i == 0 || i == weight - 1)
				cout << '#';
			if (j == x && i == y)
				cout << "0";
			else if (j == xFruit && i == yFruit)
				cout << "F";
			else {
				bool print = true;;
				for (int r = 0; r < nTail; r++)
				{
					if (j == tailX[r] && i == tailY[r]) {
						print = false;
						cout << "o";
					}

				}
				if (print)
					cout << " ";
			}
				
		}
		cout << endl;
	}
	for (int i = 0; i < height+1; i++)
	{
		cout << "#";
	}
	cout << endl;
}
void Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w': Enumiration = UP; break;
		case 's': Enumiration = DOWN; break;
		case 'a': Enumiration = LEFT; break;
		case 'd': Enumiration = RIGHT; break;
		case 'x': gameOver = true; ; break;
		}
	}

}
void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (Enumiration)
	{
	case UP: x--; break;
	case DOWN: x++; break;
	case LEFT: y--; break;
	case RIGHT: y++; break;

	}
	if (x < 0)
	    x = height;
	if (x > height)
		x = 0;
	if (y < 0)
		y = weight -2;
	if (y > weight -2)
		y = 0;
	if (x == xFruit && y == yFruit)
	{
		xFruit = rand() % height;
		yFruit = rand() % weight;
		nTail++;
	}
	for (int k = 0; k < nTail; k++)
	{
		if (x == tailX[k]&& y == tailY[k])
			gameOver = true;
		}
	
	
}




int main() {
	SetUp();
	while (!gameOver) {
		Drow();
		Input();
		Logic();
	}

	return 0;
}
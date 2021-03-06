#include "pch.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>

int main()
{
	const int tileWidth = 50;
	int M(0), N(0), m(0), n(0);
	std::cout << "Input the size of the maze" << std::endl;
	std::cout << "M = ";
	std::cin >> M;
	std::cout << "\nN = ";
	std::cin >> N;
	std::cout << std::endl;

	int ** array = new int*[N];	//迷宫的二维数组表达
	for (int i = 0; i < N; ++i)
	{
		array[i] = new int[M];
	}

	//图像红 --> 数组 1
	//图像绿 --> 数组 0
	MOUSEMSG msg;
	initgraph(M*tileWidth + tileWidth, N*tileWidth);
	setlinecolor(BLUE);
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == 0 || i == M - 1 || j == 0 || j == N - 1)
			{
				setfillcolor(RED);
				array[j][i] = 1;
			}
			else
			{
				setfillcolor(GREEN);
				array[j][i] = 0;
			}
			fillrectangle(i*tileWidth, j*tileWidth,
				(i + 1)*tileWidth, (j + 1)*tileWidth);
		}
	}
	bool flag = true;
	while (flag)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (msg.x > M*tileWidth)
			{
				flag = false;
				break;
			}
			m = msg.x / tileWidth; n = msg.y / tileWidth;
			setfillcolor(RED);
			array[n][m] = 1;
			fillrectangle(m*tileWidth, n*tileWidth,
				(m + 1)*tileWidth, (n + 1)*tileWidth);
			break;
		case WM_RBUTTONDOWN:
			m = msg.x / tileWidth; n = msg.y / tileWidth;
			setfillcolor(GREEN);
			array[n][m] = 0;
			fillrectangle(m*tileWidth, n*tileWidth,
				(m + 1)*tileWidth, (n + 1)*tileWidth);
			break;
		default:
			break;
		}
	}
	closegraph();

	int choice(0);
	std::cout << "0. Array in C;\n1. List in Python." << std::endl;
	std::cin >> choice;
	char lSep = '{';
	char rSep = '}';
	switch (choice)
	{
	case 0:
		break;
	case 1:
		lSep = '[';
		rSep = ']';
		break;
	default:
		break;
	}

	int counter(0);
	std::cout << lSep << std::endl;
	for (int i = 0; i < N; ++i)
	{
		std::cout << lSep;
		for (int j = 0; j < M; ++j)
		{
			std::cout << array[i][j];
			if (j != M - 1) { std::cout << ", "; }
			else { std::cout << rSep; }
		}
		if (i != N - 1) { std::cout << ",\n"; }
	}
	std::cout << rSep;

	for (int i = 0; i < N; ++i)
	{
		delete array[i];
	}
	delete array;

	system("PAUSE");
}

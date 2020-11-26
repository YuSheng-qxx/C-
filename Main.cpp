/*-----推箱子游戏-----created by 汤圆*/
/*
======待完成项目======
一.在死局的情况下重开关卡
二.自动生成新地图(目前只有5张地图,自己可以通过给MAP添加数组进行新地图的添加)
*/
//障碍为█，箱子为□，玩家为♀，目的地为◎，到达目的地之后为★，空地为" "，人在目的地上表示☆;
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#define ROW 12
#define COL 12
char but;//按键
//定义结构体玩家位置，x,y为玩家的坐标
struct pos {
	int x;
	int y;
}player;
struct MAP {
	const int row;
	const int col;
	char map[ROW][COL];
};
//颜色
void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
//地图
struct MAP map1[5] = { { 8, 8, { { 0, 0, 1, 1, 1, 0, 0, 0 },  //地图一
{ 0, 0, 1, 3, 1, 0, 0, 0 },
{ 0, 0, 1, 0, 1, 1, 1, 1 },
{ 1, 1, 1, 2, 0, 2, 3, 1 },
{ 1, 3, 0, 2, 4, 1, 1, 1 },
{ 1, 1, 1, 1, 2, 1, 0, 0 },
{ 0, 0, 0, 1, 3, 1, 0, 0 },
{ 0, 0, 0, 1, 1, 1, 0, 0 } } },
{ 9, 9, { { 1, 1, 1, 1, 1, 0, 0, 0, 0 },   //地图二
{ 1, 4, 0, 0, 1, 0, 0, 0, 0 },
{ 1, 0, 2, 2, 1, 0, 1, 1, 1 },
{ 1, 0, 2, 0, 1, 0, 1, 3, 1 },
{ 1, 1, 1, 0, 1, 1, 1, 3, 1 },
{ 0, 1, 1, 0, 0, 0, 0, 3, 1 },
{ 0, 1, 0, 0, 0, 1, 0, 0, 1 },
{ 0, 1, 0, 0, 0, 1, 1, 1, 1 },
{ 0, 1, 1, 1, 1, 1, 0, 0, 0 } } },
{ 7, 10, { { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },  //地图三
{ 0, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
{ 1, 1, 2, 1, 1, 1, 0, 0, 0, 1 },
{ 1, 0, 4, 0, 2, 0, 0, 2, 0, 1 },
{ 1, 0, 3, 3, 1, 0, 2, 0, 1, 1 },
{ 1, 1, 3, 3, 1, 0, 0, 0, 1, 0 },
{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 } } },
{ 8, 6, { { 0, 1, 1, 1, 1, 0 },    //地图四
{ 1, 1, 0, 0, 1, 0 },
{ 1, 4, 2, 0, 1, 0 },
{ 1, 1, 2, 0, 1, 1 },
{ 1, 1, 0, 2, 0, 1 },
{ 1, 3, 2, 0, 0, 1 },
{ 1, 3, 3, 5, 3, 1 },
{ 1, 1, 1, 1, 1, 1 } } },
{ 8, 8, { { 0, 1, 1, 1, 1, 1, 0, 0 },  //地图五
{ 0, 1, 0, 4, 0, 1, 1, 1 },
{ 1, 1, 0, 1, 2, 0, 0, 1 },
{ 1, 0, 5, 3, 0, 3, 0, 1 },
{ 1, 0, 0, 2, 2, 0, 1, 1 },
{ 1, 1, 1, 0, 1, 3, 1, 0 },
{ 0, 0, 1, 0, 0, 0, 1, 0 },
{ 0, 0, 1, 1, 1, 1, 1, 0 } } } };   //在这里增加地图，行数，列数，以及地图元素

/*
*
*
*生成地图
*
*
*/

void mapInit(char(*map)[COL], const int *row, const int *col) {
	for (int i = 0; i < *row; i++) {
		cout << "\t\t\t\t\t";
		for (int j = 0; j < *col; j++) {
			switch ((map[i][j])) {
			case 0: color(15); cout << "  ";
				break;
			case 1:color(27); cout << "█";
				break;
			case 2:color(4); cout << "□";
				break;
			case 3:color(5); cout << "◎";
				break;
			case 4:color(6); cout << "♀";
				break;
			case 5:color(8); cout << "★";
				break;
			case 7:color(9); cout << "☆";
				break;
			}
		}
		cout << endl;
	}
	color(27);
	cout << "\n\t\t\t\t\t█";
	color(15);
	cout << "障碍\n";
	color(4);
	cout << "\t\t\t\t\t□";
	color(15);
	cout << "箱子\n";
	color(5);
	cout << "\t\t\t\t\t◎";
	color(15);
	cout << "目标点\n";
	color(6);
	cout << "\t\t\t\t\t♀";
	color(15);
	cout << "人物\n";
	color(8);
	cout << "\t\t\t\t\t★";
	color(15);
	cout << "箱子在目标点上\n";
	color(9);
	cout << "\t\t\t\t\t☆";
	color(15);
	cout << "人物在目标点上\n";

	cout << "\n\t\t\t\t\tW A S D控制人物移动\n\t\t\t\t\tR键撤销移动,ESC键退出" << endl;
}

/*
*
*
*锁定玩家位置
*
*
*/
void lockPlayerPosition(char(*map)[COL], const int *row, const int *col, int *x, int *y) {
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			if ((map[i][j]) == 4 || (map[i][j] == 7)) {
				*x = i;
				*y = j;
				return;
			}
		}
	}
}
/*
*
*
*判断是否胜利
*
*
*/
int isWin(char(*map)[COL], const int*row, const int *col) {
	int count = 0;
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < *col; j++) {
			if (map[i][j] == 2 || map[i][j] == 7) {
				return 0;
			}
		}
	}
	return 1;
}
/*
*
*
*控制玩家移动
*
*
*/
void playerMov(char(*map)[COL], int *x, int *y) {
	char CheckBut = but;
	switch (but = _getch()) {
		//退出
	case 'Q':
	case 'q':
	case 27: {
				 exit(1);
	}
		//撤回
	case 'R':
	case 'r': {
				  if (CheckBut == 0) {
					  cout << "\n之前没有进行任何移动操作,请移动之后再试" << endl;
				  }
				  //上一次操作按的是W键
				  else if (CheckBut == 'w') {
					  //(1)上次人物要到的下一个位置是空地
					  if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) - 1][*y] != 2 && map[(*x) - 1][*y] != 5) {
						  map[*x][*y] = 0;
						  map[(*x) + 1][*y] = 4;
						  ++*x;
					  }
					  //(2)上次人物要到的下一个位置是空目的地
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) - 1][*y] != 5 && map[(*x) - 1][*y] != 2) {
						  map[*x][*y] = 3;
						  map[(*x) + 1][*y] = 4;
						  ++*x;
					  }
					  //(3)上次人物要推着箱子到一个空地
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 2) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][(*y)] = 0;
						  map[(*x) + 1][(*y)] = 4;

					  }
					  //(4)上次人物要推着箱子到一个空目的地
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 5) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 4;
					  }
					  //(5)上次人物要推着目的地中的箱子到空地
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 2) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 0;
						  map[(*x) + 1][*y] = 4;

					  }
					  //(6)上次人物要推着目的地中的箱子到新的目的地中
					  else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 0) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 4;

					  }
					  //(7)上次人物在目的地中到空地
					  else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 4 && map[(*x) - 1][*y] != 5) {
						  map[(*x) + 1][*y] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)上次人物在目的地中推箱子到空地
					  else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][*y] = 0;
						  map[(*x) + 1][*y] = 7;
					  }
					  //(9)上次人物在目的地中推箱子到新的目的地
					  else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 7;

					  }
					  //(10)上次人物在目的地中到新的目的地
					  else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 7 && map[(*x) - 1][*y] != 2 && map[(*x) - 1][*y] != 5) {
						  map[(*x) + 1][*y] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)人物在目的地中推下一个目的地中的箱子到空地
					  else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 0;
						  map[(*x) + 1][*y] = 7;
					  }
					  //(12)人物在目的地中推下一个目的地中的箱子到新目的地
					  else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 7;
					  }
				  }
				  //上一次操作按的是S键
				  else if (CheckBut == 's') {
					  //(1)上次人物要到的下一个位置是空地
					  if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) + 1][*y] != 2 && map[(*x) + 1][*y] != 5) {
						  map[*x][*y] = 0;
						  map[(*x) - 1][*y] = 4;
						  --*x;
					  }
					  //(2)上次人物要到的下一个位置是空目的地
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) + 1][*y] != 5 && map[(*x) + 1][*y] != 2) {
						  map[*x][*y] = 3;
						  map[(*x) - 1][*y] = 4;
						  --*x;
					  }
					  //(3)上次人物要推着箱子到一个空地
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 2) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][(*y)] = 0;
						  map[(*x) - 1][(*y)] = 4;

					  }
					  //(4)上次人物要推着箱子到一个空目的地
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 5) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 4;
					  }
					  //(5)上次人物要推着目的地中的箱子到空地
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 2) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 0;
						  map[(*x) - 1][*y] = 4;

					  }
					  //(6)上次人物要推着目的地中的箱子到新的目的地中
					  else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 0) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 4;

					  }
					  //(7)上次人物在目的地中到空地
					  else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 4 && map[(*x) + 1][*y] != 5) {
						  map[(*x) - 1][*y] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)上次人物在目的地中推箱子到空地
					  else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][*y] = 0;
						  map[(*x) - 1][*y] = 7;
					  }
					  //(9)上次人物在目的地中推箱子到新的目的地
					  else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 7;

					  }
					  //(10)上次人物在目的地中到新的目的地
					  else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 7 && map[(*x) + 1][*y] != 2 && map[(*x) + 1][*y] != 5) {
						  map[(*x) - 1][*y] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)人物在目的地中推下一个目的地中的箱子到空地
					  else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 0;
						  map[(*x) - 1][*y] = 7;
					  }
					  //(12)人物在目的地中推下一个目的地中的箱子到新目的地
					  else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 7;
					  }

				  }
				  //上一次操作按的是A键
				  else if (CheckBut == 'a') {
					  //(1)上次人物要到的下一个位置是空地
					  if (map[*x][*y] == 4 && map[*x][(*y) + 1] == 0 && map[*x][(*y) - 1] != 2 && map[*x][(*y) + 1] != 5 && map[*x][(*y) - 1] != 5) {
						  map[*x][*y] = 0;
						  map[*x][(*y) + 1] = 4;
					  }
					  //(2)上次人物要到的下一个位置是空目的地
					  else if (map[(*x)][(*y) + 1] == 0 && map[*x][*y] == 7 && map[(*x)][(*y) - 1] != 5 && map[(*x)][(*y) - 1] != 2) {
						  map[*x][*y] = 3;
						  map[(*x)][(*y) + 1] = 4;

					  }
					  //(3)上次人物要推着箱子到一个空地
					  else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 2) {
						  map[*x][*y] = 2;
						  map[(*x)][(*y) - 1] = 0;
						  map[(*x)][(*y) + 1] = 4;

					  }
					  //(4)上次人物要推着箱子到一个空目的地
					  else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 5) {
						  map[*x][*y] = 2;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 4;
					  }
					  //(5)上次人物要推着目的地中的箱子到空地
					  else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 2) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 0;
						  map[*x][(*y) + 1] = 4;

					  }
					  //(6)上次人物要推着目的地中的箱子到新的目的地中
					  else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 0) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 4;

					  }
					  //(7)上次人物在目的地中到空地
					  else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 4 && map[*x][(*y) - 1] != 5) {
						  map[*x][(*y) + 1] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)上次人物在目的地中推箱子到空地
					  else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) - 1] = 0;
						  map[*x][(*y) + 1] = 7;
					  }
					  //(9)上次人物在目的地中推箱子到新的目的地
					  else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 7;

					  }
					  //(10)上次人物在目的地中到新的目的地
					  else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 7 && map[*x][(*y) - 1] != 2 && map[*x][(*y) - 1] != 5) {
						  map[*x][(*y) + 1] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)人物在目的地中推下一个目的地中的箱子到空地
					  else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 0;
						  map[*x][(*y) + 1] = 7;
					  }
					  //(12)人物在目的地中推下一个目的地中的箱子到新目的地
					  else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 7;
					  }
				  }
				  //上一次操作按的是D键
				  else if (CheckBut == 'd') {
					  //(1)上次人物要到的下一个位置是空地
					  if (map[*x][*y] == 4 && map[*x][(*y) - 1] == 0 && map[*x][(*y) + 1] != 2 && map[*x][(*y) - 1] != 5 && map[*x][(*y) + 1] != 5) {
						  map[*x][*y] = 0;
						  map[*x][(*y) - 1] = 4;
					  }
					  //(2)上次人物要到的下一个位置是空目的地
					  else if (map[(*x)][(*y) - 1] == 0 && map[*x][*y] == 7 && map[(*x)][(*y) + 1] != 5 && map[(*x)][(*y) + 1] != 2) {
						  map[*x][*y] = 3;
						  map[(*x)][(*y) - 1] = 4;

					  }
					  //(3)上次人物要推着箱子到一个空地
					  else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 2) {
						  map[*x][*y] = 2;
						  map[(*x)][(*y) + 1] = 0;
						  map[(*x)][(*y) - 1] = 4;

					  }
					  //(4)上次人物要推着箱子到一个空目的地
					  else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 5) {
						  map[*x][*y] = 2;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 4;
					  }
					  //(5)上次人物要推着目的地中的箱子到空地
					  else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 2) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 0;
						  map[*x][(*y) - 1] = 4;

					  }
					  //(6)上次人物要推着目的地中的箱子到新的目的地中
					  else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 0) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 4;

					  }
					  //(7)上次人物在目的地中到空地
					  else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 4 && map[*x][(*y) + 1] != 5) {
						  map[*x][(*y) - 1] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)上次人物在目的地中推箱子到空地
					  else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) + 1] = 0;
						  map[*x][(*y) - 1] = 7;
					  }
					  //(9)上次人物在目的地中推箱子到新的目的地
					  else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 7;

					  }
					  //(10)上次人物在目的地中到新的目的地
					  else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 7 && map[*x][(*y) + 1] != 2 && map[*x][(*y) + 1] != 5) {
						  map[*x][(*y) - 1] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)人物在目的地中推下一个目的地中的箱子到空地
					  else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 0;
						  map[*x][(*y) - 1] = 7;
					  }
					  //(12)人物在目的地中推下一个目的地中的箱子到新目的地
					  else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 7;
					  }
				  }
				  break;
	}
		//向上走，在键盘上按下W键
	case 'W':
	case 'w':
	case 38: {
				 //(1)人物要到的下一个位置是空地
				 if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 4;
					 --*x;
				 }
				 //(2)人物要到的下一个位置是空目的地
				 else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 7;
					 --*x;
				 }
				 //(3)人物要推着箱子到一个空地
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][(*y)] = 4;
					 map[(*x) - 2][(*y)] = 2;
					 --*x;
				 }
				 //(4)人物要推着箱子到一个空目的地
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 4;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
				 //(5)人物要推着目的地中的箱子到空地
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 2;
					 --*x;
				 }
				 //(6)人物要推着目的地中的箱子到新的目的地中
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
				 //(7)人物在目的地中到空地
				 else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7) {
					 map[(*x) - 1][*y] = 4;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(8)人物在目的地中推箱子到空地
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 4;
					 map[(*x) - 2][*y] = 2;
					 --*x;
				 }
				 //(9)人物在目的地中推箱子到新的目的地
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 4;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
				 //(10)人物在目的地中到新的目的地
				 else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 7) {
					 map[(*x) - 1][*y] = 7;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(11)人物在目的地中推下一个目的地中的箱子到空地
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 2;
					 --*x;
				 }
				 //(12)人物在目的地中推下一个目的地中的箱子到新目的地
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
	}

		break;

		//向下走，在键盘上按下S键
	case 'S':
	case 's':
	case 40: {
				 //(1)人物要到的下一个位置是空地
				 if (map[(*x) + 1][(*y)] == 0 && map[*x][*y] == 4) {
					 map[*x][(*y)] = 0;
					 map[(*x) + 1][*y] = 4;
					 ++*x;
				 }
				 //(2)人物要到的下一个位置是空目的地
				 else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 7;
					 ++*x;
				 }
				 //(3)人物要推着箱子到一个空地
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][(*y)] = 4;
					 map[(*x) + 2][(*y)] = 2;
					 ++*x;
				 }
				 //(4)人物要推着箱子到一个空目的地
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 4;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
				 //(5)人物要推着目的地中的箱子到空地
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 2;
					 ++*x;
				 }
				 //(6)人物要推着目的地中的箱子到新的目的地中
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
				 //(7)人物在目的地中到空地
				 else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7) {
					 map[(*x) + 1][*y] = 4;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(8)人物在目的地中推箱子到空地
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 4;
					 map[(*x) + 2][*y] = 2;
					 ++*x;
				 }
				 //(9)人物在目的地中推箱子到新的目的地
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 4;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
				 //(10)人物在目的地中到新的目的地
				 else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 7) {
					 map[(*x) + 1][*y] = 7;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(11)人物在目的地中推下一个目的地中的箱子到空地
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 2;
					 ++*x;
				 }
				 //(12)人物在目的地中推下一个目的地中的箱子到新目的地
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
	}

		break;
		//向左走，在键盘上按下A键
	case 'A':
	case 'a':
	case 37: {
				 //(1)人物要到的下一个位置是空地
				 if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4) {
					 map[*x][(*y)] = 0;
					 map[*x][(*y) - 1] = 4;
					 --*y;
				 }
				 //(2)人物要到的下一个位置是空目的地
				 else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 7;
					 --*y;
				 }
				 //(3)人物要推着箱子到一个空地
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 2;
					 --*y;
				 }
				 //(4)人物要推着箱子到一个空目的地
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 5;
					 --*y;
				 }
				 //(5)人物要推着目的地中的箱子到空地
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 2;
					 --*x;
				 }
				 //(6)人物要推着目的地中的箱子到新的目的地中
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 5;
					 --*x;
				 }
				 //(7)人物在目的地中到空地
				 else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 7) {
					 map[*x][(*y) - 1] = 4;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(8)人物在目的地中推箱子到空地
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 2;
					 --*x;
				 }
				 //(9)人物在目的地中推箱子到新的目的地
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 5;
					 --*x;
				 }
				 //(10)人物在目的地中到新的目的地
				 else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 7) {
					 map[*x][(*y) - 1] = 7;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(11)人物在目的地中推下一个目的地中的箱子到空地
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 2;
					 --*x;
				 }
				 //(12)人物在目的地中推下一个目的地中的箱子到新目的地
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 5;
					 --*x;
				 }
	}

		break;
		//向右走，在键盘上按下D键
	case 'D':
	case 'd':
	case 39: {
				 //(1)人物要到的下一个位置是空地
				 if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4) {
					 map[*x][(*y)] = 0;
					 map[*x][(*y) + 1] = 4;
					 ++*y;
				 }
				 //(2)人物要到的下一个位置是空目的地
				 else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 7;
					 ++*y;
				 }
				 //(3)人物要推着箱子到一个空地
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 2;
					 ++*y;
				 }
				 //(4)人物要推着箱子到一个空目的地
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 5;
					 ++*y;
				 }
				 //(5)人物要推着目的地中的箱子到空地
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 2;
					 ++*x;
				 }
				 //(6)人物要推着目的地中的箱子到新的目的地中
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 5;
					 ++*x;
				 }
				 //(7)人物在目的地中到空地
				 else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 7) {
					 map[*x][(*y) + 1] = 4;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(8)人物在目的地中推箱子到空地
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 2;
					 ++*x;
				 }
				 //(9)人物在目的地中推箱子到新的目的地
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 5;
					 ++*x;
				 }
				 //(10)人物在目的地中到新的目的地
				 else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 7) {
					 map[*x][(*y) + 1] = 7;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(11)人物在目的地中推下一个目的地中的箱子到空地
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 2;
					 ++*x;
				 }
				 //(12)人物在目的地中推下一个目的地中的箱子到新目的地
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 5;
					 ++*x;
				 }
	}

		break;
	}
}
/*
*
*
*游戏主函数
*
*/
void game() {
	int i = 0, x = 0, y = 0, step = 0;
	struct MAP *pmap = NULL;
	pmap = map1;
	mapInit(pmap->map, &(pmap->row), &(pmap->col));
	while (1) {
		lockPlayerPosition(pmap->map, &(pmap->row), &(pmap->col), &x, &y);
		cout << "\n\t\t\t\t\t你一共走了" << step << "步" << endl;
		cout << but;
		playerMov(pmap->map, &x, &y);
		step++;
		system("cls");
		mapInit(pmap->map, &(pmap->row), &(pmap->col));
		if ((isWin(pmap->map, &(pmap->row), &pmap->col)) && i <= 5) {
			system("cls");
			color(5);
			cout << "\t\t\t\t\t牛逼,按任意键继续" << endl;
			step = -1;
			color(14);
			mapInit(pmap->map, &(pmap->row), &(pmap->col));
			//system("pause");
			pmap++;
			x = 0; y = 0;
			i++;
			lockPlayerPosition(pmap->map, &(pmap->row), &(pmap->col), &x, &y);
		}
	}
}
/*
*
*
*菜单
*
*
*/
void menu() {
	cout << "\t\t\t\t\t菜 单" << endl;
	cout << "\t\t\t\t\t1.开始游戏" << endl;
	cout << "\t\t\t\t\t2.退出" << endl;

}
void Display();
void Register()
{
	ofstream outFile;
	outFile.open("web1.txt", ios_base::out | ios_base::app);
	if (!outFile.is_open())
	{
		cout << "\t\t\t\t\t很遗憾,连接不上服务器";
		cout << "\t\t\t\t\t程序结束";
		cin.get();
		exit(0);
	}
	string name;
	string code;
	cout << "\t\t\t\t\t请输入用户名:";
	cin.get();
	getline(cin, name);
	outFile << name << endl;

	cout << "\t\t\t\t\t请输入密码: ";
	getline(cin, code);
	outFile << code << endl;
	outFile << "=========" << endl;
	cout << "\t\t\t\t\t注册成功";
	outFile.close();
	Display();
}
void login()
{
	cin.get();
	ifstream inFile;
	inFile.open("web1.txt");
	string strVec[100];
	int i = 1;
	if (!inFile.is_open())
	{
		cout << "\t\t\t\t\t很遗憾,连接不上服务器";
		exit(0);
	}
	string name;
	string code;
	string temp;
	char ch;
	char str[20];
	cout << "\t\t\t\t\t请输入用户名:";
	getline(cin, name);
	FILE *pFile;
	int c;
	int n = 0;
	errno_t err;
	err = fopen_s(&pFile, "web1.txt", "r");
	if (pFile == NULL)
	{
		return;
	}
	else
	{
		do
		{
			c = fgetc(pFile);
			if (c == '\n')
				n++;
		} while (c != EOF);
	}
	for (i = 0; i <= n; i++)
	{
		getline(inFile, temp);
		if (name == temp)
		{
			getline(inFile, temp);
			while (1)
			{
				i = 0;
				system("cls");
				cout << "\t\t\t\t\t请输入登陆密码：";
				ch = _getch();
				while (ch != 13)
				{
					if (ch == 8 && i > 0)
					{
						i--;
						str[i] = '\0';
						system("cls");//清屏 重新输出*
						cout << "\t\t\t\t\t输入密码：";
						for (int j = 0; j < i; j++)
						{
							cout << "*";
						}
						ch = _getch();
					}
					else
					{
						printf("*");
						str[i] = ch;
						i++;
						ch = _getch();
					}
				}
				str[i] = '\0';
				string temps = str;
				if (temps == temp)
				{
					system("cls");
					cout << "\t\t\t\t\t密码输入正确" << endl;
					break;
				}
				else
				{
					cout << "\n\t\t\t\t\t密码错误!!";
					_getch();
				}
			}

		}
	}

}
void Display()
{
	cout << "\n\t\t\t\t\t1.注册\n\t\t\t\t\t2.登录\n\t\t\t\t\t3.退出\n\t\t\t\t\t请输入选项:";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		Register();
		break;
	case 2:
		login();
		break;
	case 3:
		exit(0);
	}
}

int main(void) {
	int choice = 0;
	Display();
	cout << "\n\n\tLoading";
	for (int i = 0; i < 100; i++) {
		cout << ".";
		Sleep(10);
	}
	cout << "\n\n\n";
	do {
		menu();
		cout << "\n\t\t\t\t\t输入您的选项:";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls"), game(), system("cls");
			break;
		case 2:
			exit(1);
			break;
		}
	} while (choice);

	return 0;
}
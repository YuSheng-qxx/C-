/*-----��������Ϸ-----created by ��Բ*/
/*
======�������Ŀ======
һ.�����ֵ�������ؿ��ؿ�
��.�Զ������µ�ͼ(Ŀǰֻ��5�ŵ�ͼ,�Լ�����ͨ����MAP�����������µ�ͼ�����)
*/
//�ϰ�Ϊ��������Ϊ�������Ϊ�⣬Ŀ�ĵ�Ϊ�򣬵���Ŀ�ĵ�֮��Ϊ��յ�Ϊ" "������Ŀ�ĵ��ϱ�ʾ��;
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
char but;//����
//����ṹ�����λ�ã�x,yΪ��ҵ�����
struct pos {
	int x;
	int y;
}player;
struct MAP {
	const int row;
	const int col;
	char map[ROW][COL];
};
//��ɫ
void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
//��ͼ
struct MAP map1[5] = { { 8, 8, { { 0, 0, 1, 1, 1, 0, 0, 0 },  //��ͼһ
{ 0, 0, 1, 3, 1, 0, 0, 0 },
{ 0, 0, 1, 0, 1, 1, 1, 1 },
{ 1, 1, 1, 2, 0, 2, 3, 1 },
{ 1, 3, 0, 2, 4, 1, 1, 1 },
{ 1, 1, 1, 1, 2, 1, 0, 0 },
{ 0, 0, 0, 1, 3, 1, 0, 0 },
{ 0, 0, 0, 1, 1, 1, 0, 0 } } },
{ 9, 9, { { 1, 1, 1, 1, 1, 0, 0, 0, 0 },   //��ͼ��
{ 1, 4, 0, 0, 1, 0, 0, 0, 0 },
{ 1, 0, 2, 2, 1, 0, 1, 1, 1 },
{ 1, 0, 2, 0, 1, 0, 1, 3, 1 },
{ 1, 1, 1, 0, 1, 1, 1, 3, 1 },
{ 0, 1, 1, 0, 0, 0, 0, 3, 1 },
{ 0, 1, 0, 0, 0, 1, 0, 0, 1 },
{ 0, 1, 0, 0, 0, 1, 1, 1, 1 },
{ 0, 1, 1, 1, 1, 1, 0, 0, 0 } } },
{ 7, 10, { { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },  //��ͼ��
{ 0, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
{ 1, 1, 2, 1, 1, 1, 0, 0, 0, 1 },
{ 1, 0, 4, 0, 2, 0, 0, 2, 0, 1 },
{ 1, 0, 3, 3, 1, 0, 2, 0, 1, 1 },
{ 1, 1, 3, 3, 1, 0, 0, 0, 1, 0 },
{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 } } },
{ 8, 6, { { 0, 1, 1, 1, 1, 0 },    //��ͼ��
{ 1, 1, 0, 0, 1, 0 },
{ 1, 4, 2, 0, 1, 0 },
{ 1, 1, 2, 0, 1, 1 },
{ 1, 1, 0, 2, 0, 1 },
{ 1, 3, 2, 0, 0, 1 },
{ 1, 3, 3, 5, 3, 1 },
{ 1, 1, 1, 1, 1, 1 } } },
{ 8, 8, { { 0, 1, 1, 1, 1, 1, 0, 0 },  //��ͼ��
{ 0, 1, 0, 4, 0, 1, 1, 1 },
{ 1, 1, 0, 1, 2, 0, 0, 1 },
{ 1, 0, 5, 3, 0, 3, 0, 1 },
{ 1, 0, 0, 2, 2, 0, 1, 1 },
{ 1, 1, 1, 0, 1, 3, 1, 0 },
{ 0, 0, 1, 0, 0, 0, 1, 0 },
{ 0, 0, 1, 1, 1, 1, 1, 0 } } } };   //���������ӵ�ͼ���������������Լ���ͼԪ��

/*
*
*
*���ɵ�ͼ
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
			case 1:color(27); cout << "��";
				break;
			case 2:color(4); cout << "��";
				break;
			case 3:color(5); cout << "��";
				break;
			case 4:color(6); cout << "��";
				break;
			case 5:color(8); cout << "��";
				break;
			case 7:color(9); cout << "��";
				break;
			}
		}
		cout << endl;
	}
	color(27);
	cout << "\n\t\t\t\t\t��";
	color(15);
	cout << "�ϰ�\n";
	color(4);
	cout << "\t\t\t\t\t��";
	color(15);
	cout << "����\n";
	color(5);
	cout << "\t\t\t\t\t��";
	color(15);
	cout << "Ŀ���\n";
	color(6);
	cout << "\t\t\t\t\t��";
	color(15);
	cout << "����\n";
	color(8);
	cout << "\t\t\t\t\t��";
	color(15);
	cout << "������Ŀ�����\n";
	color(9);
	cout << "\t\t\t\t\t��";
	color(15);
	cout << "������Ŀ�����\n";

	cout << "\n\t\t\t\t\tW A S D���������ƶ�\n\t\t\t\t\tR�������ƶ�,ESC���˳�" << endl;
}

/*
*
*
*�������λ��
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
*�ж��Ƿ�ʤ��
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
*��������ƶ�
*
*
*/
void playerMov(char(*map)[COL], int *x, int *y) {
	char CheckBut = but;
	switch (but = _getch()) {
		//�˳�
	case 'Q':
	case 'q':
	case 27: {
				 exit(1);
	}
		//����
	case 'R':
	case 'r': {
				  if (CheckBut == 0) {
					  cout << "\n֮ǰû�н����κ��ƶ�����,���ƶ�֮������" << endl;
				  }
				  //��һ�β���������W��
				  else if (CheckBut == 'w') {
					  //(1)�ϴ�����Ҫ������һ��λ���ǿյ�
					  if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) - 1][*y] != 2 && map[(*x) - 1][*y] != 5) {
						  map[*x][*y] = 0;
						  map[(*x) + 1][*y] = 4;
						  ++*x;
					  }
					  //(2)�ϴ�����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) - 1][*y] != 5 && map[(*x) - 1][*y] != 2) {
						  map[*x][*y] = 3;
						  map[(*x) + 1][*y] = 4;
						  ++*x;
					  }
					  //(3)�ϴ�����Ҫ�������ӵ�һ���յ�
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 2) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][(*y)] = 0;
						  map[(*x) + 1][(*y)] = 4;

					  }
					  //(4)�ϴ�����Ҫ�������ӵ�һ����Ŀ�ĵ�
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 5) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 4;
					  }
					  //(5)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��յ�
					  else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 2) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 0;
						  map[(*x) + 1][*y] = 4;

					  }
					  //(6)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
					  else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 0) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 4;

					  }
					  //(7)�ϴ�������Ŀ�ĵ��е��յ�
					  else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 4 && map[(*x) - 1][*y] != 5) {
						  map[(*x) + 1][*y] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)�ϴ�������Ŀ�ĵ��������ӵ��յ�
					  else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][*y] = 0;
						  map[(*x) + 1][*y] = 7;
					  }
					  //(9)�ϴ�������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
					  else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 7;

					  }
					  //(10)�ϴ�������Ŀ�ĵ��е��µ�Ŀ�ĵ�
					  else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 7 && map[(*x) - 1][*y] != 2 && map[(*x) - 1][*y] != 5) {
						  map[(*x) + 1][*y] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
					  else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 0;
						  map[(*x) + 1][*y] = 7;
					  }
					  //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
					  else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) - 1][*y] = 3;
						  map[(*x) + 1][*y] = 7;
					  }
				  }
				  //��һ�β���������S��
				  else if (CheckBut == 's') {
					  //(1)�ϴ�����Ҫ������һ��λ���ǿյ�
					  if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) + 1][*y] != 2 && map[(*x) + 1][*y] != 5) {
						  map[*x][*y] = 0;
						  map[(*x) - 1][*y] = 4;
						  --*x;
					  }
					  //(2)�ϴ�����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) + 1][*y] != 5 && map[(*x) + 1][*y] != 2) {
						  map[*x][*y] = 3;
						  map[(*x) - 1][*y] = 4;
						  --*x;
					  }
					  //(3)�ϴ�����Ҫ�������ӵ�һ���յ�
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 2) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][(*y)] = 0;
						  map[(*x) - 1][(*y)] = 4;

					  }
					  //(4)�ϴ�����Ҫ�������ӵ�һ����Ŀ�ĵ�
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4 && map[(*x) + 1][*y] == 5) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 4;
					  }
					  //(5)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��յ�
					  else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7 && map[(*x) + 1][*y] == 2) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 0;
						  map[(*x) - 1][*y] = 4;

					  }
					  //(6)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
					  else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 0) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 4;

					  }
					  //(7)�ϴ�������Ŀ�ĵ��е��յ�
					  else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 4 && map[(*x) + 1][*y] != 5) {
						  map[(*x) - 1][*y] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)�ϴ�������Ŀ�ĵ��������ӵ��յ�
					  else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][*y] = 0;
						  map[(*x) - 1][*y] = 7;
					  }
					  //(9)�ϴ�������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
					  else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 2;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 7;

					  }
					  //(10)�ϴ�������Ŀ�ĵ��е��µ�Ŀ�ĵ�
					  else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 7 && map[(*x) + 1][*y] != 2 && map[(*x) + 1][*y] != 5) {
						  map[(*x) - 1][*y] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
					  else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 0;
						  map[(*x) - 1][*y] = 7;
					  }
					  //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
					  else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 1][*y] == 3) {
						  map[*x][*y] = 5;
						  map[(*x) + 1][*y] = 3;
						  map[(*x) - 1][*y] = 7;
					  }

				  }
				  //��һ�β���������A��
				  else if (CheckBut == 'a') {
					  //(1)�ϴ�����Ҫ������һ��λ���ǿյ�
					  if (map[*x][*y] == 4 && map[*x][(*y) + 1] == 0 && map[*x][(*y) - 1] != 2 && map[*x][(*y) + 1] != 5 && map[*x][(*y) - 1] != 5) {
						  map[*x][*y] = 0;
						  map[*x][(*y) + 1] = 4;
					  }
					  //(2)�ϴ�����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
					  else if (map[(*x)][(*y) + 1] == 0 && map[*x][*y] == 7 && map[(*x)][(*y) - 1] != 5 && map[(*x)][(*y) - 1] != 2) {
						  map[*x][*y] = 3;
						  map[(*x)][(*y) + 1] = 4;

					  }
					  //(3)�ϴ�����Ҫ�������ӵ�һ���յ�
					  else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 2) {
						  map[*x][*y] = 2;
						  map[(*x)][(*y) - 1] = 0;
						  map[(*x)][(*y) + 1] = 4;

					  }
					  //(4)�ϴ�����Ҫ�������ӵ�һ����Ŀ�ĵ�
					  else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 5) {
						  map[*x][*y] = 2;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 4;
					  }
					  //(5)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��յ�
					  else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 2) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 0;
						  map[*x][(*y) + 1] = 4;

					  }
					  //(6)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
					  else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 0) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 4;

					  }
					  //(7)�ϴ�������Ŀ�ĵ��е��յ�
					  else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 4 && map[*x][(*y) - 1] != 5) {
						  map[*x][(*y) + 1] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)�ϴ�������Ŀ�ĵ��������ӵ��յ�
					  else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) - 1] = 0;
						  map[*x][(*y) + 1] = 7;
					  }
					  //(9)�ϴ�������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
					  else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 7;

					  }
					  //(10)�ϴ�������Ŀ�ĵ��е��µ�Ŀ�ĵ�
					  else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 7 && map[*x][(*y) - 1] != 2 && map[*x][(*y) - 1] != 5) {
						  map[*x][(*y) + 1] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
					  else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 0;
						  map[*x][(*y) + 1] = 7;
					  }
					  //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
					  else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) - 1] = 3;
						  map[*x][(*y) + 1] = 7;
					  }
				  }
				  //��һ�β���������D��
				  else if (CheckBut == 'd') {
					  //(1)�ϴ�����Ҫ������һ��λ���ǿյ�
					  if (map[*x][*y] == 4 && map[*x][(*y) - 1] == 0 && map[*x][(*y) + 1] != 2 && map[*x][(*y) - 1] != 5 && map[*x][(*y) + 1] != 5) {
						  map[*x][*y] = 0;
						  map[*x][(*y) - 1] = 4;
					  }
					  //(2)�ϴ�����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
					  else if (map[(*x)][(*y) - 1] == 0 && map[*x][*y] == 7 && map[(*x)][(*y) + 1] != 5 && map[(*x)][(*y) + 1] != 2) {
						  map[*x][*y] = 3;
						  map[(*x)][(*y) - 1] = 4;

					  }
					  //(3)�ϴ�����Ҫ�������ӵ�һ���յ�
					  else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 2) {
						  map[*x][*y] = 2;
						  map[(*x)][(*y) + 1] = 0;
						  map[(*x)][(*y) - 1] = 4;

					  }
					  //(4)�ϴ�����Ҫ�������ӵ�һ����Ŀ�ĵ�
					  else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4 && map[*x][(*y) + 1] == 5) {
						  map[*x][*y] = 2;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 4;
					  }
					  //(5)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��յ�
					  else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 7 && map[*x][(*y) + 1] == 2) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 0;
						  map[*x][(*y) - 1] = 4;

					  }
					  //(6)�ϴ�����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
					  else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 0) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 4;

					  }
					  //(7)�ϴ�������Ŀ�ĵ��е��յ�
					  else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 4 && map[*x][(*y) + 1] != 5) {
						  map[*x][(*y) - 1] = 7;
						  map[*x][*y] = 0;

					  }
					  //(8)�ϴ�������Ŀ�ĵ��������ӵ��յ�
					  else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) + 1] = 0;
						  map[*x][(*y) - 1] = 7;
					  }
					  //(9)�ϴ�������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
					  else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 2;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 7;

					  }
					  //(10)�ϴ�������Ŀ�ĵ��е��µ�Ŀ�ĵ�
					  else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 7 && map[*x][(*y) + 1] != 2 && map[*x][(*y) + 1] != 5) {
						  map[*x][(*y) - 1] = 7;
						  map[*x][*y] = 3;
					  }
					  //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
					  else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 0;
						  map[*x][(*y) - 1] = 7;
					  }
					  //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
					  else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 1] == 3) {
						  map[*x][*y] = 5;
						  map[*x][(*y) + 1] = 3;
						  map[*x][(*y) - 1] = 7;
					  }
				  }
				  break;
	}
		//�����ߣ��ڼ����ϰ���W��
	case 'W':
	case 'w':
	case 38: {
				 //(1)����Ҫ������һ��λ���ǿյ�
				 if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 4;
					 --*x;
				 }
				 //(2)����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
				 else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 7;
					 --*x;
				 }
				 //(3)����Ҫ�������ӵ�һ���յ�
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][(*y)] = 4;
					 map[(*x) - 2][(*y)] = 2;
					 --*x;
				 }
				 //(4)����Ҫ�������ӵ�һ����Ŀ�ĵ�
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 4;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
				 //(5)����Ҫ����Ŀ�ĵ��е����ӵ��յ�
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 2;
					 --*x;
				 }
				 //(6)����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
				 //(7)������Ŀ�ĵ��е��յ�
				 else if (map[(*x) - 1][*y] == 0 && map[*x][*y] == 7) {
					 map[(*x) - 1][*y] = 4;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(8)������Ŀ�ĵ��������ӵ��յ�
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 4;
					 map[(*x) - 2][*y] = 2;
					 --*x;
				 }
				 //(9)������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
				 else if (map[(*x) - 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 4;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
				 //(10)������Ŀ�ĵ��е��µ�Ŀ�ĵ�
				 else if (map[(*x) - 1][*y] == 3 && map[*x][*y] == 7) {
					 map[(*x) - 1][*y] = 7;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 2;
					 --*x;
				 }
				 //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
				 else if (map[(*x) - 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) - 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) - 1][*y] = 7;
					 map[(*x) - 2][*y] = 5;
					 --*x;
				 }
	}

		break;

		//�����ߣ��ڼ����ϰ���S��
	case 'S':
	case 's':
	case 40: {
				 //(1)����Ҫ������һ��λ���ǿյ�
				 if (map[(*x) + 1][(*y)] == 0 && map[*x][*y] == 4) {
					 map[*x][(*y)] = 0;
					 map[(*x) + 1][*y] = 4;
					 ++*x;
				 }
				 //(2)����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
				 else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 7;
					 ++*x;
				 }
				 //(3)����Ҫ�������ӵ�һ���յ�
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][(*y)] = 4;
					 map[(*x) + 2][(*y)] = 2;
					 ++*x;
				 }
				 //(4)����Ҫ�������ӵ�һ����Ŀ�ĵ�
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 4;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
				 //(5)����Ҫ����Ŀ�ĵ��е����ӵ��յ�
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 2;
					 ++*x;
				 }
				 //(6)����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 4 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 0;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
				 //(7)������Ŀ�ĵ��е��յ�
				 else if (map[(*x) + 1][*y] == 0 && map[*x][*y] == 7) {
					 map[(*x) + 1][*y] = 4;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(8)������Ŀ�ĵ��������ӵ��յ�
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 4;
					 map[(*x) + 2][*y] = 2;
					 ++*x;
				 }
				 //(9)������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
				 else if (map[(*x) + 1][*y] == 2 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 4;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
				 //(10)������Ŀ�ĵ��е��µ�Ŀ�ĵ�
				 else if (map[(*x) + 1][*y] == 3 && map[*x][*y] == 7) {
					 map[(*x) + 1][*y] = 7;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 0) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 2;
					 ++*x;
				 }
				 //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
				 else if (map[(*x) + 1][*y] == 5 && map[*x][*y] == 7 && map[(*x) + 2][*y] == 3) {
					 map[*x][*y] = 3;
					 map[(*x) + 1][*y] = 7;
					 map[(*x) + 2][*y] = 5;
					 ++*x;
				 }
	}

		break;
		//�����ߣ��ڼ����ϰ���A��
	case 'A':
	case 'a':
	case 37: {
				 //(1)����Ҫ������һ��λ���ǿյ�
				 if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 4) {
					 map[*x][(*y)] = 0;
					 map[*x][(*y) - 1] = 4;
					 --*y;
				 }
				 //(2)����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
				 else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 7;
					 --*y;
				 }
				 //(3)����Ҫ�������ӵ�һ���յ�
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 2;
					 --*y;
				 }
				 //(4)����Ҫ�������ӵ�һ����Ŀ�ĵ�
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 5;
					 --*y;
				 }
				 //(5)����Ҫ����Ŀ�ĵ��е����ӵ��յ�
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 2;
					 --*x;
				 }
				 //(6)����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 5;
					 --*x;
				 }
				 //(7)������Ŀ�ĵ��е��յ�
				 else if (map[*x][(*y) - 1] == 0 && map[*x][*y] == 7) {
					 map[*x][(*y) - 1] = 4;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(8)������Ŀ�ĵ��������ӵ��յ�
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 2;
					 --*x;
				 }
				 //(9)������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
				 else if (map[*x][(*y) - 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 4;
					 map[*x][(*y) - 2] = 5;
					 --*x;
				 }
				 //(10)������Ŀ�ĵ��е��µ�Ŀ�ĵ�
				 else if (map[*x][(*y) - 1] == 3 && map[*x][*y] == 7) {
					 map[*x][(*y) - 1] = 7;
					 map[*x][*y] = 3;
					 --*x;
				 }
				 //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 2;
					 --*x;
				 }
				 //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
				 else if (map[*x][(*y) - 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) - 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) - 1] = 7;
					 map[*x][(*y) - 2] = 5;
					 --*x;
				 }
	}

		break;
		//�����ߣ��ڼ����ϰ���D��
	case 'D':
	case 'd':
	case 39: {
				 //(1)����Ҫ������һ��λ���ǿյ�
				 if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 4) {
					 map[*x][(*y)] = 0;
					 map[*x][(*y) + 1] = 4;
					 ++*y;
				 }
				 //(2)����Ҫ������һ��λ���ǿ�Ŀ�ĵ�
				 else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 4) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 7;
					 ++*y;
				 }
				 //(3)����Ҫ�������ӵ�һ���յ�
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 2;
					 ++*y;
				 }
				 //(4)����Ҫ�������ӵ�һ����Ŀ�ĵ�
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 5;
					 ++*y;
				 }
				 //(5)����Ҫ����Ŀ�ĵ��е����ӵ��յ�
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 2;
					 ++*x;
				 }
				 //(6)����Ҫ����Ŀ�ĵ��е����ӵ��µ�Ŀ�ĵ���
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 4 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 0;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 5;
					 ++*x;
				 }
				 //(7)������Ŀ�ĵ��е��յ�
				 else if (map[*x][(*y) + 1] == 0 && map[*x][*y] == 7) {
					 map[*x][(*y) + 1] = 4;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(8)������Ŀ�ĵ��������ӵ��յ�
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 2;
					 ++*x;
				 }
				 //(9)������Ŀ�ĵ��������ӵ��µ�Ŀ�ĵ�
				 else if (map[*x][(*y) + 1] == 2 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 3) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 4;
					 map[*x][(*y) + 2] = 5;
					 ++*x;
				 }
				 //(10)������Ŀ�ĵ��е��µ�Ŀ�ĵ�
				 else if (map[*x][(*y) + 1] == 3 && map[*x][*y] == 7) {
					 map[*x][(*y) + 1] = 7;
					 map[*x][*y] = 3;
					 ++*x;
				 }
				 //(11)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ��յ�
				 else if (map[*x][(*y) + 1] == 5 && map[*x][*y] == 7 && map[*x][(*y) + 2] == 0) {
					 map[*x][*y] = 3;
					 map[*x][(*y) + 1] = 7;
					 map[*x][(*y) + 2] = 2;
					 ++*x;
				 }
				 //(12)������Ŀ�ĵ�������һ��Ŀ�ĵ��е����ӵ���Ŀ�ĵ�
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
*��Ϸ������
*
*/
void game() {
	int i = 0, x = 0, y = 0, step = 0;
	struct MAP *pmap = NULL;
	pmap = map1;
	mapInit(pmap->map, &(pmap->row), &(pmap->col));
	while (1) {
		lockPlayerPosition(pmap->map, &(pmap->row), &(pmap->col), &x, &y);
		cout << "\n\t\t\t\t\t��һ������" << step << "��" << endl;
		cout << but;
		playerMov(pmap->map, &x, &y);
		step++;
		system("cls");
		mapInit(pmap->map, &(pmap->row), &(pmap->col));
		if ((isWin(pmap->map, &(pmap->row), &pmap->col)) && i <= 5) {
			system("cls");
			color(5);
			cout << "\t\t\t\t\tţ��,�����������" << endl;
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
*�˵�
*
*
*/
void menu() {
	cout << "\t\t\t\t\t�� ��" << endl;
	cout << "\t\t\t\t\t1.��ʼ��Ϸ" << endl;
	cout << "\t\t\t\t\t2.�˳�" << endl;

}
void Display();
void Register()
{
	ofstream outFile;
	outFile.open("web1.txt", ios_base::out | ios_base::app);
	if (!outFile.is_open())
	{
		cout << "\t\t\t\t\t���ź�,���Ӳ��Ϸ�����";
		cout << "\t\t\t\t\t�������";
		cin.get();
		exit(0);
	}
	string name;
	string code;
	cout << "\t\t\t\t\t�������û���:";
	cin.get();
	getline(cin, name);
	outFile << name << endl;

	cout << "\t\t\t\t\t����������: ";
	getline(cin, code);
	outFile << code << endl;
	outFile << "=========" << endl;
	cout << "\t\t\t\t\tע��ɹ�";
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
		cout << "\t\t\t\t\t���ź�,���Ӳ��Ϸ�����";
		exit(0);
	}
	string name;
	string code;
	string temp;
	char ch;
	char str[20];
	cout << "\t\t\t\t\t�������û���:";
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
				cout << "\t\t\t\t\t�������½���룺";
				ch = _getch();
				while (ch != 13)
				{
					if (ch == 8 && i > 0)
					{
						i--;
						str[i] = '\0';
						system("cls");//���� �������*
						cout << "\t\t\t\t\t�������룺";
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
					cout << "\t\t\t\t\t����������ȷ" << endl;
					break;
				}
				else
				{
					cout << "\n\t\t\t\t\t�������!!";
					_getch();
				}
			}

		}
	}

}
void Display()
{
	cout << "\n\t\t\t\t\t1.ע��\n\t\t\t\t\t2.��¼\n\t\t\t\t\t3.�˳�\n\t\t\t\t\t������ѡ��:";
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
		cout << "\n\t\t\t\t\t��������ѡ��:";
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
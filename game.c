#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//菜单
void menu()
{
	printf("----------------------------\n");
	printf("-----------1.play-----------\n");
	printf("-----------0.exit-----------\n");
	printf("----------------------------\n");
}

void game()
{
	//创建棋盘
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//判断先手
	int temp = FirstHand();
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	int ret = 0;

	if (temp == 1)
	{
		while (1)
		{
			//玩家回合
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'C')
				break;

			//电脑回合
			printf("电脑回合\n");
			//进攻
			ret = Attack(board, ROW, COL);
			if (ret == 0)
			{
				//防御
				ret = Defend(board, ROW, COL);
				if (ret == 0)
				{
					ComputerMove(board, ROW, COL);
				}
			}
			Sleep(100);
			DisplayBoard(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
	}
	if (temp == 0)
	{
		while (1)
		{
			//电脑回合
			printf("电脑回合\n");
			//进攻
			ret = Attack(board, ROW, COL);
			if (ret == 0)
			{
				//防御
				ret = Defend(board, ROW, COL);
				if (ret == 0)
				{
					ComputerMove(board, ROW, COL);
				}
			}
			Sleep(100);
			DisplayBoard(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'C')
				break;

			//玩家回合
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
	}
	if (ret == '*')
		printf("你赢了\n\n");
	else if (ret == '#')
		printf("你输了\n\n");
	else
		printf("平局\n\n");
}

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf("+---");
			if (j == col - 1)
			{
				printf("+");
			}
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("| %c ", board[i][j]);
			if (j == col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i == row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("+---");
				if (j == col - 1)
				{
					printf("+");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}



//判断先手
int FirstHand()
{
	int ret = 0;
	printf("----------------------\n");
	printf("----  1.玩家先手  ----\n");
	printf("----  0.电脑先手  ----\n");
	printf("----------------------\n");
	while (1)
	{
		printf("请选择先手:>\n");
		scanf("%d", &ret);
		printf("\n");
		if (ret == 1)
			return 1;
		else if (ret == 0)
			return 0;
		else
			printf("选择错误，请重新选择\n");
	}
}


//玩家回合
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("你的回合，请输入棋子坐标:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("坐标被占用，请重新输入:>\n");
		}
		else
			printf("坐标非法，请重新输入:>\n");
	}
}


//电脑回合

// 进攻
int Attack(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == '#' && board[i][2] == ' ')
		{
			board[i][2] = '#';
			return 1;
		}
		if (board[i][0] == board[i][2] && board[i][0] == '#' && board[i][1] == ' ')
		{
			board[i][1] = '#';
			return 1;
		}
		if (board[i][1] == board[i][2] && board[i][1] == '#' && board[i][0] == ' ')
		{
			board[i][0] = '#';
			return 1;
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == '#' && board[2][i] == ' ')
		{
			board[2][i] = '#';
			return 1;
		}
		if (board[0][i] == board[2][i] && board[0][i] == '#' && board[1][i] == ' ')
		{
			board[1][i] = '#';
			return 1;
		}
		if (board[1][i] == board[2][i] && board[1][i] == '#' && board[0][i] == ' ')
		{
			board[0][i] = '#';
			return 1;
		}
	}
	//判断正对角线
	if (board[0][0] == board[1][1] && board[0][0] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		return 1;
	}
	if (board[0][0] == board[2][2] && board[0][0] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return 1;
	}
	if (board[2][2] == board[1][1] && board[1][1] == '#' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		return 1;
	}
	//判断反对角线
	if (board[2][0] == board[1][1] && board[2][0] == '#' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		return 1;
	}
	if (board[2][0] == board[0][2] && board[2][0] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return 1;
	}
	if (board[0][2] == board[1][1] && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		return 1;
	}
	return 0;
}
// 防御
int Defend(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == '*' && board[i][2] == ' ')
		{
			board[i][2] = '#';
			return 1;
		}
		if (board[i][0] == board[i][2] && board[i][0] == '*' && board[i][1] == ' ')
		{
			board[i][1] = '#';
			return 1;
		}
		if (board[i][1] == board[i][2] && board[i][1] == '*' && board[i][0] == ' ')
		{
			board[i][0] = '#';
			return 1;
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == '*' && board[2][i] == ' ')
		{
			board[2][i] = '#';
			return 1;
		}
		if (board[0][i] == board[2][i] && board[0][i] == '*' && board[1][i] == ' ')
		{
			board[1][i] = '#';
			return 1;
		}
		if (board[1][i] == board[2][i] && board[1][i] == '*' && board[0][i] == ' ')
		{
			board[0][i] = '#';
			return 1;
		}
	}
	//判断正对角线
	if (board[0][0] == board[1][1] && board[0][0] == '*' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		return 1;
	}
	if (board[0][0] == board[2][2] && board[0][0] == '*' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return 1;
	}
	if (board[2][2] == board[1][1] && board[1][1] == '*' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		return 1;
	}
	//判断反对角线
	if (board[2][0] == board[1][1] && board[2][0] == '*' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		return 1;
	}
	if (board[2][0] == board[0][2] && board[2][0] == '*' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return 1;
	}
	if (board[0][2] == board[1][1] && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		return 1;
	}
	return 0;
}
//随机
void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//判断坐标合法性
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断输赢
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//判断三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//判断正对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	//判断反对角线
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	else
		return'C';
}

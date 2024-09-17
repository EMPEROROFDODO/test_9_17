#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


//�˵�
void menu()
{
	printf("----------------------------\n");
	printf("-----------1.play-----------\n");
	printf("-----------0.exit-----------\n");
	printf("----------------------------\n");
}

void game()
{
	//��������
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//�ж�����
	int temp = FirstHand();
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	int ret = 0;

	if (temp == 1)
	{
		while (1)
		{
			//��һغ�
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'C')
				break;

			//���Իغ�
			printf("���Իغ�\n");
			//����
			ret = Attack(board, ROW, COL);
			if (ret == 0)
			{
				//����
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
			//���Իغ�
			printf("���Իغ�\n");
			//����
			ret = Attack(board, ROW, COL);
			if (ret == 0)
			{
				//����
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

			//��һغ�
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = Iswin(board, ROW, COL);
			if (ret != 'C')
				break;
		}
	}
	if (ret == '*')
		printf("��Ӯ��\n\n");
	else if (ret == '#')
		printf("������\n\n");
	else
		printf("ƽ��\n\n");
}

//��ʼ������
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


//��ӡ����
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



//�ж�����
int FirstHand()
{
	int ret = 0;
	printf("----------------------\n");
	printf("----  1.�������  ----\n");
	printf("----  0.��������  ----\n");
	printf("----------------------\n");
	while (1)
	{
		printf("��ѡ������:>\n");
		scanf("%d", &ret);
		printf("\n");
		if (ret == 1)
			return 1;
		else if (ret == 0)
			return 0;
		else
			printf("ѡ�����������ѡ��\n");
	}
}


//��һغ�
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("��Ļغϣ���������������:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("���걻ռ�ã�����������:>\n");
		}
		else
			printf("����Ƿ�������������:>\n");
	}
}


//���Իغ�

// ����
int Attack(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
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
	//�ж���
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
	//�ж����Խ���
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
	//�жϷ��Խ���
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
// ����
int Defend(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
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
	//�ж���
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
	//�ж����Խ���
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
	//�жϷ��Խ���
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
//���
void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//�ж�����Ϸ���
		if (x >= 0 && x < row && y >= 0 && y < col)
		{
			//�ж������Ƿ�ռ��
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
//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;

	//�ж�����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�ж�����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//�ж����Խ���
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	//�жϷ��Խ���
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ')
	{
		return board[1][1];
	}

	//�ж��Ƿ�ƽ��
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	else
		return'C';
}

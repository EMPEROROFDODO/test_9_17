#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


int main()
{

	int  input = 0;

	//���������
	srand((unsigned int)time(NULL));

	do
	{
		//�˵�
		menu();
		printf("���������ѡ��:>\n");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}
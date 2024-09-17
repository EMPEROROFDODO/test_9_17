#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


int main()
{

	int  input = 0;

	//发现随机数
	srand((unsigned int)time(NULL));

	do
	{
		//菜单
		menu();
		printf("请输入你的选择:>\n");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}
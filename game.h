#pragma once
//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//�˵�
void menu();

//��������
#define ROW 3
#define COL 3


//���庯��
void game();
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);
//�ж�����
int FirstHand();
//��һغ�
void PlayerMove(char board[ROW][COL], int row, int col);

//���Իغ�
//����
int Attack(char board[ROW][COL], int row, int col);
//����
int Defend(char board[ROW][COL], int row, int col);
//���
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char Iswin(char board[ROW][COL], int row, int col);
#include <iostream>
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
int main()
{
	char a[4] = { '|','/','-','\\' };	//�洢��ص��ַ�
	int i, j, x = 2, y = 1;	//��������
	std::cout << "*******���ؽ�����ģ��*******" << std::endl;	//�������
	putchar('\n');	//Ϊ�������Ľ�����������λ
	std::cout << "******����***+***��ע******" << std::endl;	//����׿�
	gotoxy(x, y);	//���ú������ƹ��λ��
	for (i = 0; i <= 100; i++) {	//�������ܽ��ȿ���
		std::cout << " [";	//��������߿�
		for (j = 0; j < i / 10; j++) {	//���Ƽ��ؽ��ȵ���ʾ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);	//���ü�������ʽ����
			std::cout << "_";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//�ָ�ԭ����
		for (j = 0; j < (10 - (i / 10)); j++) { printf("%c", '.'); }	//δ���ؽ�����ʾ
		std::cout << "] ";	//�������ұ߿�
		std::cout << a[i % 4] << "���ڼ�����";	//��ʾ�ͳ����������ʾ�͡����ڼ��ء�������ʾ
		for (j = 0; j < (i % 4); j++) { std::cout << "."; }	//ʵ�ֶ�̬��ʾ
		for (j = 0; j < (4 - i % 4); j++) { printf("%c", ' '); }
		Sleep(100);	//���Ƴ��������ٶ�
		putchar('\r');	//�س�
	}
	std::cout << "( �b- �b)�ĥ�BiliBili�ɱ�~\n" << std::endl;	//������
}
void gotoxy(int x, int y)	//�Զ��� gotoxy ����
{
	COORD c;
	c.X = x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
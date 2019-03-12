// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	char stop = ' ' ;
	char stop2 = ' ';
	char text[300];
	ifstream in("story.txt");
	while (stop2!='%')
	{
		stop = ' ';
		while (stop != '#')
		{
			in.getline(text, 300, '^');
			in >> stop >> stop2;
			cout << text;
			
		}
		cout << endl;
		Sleep(6000);
	}
	cout << endl;
	Knight *knight = new Knight;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choose, kazino, ch = 1, choose2=1;
	int coins = knight->get_coins();
	while (choose2==1)
	{
		cout << "��� ������������ �����?" << endl << "1. ������ � ������" << endl << "2. ������� �����" << endl << "3. ��������" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "�� ��� ������ �����?" << endl << "1. �������" << endl << "2. �������� " << endl << "3. �����" << endl;
			cin >> kazino;
			if (kazino == 1)
			{
				while (ch == 1)
				{
					if (coins > 0)
					{
						coins = knight->game();
						cout << "���������� ������?" << endl << "1. ��" << endl << "2. ���" << endl;
						cin >> ch;
					}
					else
					{
						cout << "�� �� ������ ������ ������, � ��� ��� �����" << endl;
						ch = 0;
					};
				};
			};
			if(kazino==2) knight->blackjack();
			if(kazino==3) knight->dice();
			break;
		case 2: knight->theft(); break;
		case 3:
			ch = 1;
			choose = 0;
			while (ch == 1)
			{
				knight->work();
				choose += 1;
				if (choose > 5)
				{
					cout << "�� ��� ������������, ��� ����������, ��� ����� ��������� ������ ��� ���� �������" << endl;
					cout << "���� ��������" << endl;
					exit(0);
				}
				else
				{
					cout << "���������� ��������?" << endl << "1. ��" << endl << "2. ���" << endl;
					cin >> ch;
					cout << endl;
				}
			};
			break;
		};
		ch = 1;
		cout << "���������� ������������ ������?" << endl << "1. ��" << endl << "2. ���" << endl;
		cin >> choose2;
		coins = knight->get_coins();
		if (choose2 != 1)
		{
			if (coins < 250)
			{
				cout << "� ��� " << coins << " �.�, � ���� ���� 250 �.�" <<endl;
				choose2 = 1;
			}
			else break;
		}
	}
	stop2 = ' ';
	while (stop2 != '%')
	{
		stop = ' ';
		while (stop != '#')
		{
			in.getline(text, 300, '^');
			in >> stop >> stop2;
			cout << text;
		}
		cout << endl;
		Sleep(4000);
	}
	cout << "������� � ����? ���������� �� �� ������"  << endl;
	Sleep(2000);
	Games g;
	g.games();
	stop2 = ' ';
	while (stop2 != '%')
	{
		stop = ' ';
		while (stop != '#')
		{
			in.getline(text, 300, '^');
			in >> stop >> stop2;
			cout << text;
		}
		cout << endl;
		Sleep(1000);
	}
	Sleep(3000);
	cout << "����, ����� � �������� ���������?" << endl << "1. ��" << endl << "2. ���" << endl;
	cin >> choose;
	if (choose == 1)
	{
		Dragon d;
		d.fight(*knight);
	}
	else
	{
		cout << "��������? �� ������ ����� ����, � ������ �������� �������" << endl;
		cout << "���� ��� �����" << endl;
		cout << "���� ��������" << endl;
	}
	/*spirt l[2];
	l[0].mosh();
	l[1].mosh();*/
	in.close();
	return 0;
}
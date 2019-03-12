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
		cout << "Как зарабатывать будем?" << endl << "1. играть в разное" << endl << "2. украсть денег" << endl << "3. работать" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Во что играть будем?" << endl << "1. рулетка" << endl << "2. блэкджэк " << endl << "3. кости" << endl;
			cin >> kazino;
			if (kazino == 1)
			{
				while (ch == 1)
				{
					if (coins > 0)
					{
						coins = knight->game();
						cout << "Продолжить играть?" << endl << "1. Да" << endl << "2. Нет" << endl;
						cin >> ch;
					}
					else
					{
						cout << "Вы не можете больше играть, у вас нет денег" << endl;
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
					cout << "Вы так заработались, что пропустили, как более удачливый рыцарь уже убил дракона" << endl;
					cout << "Игра окончена" << endl;
					exit(0);
				}
				else
				{
					cout << "Продолжить работать?" << endl << "1. Да" << endl << "2. Нет" << endl;
					cin >> ch;
					cout << endl;
				}
			};
			break;
		};
		ch = 1;
		cout << "Продолжить зарабатывать дальше?" << endl << "1. Да" << endl << "2. Нет" << endl;
		cin >> choose2;
		coins = knight->get_coins();
		if (choose2 != 1)
		{
			if (coins < 250)
			{
				cout << "У вас " << coins << " у.е, а надо хоть 250 у.е" <<endl;
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
	cout << "Сыграем в игру? Отказаться вы не можете"  << endl;
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
	cout << "Итак, будем с драконом сражаться?" << endl << "1. Да" << endl << "2. Нет" << endl;
	cin >> choose;
	if (choose == 1)
	{
		Dragon d;
		d.fight(*knight);
	}
	else
	{
		cout << "Серьезно? Вы прошли такой путь, а теперь трусливо сбежали" << endl;
		cout << "Тоже мне герой" << endl;
		cout << "Игра окончена" << endl;
	}
	/*spirt l[2];
	l[0].mosh();
	l[1].mosh();*/
	in.close();
	return 0;
}
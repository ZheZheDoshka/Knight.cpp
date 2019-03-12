#include "stdafx.h"
#include "Header.h"


void Money::winner(int ch)
{
	cout << "�� ������" << endl;
}
void Money::looser(int ch)
{
	cout << "�� ������" << endl;
}
int Knight::game()
{
	{
		int col;
		int choose2;
		int ch;
		int l;
		double colo;
		srand(time(0));
		int ran;
		cout << "� ��� " << coin << "�.�" << endl;
		cout << "�� ��� ������ �������?" << endl << "1. ����" << endl << "2. ���/�����" << endl << "3. ����" << endl << "4. �����" << endl;
		cin >> choose;
		col = rand() % 950 + 50;
		switch (choose)
		{
		case 1:
			ch = stavka();
			l = 36 - lucky / 5;
			ran = rand() % l;
			cout << ran << endl;
			if (ran == 0)
			{
				winner(ch * 20);
				lucky += lucky / 5;
			}
			else looser(ch);
			break;
		case 2:
			cout << "��� ���������:" << endl << "1. ���" << endl << "2. �����" << endl;
			cin >> choose2;
			ch = stavka();
			if (lucky<55) col = col + 3.2*lucky;
			else col = col + 2 * lucky;
			colo = col / 1000.0;
			if (colo > 0.5)
			{
				winner(ch);
				lucky += lucky / 10;
			}
			else looser(ch);
			break;
		case 3: cout << "��� ���������:" << endl << "1. ������" << endl << "2. �������" << endl;
			cin >> choose2;
			ch = stavka();
			col = col + 2.5*lucky;
			colo = col / 1000.0;
			if (colo > 0.5)
			{
				winner(ch);
				lucky += lucky / 10;
			}
			else looser(ch);
			break;
		case 4: cout << "������� �����" << endl;
			cin >> choose2;
			ch = stavka();
			if (choose2 < 15)
			{
				l = lucky / 5 + 1;
				ran = rand() % l;
				cout << ran << endl;
			}
			if (choose2>20)
			{
				l = lucky / 5;
				ran = rand() % 36 + l;
				cout << ran << endl;
			}
			if ((choose2 <= 20) && (choose2 >= 15))
			{
				l = lucky / 5;
				int c2 = l / 2 + 3;
				int c = 35 - l / 2 - c2;
				ran = rand() % c + c2;
				cout << ran << endl;
			}
			if (ran == choose2)
			{
				winner(ch * 20);
				lucky += lucky / 5;
			}
			else looser(ch);
			break;
		};
		return coin;
	};
}
void Knight::theft()
{
	srand(time(0));
	int sum;
	sum = rand() % 1000 + 1;
	//cout << sum << endl;
	sum += 2 * deftness + iq + charisma;
	double summa;
	summa = sum / 1000.0;
	//cout << summa << endl;
	if (summa > 0.5)
	{
		int s = rand() % 200 + 20;
		s = s*lucky;
		coin += s;
		cout << "�� ������: " << s << " �.�" << endl << "�������: " << coin << " �.�" << endl;
		deftness += 1;
	}
	else
	{
		cout << "��� �������" << endl << "��� ������ �����?" << endl;
		cout << "1. �������" << endl << "2. ��������� ���������" << endl;
		cin >> choose;
		if (choose == 1)
		{
			sum = rand() % 1000 + 1;
			cout << sum << endl;
			sum += deftness + lucky + strength;
			summa = sum / 1000;
			//cout << summa << endl;
			if (summa > 0.5) 
			{ 
				cout << "�� ��������" << endl; 
				strength += strength / 10;
				hp += hp / 10;
			}
			else
			{
				cout << "�� ���������" << endl;
				strength -= 1;
				int h = rand() % 15 + 1;
				hp = hp - h;
				cout << "HP: " << hp << endl;
				if (hp <= 0)
				{
					cout << "�� ������" << endl;
					exit(0);
				}
			}
		}
		else
		{
			sum = rand() % 1000 + 1;
			sum += 2 * lucky + iq + charisma;
			double summa;
			summa = sum / 1000.0;
			if (summa > 0.5) cout << "��� ���������" << endl;
			else
			{
				cout << "��� ������" << endl;
				strength -= 1;
				int h = rand() % 15 + 1;
				hp = hp - h;
				cout << "HP: " << hp << endl;
				if (hp <= 0)
				{
					cout << "�� ������" << endl;
					exit(0);
				}
			}
		}
	};
};
void Knight::work()
{
	int r = rand() % 20 + 40;
	r = r + iq / 10;
	coin += r;
	strength += strength / 10;
	hp += hp / 10;
	cout << "������ � ��� " << coin << " �.�" << endl;
}
void Knight::winner(int ch)
{
	cout << "�� ��������" << endl;
	coin += ch;
	cout << "������ � ��� " << coin << " �.�" << endl;
}
void Knight::looser(int ch)
{
	cout << "�� ���������" << endl;
	coin -= ch;
	cout << "� ��� �������� " << coin << " �.�" << endl;
}
int Knight::stavka()
{
	int ch;
	cout << "���� ������?" << endl;
	cin >> ch;
	while (ch > coin)
	{
		cout << "�� �� ������ ��������� ����� ������, ��� � ��� ����" << endl;
		cout << "������� � ��� " << coin << " �.�" << endl;
		cout << "���� ������?" << endl;
		cin >> ch;
	}
	return ch;
}
void Dragon::fight(Knight &k)
{
	int x;
	int hp = k.get_hp();
	srand(time(0));
	while ((hp>0) && (HP>0))
	{
		int c2 = rand() % 3 + 1;
		int c = rand() % 20 + 10;
		HP = HP - k.get_ad() - (k.get_str() + k.get_deft()) / c2 - k.get_luck() / c + Armour;
		x = rand() % 2 + 1;
		if (x == 1) hp = hp - AD + k.get_arm() + k.get_luck() / c;
		//cout << x << endl;
		//cout << HP << endl;
		//cout << hp << endl << endl;
	}
	if (HP <= 0) cout << "�� ��������" << endl;
	else cout << "�� ���������" << endl;
}
void Guard::fight()
{
	Knight k;
	int x;
	int hp = k.get_hp();
	srand(time(0));
	while ((hp>0) && (HP>0))
	{
		int c2 = rand() % 3 + 1;
		int c = rand() % 20 + 10;
		HP = HP - k.get_ad() - (k.get_str() + k.get_deft()) / c2 - k.get_luck() / c + Armour;
		x = rand() % 2 + 1;
		if (x == 1) hp = hp - AD + k.get_arm() + k.get_luck() / c;
	}
	if (HP <= 0) cout << "�� �������� � ���������" << endl;
	else
	{
		cout << "�� ��������� ���� ��������� � ������" << endl;
		cout << "���� ��������" << endl;
		exit(0);
	}
}
void Games::games()
{
	Guard g;
	string answer;
	cout << "�� ����� 70 ������ ������. �� ������ 10 ������ ����� ��������� 10 ������." << endl << "������� ������ �����������, ����� ��������� 50 ������?" << endl;
	cin >> answer;
	if (answer == "20") cout << "OK" << endl;
	else
	{
		cout << "HE OK" << endl;
		cout << "�����: 20" << endl;
		g.fight();
	}
	cout << "����� ����� ���������� � ���� ���� � � ������������� ����� ������� �?" << endl;
	cin >> answer;
	if (answer == "�������������") cout << "OK" << endl;
	else 
	{
		cout << "HE OK" << endl;
		cout << "�����: �������������" << endl;
		g.fight();
	}
	cout << "��� ����� �� ����� �� ������� �����, � ������� �� ����, � ������� �� ����?" << endl;
	cin >> answer;
	if (answer == "�������") cout << "OK" << endl;
	else 
	{
		cout << "HE OK" << endl;
		cout << "�����: �������" << endl;
		g.fight();
	}
	cout << "�� �����, � ��������, �� ����, � �����. �� �����, �..." << endl;
	cin >> answer;
	if (answer == "����������") cout << "OK" << endl;
	else 
	{
		cout << "HE OK" << endl;
		cout << "�����: ����������" << endl;
		g.fight();
	}
	cout << "� ��� ���� �������. �� ����� �� ���������� ���� ������. " << endl << "������� ��� ���������� 19,617 ������. ������ ����� ���� ��������?" << endl;
	cout << "1. �����-����������" << endl << "2. �����" << endl << "3. �����" << endl << "4. ������" << endl << "5. �����" << endl;
	cin >> answer;
	if (answer == "4") cout << "OK" << endl;
	else
	{
		cout << "HE OK" << endl;
		cout << "�����: ������" << endl;
		g.fight();
	}
}
void Knight::blackjack()
{
	int stake, a, b, q = 0, i = 0, u = 0, l = 0;
	char c, d;
	cout << "���� ������: ";
	cin >> stake;
	cout << endl;
	if (stake > coin) {
		cout << "� ��� ��� ����� ���� �����. �������." << endl;
	}
	else {
		coin = coin - stake;
		while (q == 0) {
			a = rand() % 13 + 2;
			b = rand() % 13 + 2;
			if (a < 10)
			{
				c = a + '0';
			}
			else {
				if (a = 11) { c = 'J'; }
				if (a = 12) { c = 'Q'; }
				if (a = 13) { c = 'K'; }
				if (a = 14) { c = 'A'; }
			}
			if (b < 10)
			{
				d = b + '0';
			}
			else {
				if (b = 11) { d = 'J'; }
				if (b = 12) { d = 'Q'; }
				if (b = 13) { d = 'K'; }
				if (b = 14) { d = 'A'; }
			}
			i = i + a;
			u = u + b;

			cout << "  ��       �� ��" << endl;
			cout << " _____     _____ " << endl;
			cout << "|" << c << "    |   |" << d << "    |" << endl;
			cout << "|  ^  |   |  ^  |" << endl;
			cout << "|     |   |     |" << endl;
			cout << "|  ^  |   |  ^  |" << endl;
			cout << "|____B|   |____B|" << endl;
			if (i > 21 || u > 21) { q = 1; }
			else {
				cout << "1 - ���������, 0 - ����� �����" << endl;
				cin >> q;
			}
		}
		if (i > 21) {
			cout << "�������� ��� ��������. " << endl; looser(l);
		}
		else {
			u = u + rand() % (21 - u) + 2;
			cout << "��������� ���� ������..." << endl;
			if (u >= 22)
			{
				winner(stake*3);
			}
			else {
				if (i > u) {
					winner(stake * 3);
				}
				else {
					looser(l);
				}
			}

		}

	}

}

void Knight::dice()
{
	int stake, a, b, c, d, l = 0;
	cout << "���� ������: ";
	cin >> stake;
	cout << endl;
	if (stake > coin) {
		cout << "��������, �� �� ��������� �� ��?" << endl;
	}
	else {
		coin = coin - stake;
		a = rand() % 6 + 1;
		b = rand() % 6 + 1;
		c = rand() % 6 + 1;
		d = rand() % 6 + 1;
		cout << "���� �����" << endl;
		cout << " _______.       _______." << endl;
		cout << "|       |\\     |       |\\   " << endl;
		cout << "|   " << a << "   | \\|   |   " << b << "   | \\" << endl;
		cout << "|       |  |   |       |  |   " << endl;
		cout << "|_______|  |   |_______|  |   " << endl;
		cout << " \\       \\ |    \\       \\ |   " << endl;
		cout << "  \\____ __\\|     \\____ __\\|   " << endl;
		cout << "�� ���� �����" << endl;
		cout << " _______.       _______." << endl;
		cout << "|       |\\     |       |\\   " << endl;
		cout << "|   " << c << "   | \\|   |   " << d << "   | \\" << endl;
		cout << "|       |  |   |       |  |   " << endl;
		cout << "|_______|  |   |_______|  |   " << endl;
		cout << " \\       \\ |    \\       \\ |   " << endl;
		cout << "  \\____ __\\|     \\____ __\\|   " << endl;
		if (a + b > c + d)
		{
			cout << "����������, �� ���� �������� ������." << endl; coin = coin + stake * 2;
			winner(l);
		}
		else { cout << "�� ���������." << endl; }
		if (a + b == c + d) {
			cout << "�� � ���������" << endl; coin = coin + stake;
			looser(l);
		}
	}
}
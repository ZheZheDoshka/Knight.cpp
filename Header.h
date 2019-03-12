#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <fstream>
#include <windows.h>
#include "locale.h"
using namespace std;


class Money
{
public:
	virtual void winner(int ch);
	virtual void looser(int ch);
};

class Knight : public Money
{
public:
	Knight()
	{
		lucky = 40;
		//cheat = 100;
		strength = 40;
		iq = 40;
		deftness = 40;
		hp = 100;
		ad = 20;
		charisma = 50;
		coin = 100;
		armour = 10;
	};
	/*Knight(string n_n)
	{
	name = n_n;
	lucky = 40;
	cheat = 100;
	strength = 40;
	iq = 40;
	deftness = 40;
	hp = 100;
	ad = 20;
	charisma = 50;
	coin = 100;
	armour = 10;
	};*/
	int get_arm(){ return armour; };
	int get_ad(){ return ad; };
	int get_str(){ return strength; };
	int get_deft(){ return deftness; };
	int get_hp(){ return hp; };
	int get_luck(){ return lucky; };
	int get_coins(){ return coin; };
	void winner(int ch);
	void looser(int ch);
	int stavka();
	int game();
	void theft();
	void work();
	void dice();
	void blackjack();
private:
	//string name;
	int lucky;
	int strength;
	int iq;
	int deftness;
	//int cheat;
	int hp;
	int ad;
	int coin;
	int charisma;
	int choose;
	int armour;
};

class Dragon
{
public:
	Dragon()
	{
		HP = 1000;
		AD = 30;
		Armour = 30;
	};
	virtual void fight(Knight &k);
protected:
	int HP;
	int AD;
	int Armour;
};

class Guard : public Dragon
{
public:
	Guard()
	{
		HP = 100;
		AD = 15;
		Armour = 5;
	};
	void fight();
	int get_HP(){ return HP; }
};

class Games
{
public:
	void games();
};






/*class kopiruet {
	publick:
		int rozmer;
	char * slovo;
	kopiruet()
	{
		rozmer = 20;
		slovo=new slovo[rozmer];
	};
	kopiruet(int a)
	{
	cin>>rozmer;
	slovo = new slovo[rozmer];
	};
	kopiruet(const kopiruet & kopiruem)
	{
		size = kopiruem.size;
		slovo = new double[rozmer];
		for (int i = 0; i < rozmer; i++) {
			slovo[i] = kopiruem.slovo[i];
		}

	};
};*/
#pragma once
#include <iostream>
#include <string.h>

using namespace std;

const int M_MAX_ACHIEVEMENTS = 30;
int m_chosenChar;
int m_numAchievements = 0;

class Character {
public:
	void move() { cout << "I-a move my legs" << endl; }
	virtual void healthShow() { cout << "Health unknown" << endl; }
	virtual void xpShow() { cout << "XP unknown" << endl; }
};

class Plumber : public Character {
public:
	void receiveDamage();
	void healthShow();
	void xpShow();
	void addName(string t_name);
	string showName();
	void playerChoice();
	void melee();
	void defense();
	void abilities();

private:
	string m_name = "";
	int m_health = 10;
	int m_xp = 4;
};

	

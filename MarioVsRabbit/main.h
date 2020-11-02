#pragma once
#include <iostream>
#include <string.h>

using namespace std;

const int M_MAX_ACHIEVEMENTS = 30;
const int M_MAX_ENEMY = 10;
int m_chosenChar;
int m_numAchievements = 0;
int m_damageGiven;
int m_currentEnemy = 0;
bool m_enemyAlive[M_MAX_ENEMY]{ true,true,true,true,true,true,true,true,true,true };


string m_meleeAttack[7]{ " jumps up and bonks Rabbit with their hell."," whacks Rabbit in the chin, Rabbid sees a pretty shape in the clouds.",
					   " whacks Rabbit in the head with their wrench, an ugly bump forms."," lands backside first on the ground, a mini earthquake knocks Rabbid off their feet.",
					   " uses their cape to shoo Rabbit away, Rabbit gets mildly hurt."," jumps on Rabbit's back and cuts hole around Rabbit, Rabbit falls down and bounces back up.",
					   " pretends to take Rabbit's nose, Rabbit hurts itself in its confusion."};

string m_abilityAttack[5]{ " throws carrots at the Rabbit's feet in desperation."," uses a bow and shoots carrots into the Rabbit's mouth. Rabbit rubs their stomach.",
						   " baits Rabbit into walking beside a carrot patch, Rabbit can't resist the temptation. "," leads Rabbit into a carrot filled trap.",
						   " bakes a carrot cake so delicious, Rabbit can't resist and eats it all."};

string m_defenseAttack[3]{ "'s cape wraps around him, all melee attacks will be blocked once. Rabbit's next attack will be parried with half the damage.",
						   " manifested a Super Star, all ability attacks will be blocked once. Rabbit's next ability attack will be parried with part of the damage",
						   " uses Shroom Soup. Health has been restored." };

string m_abilityRabbid[5]{ "Rabbit uses gun! Plungers shoot out and hit you in the stomach.","Rabbit has stolen your turn! You also got a smack on the wrist. Ouch.",
						   "Rabbit's are unfortunately not known for their singing abilities. You witnessed this firsthand. Your ears are bleeding now.",
						   "Rabbit somehow found an energy drink! He grows big and blue. Rabbit has successfully used you as a chair!",
						   "Rabbits love cosplay. A rabbit shaped Princess Plum has appeared where the rabbit once stood. You facepalm." };
class Character {
public:
	void move() { cout << "I-a move my legs" << endl; }
	virtual int healthShow() { cout << "Health unknown" << endl; return 0; }
	virtual void melee() { cout << "I can swing my sword"; }
	virtual void defense() { cout << "Block out the haters"; }
	virtual void abilities() { cout << "I use my brain"; }
	virtual void turn() { cout << "It's MY turn on the XBOX"; }
	void xpShow() { cout << "XP unknown" << endl; }
};

class Plumber : public Character {
public:
	void receiveDamage();
	int healthShow();
	void xpShow();
	void addName(string t_name);
	string showName();
	void playerChoice();
	void melee();
	void defense();
	void abilities();
	void turn();

private:
	string m_name = "";
	int m_health = 50;
	int m_xp = 0;
	const int M_MAX_MELEE = 11;
	const int M_MAX_ABILITY = 20;
	const int M_MIN_ABILITY = 10;
};

class Rabbid : public Character {
public:
	void receiveDamage();
	void generateHealth();
	int healthShow() { return m_health; }
	void rabbidChoice();
	void melee();
	void defense();
	void abilities();
	void turn();

private:
	int m_health;
};

Plumber player;
Rabbid rabbids[10];
	

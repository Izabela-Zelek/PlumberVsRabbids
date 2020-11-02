#pragma once
#include <iostream>
#include <string.h>

using namespace std;

const int M_MAX_ACHIEVEMENTS = 30;
const int M_MAX_ENEMY = 10;
int m_chosenChar;
int m_numAchievements = 0;
int m_damageToRabbit;
int m_damageReceived;

int m_capeAmount = 1;
bool m_capeUsed = false;

int m_starAmount = 0;
bool m_starUsed = false;

int m_soupAmount = 0;

int modeRabbit = -1; 

static int m_currentEnemy = 0;
bool m_enemyAlive[M_MAX_ENEMY]{ true,true,true,true,true,true,true,true,true,true };


string m_meleeAttack[7]{ " jumps on Rabbit. Rabbit didn't enjoy that."," whacks Rabbit in the chin, Rabbid sees a pretty shape in the clouds.",
					   " whacks Rabbit in the head with their wrench, an ugly bump forms."," lands backside first on the ground, a mini earthquake knocks Rabbid off their feet.",
					   " uses their cape to shoo Rabbit away, Rabbit gets mildly hurt."," jumps on Rabbit's back and cuts hole around Rabbit, Rabbit falls down and bounces back up.",
					   " pretends to take Rabbit's nose, Rabbit hurts itself in its confusion."};

string m_abilityAttack[5]{ " throws carrots at the Rabbit's feet in desperation."," uses a bow and shoots carrots into the Rabbit's mouth. Rabbit rubs their stomach.",
						   " baits Rabbit into walking beside a carrot patch, Rabbit can't resist the temptation. "," leads Rabbit into a carrot filled trap.",
						   " bakes a carrot cake so delicious, Rabbit can't resist and eats it all."};

string m_defenseAttack[3]{ "'s cape wraps around him, all melee attacks will be blocked once. Rabbit's next attack will be parried with half the damage.",
						   " manifested a Super Star, all ability attacks will be blocked once. Rabbit's next ability attack will be parried with part of the damage",
						   " uses Shroom Soup. Health has been restored." };

string m_meleeRabbid[7]{ "Rabbit whacks you with a toilet plunger...that can't be sanitary.","It's a Rabbit! It's a shark! It's Rabbit in a shark costume. You have been bitten.",
						 "You have gone blind! Not really, Rabbit just stuck his plunger to your face. You suffer from mild bruising.","Remember where we parked... what't this? A parking ticket? Officer Rabbit smacks you with his police baton.",
						 "You stare intently as Rabbit takes a burger patty and burns it on a charcoal grill. As a proud Italian, you take physical damage.",
						 "Rabbit invited his friends!...wait why are they all piling together... RUN IT'S A BUNNY BOULDER", "Rabbit points up. You slowly turn your head and see...A watermelon? It hits your head, ouch that'll laeve a bruise" };

string m_abilityRabbid[5]{ "Rabbit uses gun! Plungers shoot out and hit you in the stomach.","Rabbit has stolen your turn! You also got a smack on the wrist. Ouch.",
						   "Rabbits are unfortunately not known for their singing abilities. You witnessed this firsthand. Your ears are bleeding now.",
						   "Rabbit somehow found an energy drink! He grows big and blue. Rabbit has successfully used you as a chair!",
						   "Rabbits love cosplay. A rabbit shaped Princess Plum has appeared where the rabbit once stood. You facepalm." };

string m_defenseRabbid[3]{ "Rabbit is a guitar virtuoso. The sonic waves knock you back, half your damage was shielded, you took damage.",
						  "Rabbit eats a banana, and dumps the peel on the ground. He then proceeds to slip on it, avoiding your attack. Rabbit was healed",
						  "Rabbit takes out their trusted rolling pin and rolls out some pizza dough. He hides under it, abilities are blocked for 1 turn." }; 

class Character {
public:
	void move() { cout << "I-a move my legs" << endl; }
	virtual void receiveDamage() { ; }
	virtual int healthShow() { cout << "Health unknown" << endl; return 0; }
	virtual void melee() { cout << "I can swing my sword"; }
	virtual void defense() { cout << "Block out the haters"; }
	virtual void abilities() { cout << "I use my brain"; }
	virtual void turn() { cout << "It's MY turn on the XBOX"; }
	virtual void generateHealth() { cout << "This is my health"; }
	void xpShow() { cout << "XP unknown" << endl; }
};

class Plumber : public Character {
public:
	int healthShow();
	void xpShow();
	void addName(string t_name);
	string showName();
	void playerChoice();
	void melee();
	void defense();
	void abilities();
	void turn();
	void receiveDamage();

private:
	const int M_MAX_HEALTH = 50; //max health for the player
	const int M_MAX_MELEE = 11; //used for generating random damage
	const int M_MAX_ABILITY = 20; 
	const int M_MIN_ABILITY = 10;
	string m_name = ""; //stores chosen character
	int m_health = M_MAX_HEALTH;
	int m_xp = 0;
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
	int m_normHealth;
	const int M_MAX_MELEE = 8;
	const int M_MAX_ABILITY = 10;
	const int M_MIN_ABILITY = 5;
};

class Game :public Rabbid, public Plumber
{
public:

	void calculateDamage();
	void game();
};
	

Plumber player;
Character* enemies[10];
#include <iostream>
#include "main.h"

using namespace std;
 //Plunger - rabbid whacks mario with a toiler plunger

/// <summary>
///these attacks will all be using carrots as the point is to overfeed the rabbits til they're too full to fight
/// Melee: 
/// Stomp - mario jumps on the rabbit's head
/// Uppercut - mario punches rabbit's chin
/// Wrench - mario whacks the rabbit in the head, a bump forms
/// Groundpound - mario double jumps and stomps on the ground, rabbit is knocked off feet
/// Cape slash - mario throws his cape like a whip
/// Saw Surprise - mario cuts hole around rabbit, rabbit falls down and jumps back up
/// Mr Nose-it-all - mario pretends to take rabbit's nose, hurts itself in its confusion
/// 
/// Ability:
/// Carrot Archery - mario uses a bow to shoot carrots at the rabbit
/// Carrot Cake - mario makes a carrot cake so delicious, the rabbit can't help but eat it all
/// Carrot Trap - mario leads rabbit into trap
/// Carrot Temptation - mario baits the rabbit into following beside carrot patch, rabbit can't resist and eats some
/// Carrot Yeet - mario throws carrots at the rabbit...that's it
/// 
/// Defense:
/// Cape parry - cape acts as a shield and gives half the damage back to the rabbit (can only be used against melee)
/// Starman - mario receives no damage if the attack is an ability
/// Shroom Soup - mario can replenish some health
/// </summary>

Plumber player;
Rabbid rabbids[10];

int main(void)
{
	rabbids[m_currentEnemy].generateHealth();

	cout << "Please choose a brother: \n0 - Morgan\n1 - Lorcan\n";
	cin >> m_chosenChar;

	if (m_chosenChar == 0)
	{
		player.addName("Morgan");
	}
	else if (m_chosenChar == 1)
	{
		player.addName("Lorcan");
	}
	else
	{
		player.addName("Lorcan");
		cout << "Invalid number, Lorcan was chosen automatically\n";
	}
	system("cls");
	//the game loop, enemies will spawn as long as the player doesn't have all achievements
	while (m_numAchievements < M_MAX_ACHIEVEMENTS)
	{
		int enemyHealth = rabbids[m_currentEnemy].healthShow();
		cout << enemyHealth<< "\n";
		player.healthShow();
		player.xpShow();
		player.playerChoice();
		rabbids[m_currentEnemy].receiveDamage();
	
		//rabbids turn

		//player.move();
		//player.receiveDamage();






	}

	cin.get();
}

void Plumber::receiveDamage()
{
}

int Plumber::healthShow()
{
	cout << showName() << "'s health - " << m_health << "	";

	return 0;
}

void Plumber::xpShow()
{
	cout << showName() << "'s XP -  " << m_xp << "\n";
}

void Plumber::addName(string t_name)
{
	m_name = t_name;
}

string Plumber::showName()
{
	return m_name;
}

void Plumber::playerChoice()
{
	int action;

	cout << "Please choose " << showName() << "'s action:\n0 - Melee\n1 - Defense\n2 - Ability\n";
	cin >> action;

	if (action == 0)
	{
		melee();
	}
	else if (action == 1)
	{
		defense();
	}
	else if (action == 2)
	{
		abilities();
	}
	else
	{
		system("Cls");
		playerChoice();
	}
}

void Plumber::melee()
{
	system("Cls");
	int choice = -1;
	cout << "Melee:\n0 - Stomp\n1 - Uppercut\n2 - Wrench\n3 - Groundpound\n4 - Cape Slash\n5 - Saw Surprise\n6 - Mr Nose-it-all\n";
	cin >> choice;
	
	if (choice <= 6)
	{
		cout << m_name << m_meleeAttack[choice] << "\n";
		m_damageGiven = rand() % M_MAX_MELEE;
		cout << m_damageGiven;
		system("Pause");
		system("Cls");
	}
	else
	{
		melee();
	}
}
/// Defense:
/// Cape parry - cape acts as a shield and gives half the damage back to the rabbit (can only be used against melee)
/// Starman - mario receives no damage if the attack is an ability
/// Shroom Soup - mario can replenish some health
/// </summary>
void Plumber::defense()
{
	system("Cls");
	int choice = -1;
	cout << "Defense:\n0 - Cape Parry\n1 - Starman\n2 - Shroom Soup\n";
	cin >> choice;

	if (choice <= 2)
	{
		cout << m_name << m_defenseAttack[choice] << "\n";
		m_damageGiven = rand() % 10;
		cout << m_damageGiven;
		system("Pause");
		system("Cls");
	}
	else
	{
		defense();
	}
} 
void Plumber::abilities()
{
	system("Cls");
	int choice = -1;
	cout << "Abilities:\n0 - Carrot Yeet\n1 - Bow and Carrot\n2 - Carrot Temptation\n3 - Carrot Trap\n4 - CarrotCake\n";
	cin >> choice;

	if (choice <= 4)
	{
		cout << m_name << m_abilityAttack[choice] << "\n";
		m_damageGiven = rand() % M_MAX_ABILITY + M_MIN_ABILITY;
		cout << m_damageGiven << "\n";
		system("Pause");
		system("Cls");
	}
	else
	{
		abilities();
	}

}

void Rabbid::receiveDamage()
{
	m_health -= m_damageGiven;
	if (m_health <= 0)
	{
		cout << "Rabbid defeated!\n";
		m_enemyAlive[m_currentEnemy] = false;
		m_currentEnemy++;
		rabbids[m_currentEnemy].generateHealth();
	}
}

void Rabbid::generateHealth()
{
	m_health = rand() % 20 + 50;
}

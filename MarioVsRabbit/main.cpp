#include <iostream>
#include "main.h"

using namespace std;
///Melee:
/// 
/// Plunger - rabbid whacks mario with a toiler plunger
/// Shark Attack - Rabbid will cosplay as a shark and bite player
/// Now-you-see-me - Rabbid sticks plunger on player's face, leave round shaped bruises
/// 

/// <summary>
/// Abilities
/// Plunger Gun - uses a gun to shoot plungers
/// Boutta Steal - Rabbid can steal one of player's turns
/// Siren's Song - Rabbit will 'sing' badly and give Player a headache
/// Energy Drink - Rabbit mutates and squashes player by sitting on them
/// Tactical Ruse - Rabbit cosplays as princess plum, player facepalms so hard they hurt themself
/// 
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
		player.turn();
		rabbids[m_currentEnemy].turn();
		//player.move();
		//player.receiveDamage();
	}
	cin.get();
}

void Plumber::receiveDamage()
{
}
/// <summary>
/// Displays the player's health on screen
/// </summary>
/// <returns></returns>
int Plumber::healthShow()
{
	cout << showName() << "'s health - " << m_health << "	";

	return 0;
}
/// <summary>
/// Displays the player's XP on screen
/// </summary>
void Plumber::xpShow()
{
	cout << showName() << "'s XP -  " << m_xp << "\n";
}
/// <summary>
/// Used to confirm player's chosen character
/// </summary>
/// <param name="t_name"></param>
void Plumber::addName(string t_name)
{
	m_name = t_name;
}
/// <summary>
/// returns player's name
/// </summary>
/// <returns></returns>
string Plumber::showName()
{
	return m_name;
}
/// <summary>
/// Asks player what option they would want to choose in battle
/// </summary>
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
/// <summary>
/// Lists all player melee attacks and displays text accordingly
/// </summary>
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
		cout << "Rabbit loses " << m_damageGiven << " health\n";
		system("Pause");
		system("Cls");
	}
	else
	{
		melee();
	}
}
/// <summary>
/// Lists all player defense attacks and displays text accordingly
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
		cout << "Rabbit loses " << m_damageGiven << " health\n";
		system("Pause");
		system("Cls");
	}
	else
	{
		defense();
	}
}
/// <summary>
/// Lists all player ability attacks and displays text accordingly
/// </summary>
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
		cout << "Rabbit loses " << m_damageGiven << " health\n";
		system("Pause");
		system("Cls");
	}
	else
	{
		abilities();
	}

}
/// <summary>
/// determines what happens during player's turn
/// </summary>
void Plumber::turn()
{
	player.healthShow();
	player.xpShow();
	player.playerChoice();

}
/// <summary>
/// calculates the remaining health of the rabbits and makes new enemy
/// </summary>
void Rabbid::receiveDamage()
{
	m_health -= m_damageGiven;
	if (m_health <= 0)
	{
		cout << "Rabbid defeated!\n";
		m_enemyAlive[m_currentEnemy] = false;
		m_currentEnemy++;
		rabbids[m_currentEnemy].generateHealth();
		if (m_enemyAlive[M_MAX_ENEMY - 1] == false)
		{
			for (int i = 0; i < M_MAX_ENEMY; i++)
			{
				m_enemyAlive[i] == true;
				rabbids[i].generateHealth();
			}
			m_currentEnemy = 0;
		}
	}
}
/// <summary>
/// Randomly generates rabbit health
/// </summary>
void Rabbid::generateHealth()
{
	m_health = rand() % 20 + 50;
}

/// <summary>
/// randomly generates rabbit option choice
/// </summary>
void Rabbid::rabbidChoice()
{
	int randChoice = rand() % 3;
	if (randChoice == 0)
	{
		melee();
	}
	else if (randChoice == 1)
	{
		defense();
	}
	else if (randChoice == 2)
	{
		abilities();
	}
	else
	{
		system("Cls");
		rabbidChoice();
	}
}
/// <summary>
/// generates what melee attack the rabbid uses
/// </summary>
void Rabbid::melee()
{
}
/// <summary>
/// generates what defense the rabbid uses
/// </summary>
void Rabbid::defense()
{
}
/// Abilities
/// Plunger Gun - uses a gun to shoot plungers
/// Boutta Steal - Rabbid can steal one of player's turns
/// Siren's Song - Rabbit will 'sing' badly and give Player a headache
/// Energy Drink - Rabbit mutates and squashes player by sitting on them
/// Tactical Ruse - Rabbit cosplays as princess plum, player facepalms so hard they hurt themself
/// 
/// <summary>
/// generates what ability attack the rabbid uses
/// </summary>
void Rabbid::abilities()
{
	system("Cls");
	int abChoice = rand() % 5;

	cout << m_abilityRabbid[abChoice] << "\n";
	
		//m_damageGiven = rand() % M_MAX_ABILITY + M_MIN_ABILITY;
		//cout << "Rabbit lost " << m_damageGiven << " health\n";
	system("Pause");
	if (abChoice == 1)
	{
		turn();
	}
	system("Cls");
	
}

/// <summary>
/// determines what happens during rabbid turn
/// </summary>
void Rabbid::turn()
{
	rabbids[m_currentEnemy].receiveDamage();
	int enemyHealth = rabbids[m_currentEnemy].healthShow();
	cout << "Rabbit's health is now at " << enemyHealth << "\n";
	rabbidChoice();
	system("Pause");
	system("Cls");
}





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
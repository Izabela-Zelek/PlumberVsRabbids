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


int main(void)
{
	Plumber player;

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
		player.healthShow();
		player.xpShow();
		player.playerChoice();
		//rabbids turn

		//player.move();
		//player.receiveDamage();






	}

	cin.get();
}

void Plumber::receiveDamage()
{
}

void Plumber::healthShow()
{
	cout << showName() << "'s health - " << m_health << "\n";
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
		playerChoice();
	}
}

void Plumber::melee()
{
}

void Plumber::defense()
{
}

void Plumber::abilities()
{
}

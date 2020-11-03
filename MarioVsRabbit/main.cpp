#include <iostream>
#include "main.h"

using namespace std;

int main(void)
{
	Game gameScreen;

	gameScreen.game();
	cin.get();
}

/// <summary>
/// takes into consideration special defenses when calculating damage
/// </summary>
void Game::calculateDamage()
{
	if (m_capeUsed)
	{
		if (modeRabbit == 0)
		{
			m_damageToRabbit = m_damageReceived / 2;
			m_damageReceived = 0;
		}
	}
	if (m_starUsed)
	{
		if (modeRabbit == 2)
		{
			m_damageToRabbit = 0;
		}
	}
	
	enemies[m_currentEnemy]->receiveDamage();
	player.receiveDamage();
}

/// <summary>
/// main game loop and the starter storyline
/// </summary>
void Game::game()
{
	for (int i = 0; i < M_MAX_ENEMY; i++)
	{
		enemies[i] = new Rabbid;
		enemies[i]->generateHealth();
	}


	enemies[m_currentEnemy]->generateHealth();
	cout << "Please choose a brother: \n0 - Morgan\n1 - Lorcan\n";
	cin >> m_chosenChar;

	if (m_chosenChar == 0)
	{
		player.addName("Morgan");
		m_capeAmount = 1;
		m_starAmount = 1;
		m_soupAmount = 2;
	}
	else if (m_chosenChar == 1)
	{
		player.addName("Lorcan");
		m_capeAmount = 2;
		m_starAmount = 2;
		m_soupAmount = 4;
	}
	else
	{
		player.addName("Lorcan");
		cout << "Invalid number, Lorcan was chosen automatically\n";
		m_capeAmount = 2;
		m_starAmount = 2;
		m_soupAmount = 4;
		system("Pause");
	}


	system("cls");
	//the game loop, enemies will spawn as long as the player doesn't have all achievements
	while (m_numAchievements < M_MAX_ACHIEVEMENTS)
	{
		player.turn();
		enemies[m_currentEnemy]->turn();
		calculateDamage();
		
	}
}
void Game::shop()
{
	system("Cls");
	cout << <<
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
void Plumber::moneyShow()
{
	cout << showName() << "'s money -  " << m_coins << "\n";
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
	Game shop;
	int action;

	cout << "Please choose " << showName() << "'s action:\n0 - Melee\n1 - Defense\n2 - Ability\n3 - Shop";
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
	else if (action == 3)
	{
		shop.shop();
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
		m_damageToRabbit = rand() % M_MAX_MELEE;
		cout << "Rabbit loses " << m_damageToRabbit << " health\n";
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
	cout << "Defense:\n0 - Cape Parry\n1 - Starman\n2 - Shroom Soup\n3 - Go Back\n";
	cin >> choice;

	if (choice <= 3)
	{
		
		system("Pause");
		system("Cls");

		switch (choice)
		{
		case 0:
			if (m_capeAmount == 0)
			{
				cout <<"Cape not available.\n";
				defense();
				break;
			}
			else
			{
				cout << m_name << m_defenseAttack[choice] << "\n";
				m_capeUsed = true;
				cout << "Cape Equipped!\n";
				m_capeAmount--;
			}
			break;
		case 1:
			if (m_starAmount == 0)
			{
				cout <<"Star not available.\n";
				defense();
				break;
			}
			else
			{
				cout << m_name << m_defenseAttack[choice] << "\n";
				m_starUsed = true;
				cout << "Star Equipped!\n";
				m_starAmount--;
			}
			break;
		case 2:
			if (m_soupAmount <= 0)
			{
				cout << "Soup not available.\n";
				defense();
				break;
			}
			else
			{
				cout << m_name << m_defenseAttack[choice] << "\n";
				m_health = M_MAX_HEALTH;
				m_soupAmount--;
			}
			break;
		case 3:
			playerChoice();
			break;
		default:
			break;
		}

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
		m_damageToRabbit = rand() % M_MAX_ABILITY + M_MIN_ABILITY;
		cout << "Rabbit loses " << m_damageToRabbit << " health\n";
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
	player.moneyShow();
	player.playerChoice();

}

/// <summary>
/// takes away damage from player health
/// </summary>
void Plumber::receiveDamage()
{
	m_health -= m_damageReceived;
}

/// <summary>
/// processes damage and generates new character
/// </summary>
void Rabbid::receiveDamage()
{
	m_health -= m_damageToRabbit;
	
	if (m_health <= 0)
	{
		cout << "Rabbid defeated!\n";
		m_xp += 25;
		m_coins += 6;
		cout << "You have gained 25 XP and 6 coins\n";
		m_enemyAlive[m_currentEnemy] = false;
		m_currentEnemy++;
		m_health = m_normHealth;
		cout << "New enemy located!\n";
		if (m_enemyAlive[M_MAX_ENEMY - 1] == false)
		{
			for (int i = 0; i < M_MAX_ENEMY; i++)
			{
				m_enemyAlive[i] == true;
				enemies[i]->generateHealth();
			}
			m_currentEnemy = 0;
		}
	}
	cout << "Rabbit is now at " << m_health << " health.\n";
	system("Pause");
	system("Cls");
}
/// <summary>
/// Randomly generates rabbit health
/// </summary>
void Rabbid::generateHealth()
{
	m_health = rand() % 20 + 50;
	m_normHealth = m_health;
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
	modeRabbit = 0;
	system("Cls");
	int abChoice = rand() % 7;

	cout << m_meleeRabbid[abChoice] << "\n";

	m_damageReceived = rand() % M_MAX_MELEE;
	system("Pause");
	system("Cls");
}



/// <summary>
/// generates what defense the rabbid uses
/// </summary>
void Rabbid::defense()
{
	modeRabbit = 1;
	system("Cls");
	int abChoice = rand() % 3;

	cout << m_defenseRabbid[abChoice] << "\n";

	system("Pause");
	system("Cls");
}

/// <summary>
/// generates what ability attack the rabbid uses
/// </summary>
void Rabbid::abilities()
{
	modeRabbit = 2;
	system("Cls");
	int abChoice = rand() % 5;

	cout << m_abilityRabbid[abChoice] << "\n";

	if (abChoice == 1)
	{
		turn();
	}
	m_damageReceived = rand() % M_MAX_ABILITY + M_MIN_ABILITY;
	system("Pause");
	system("Cls");
	
}

/// <summary>
/// determines what happens during rabbid turn
/// </summary>
void Rabbid::turn()
{
	rabbidChoice();
}





/// <summary>
/// PLUMBER
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
/// 
/// 
/// RABBID
///Melee:
/// 
/// Plunger - rabbid whacks mario with a toiler plunger
/// Shark Attack - Rabbid will cosplay as a shark and bite player
/// Now-you-see-me - Rabbid sticks plunger on player's face, leave round shaped bruises
/// Bunny Baton - Player got a parking ticket! Officer Rabbid isn't happy
/// Overcooked!!! rabbit burns food, italian plumber can't accept this
/// Bunny Boulder
/// 

/// <summary>
/// Abilities
/// Plunger Gun - uses a gun to shoot plungers
/// Boutta Steal - Rabbid can steal one of player's turns
/// Siren's Song - Rabbit will 'sing' badly and give Player a headache
/// Energy Drink - Rabbit mutates and squashes player by sitting on them
/// Tactical Ruse - Rabbit cosplays as princess plum, player facepalms so hard they hurt themself
/// 
/// 
/// Defense:
/// Sonic Waves- Rabbit plays guitar, half the damage from player, minimal damage to player
/// Peeling Good - Rabbit eats a banana and slips on the peel, avoids damage, heals
/// Dough A Deer - Rabbit rolls out some pizza dough and hides under it. Shield against abilities
/// 
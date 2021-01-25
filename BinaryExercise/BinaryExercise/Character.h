#pragma once

class Character 
{
public:
	Character() {}
	Character(int health, int damage, int armor);

	int m_health;
	int m_damage;
	int m_armor;
};
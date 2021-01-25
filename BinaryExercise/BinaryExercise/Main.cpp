#include <iostream>
#include <fstream>
#include "Character.h"

int main() 
{
	Character example1 = Character(100, 10, 30);
	Character example2 = Character(75, 30, 35);

	std::fstream file;

	file.open("datData.dat", std::ios::out | std::ios::binary);
	if (!file.is_open()) 
	{
		return false;
	}

	file.write((char*)&example1, sizeof(Character));
	file.write((char*)&example2, sizeof(Character));
	file.close();

	Character example3 = Character();

	file.open("datData.dat", std::ios::in | std::ios::binary);
	if (!file.is_open()) 
	{
		return false;
	}
	file.seekg(sizeof(Character) * 2, std::ios::beg);
	file.read((char*)&example3, sizeof(Character));
	std::cout << example3.m_health << std::endl;
	std::cout << example3.m_damage << std::endl;
	std::cout << example3.m_armor << std::endl;
	file.close();

	return true;
}
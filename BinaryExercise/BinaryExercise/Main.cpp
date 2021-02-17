#include <iostream>
#include <fstream>
#include "Character.h"

int main() 
{
	//Initialize the two example characters
	Character example1 = Character(100, 10, 30);
	Character example2 = Character(75, 30, 35);

	std::fstream file;

	//open the file
	file.open("datData.dat", std::ios::out | std::ios::binary);
	if (!file.is_open()) 
	{
		return false;
	}

	//write the examples into the file then close
	file.write((char*)&example1, sizeof(Character));
	file.write((char*)&example2, sizeof(Character));
	file.close();

	//initialize other example character
	Character example3 = Character();

	//open the file
	file.open("datData.dat", std::ios::in | std::ios::binary);
	if (!file.is_open()) 
	{
		//if the file's not open, return false
		return false;
	}
	//Translate from binary
	file.seekg(sizeof(Character) * 2, std::ios::beg);
	//read the contents of the file and record them into the third example
	file.read((char*)&example3, sizeof(Character));
	//display the example results
	std::cout << example3.m_health << std::endl;
	std::cout << example3.m_damage << std::endl;
	std::cout << example3.m_armor << std::endl;
	//close file
	file.close();

	//close program
	return true;
}
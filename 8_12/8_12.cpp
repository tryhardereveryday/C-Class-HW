// 8_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Charley Mao   20181111

#include "pch.h"
#include <iostream>
#include <string>
#include <random>
#include <thread>
using namespace std;

bool locationCheck(int& location) 
{
	const int end{ 70 }; //end of the 70 lines
	if (location < 1) 
	{
		location = 1;//back to square 1 if slip far left.
		return false;
	}
	else if (location >= 70)
	{
		return true;
	}
	else if (1<= location <70) {
		return false;
	}
}


int main()
{
	
	int tortoisePos{ 1 }, harePos{ 1 };//initial position

	cout << "BANG !!!!!\n" << "AND THEY'RE OFF !!!!!\n";
	srand((unsigned)time(0));
	int a = 0; 
	while (!a)
	{
		string course = string(70, '-') + string(9, ' ');//for the 9 squares to the right memory slots
		// speed for 2 animals
		const int tortoiseMoves[10] = { 3, 3, 3, 3, 3, -6, -6, 1, 1, 1 };
		const int hareMoves[10] = { 0, 0, 9, 9, -12, 1, 1, 1, -2, -2 };
		
		int rand1 = (10 * rand() / (RAND_MAX + 1.0));
		int rand2 = (10 * rand() / (RAND_MAX + 1.0));

		tortoisePos += tortoiseMoves[rand1]; //tortoise reposition
		if(locationCheck(tortoisePos))
			a = 1;

		harePos += hareMoves[rand2];	//hare reposition
		if(locationCheck(harePos))
			a=1;

		if (tortoisePos == harePos)
			course.replace(harePos, 7, "OUCH!!!");
		else
		{
			course.replace(harePos, 1, "H");
			course.replace(tortoisePos, 1, "T");
		}

		cout << course << endl;
		this_thread::sleep_for(chrono::milliseconds(200)); //0.2 sec refresh
	}

	//result
	if(tortoisePos>=harePos)
		cout << "\nTORTOISE WINS!!! YAY!!!\n";
	else
		cout << "\nHare wins. Yuch.\n";
	cin.get();
	cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

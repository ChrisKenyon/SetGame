// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SetGame.h"

int main()
{
	try
	{
		SetGame game;
		game.playSet();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
		exit(0);
	}
 
	int exit;
	cin >> exit;
	return 0;
}


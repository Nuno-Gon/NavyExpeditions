// NavyExpeditions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Configuration.h"
#include "Game.h"

using namespace std;

int main(){
	Configuration config;
	config.run();
	
	Game game(config);
	game.run();
    return 0;
}


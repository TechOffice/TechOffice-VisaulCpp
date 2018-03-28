// SDLExample.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "SDL.h"

int main(int argc, char **argv) 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL cannot initialize." << SDL_GetError() << std::endl;
	}
    return EXIT_SUCCESS;
}


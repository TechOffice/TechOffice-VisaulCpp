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

	//Set up screen
	SDL_Window* screen = NULL;
	screen = SDL_CreateWindow("My Game Window",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640, 480,
		SDL_WINDOW_SHOWN);

	// Setup renderer
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

	//Load image
	SDL_Surface* hello = NULL;
	hello = SDL_LoadBMP("hello.bmp");

	SDL_Texture* helloTexture = NULL;
	helloTexture = SDL_CreateTextureFromSurface(renderer, hello);
	SDL_FreeSurface(hello);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, helloTexture, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

    return EXIT_SUCCESS;
}


#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;


int main(int argc, char*args[])
{
	SDL_Window*okno = NULL;
	SDL_Surface*ekran = NULL;
	int frame = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "inicjalizacja nie pykla, SDL error: " << SDL_GetError() << endl;
	}
	else
	{
		okno = SDL_CreateWindow("Scotty",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
		ekran = SDL_GetWindowSurface(okno);
		while (1)
		{
			if (frame == 0)
			{

			}
			if (frame == 1)
			{
				SDL_Surface*tlo = SDL_LoadBMP("Graphic/tlo.bmp");
				
				SDL_FreeSurface(tlo);
			}
			SDL_Delay(2000);
		}
	}

}
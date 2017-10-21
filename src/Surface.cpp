#include "Surface.h"

SDL_Surface* Surface::doLoad(const char* file){
	//return SDL_LoadBMP(file); //Old version
	//return IMG_Load(file);
	auto toto = IMG_Load(file);
	if(toto == NULL){
		std::cout << "ERROR" <<std::endl;
		while(true){}
	}
	return toto;
}

bool Surface::doDraw(SDL_Surface * src, SDL_Surface* dest, int x, int y){
	if(dest==NULL||src==NULL){ return false; }
	SDL_Rect rectDest;
	rectDest.x = x;
	rectDest.y = y;
	SDL_BlitSurface(src, NULL, dest, &rectDest);
	return true;
}

bool Surface::doDraw(SDL_Surface* src, int x, int y, int w, int h, SDL_Surface* dest, int x2, int y2){
	if(src==NULL||dest==NULL){ return false; }

	//Create the rect with position coordinates (Src and Dest)
	SDL_Rect srcRect;
	srcRect.x = x;
	srcRect.y = y;
	srcRect.w = w;
	srcRect.h = h;
	SDL_Rect destRect;
	destRect.x = x2;
	destRect.y = y2;

	SDL_BlitSurface(src, &srcRect, dest, &destRect);
	return true;;
}

bool Surface::transparent(SDL_Surface * dest, int r, int g, int b){
	if(dest==NULL){ return false; }
	int val = SDL_SetColorKey(dest, SDL_TRUE, SDL_MapRGB(dest->format, r, g, b));
	return val==0 ? true : false; //Note: Returning val could be better
}
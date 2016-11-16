#pragma once
#include <iostream>
#include "Map.h"

/**
 *
 * \date Nov 14, 2016
 *
 * \brief Describe an Area
 * \details Area is composed by a set of Maps
 *
 */
class Area{
public:
	//--------------------------------------------------------------------------
	// Constants - Attributes
	//--------------------------------------------------------------------------
	static Area areaControl; //Just a public access to this area class
public:
	std::vector<Map> listMap; //List map in this area
private:
	int areaSize; //Asume always square, so size 3 means 3x3 maps
	SDL_Surface* tilesSprites; //Spritesheet with all tiles images (sprites)

public:
	//--------------------------------------------------------------------------
	// Constructors - Desctructors
	//--------------------------------------------------------------------------
	Area();
	~Area();

	//--------------------------------------------------------------------------
	// Body functions
	//--------------------------------------------------------------------------

	/**
	 * \brief Load an Area from file save
	 * \warning unsafe result if invalid file format or data
	 *
	 * \param file File to load (Path + name + extension)
	 * \return True if successfully loaded, otherwise, return false
	 */
	bool loadArea(const char* file);

	/**
	 * \brief Render the Area on the destination
	 * 
	 * \todo DOCUMENTATION TO DO
	 */
	void renderArea(SDL_Surface* dest, int cameraX, int cameraY);

	/***
	 * \brief Cleanup this Area. Free allocated memory and reset values
	 *
	 */
	void cleanupArea();
};


#pragma once
#include <SDL.h>
#include <vector>

#include "Animation.h"
#include "Surface.h"
#include "Tile.h"
#include "EntityCollision.h"
#include "FPS.h"
#include "Camera.h"
#include "Area.h"


// -----------------------------------------------------------------------------
// ENUM definitions
// -----------------------------------------------------------------------------
enum{
	ENTITY_TYPE_GENERIC = 0,
	ENTITY_TYPE_PLAYER
};

/**
 * Enum that define the entity collision behavior
 * In order to treat the flag as binary, the values
 * must be binaries like 0, 10, 100, 1000
 */
enum{
	ENTITY_FLAG_NONE	= 0,
	ENTITY_FLAG_GRAVITY = 0x1,
	ENTITY_FLAG_GHOST	= 0x2,
	ENTITY_FLAG_MAPONLY	= 0x4
};


/**
 * \brief		Define an Entity.
 * \details		Entity is anything we can interact with. (Almost anything that moves).
 * \warning		Currently works only with spritesheet using one column.
 *
 * \date		Nov 14, 2016
 * \note		Based on SDL Tutorial (http://www.sdltutorials.com/sdl-entities).
 */
class Entity{
	// -------------------------------------------------------------------------
	// Variables - Constants
	// -------------------------------------------------------------------------
public:
	static std::vector<Entity*> listEntities; //List of all created entities
protected:
	Animation		animEntity; //Animation for this entity
	SDL_Surface*	surfaceEntity; //Surface for this entity (A spritesheet)
public:
	float	x; //UpperLeftCorner X position of entity
	float	y; //UpperLeftCorner Y position of entity
	int		width;
	int		height;
	bool	moveLeft;
	bool	moveRight;

public:
	int		type; //Define type like Player or whatever (From enum)
	bool	dead;
	int		flags; //Define special behavior (From enum)

protected:
	float	speedX; //Current entity's speed
	float	speedY;
	float	accelX; //Current acceleration
	float	accelY;
	float	maxSpeedX; //Maximum possible speed
	float	maxSpeedY;

protected:
	int		currentFrameCol;
	int		currentFrameRow;

protected:
	int		col_x;
	int		col_y;
	int		col_width;
	int		col_height;

public:
	// -------------------------------------------------------------------------
	// Constructors - Initialization
	// -------------------------------------------------------------------------
	Entity();

public:
	// -------------------------------------------------------------------------
	// Main Loop functions
	// -------------------------------------------------------------------------

	/**
	 * \brief			Load entity from file.
	 * \details			A transparent color is automatically applied on pink (255,0,255).
	 *
	 * \param file		File to load (path + filename + extension).
	 * \param w			Width of the entity (Pixels).
	 * \param h			Height of the entity (Pixels).
	 * \param nbFrames	Define how many image draw this entity (used for animation).
	 */
	virtual bool loadEntity(const char* file, int w, int h, int nbFrames);

	/**
	 * \brief			Define action to do at each loop.
	 *
	 */
	virtual void doLoop();

	/**
	 * \brief			Draw entity on given surface.
	 *
	 * \param dest		SDL_Surface where to draw entity.
	 */
	virtual void doRender(SDL_Surface* dest);

	/**
	 * \brief			Cleanup entity.
	 * \details			Entity mustn't be used till another load.
	 */
	virtual void doCleanup();

	/**
	 *
	 */
	virtual void doAnimate();

	/**
	 * \brief			Called when entity collide with another
	 *
	 * \param other		Entity the current one collide with
	 */
	virtual void doCollision(Entity* other);

	void doMove(float moveX, float moveY);
	void stopMove();

	/**
	 * \brief			Check whether collision append with element
	 * \details			Use a simple check whether current rectangle bound
	 *					intersect the given rectangle.
	 *
	 * \param oX		UpperLeftCorner X position of the element
	 * \param oY		UpperLeftCorner Y position of the element
	 * \param oW		Rectangle width of the element
	 * \param oH		Rectangle height of the element
	 * \return			True if collide, otherwise, return false
	 */
	bool collides(int oX, int oY, int oW, int oH);

private:
	bool posValid(int newX, int newY);
	bool posValidTile(Tile* tile);
	bool posValidEntity(Entity* entity, int newX, int newY);
};
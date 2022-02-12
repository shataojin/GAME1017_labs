#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

#include <SDL.h>

class Bullet
{
private:
	
	

public:
	double m_dx, m_dy;
	SDL_FRect m_dst;
	Bullet(SDL_FRect dst, double dx, double dy);
	void Update();
	void Render();
};

#endif
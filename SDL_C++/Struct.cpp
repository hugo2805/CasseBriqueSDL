#pragma once
#include "Struct.h"

using namespace std;

//Constructeur 
renderer::renderer()
{
	this->pWindow = NULL;
	this->pRenderer = NULL;
}

//constructeur de copie
renderer::renderer(renderer& rend1)
{
	this->pWindow = rend1.pWindow;
	this->pRenderer = rend1.pRenderer;
}

//destructeur
renderer::~renderer()
{
}

//Accesseur
SDL_Window* renderer::getPWindow()
{
	return this->pWindow;
}

SDL_Renderer* renderer::getPRenderer()
{
	return this->pRenderer;
}

int renderer::getWinWidth()
{
	return winWidth;
}

int renderer::getWinHeight()
{
	return winHeight;
}

void renderer::setPWindow(SDL_Window* pWindow)
{
	this->pWindow = pWindow;
}

void renderer::setPRenderer(SDL_Renderer* pRenderer)
{
	this->pRenderer = pRenderer;
}

//Constructeur
rendererObject::rendererObject()
{
	this->pSurface = pSurface;
	this->pTexture = pTexture;
}

//Constructeur de copie
rendererObject::rendererObject(rendererObject& rendObj1)
{
	this->pSurface = rendObj1.pSurface;
	this->pTexture = rendObj1.pTexture;
}

//Destructeur
rendererObject::~rendererObject()
{
}
//Accesseurs
SDL_Surface* rendererObject::getPSureface()
{
	return pSurface;
}

SDL_Texture* rendererObject::getPTexture()
{
	return pTexture;
}

//Mutateurs
void rendererObject::setPSurface(SDL_Surface* pSurface)
{
	this->pSurface = pSurface;
}

void rendererObject::setPTexture(SDL_Texture* pTexture)
{
	this->pTexture = pTexture;
}

//Constructeur
Vect2D::Vect2D()
{
	this->n_x = 0;
	this->n_y = 0;
}

Vect2D::Vect2D(const int x, const int y)
{
	this->n_x = x;
	this->n_y = y;
}

//Constructeur de copie
Vect2D::Vect2D(Vect2D& vect1)
{
	this->n_x = vect1.n_x;
	this->n_y = vect1.n_y;
}

//Destructeur
Vect2D::~Vect2D()
{
}

//Acceseurs
int Vect2D::getX()
{
	return n_x;
}

int Vect2D::getY()
{
	return n_y;
}

//Mutateurs
void Vect2D::setX(int n_x)
{
	this->n_x = n_x;
}

void Vect2D::setY(int n_y)
{
	this->n_y = n_y;
}

int Vect2D::operator+=(int y)
{
	int n_temp;
	n_temp = this->n_y += y;

	return n_temp;
}

int Vect2D::operator-=(int y)
{
	int n_temp;
	n_temp = this->n_y -= y;

	return n_temp;
}

#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

using namespace std;

//Ressources pour rendu
class renderer {
private :
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    int winWidth = 1200;
    int winHeight = 700;

public :
    //Constructeur
    renderer();//SDL_Window* pWindow, SDL_Renderer* pRenderer);

    //constructeur de copie
    renderer(renderer& rend1);

    //destructeur
    ~renderer();

    //Accesseurs
    SDL_Window* getPWindow();
    SDL_Renderer* getPRenderer();
    int getWinWidth();
    int getWinHeight();

    //Mutateurs
    void setPWindow(SDL_Window* pWindow);
    void setPRenderer(SDL_Renderer* pRenderer);

};


//Ressources pour les objets (assets) a afficher dans le rendu
class rendererObject {

private: 
    SDL_Surface* pSurface;
    SDL_Texture* pTexture;

public:
    //Constructeur
    rendererObject();

    //constructeur de copie
    rendererObject(rendererObject& rendObj1);

    //destructeur
    ~rendererObject();

    //Accesseurs
    SDL_Surface* getPSureface();
    SDL_Texture* getPTexture();

    //Mutateurs
    void setPSurface(SDL_Surface* pSurface);
    void setPTexture(SDL_Texture* pTexture);

};


//Vecteur pour set la position des objets
class Vect2D {

private:
    int n_x;
    int n_y;

public: 
    //Constructeur
    Vect2D();
    Vect2D(const int x, const int y);

    //constructeur de copie
    Vect2D(Vect2D& vect1);

    //destructeur
    ~Vect2D();

    //Accesseurs
    int getX();
    int getY();

    //Mutateurs
    void setX(int n_x);
    void setY(int n_y);

    //opérateur+=
    int operator+=(int y);
    int operator-=(int y);
};

//Etats controller
typedef enum controller {

    up,
    down,
    idle 

}controller;



#pragma once
#include "Brick.h"
#include <iostream>

using namespace std;


//Constructeur
Brick::Brick()
{
    this->brick = brick;
    this->posBrick = posBrick;
    this->BrickWidth = 70;
    this->BrickHeight = 20;
    this->DestroyedBricks = false;
    this->color = 0;
}


//Constructeur de copie
Brick::Brick(Brick& B1)
{
    this->brick = B1.brick;
    this->posBrick = B1.posBrick;
    this->BrickWidth = B1.BrickWidth;
    this->BrickHeight = B1.BrickHeight;
    this->DestroyedBricks = B1.DestroyedBricks;
    this->color = B1.color;
}

//Destructeur
Brick::~Brick()
{

}

//Accesseurs
rendererObject Brick::getBrick()
{
    return brick;
}


Vect2D Brick::getPosBrick()
{
    return posBrick;
}

int Brick::getBrickWidth()
{
    return BrickWidth;
}

int Brick::getBrickHeight()
{
    return BrickHeight;
}

bool Brick::getDestroyedBricks()
{
    return DestroyedBricks;
}

int Brick::getColor()
{
    return color;
}


//Mutateurs

void Brick::setBrick (rendererObject brick)
{
    this->brick = brick;
}

void Brick::setPosBrick(Vect2D PosBrick)
{
    this->posBrick = PosBrick;
}

void Brick::setBrickWidth(int BrickWidth)
{
    this->BrickWidth = BrickWidth;
}

void Brick::setBrickHeight(int BrickHeight)
{
    this->BrickHeight = BrickHeight;
}

void Brick::setDestroyedBricks(bool DestroyedBricks)
{
    this->DestroyedBricks = DestroyedBricks;
}

void Brick::setColor(int color)
{
    this->color = color;
}



int Brick::initBrick(renderer* rendu, int x, int y, int color)
{
    SDL_Surface* Surf;
    SDL_Texture* texture;

    Surf = brick.getPSureface();

    posBrick.setX(x);
    posBrick.setY(y);

    if (rendu->getPRenderer())
    {
        switch (color)
        {
        case 1 :
            Surf = IMG_Load("../Asset/B3.png");
            setColor(3);
            break;
        case 2:
            Surf = IMG_Load("../Asset/B2.png");
            setColor(2);
            break;
        case 3:
            Surf = IMG_Load("../Asset/B1.png");
            setColor(1);
            break;
        }
           
        brick.setPSurface(Surf);
        Surf = brick.getPSureface();

        if (brick.getPSureface())
        {
            texture = SDL_CreateTextureFromSurface(rendu->getPRenderer(), brick.getPSureface());
            brick.setPTexture(texture);


            if (brick.getPTexture())
            {
                SDL_Rect dest = { posBrick.getX(), posBrick.getY(), BrickWidth, BrickHeight };
                SDL_RenderCopy(rendu->getPRenderer(), brick.getPTexture(), NULL, &dest);
            }
            else
            {
                fprintf(stderr, ":1: Echec de création de la texture : %s ", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, ":1: Echec de chargement du sprite : %s ", SDL_GetError());
        }
    }
    else
    {
        fprintf(stderr, " :1: echec de création du renderer : %s", SDL_GetError());
    }

    return 1;
}

int Brick::AfficheBrick(Vect2D* posBrick, renderer* rendu)
{

    SDL_Rect dest = { posBrick->getX(), posBrick->getY(), BrickWidth, BrickHeight };
    SDL_RenderCopy(rendu->getPRenderer(), brick.getPTexture(), NULL, &dest);

    //fprintf(stderr, "C Copie");

    return 1;
}

int Brick::VerifBall(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posBrick, int score)
{
    if ((posBall->getY()) <= (posBrick->getY()+25) && ((posBall->getX() + 25) >= posBrick->getX() && (posBall->getX() + 25) <= (posBrick->getX() + 70)))
    {
        speed = speed;
        MovBall->setY(MovBall->getY() * -1);
        setDestroyedBricks(true);
        switch (color)
        {
        case 1:
            score += 10;
            break;
        case 2:
            score += 20;
            break;
        case 3:
            score += 30;
            break;
        }

        system("cls");
        //printf( " SCORE : = %u\n"+ score);
        cout << "SCORE : " << score << "\n";


    }
    return score;
}






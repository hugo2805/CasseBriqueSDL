#pragma once
#include "Ball.h"

using namespace std;


//Constructeur
C_Ball::C_Ball()
{
    this->Ball = Ball;
    this->posBall = posBall;
    this->BallWidth = 50;
    this->BallHeight = 50;
}


//Constructeur de copie
C_Ball::C_Ball(C_Ball& b1)
{
    this->Ball = b1.Ball;
    this->posBall = b1.posBall;
    this->BallWidth = b1.BallWidth;
    this->BallHeight = b1.BallHeight;
}

//Destructeur
C_Ball::~C_Ball()
{
}

//Accesseurs
rendererObject C_Ball::getBall()
{
    return Ball;
}


Vect2D C_Ball::getPosBall()
{
    return posBall;
}

int C_Ball::getBallWidth()
{
    return BallWidth;
}

int C_Ball::getBallHeight()
{
    return BallHeight;
}


//Mutateurs

void C_Ball::setBall(rendererObject Ball)
{
    this->Ball = Ball;
}

void C_Ball::setPosBall(Vect2D PosBall)
{
    this->posBall = PosBall;
}
void C_Ball::setBallWidth(int BallWidth)
{
    this->BallWidth = BallWidth;
}

void C_Ball::setBallHeight(int BallHeight)
{
    this->BallHeight = BallHeight;
}



int C_Ball::initBall(renderer* rendu)
{
    bool ok = true;

    posBall.setX(rendu->getWinWidth() / 2 - BallWidth / 2);
    posBall.setY(rendu->getWinHeight() / 2 - BallHeight / 2);
    if (rendu->getPRenderer())
    {
        Ball.setPSurface(IMG_Load("../Asset/ball.png"));
        if (Ball.getPSureface())
        {
            Ball.setPTexture(SDL_CreateTextureFromSurface(rendu->getPRenderer(), Ball.getPSureface()));
            if (Ball.getPTexture())
            {
                SDL_Rect dest = { posBall.getX(), posBall.getY(), BallWidth, BallHeight };
                SDL_RenderCopy(rendu->getPRenderer(), Ball.getPTexture(), NULL, &dest);
            }
            else
            {
                fprintf(stderr, ":2: Echec de création de la texture : %s ", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, ":2: Echec de chargement du sprite : %s ", SDL_GetError());
        }
    }
    else
    {
        fprintf(stderr, ":2: echec de création du renderer : %s", SDL_GetError());
    }

    return 1;
}

int C_Ball::AfficheBall(Vect2D posBall, renderer* rendu)
{
    //posBall.setX();
    SDL_Rect dest = { posBall.getX(), posBall.getY(), BallWidth, BallHeight };
    SDL_RenderCopy(rendu->getPRenderer(), Ball.getPTexture(), NULL, &dest);

    return 1;
}



int C_Ball::CollisionBall(Vect2D* posBall, int speed, Vect2D* MovBall)
{
    
    if ((posBall->getY() <= 0))
    {
        speed = -speed;
        MovBall->setX(MovBall->getX()*-1);
       // fprintf(stderr, " val:1: = %d\n" + MovBall->getX());
        //fprintf(stderr, ":1:");
    }


    if ((posBall->getY() + BallHeight >= 700))
    {
        speed = -speed;
        MovBall->setX(MovBall->getX()*-1);
        //fprintf(stderr, " val:2: = %d\n" + MovBall->getX());
        //fprintf(stderr, ":2:");

    }


    if ((posBall->getX() <= 0))
    {
        speed = speed;
        MovBall->setX(MovBall->getX()*-1);
        //fprintf(stderr, " val:3: = %d\n" + MovBall->getX());
        //fprintf(stderr, ":3:");

    }


    if ((posBall->getX()+BallWidth >=1200))
    {
        speed = speed;
        MovBall->setX(MovBall->getX()*-1);
       // fprintf(stderr, " val:4: = %d\n" + MovBall->getX());
       //fprintf(stderr, ":4:");

    }

    return speed;
   
}

/*int C_Ball::VerifRG(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posRG)
{
    if (posBall->getY() + BallHeight >= posRG->getY() && (posBall->getX() + BallWidth/2 >= posRG->getX() && posBall->getX() + BallWidth / 2 <= posRG->getX() + 300))
    {
        speed = speed;
        MovBall->setY(MovBall->getY()*-1);
        //fprintf(stderr, " val:G: = %d\n" + MovBall->getX());
        fprintf(stderr, ":Gauche:");
    }
    return speed;
}*/

/*int C_Ball::VerifRD(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posRD)
{
    if (posBall->getX()+BallWidth >= posRD->getX() && (posBall->getY() + BallHeight / 2 >= posRD->getY() && posBall->getY() + BallHeight / 2 <= posRD->getY() + 300 && MovBall->getX() < 0 ))
    {
        speed = speed;
       MovBall->setX(MovBall->getX()*-1);
        fprintf(stderr, " val:D: = %d\n" + MovBall->getX());
        //fprintf(stderr, ":Droite:");
    }
    return speed;
}*/







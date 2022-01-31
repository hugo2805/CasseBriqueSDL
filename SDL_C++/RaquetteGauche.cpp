#pragma once
#include "RaquetteGauche.h"

using namespace std;


//Constructeur
RaquetteGauche::RaquetteGauche()
{
	this->RaquetteG = RaquetteG;
	this->posRG = posRG;
	this->RGWidth = 300;
	this->RGHeight = 30;
}


//Constructeur de copie
RaquetteGauche::RaquetteGauche(RaquetteGauche& RG1)
{
	this->RaquetteG = RG1.RaquetteG;
	this->posRG = RG1.posRG;
	this->RGWidth = RG1.RGWidth;
	this->RGHeight = RG1.RGHeight;
}

//Destructeur
RaquetteGauche::~RaquetteGauche() 
{

}

//Accesseurs
rendererObject RaquetteGauche::getRaquetteG()
{
	return RaquetteG;
}


Vect2D RaquetteGauche::getPosRG()
{
	return posRG;
}

int RaquetteGauche::getRGwidth()
{
	return RGWidth;
}

int RaquetteGauche::getRGheight()
{
	return RGHeight;
}


//Mutateurs

void RaquetteGauche::setRaquetteG(rendererObject RaquetteG)
{
	this->RaquetteG = RaquetteG;
}

void RaquetteGauche::setPosRG(Vect2D PosRG)
{
	this->posRG = PosRG;
}

void RaquetteGauche::setRGWidth(int RGWidth)
{
	this->RGWidth = RGWidth;
}

void RaquetteGauche::setRGHeight(int RGHeight)
{
	this->RGHeight = RGHeight;
}



int RaquetteGauche::initRg(renderer* rendu)
{

    
    SDL_Surface* Surf;
    SDL_Texture* texture;

   
    Surf = RaquetteG.getPSureface();

     posRG.setX(rendu->getWinWidth()/2 + RGWidth / 2);
     posRG.setY( rendu->getWinHeight() -50);
    
    if (rendu->getPRenderer())
    {
        Surf = IMG_Load("../Asset/RG1.png");
        RaquetteG.setPSurface(Surf);
        Surf = RaquetteG.getPSureface();

        if (RaquetteG.getPSureface())
        {
            texture = SDL_CreateTextureFromSurface(rendu->getPRenderer(), RaquetteG.getPSureface());
            RaquetteG.setPTexture(texture);
            

            if (RaquetteG.getPTexture())
            {
                SDL_Rect dest = { posRG.getX(), posRG.getY(), RGWidth, RGHeight };
                SDL_RenderCopy(rendu->getPRenderer(),RaquetteG.getPTexture(), NULL, &dest);
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

int RaquetteGauche::AfficheRG(Vect2D* posRG, renderer* rendu)
{
   
    posRG->setY(rendu->getWinHeight() - 50);
    SDL_Rect dest = { posRG->getX(), posRG->getY(), RGWidth, RGHeight };
    SDL_RenderCopy(rendu->getPRenderer(), RaquetteG.getPTexture(), NULL, &dest);

    //fprintf(stderr, "C Copie");

    return 1;
}

int RaquetteGauche::VerifBall(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posRG)
{
    if ((posBall->getY() + 50) >= posRG->getY() && ((posBall->getX() + 25) >= posRG->getX() && (posBall->getX() + 25 )<= (posRG->getX() + 300)))
    {
        speed = speed;
        MovBall->setY(MovBall->getY() * -1);
    }
    return speed;
}






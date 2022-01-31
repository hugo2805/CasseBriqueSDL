#pragma once
#include "RaquetteDroite.h"

using namespace std;


//Constructeur
RaquetteDroite::RaquetteDroite()
{
    this->RaquetteD = RaquetteD;
    this->posRD = posRD;
    this->RDWidth = 30;
    this->RDHeight = 300;
}


//Constructeur de copie
RaquetteDroite::RaquetteDroite(RaquetteDroite& RD1)
{
    this->RaquetteD = RD1.RaquetteD;
    this->posRD = RD1.posRD;
    this->RDWidth = RD1.RDWidth;
    this->RDHeight = RD1.RDHeight;
}

//Destructeur
RaquetteDroite::~RaquetteDroite()
{

}

//Accesseurs
rendererObject RaquetteDroite::getRaquetteD()
{
    return RaquetteD;
}


Vect2D RaquetteDroite::getPosRD()
{
    return posRD;
}

int RaquetteDroite::getRDwidth()
{
    return RDWidth;
}

int RaquetteDroite::getRDheight()
{
    return RDHeight;
}


//Mutateurs

void RaquetteDroite::setRaquetteD(rendererObject RaquetteD)
{
    this->RaquetteD = RaquetteD;
}

void RaquetteDroite::setPosRD(Vect2D PosRD)
{
    this->posRD = PosRD;
}

void RaquetteDroite::setRDWidth(int RDWidth)
{
    this->RDWidth = RDWidth;
}

void RaquetteDroite::setRDHeight(int RDHeight)
{
    this->RDHeight = RDHeight;
}





int RaquetteDroite::initRd(renderer* rendu)
{

    bool ok = true;

    posRD.setX(1150 + RDWidth / 2);
    posRD.setY(rendu->getWinHeight() / 2 - RDHeight / 2);
    if (rendu->getPRenderer())
    {
        RaquetteD.setPSurface(IMG_Load("../Asset/RD.png"));
        if (RaquetteD.getPSureface())
        {
            RaquetteD.setPTexture(SDL_CreateTextureFromSurface(rendu->getPRenderer(), RaquetteD.getPSureface()));
            if (RaquetteD.getPTexture())
            {
                SDL_Rect dest = { posRD.getX(), posRD.getY(), RDWidth, RDHeight };
                SDL_RenderCopy(rendu->getPRenderer(), RaquetteD.getPTexture(), NULL, &dest);
            }
            else
            {
                fprintf(stderr, ":3: Echec de création de la texture : %s ", SDL_GetError());
            }
        }
        else
        {
            fprintf(stderr, ":3: Echec de chargement du sprite : %s ", SDL_GetError());
        }
    }
    else
    {
        fprintf(stderr, ":3: echec de création du renderer : %s", SDL_GetError());
    }

    return 1;
}

int RaquetteDroite::AfficheRD(Vect2D* posRD, renderer* rendu)
{
    posRD->setX(1150);
    SDL_Rect dest = { posRD->getX(), posRD->getY(), RDWidth, RDHeight };
    SDL_RenderCopy(rendu->getPRenderer(), RaquetteD.getPTexture(), NULL, &dest);

    return 1;
}
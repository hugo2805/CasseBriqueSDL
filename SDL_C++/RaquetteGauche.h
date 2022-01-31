#pragma once
#include "Struct.h"

using namespace std;

class RaquetteGauche
{
private:
    rendererObject RaquetteG;
    Vect2D posRG;
    int RGWidth;
    int RGHeight;

public:

    //Constructeur
    RaquetteGauche();

    //constructeur de copie
    RaquetteGauche(RaquetteGauche& RG1);

    //destructeur
    ~RaquetteGauche();

    //Accesseurs
    rendererObject getRaquetteG();
    Vect2D getPosRG();
    int getRGwidth();
    int getRGheight();

    //Mutateurs
    void setRaquetteG(rendererObject RaquetteG);
    void setPosRG(Vect2D PosRG);
    void setRGWidth(int RGWidth);
    void setRGHeight(int RGHeight);

    int initRg(renderer* rendu);
    int AfficheRG(Vect2D* posRG, renderer* rendu);
    int VerifBall(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posRG);

};

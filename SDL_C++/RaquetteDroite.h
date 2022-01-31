#pragma once
#include "Struct.h"

using namespace std;

class RaquetteDroite
{
private:
    rendererObject RaquetteD;
    Vect2D posRD;
    int RDWidth;
    int RDHeight;

public:

    //Constructeur
    RaquetteDroite();

    //constructeur de copie
    RaquetteDroite(RaquetteDroite& RD1);

    //destructeur
    ~RaquetteDroite();

    //Accesseurs
    rendererObject getRaquetteD();
    Vect2D getPosRD();
    int getRDwidth();
    int getRDheight();

    //Mutateurs
    void setRaquetteD(rendererObject RaquetteD);
    void setPosRD(Vect2D PosRD);
    void setRDWidth(int RDWidth);
    void setRDHeight(int RDHeight);
    

    int initRd(renderer* rendu);
    int AfficheRD(Vect2D* posRD, renderer* rendu);

};


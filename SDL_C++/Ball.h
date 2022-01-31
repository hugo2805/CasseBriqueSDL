#pragma once
#include "Struct.h"
#include <time.h>

using namespace std;

class C_Ball
{
private:
    rendererObject Ball;
    Vect2D posBall;
    int BallWidth = 50;
    int BallHeight = 50;

public:

    //Constructeur
    C_Ball();

    //constructeur de copie
    C_Ball(C_Ball& b1);

    //destructeur
    ~C_Ball();

    //Accesseurs
    rendererObject getBall();
    Vect2D getPosBall();
    int getBallWidth();
    int getBallHeight();
    

    //Mutateurs
    void setBall(rendererObject Ball);
    void setPosBall(Vect2D PosBall);
    void setBallWidth(int BallWidth);
    void setBallHeight(int BallHeight);

    int initBall(renderer* rendu);
    int AfficheBall(Vect2D posBall, renderer* rendu);
    int CollisionBall(Vect2D* posBall, int spped, Vect2D* MovBall);

    //int VerifRG(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posRG);
    //int VerifRD(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posRD);

};

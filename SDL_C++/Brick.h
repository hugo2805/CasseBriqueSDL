#pragma once
#include "Struct.h"

using namespace std;

class Brick
{
private:
    rendererObject brick;
    Vect2D posBrick;
    int BrickWidth;
    int BrickHeight;
    bool DestroyedBricks;
    int color;

public:

    //Constructeur
    Brick();

    //constructeur de copie
    Brick(Brick& B1);

    //destructeur
    ~Brick();

    //Accesseurs
    rendererObject getBrick();
    Vect2D getPosBrick();
    int getBrickWidth();
    int getBrickHeight();
    bool getDestroyedBricks();
    int getColor();

    //Mutateurs
    void setBrick(rendererObject brick);
    void setPosBrick(Vect2D PosBrick);
    void setBrickWidth(int BrickWidth);
    void setBrickHeight(int BrickHeight);
    void setDestroyedBricks(bool DestroyedBricks);
    void setColor(int color);

    int initBrick(renderer* rendu, int x, int y, int color);
    int AfficheBrick(Vect2D* posBrick, renderer* rendu);
    int VerifBall(Vect2D* posBall, int speed, Vect2D* MovBall, Vect2D* posBrick, int score);

};


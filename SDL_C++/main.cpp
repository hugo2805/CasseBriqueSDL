#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Window.h"
#include "Struct.h"
#include "Ball.h"
#include "RaquetteGauche.h"
#include "RaquetteDroite.h"
#include "Brick.h"

#define LIGNE 3
#define COLONE 16

using namespace std;

void handleEvents(controller* controlJ2, int* close);

int main(int argc, char** argv)
{
    controller controlJ2;
    renderer rendu;
    int close = 0;
 
    C_Ball Obj_Ball;
    RaquetteGauche Obj_RG;
    RaquetteDroite Obj_RD;
    Brick Obj_brick[LIGNE][COLONE];
    Vect2D posBall;
    Vect2D MovBall(1, 1);
    int speedBall = 4;
    Vect2D posRD;
    Vect2D posRG;
    Vect2D posBrick = { 5,5 };
    int i = 0;
    int j = 0;
    int color = 1;
    int score = 0;
    int nbDest = 0;
    bool gameState = false;


    initWindow(&rendu);

        if (rendu.getPWindow())
        {
            
           Obj_Ball.initBall(&rendu);
           Obj_RG.initRg(&rendu);

           //Mise en place des briques
           for (i = 0; i < LIGNE; i++) {
               for(j = 0; j < COLONE; j++)
               {
               Obj_brick[i][j].setDestroyedBricks(false);
               Obj_brick[i][j].initBrick(&rendu, posBrick.getX(), posBrick.getY(),color);
               posBrick.setX(posBrick.getX() + 75);
               }
               posBrick.setY(posBrick.getY() + 20);
               color++;
           }

        
            while (!close) {
                while (!gameState)
                {


                    posBall = Obj_Ball.getPosBall();
                    posRG = Obj_RG.getPosRG();

                    handleEvents(&controlJ2, &close);

                    //Déplacement de la Raquette
                    switch (controlJ2)
                    {
                    case up:
                        if (posRG.getX() > 0)
                            posRG.setX(posRG.getX() - 5);
                        break;
                    case down:
                        if (posRG.getX() < 1200 - Obj_RG.getRGwidth())
                            posRG.setX(posRG.getX() + 5);
                        break;
                    }

                    Obj_RG.setPosRG(posRG);
                    //Verification de collision
                    speedBall = Obj_Ball.CollisionBall(&posBall, speedBall, &MovBall);
                    speedBall = Obj_RG.VerifBall(&posBall, speedBall, &MovBall, &posRG);

                    //mise a jours des Positiond'objet
                    Vect2D newPos(posBall.getX() + MovBall.getX() * speedBall, posBall.getY() + MovBall.getY() * speedBall);
                    Vect2D posBrick(5, 5);
                    Obj_Ball.setPosBall(newPos);

                    //Effacement du rendu précédent
                    SDL_RenderClear(rendu.getPRenderer());
                    //Affichage de la balle
                    Obj_Ball.AfficheBall(newPos, &rendu);

                    //Affichage des briques
                    for (i = 0; i < LIGNE; i++) {
                        for (j = 0; j < COLONE; j++)
                        {
                            if (Obj_brick[i][j].getDestroyedBricks() == false)
                            {
                                Obj_brick[i][j].AfficheBrick(&posBrick, &rendu);
                                score = Obj_brick[i][j].VerifBall(&posBall, speedBall, &MovBall, &posBrick, score);
                            }
                            else
                            {
                                nbDest++;
                            }
                            posBrick.setX(posBrick.getX() + 75);
                        }
                        posBrick.setX(5);
                        posBrick.setY(posBrick.getY() + 25);
                    }

                    if (nbDest == 48)
                    {
                        printf("VICTOIRE !!");
                        gameState = true;
                    }
                    else
                    {
                        nbDest = 0;
                    }

                    //Affichage de la Raquette
                    Obj_RG.AfficheRG(&posRG, &rendu);
                    SDL_RenderPresent(rendu.getPRenderer());
                    i++;
                    SDL_Delay(1000 / 60);
                }
                
            }
        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }
        SDL_DestroyRenderer(rendu.getPRenderer());
    
    SDL_Quit();

    return 0;
}

//Set controller event
void handleEvents(controller* controlJ2, int* close)
{

    SDL_Event events;

    while(SDL_PollEvent(&events)) {

        switch (events.type) {
        case SDL_QUIT:
            *close = 1;
            break;
        case SDL_KEYDOWN:
            switch (events.key.keysym.sym)
            {
            case SDLK_LEFT:
                *controlJ2 = up;
                break;
            case SDLK_RIGHT:                                                        
                *controlJ2 = down;
                break;
            }break;

        default:
            *controlJ2 = idle;
            break;
        }        
    }
}

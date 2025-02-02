//
// Created by direx on 27/01/2025.
//

#include "Player.h"

#include <stdlib.h>

//Initialisation du joueur à la position (5, 5) si il existe, sinon création d'un joueur à la position (5, 5)
PLAYER* InitializePlayer(PLAYER * player) {
    if(player) {
        player->PosX = 5;
        player->PosY = 5;
    }else {
        PLAYER* newPlayer = (PLAYER*)malloc(sizeof(PLAYER)); 
        newPlayer->PosY = 5;
        player = newPlayer;
    }
    return player;
}

//Libération de la mémoire du joueur
void FreePlayer(PLAYER * player) {
    if(player) {
        free(player);
    }
}

//Definition de l'espace de jeu et des mouvements du joueur
void MovePlayerCoord(PLAYER* player, const int X, const int Y) {
    if(player)
    {
        if(X == 1) {
            if(player->PosX < 9) { // Si la position du joueur est inférieure à 9, le joueur peut se déplacer sur la position X
                player->PosX += 1;
            }
        }else if(X == -1) {
            if(player->PosX > 0) { 
                player->PosX -= 1;
            }
        }else if(Y == 1) {
            if(player->PosY < 9) { //Idem pour la position Y
                player->PosY += 1;
            }
        }else if (Y == -1) {
            if(player->PosY > 0) {
                player->PosY -= 1;
            }
        }
    }
}
//Déplacement du joueur en fonction de l'input
void MovePlayer(PLAYER* player, const char* input) {
    if(player) {
        if(*input == 'z') {
            MovePlayerCoord(player, 0, 1); //Definition des deplacements du joueur en fonction de l'input
        }else if(*input == 'q') {
            MovePlayerCoord(player, -1, 0); //Idem
        }else if(*input == 's') {
            MovePlayerCoord(player, 0, -1); //Idem
        }else if(*input == 'd') {
            MovePlayerCoord(player, 1, 0); //Idem
        }
    }
}
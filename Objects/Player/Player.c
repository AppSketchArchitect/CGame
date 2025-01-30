//
// Created by direx on 27/01/2025.
//

#include "Player.h"

#include <stdlib.h>

PLAYER* InitializePlayer(PLAYER * player) {
    if(player) {
        player->PosX = 5;
        player->PosY = 5;
    }else {
        PLAYER* newPlayer = (PLAYER*)malloc(sizeof(PLAYER));
        newPlayer->PosX = 5;
        newPlayer->PosY = 5;
        player = newPlayer;
    }
    return player;
}

void FreePlayer(PLAYER * player) {
    if(player) {
        free(player);
    }
}

void MovePlayerCoord(PLAYER* player, const int X, const int Y) {
    if(player)
    {
        if(X == 1) {
            if(player->PosX < 9) {
                player->PosX += 1;
            }
        }else if(X == -1) {
            if(player->PosX > 0) {
                player->PosX -= 1;
            }
        }else if(Y == 1) {
            if(player->PosY < 9) {
                player->PosY += 1;
            }
        }else if (Y == -1) {
            if(player->PosY > 0) {
                player->PosY -= 1;
            }
        }
    }
}
void MovePlayer(PLAYER* player, const char* input) {
    if(player) {
        if(*input == 'z') {
            MovePlayerCoord(player, 0, 1);
        }else if(*input == 'q') {
            MovePlayerCoord(player, -1, 0);
        }else if(*input == 's') {
            MovePlayerCoord(player, 0, -1);
        }else if(*input == 'd') {
            MovePlayerCoord(player, 1, 0);
        }
    }
}
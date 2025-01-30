//
// Created by direx on 27/01/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#endif //PLAYER_H

typedef struct Player {
    int PosX;
    int PosY;
}PLAYER;

PLAYER* InitializePlayer(PLAYER * player);
void FreePlayer(PLAYER * player);
void MovePlayer(PLAYER* player, const char* input);
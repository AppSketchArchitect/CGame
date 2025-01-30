
#include "Writer.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool PrintToConsole(const PLAYER* player, const OBSTACLE_LINK* obstacles) {

    bool playerInObstacle = false;
    printf("\n");

    char* pixels = (char*) malloc(100 * sizeof(char));

    for (int i = 0; i < 100; i++) {
        pixels[i] = '_';
    }

    if(player != NULL) {
        pixels[player->PosX + 10*player->PosY] = 'P';
    }

    if(obstacles) {
        if(obstacles->PosY >= 0) {
            pixels[obstacles->PosX + 10*obstacles->PosY] = 'O';
            const OBSTACLE_LINK* obstacle = obstacles;

            while(obstacle->next) {
                obstacle = obstacle->next;
                if(obstacle->PosY >= 0) {
                    if(pixels[obstacle->PosX + 10*obstacle->PosY] == 'P') {
                        playerInObstacle = true;
                        pixels[obstacle->PosX + 10*obstacle->PosY] = 'X';
                    }else {
                        pixels[obstacle->PosX + 10*obstacle->PosY] = 'O';
                    }

                }
            }
        }
    }

    printf("\n");
    for(int y = 9; y >= 0; y--) {
        for(int x = 0; x < 10; x++) {
            printf(" %c", pixels[x + y*10]);
        }
        printf("\n");
    }

    free(pixels);

    return playerInObstacle;
}

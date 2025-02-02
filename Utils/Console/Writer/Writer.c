
#include "Writer.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Affichage du jeu dans la console
bool PrintToConsole(const PLAYER* player, const OBSTACLE_LINK* obstacles) {

    bool playerInObstacle = false;
    printf("\n");

    char* pixels = (char*) malloc(100 * sizeof(char));

    for (int i = 0; i < 100; i++) {
        pixels[i] = '_';
    }
    //Affichage du joueur par la lettre P
    if(player != NULL) {
        pixels[player->PosX + 10*player->PosY] = 'P';
    }
    //Affichage des obstacles par la lettre O
    if(obstacles) {
        if(obstacles->PosY >= 0) { //
            pixels[obstacles->PosX + 10*obstacles->PosY] = 'O';
            const OBSTACLE_LINK* obstacle = obstacles;
            //Affichage des obstacles suivants
            while(obstacle->next) {
                obstacle = obstacle->next;
                if(obstacle->PosY >= 0) {
                    if(pixels[obstacle->PosX + 10*obstacle->PosY] == 'P') {
                        playerInObstacle = true;
                        pixels[obstacle->PosX + 10*obstacle->PosY] = 'X'; // Si le joueur est sur un obstacle, il est affiché par la lettre X
                    }else {
                        pixels[obstacle->PosX + 10*obstacle->PosY] = 'O';
                    }

                }
            }
        }
    }
        printf("\n"); 
        for(int y = 9; y >= 0; y--) { // Boucle à travers chaque ligne de la grille
            for(int x = 0; x < 10; x++) { // Boucle à travers chaque pixel de la ligne
                printf(" %c", pixels[x + y*10]); // Affiche le pixel
            }
            printf("\n"); 
        }

        free(pixels); // Libère la mémoire allouée pour les pixels

        return playerInObstacle; 
    }

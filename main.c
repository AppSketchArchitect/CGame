#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

#include "Utils/Console/Reader/Reader.h"
#include "Utils/Console/Writer/Writer.h"


PLAYER* player = NULL; // Déclaration du joueur
OBSTACLE_LINK* obstacles = NULL;// Déclaration des obstacles
bool bQuit = false; // Déclaration de la variable de fin de jeu


//Initialisation du jeu et des objets
void Initialize() {
    printf("\nInitialisation...\n");
    InitializeKeyReader();

    player = InitializePlayer(player);

    obstacles = CreateObstacle(obstacles, 3, 3, 0);
    obstacles = CreateObstacle(obstacles, 4, 7, 1);
}

//Mise à jour du jeu en fonction de l'input
void Update(const char* input) {
    printf("\nUpdating...");
    MovePlayer(player, input);
    MoveObstacle(obstacles);
    obstacles = DeleteOutObstacle(obstacles);
    obstacles = SpawnObstacle(obstacles);
    printf("\nAffichage...");
    bool bGameOver = PrintToConsole(player, obstacles);
    if (bGameOver) {
        printf("\nGame Over...");
        bQuit = true;
    }
}

//Fin du jeu et libération de la mémoire
void Exit() {
    printf("\nExit...\n");
    StopKeyReader();
    FreeAll(obstacles);
    FreePlayer(player);
}

//Fonction principale du jeu
int main(void) {

    Initialize();
    //Boucle principale du jeu
    while(!bQuit) {
        char input = GetInput();
        Update(&input);
        Sleep(1000);
        if (input == 'b') {
            bQuit = true;
        }
    }

    Exit();

    return 0;
}
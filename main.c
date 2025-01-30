#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

#include "Utils/Console/Reader/Reader.h"
#include "Utils/Console/Writer/Writer.h"


PLAYER* player = NULL;
OBSTACLE_LINK* obstacles = NULL;
bool bQuit = false;

void Initialize() {
    printf("\nInitialisation...\n");
    InitializeKeyReader();

    player = InitializePlayer(player);

    obstacles = CreateObstacle(obstacles, 3, 3, 0);
    obstacles = CreateObstacle(obstacles, 4, 7, 1);
}

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

void Exit() {
    printf("\nExit...\n");
    StopKeyReader();
    FreeAll(obstacles);
    FreePlayer(player);
}

int main(void) {

    Initialize();

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
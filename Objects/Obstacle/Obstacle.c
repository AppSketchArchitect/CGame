
#include "Obstacle.h"

#include <stdio.h>
#include <stdlib.h>

//Création d'un obstacle à la fin de la liste
OBSTACLE_LINK* CreateObstacle(OBSTACLE_LINK* obstacle, const int X, const int Y, const int index) {
    OBSTACLE_LINK* new = (OBSTACLE_LINK*)malloc(sizeof(OBSTACLE_LINK));
    new -> PosX = X;
    new -> PosY = Y;
    new -> next = NULL;
    if(obstacle) {
        if(index == 0) {
            new->next = obstacle;
            obstacle = new;
        }else {
            OBSTACLE_LINK* P = obstacle;
            int x = 0;
            while(P -> next && x < index - 1) {
                P = P -> next;
                x++;
            }
            if(P -> next) {
                new -> next = P -> next;
            }
            P -> next = new;
        }

    }else {
        obstacle = new;
    }
    return obstacle;
}
OBSTACLE_LINK* DeleteObstacleAtIndex(OBSTACLE_LINK* obstacle, const int index) {
    if(obstacle) {
        if(index == 0) {
            obstacle = RemoveObstacleFromHead(obstacle);
        }else {
            OBSTACLE_LINK* P = obstacle;
            int x = 1;
            while (x < index - 1) {
                P = P -> next;
                x++;
            }
            OBSTACLE_LINK* P2 = P -> next;
            if(P -> next -> next == NULL) {
                P -> next = NULL;
            }else {
                P -> next = P -> next -> next;
            }
            free(P2);
        }
    }
    return obstacle;
}
OBSTACLE_LINK* RemoveObstacleFromHead(OBSTACLE_LINK *obstacle) {
    printf("Remove");
    if(obstacle) {
        const int length = ObstacleListLength(obstacle);
        if(length == 1) {
            obstacle = NULL;
        }else {
            OBSTACLE_LINK* P = obstacle;
            obstacle = obstacle -> next;
            free(P);
        }
    }
    return obstacle;
}

void PrintObstacle(const OBSTACLE_LINK* obstacle) {
    if(obstacle) {
        const OBSTACLE_LINK* current = obstacle;
        printf("PosX: %d / PosY: %d", current->PosX, current->PosY);
        while(current -> next) {
            current = current -> next;
            printf("PosX: %d / PosY: %d", current->PosX, current->PosY);
        }
    }
}
int ObstacleListLength(const OBSTACLE_LINK* obstacle) {
    int length = 0;
    if(obstacle) {
        const OBSTACLE_LINK* P = obstacle;
        length = 1;
        while(P -> next) {
            P = P->next;
            length++;
        }
    }
    return length;
}

void FreeAll(OBSTACLE_LINK* obstacle) {
    if(!obstacle) {
        return;
    }

    OBSTACLE_LINK* current = obstacle;
    OBSTACLE_LINK* temp = NULL;
    while(current -> next) {
        temp = current->next;
        free(current);
        current = temp;
    }
    free(current);
}

OBSTACLE_LINK* SpawnObstacle(OBSTACLE_LINK* obstacle) {
    int x = rand() % 10;
    obstacle = CreateObstacle(obstacle, x, 9, 0);
    return obstacle;
}

void MoveObstacle(OBSTACLE_LINK* obstacle) {
    if(obstacle) {
        OBSTACLE_LINK* current = obstacle;
        current->PosY -= 1;
        while(current->next) {
            current = current->next;
            current->PosY -= 1;
        }
    }
}
OBSTACLE_LINK* DeleteOutObstacle(OBSTACLE_LINK* obstacle) {
    if(obstacle) {
        int index = 0;
        if(obstacle->PosY < 0) {
            obstacle = DeleteObstacleAtIndex(obstacle, index);
            return obstacle;
        }
        OBSTACLE_LINK* current = obstacle;
        while(current->next) {
            index++;
            current = current->next;
            if(current->PosY < 0) {
                obstacle = DeleteObstacleAtIndex(obstacle, index + 1);
                return obstacle;
            }
        }
    }
    return obstacle;
}
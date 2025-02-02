
#ifndef OBSTACLE_H
#define OBSTACLE_H

#endif //OBSTACLE_H

// Creation d'une structure pour les obstacles avec les coordonnées X et Y
typedef struct ObstacleLink {
    int PosX;
    int PosY;
    struct ObstacleLink *next;
    struct ObstacleLink *prev;
}OBSTACLE_LINK;

// Fonctions avec leurs paramètres 

OBSTACLE_LINK* CreateObstacle(OBSTACLE_LINK* obstacle, int X, int Y, int index);
OBSTACLE_LINK* DeleteObstacleAtIndex(OBSTACLE_LINK* obstacle, int index);
OBSTACLE_LINK* RemoveObstacleFromHead(OBSTACLE_LINK *obstacle);
int ObstacleListLength(const OBSTACLE_LINK* obstacle);
void PrintObstacle(const OBSTACLE_LINK* obstacle);
void FreeAll(OBSTACLE_LINK* obstacle);
OBSTACLE_LINK* SpawnObstacle(OBSTACLE_LINK* obstacle);
void MoveObstacle(OBSTACLE_LINK* obstacle);
OBSTACLE_LINK* DeleteOutObstacle(OBSTACLE_LINK* obstacle);
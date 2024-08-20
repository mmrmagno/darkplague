#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject {
public:
    Enemy(Vector3 startPosition);
    void update(Player& player);
    GLuint createEnemyVAO();
};

#endif

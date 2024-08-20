#ifndef PHYSICS_H
#define PHYSICS_H

#include "Player.h"
#include "Enemy.h"

class Physics {
public:
    void update(Player& player, Enemy& enemy);
    bool checkCollision(GameObject& a, GameObject& b);
};

#endif

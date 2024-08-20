#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject {
public:
    void update(Player& player);
};

#endif

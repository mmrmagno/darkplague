#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject {
public:
    Enemy(glm::vec3 startPosition);
    void update(Player& player);
    GLuint createEnemyVAO();

    GLuint getVAO() override;
    int getVertexCount() override;

private:
    GLuint vao;
    int vertexCount;

    void attack(Player& player);  // Declare the attack function
};

#endif

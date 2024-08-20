#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Input.h"

class Player : public GameObject {
public:
    Player();
    void update(Input& input);
    GLuint createPlayerVAO();

    GLuint getVAO() override;
    int getVertexCount() override;

private:
    GLuint vao;
    int vertexCount;
    float movementSpeed;
    bool isDodging;
    int health;
    int stamina;

    void handleMovement(Input& input);
    void handleCombat(Input& input);
    void dodge();
    void jump();
    void attack();
    void parry();
    void useItem();
};

#endif

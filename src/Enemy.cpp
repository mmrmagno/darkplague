#include "Enemy.h"

Enemy::Enemy(Vector3 startPosition) {
    this->position = startPosition;
    this->vao = createEnemyVAO();
    this->vertexCount = 36;  // Assume the enemy model is a cube with 36 vertices
}

void Enemy::update(Player& player) {
    // Basic AI logic: follow the player
    Vector3 direction = player.position - this->position;
    direction.normalize();
    this->position += direction * 0.01f;  // Move towards the player
}

GLuint Enemy::createEnemyVAO() {
    // Set up VAO, VBO, and EBO for enemy
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // Setup VBO and attributes
    return vao;
}

GLuint Enemy::getVAO() {
    return this->vao;
}

int Enemy::getVertexCount() {
    return this->vertexCount;
}

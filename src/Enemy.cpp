#include "Enemy.h"
#include <glm/glm.hpp>

Enemy::Enemy(glm::vec3 startPosition) {
    this->position = startPosition;
    this->vao = createEnemyVAO();
    this->vertexCount = 36;  // Assume the enemy model is a cube with 36 vertices
}

void Enemy::update(Player& player) {
    glm::vec3 direction = player.position - this->position;
    float distance = glm::length(direction);

    if (distance > 0.1f) {
        direction = glm::normalize(direction);
        this->position += direction * 0.05f;  // Move towards the player
    } else {
        attack(player);  // Attack if close to the player
    }
}

void Enemy::attack(Player& player) {
    // Implement attack logic: reduce player's health, etc.
    // Example: player.health -= 10;
}

GLuint Enemy::createEnemyVAO() {
    // Placeholder vertex data for the enemy (a cube)
    float vertices[] = {
        // Positions          // Normals
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        // (Add the remaining vertices for the cube)
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    return vao;  // Ensure we return the VAO
}

GLuint Enemy::getVAO() {
    return this->vao;
}

int Enemy::getVertexCount() {
    return this->vertexCount;
}

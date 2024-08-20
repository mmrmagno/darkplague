#include "Player.h"

Player::Player() {
    // Initialize player VAO, VBO, and other OpenGL-related data
    this->vao = createPlayerVAO();
    this->vertexCount = 36;  // Assume the player model is a cube with 36 vertices
}

void Player::update() {
    // Update player logic (movement, animation, etc.)
}

GLuint Player::createPlayerVAO() {
    // Set up VAO, VBO, and EBO for player
    // This would include loading the model and setting up vertex data
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // Setup VBO and attributes
    return vao;
}

GLuint Player::getVAO() {
    return this->vao;
}

int Player::getVertexCount() {
    return this->vertexCount;
}

#include "Player.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>

Player::Player() {
    this->vao = createPlayerVAO();
    this->vertexCount = 36;  // Assume the player model is a cube with 36 vertices
    this->position = glm::vec3(0.0f, 0.0f, 0.0f);
    this->health = 100;
    this->stamina = 100;
    this->movementSpeed = 0.1f;
    this->isDodging = false;
}

void Player::update(Input& input) {
    handleMovement(input);
    handleCombat(input);
}

void Player::handleMovement(Input& input) {
    // Movement using WASD keys
    if (input.isKeyDown(SDL_SCANCODE_W)) {
        this->position.z -= movementSpeed;
    }
    if (input.isKeyDown(SDL_SCANCODE_S)) {
        this->position.z += movementSpeed;
    }
    if (input.isKeyDown(SDL_SCANCODE_A)) {
        this->position.x -= movementSpeed;
    }
    if (input.isKeyDown(SDL_SCANCODE_D)) {
        this->position.x += movementSpeed;
    }

    // Sprinting using Shift
    if (input.isKeyDown(SDL_SCANCODE_LSHIFT)) {
        this->movementSpeed = 0.2f;  // Increase movement speed when sprinting
    } else {
        this->movementSpeed = 0.1f;  // Normal movement speed
    }

    // Dodging using Spacebar
    if (input.isKeyDown(SDL_SCANCODE_SPACE) && !isDodging) {
        dodge();
    }

    // Jumping using Shift key (tap, not hold)
    if (input.isKeyDown(SDL_SCANCODE_LSHIFT)) {
        jump();
    }

    // Camera controls
    if (input.isMouseMoving()) {
        // Implement camera control logic here
    }
}

void Player::handleCombat(Input& input) {
    // Attack using left mouse button
    if (input.isMouseButtonDown(SDL_BUTTON_LEFT)) {
        attack();
    }

    // Parry using right mouse button
    if (input.isMouseButtonDown(SDL_BUTTON_RIGHT)) {
        parry();
    }

    // Use item with Q
    if (input.isKeyDown(SDL_SCANCODE_Q)) {
        useItem();
    }
}

void Player::dodge() {
    isDodging = true;
    // Implement dodge mechanics
    // Example: temporary invincibility, fast movement, etc.
}

void Player::jump() {
    // Implement jump mechanics
}

void Player::attack() {
    // Implement attack mechanics
    // Example: reduce enemy health, play attack animation, etc.
}

void Player::parry() {
    // Implement parry mechanics
    // Example: reflect attack, stagger enemy, etc.
}

void Player::useItem() {
    // Implement item usage mechanics
    // Example: restore health, stamina, apply effects, etc.
}

GLuint Player::createPlayerVAO() {
    float vertices[] = {
        // Positions          // Normals
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        // (Add remaining vertices for the cube)
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

    return vao;
}

GLuint Player::getVAO() {
    return this->vao;
}

int Player::getVertexCount() {
    return this->vertexCount;
}

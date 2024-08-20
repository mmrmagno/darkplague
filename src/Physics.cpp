#include "Physics.h"

void Physics::update(Player& player, Enemy& enemy) {
    // Handle simple collision detection between the player and the enemy
    if (checkCollision(player, enemy)) {
        // Apply collision response, e.g., reduce health, play sound, etc.
    }
}

bool Physics::checkCollision(GameObject& a, GameObject& b) {
    // Simple AABB collision detection
    return (abs(a.position.x - b.position.x) < (a.size.x + b.size.x) / 2.0f) &&
           (abs(a.position.y - b.position.y) < (a.size.y + b.size.y) / 2.0f) &&
           (abs(a.position.z - b.position.z) < (a.size.z + b.size.z) / 2.0f);
}

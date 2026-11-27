#pragma once

#include "config.hpp"

struct Vec2 {
    float x{0.0f};
    float y{0.0f};
};

struct Orb {
    Vec2 pos{};
    Vec2 vel{};
    Character tier{Character::Gojo};
};

inline void stepOrb(Orb& orb, float gravity, float dt,
                    float leftX, float rightX, float floorY, float bounciness) {
    orb.vel.y += gravity * dt;
    orb.pos.x += orb.vel.x * dt;
    orb.pos.y += orb.vel.y * dt;

    const float radius = getSpec(orb.tier).radius;
    if (orb.pos.y + radius > floorY) {
        orb.pos.y = floorY - radius;
        if (orb.vel.y > 0.0f) {
            orb.vel.y = -orb.vel.y * bounciness;
        }
    }
    if(orb.pos.x - radius < leftX){
        orb.pos.x = leftX + radius;
        if(orb.vel.x < 0.0f) orb.vel.x = -orb.vel.x * bounciness;
    }
    if(orb.pos.x + radius > rightX){
        orb.pos.x = rightX - radius;
        if(orb.vel.x > 0.0f) orb.vel.x = -orb.vel.x * bounciness;
    }
}
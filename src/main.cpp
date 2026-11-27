#include "raylib.h"
#include "config.hpp"
#include "physics.hpp"
#include <vector>
#include <algorithm>

static_assert(canMerge(Character::Gojo, Character::Gojo));
static_assert(!canMerge(Character::Zeno, Character::Zeno));
static_assert(nextTier(Character::Gojo) == Character::Luffy);
static_assert(getSpec(Character::Zeno).name == "Zeno");

int main() {
    constexpr int kScreenWidth = 800;
    constexpr int kScreenHeight = 700;
    constexpr float kBoxLeft = 200.0f;
    constexpr float kBoxRight = 600.0f;
    constexpr float kFloorY = 650.0f;
    constexpr float kDropY = 90.0f;

    InitWindow(kScreenWidth, kScreenHeight, "Anime Suika");
    SetTargetFPS(60);

    std::vector<Orb> orbs;

    while (!WindowShouldClose()) {
        const float dt = GetFrameTime();

        const float dropRadius = getSpec(Character::Gojo).radius;
        const float dropX = std::clamp(GetMousePosition().x, kBoxLeft + dropRadius, kBoxRight - dropRadius);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            orbs.push_back(Orb{.pos{dropX, kDropY}, .tier = Character::Gojo});
        }

        for (Orb& orb : orbs) {
            stepOrb(orb, 980.0f, dt, kBoxLeft, kBoxRight, kFloorY, 0.5f);
        }

        BeginDrawing();
        ClearBackground(Color{18, 18, 28, 255});

       
        DrawLine(static_cast<int>(kBoxLeft), static_cast<int>(kFloorY),
                 static_cast<int>(kBoxRight), static_cast<int>(kFloorY), WHITE);

        
        const CharacterSpec& dropSpec = getSpec(Character::Gojo);
        const Color previewColor{dropSpec.accent.r, dropSpec.accent.g, dropSpec.accent.b, 120};
        DrawCircleV(Vector2{dropX, kDropY}, dropSpec.radius, previewColor);

        
        for (const Orb& orb : orbs) {
            const CharacterSpec& spec = getSpec(orb.tier);
            const Color orbColor{spec.accent.r, spec.accent.g, spec.accent.b, 255};
            DrawCircleV(Vector2{orb.pos.x, orb.pos.y}, spec.radius, orbColor);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
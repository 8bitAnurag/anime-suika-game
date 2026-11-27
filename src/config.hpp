#pragma once

#include <cstdint>
#include <array>
#include <cstddef>
#include <string_view>

struct RgbColor {
    std::uint8_t r{0};
    std::uint8_t g{0};
    std::uint8_t b{0};
};


enum class Character : std::uint8_t{
    Gojo = 0,
    Luffy,
    Uchiha,
    Naruto,
    Aizen,
    Ichigo,
    Vegeta,
    Saitama,
    Goku,
    Zeno
};


constexpr bool canMerge(Character a, Character b) {
    return a==b && a < Character::Zeno;
}

inline constexpr std::size_t kTierCount = 10;

struct CharacterSpec {

    std::string_view name{};
    float radius{};
    int mergePoints{};
    RgbColor accent{};

};

constexpr std::size_t toIndex(Character c) {

    return static_cast<std::size_t>(c);

}

constexpr Character nextTier(Character c) {

    if(c < Character::Zeno){
        std::size_t nextCharVal = toIndex(c) + 1;
        return static_cast<Character>(nextCharVal);
    }
    return c;
}

inline constexpr std::array<CharacterSpec, kTierCount> kCharacterSpecs{{
    {"Gojo",    16.0f,  1, {120, 225, 240}}, // Six Eyes icy cyan
    {"Luffy",   22.0f,  3, {230,  55,  55}}, // Straw Hat crimson red
    {"Uchiha",  29.0f,  6, {150,  60, 220}}, // Susanoo violet
    {"Naruto",  37.0f, 10, {250, 145,  35}}, // Kurama / jumpsuit orange
    {"Aizen",   46.0f, 15, {130, 165, 245}}, // Hogyoku cool indigo-blue
    {"Ichigo",  56.0f, 21, {220,  45,  95}}, // Bankai / Getsuga crimson
    {"Vegeta",  67.0f, 28, { 45,  95, 235}}, // Saiyan royal blue
    {"Saitama", 79.0f, 36, {250, 215,  45}}, // Hero suit bright yellow
    {"Goku",    92.0f, 45, {215, 225, 245}}, // Ultra Instinct silver-white
    {"Zeno",   106.0f, 55, {235,  80, 190}}, // Omni-King cosmic magenta
}};

constexpr const CharacterSpec& getSpec(Character c) {

    return kCharacterSpecs.at(toIndex(c));
    
}
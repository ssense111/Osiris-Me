#pragma once

#include <array>
#include <string>
#include <vector>
#include "../SDK/WeaponId.h"

enum class FrameStage;

namespace ModelChanger
{
    void weaponModel(FrameStage stage) noexcept;
    struct weapon_name
    {
        constexpr weapon_name(const int definition_index, const char* name) :
            definition_index(definition_index),
            name(name)
        {}

        int definition_index = 0;
        const char* name = nullptr;
    };
    constexpr weapon_name weapon_names[]{
        {42, "Knife"},
        {0, "Glove"},
        {7, "AK-47"},
        {8, "AUG"},
        {9, "AWP"},
        {63, "CZ75 Auto"},
        {1, "Desert Eagle"},
        {2, "Dual Berettas"},
        {10, "FAMAS"},
        {3, "Five-SeveN"},
        {11, "G3SG1"},
        {13, "Galil AR"},
        {4, "Glock-18"},
        {14, "M249"},
        {60, "M4A1-S"},
        {16, "M4A4"},
        {17, "MAC-10"},
        {27, "MAG-7"},
        {23, "MP5-SD"},
        {33, "MP7"},
        {34, "MP9"},
        {28, "Negev"},
        {35, "Nova"},
        {32, "P2000"},
        {36, "P250"},
        {19, "P90"},
        {26, "PP-Bizon"},
        {64, "R8 Revolver"},
        {29, "Sawed-Off"},
        {38, "SCAR-20"},
        {40, "SSG 08"},
        {39, "SG 553"},
        {30, "Tec-9"},
        {24, "UMP-45"},
        {61, "USP-S"},
        {25, "XM1014"},
        {31, "Zeus x27"},
        {43, "Flashbang"},
        {44, "HE Grenade"},
        {45, "Smoke Grenade"},
        {46, "Molotov"},
        {47, "Decoy"},
        {48, "Incendiary Grenade"},
        {49, "C4"},
    };
    static constexpr auto is_knife(WeaponId id)
    {
        return (id >= WeaponId::Bayonet && id < WeaponId::GloveStuddedBloodhound) || id == WeaponId::KnifeT || id == WeaponId::Knife;
    }
}

struct modelchanger_setting
{
	bool mdlenabled = false;
	bool vtfenabled = false;
	char modelthatyouselected[255] = "";
	char skinthatyouselected[255] = "";
};

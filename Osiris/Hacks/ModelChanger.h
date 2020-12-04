#pragma once

#include <array>
#include <string>
#include <vector>

enum class FrameStage;

namespace ModelChanger
{
    void weaponModel(FrameStage stage) noexcept;
}

struct modelchanger_setting
{
	bool mdlenabled = false;
	char modelthatyouselected[999] = "";
};

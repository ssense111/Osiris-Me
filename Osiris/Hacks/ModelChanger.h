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
	bool vtfenabled = false;
	char modelthatyouselected[255] = "";
	char skinthatyouselected[255] = "";
};

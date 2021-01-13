#include "ModelChanger.h"
#include "../SDK/Entity.h"
#include "../SDK/FrameStage.h"
#include "../SDK/ModelInfo.h"
#include "../SDK/NetworkStringTable.h"

void ModelChanger::weaponModel(FrameStage stage) noexcept
{
    if (stage != FrameStage::RENDER_START && stage != FrameStage::RENDER_END)
        return;

    if (stage == FrameStage::RENDER_START) {
        if (const auto modelprecache = interfaces->networkStringTableContainer->findTable("modelprecache")) {
            const auto view_model_handle = localPlayer->viewModel();
            if (localPlayer->isAlive()) {
                const auto activeWeapon = localPlayer->getActiveWeapon();
                const auto itemIndex = activeWeapon->itemDefinitionIndex();
                const auto itemIndex2 = activeWeapon->itemDefinitionIndex2();
                int WEAPON_KNIFE = 42;
                auto& selected_entry = config->modelChanger[ModelChanger::is_knife(itemIndex2) ? WEAPON_KNIFE : itemIndex];
                if (itemIndex && ((ModelChanger::is_knife(itemIndex2) ? WEAPON_KNIFE : itemIndex) || (itemIndex < 65)) && selected_entry.mdlenabled) {
                    modelprecache->addString(false, selected_entry.modelthatyouselected);
                    activeWeapon->setModelIndex(interfaces->modelInfo->getModelIndex(selected_entry.modelthatyouselected));
                    if (view_model_handle) {
                        const auto view_model = interfaces->entityList->getEntityFromHandle(localPlayer->viewModel());
                        int index = interfaces->modelInfo->getModelIndex(selected_entry.modelthatyouselected);
                        if (view_model->modelIndex() != index)
                            view_model->setModelIndex(index);
                    }
                }
            }
        }
    }
}

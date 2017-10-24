/*
 * Copyright (C) 2016~2016 by CSSlayer
 * wengxt@gmail.com
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; see the file COPYING. If not,
 * see <http://www.gnu.org/licenses/>.
 */

#include "globalconfig.h"
#include "fcitx-config/configuration.h"

namespace fcitx {

namespace impl {
FCITX_CONFIGURATION(
    GlobalConfig,
    fcitx::Option<KeyList> triggerKeys{
        this,
        "Hotkey/TriggerKeys",
        "Trigger Input Method",
        {Key("Control+space"), Key("Zenkaku_Hankaku"), Key("Hangul")}};
    fcitx::Option<KeyList> altTriggerKeys{
        this,
        "Hotkey/AltTriggerKeys",
        "Trigger Input Method Only after using it to deactivate",
        {Key("Shift_L")}};
    fcitx::Option<KeyList> enumerateForwardKeys{
        this,
        "Hotkey/EnumerateForwardKeys",
        "Enumerate Input Method Forward",
        {Key("Control+Shift_R")}};
    fcitx::Option<KeyList> enumerateBackwardKeys{
        this,
        "Hotkey/EnumerateBackwardKeys",
        "Enumerate Input Method Backward",
        {Key("Control+Shift_L")}};
    fcitx::Option<KeyList> enumerateGroupForwardKeys{
        this,
        "Hotkey/EnumerateGroupForwardKeys",
        "Enumerate Input Method Group Forward",
        {Key("Super+space")}};
    fcitx::Option<KeyList> enumerateGroupBackwardKeys{
        this,
        "Hotkey/EnumerateGroupBackwardKeys",
        "Enumerate Input Method Group Backward",
        {Key("Super+Shift+space")}};
    fcitx::Option<KeyList> activateKeys{this,
                                        "Hotkey/ActivateKeys",
                                        "ActivateKeys",
                                        {
                                            Key("Hangul_Hanja"),
                                        }};
    fcitx::Option<KeyList> deactivateKeys{this,
                                          "Hotkey/DeactivateKeys",
                                          "DeactivateKeys",
                                          {Key("Hangul_Romaja")}};

    fcitx::Option<bool> activeByDefault{this, "Behavior/ActiveByDefault",
                                        "Active By Default"};
    fcitx::Option<bool> showInputMethodInformation{
        this, "Behavior/ShowInputMethodInformation",
        "ShowInputMethodInformation when switch input method", true};
    fcitx::Option<KeyList> defaultPrevPage{
        this, "Hotkey/PrevPage", "Default Previous page", {Key("Up")}};
    fcitx::Option<KeyList> defaultNextPage{
        this, "Hotkey/NextPage", "Default Next page", {Key("Down")}};
    fcitx::Option<int, IntConstrain> defaultPageSize{
        this, "Behavior/DefaultPageSize", "Default page size", 5,
        IntConstrain(1, 10)};);
}

class GlobalConfigPrivate : public impl::GlobalConfig {};

GlobalConfig::GlobalConfig() : d_ptr(std::make_unique<GlobalConfigPrivate>()) {}

GlobalConfig::~GlobalConfig() {}

void GlobalConfig::load(const RawConfig &config) {
    FCITX_D();
    d->load(config);
}

const KeyList &GlobalConfig::triggerKeys() const {
    FCITX_D();
    return d->triggerKeys.value();
}

const KeyList &GlobalConfig::activateKeys() const {
    FCITX_D();
    return d->activateKeys.value();
}

const KeyList &GlobalConfig::deactivateKeys() const {
    FCITX_D();
    return d->deactivateKeys.value();
}

const KeyList &GlobalConfig::enumerateForwardKeys() const {
    FCITX_D();
    return d->enumerateForwardKeys.value();
}

const KeyList &GlobalConfig::enumerateBackwardKeys() const {
    FCITX_D();
    return d->enumerateBackwardKeys.value();
}

const KeyList &GlobalConfig::enumerateGroupForwardKeys() const {
    FCITX_D();
    return *d->enumerateGroupForwardKeys;
}

const KeyList &GlobalConfig::enumerateGroupBackwardKeys() const {
    FCITX_D();
    return *d->enumerateGroupBackwardKeys;
}

bool GlobalConfig::activeByDefault() const {
    FCITX_D();
    return d->activeByDefault.value();
}

bool GlobalConfig::showInputMethodInformation() const {
    FCITX_D();
    return d->showInputMethodInformation.value();
}

const KeyList &GlobalConfig::defaultPrevPage() const {
    FCITX_D();
    return d->defaultPrevPage.value();
}

const KeyList &GlobalConfig::defaultNextPage() const {
    FCITX_D();
    return d->defaultNextPage.value();
}

int GlobalConfig::defaultPageSize() const {
    FCITX_D();
    return d->defaultPageSize.value();
}
}

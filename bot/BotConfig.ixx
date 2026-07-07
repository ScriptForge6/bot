// Copyright 2026 Scriptforge
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file BotConfig.ixx
 * @brief 定义了 BotConfig 模块，用于设置全局配置。
 * @author Scriptforge
 * @date 2026/7/8
 */
export module BotConfig;

import Scriptforge.Pch;
import Scriptforge.LanguageCode;

export namespace BotConfig {
    inline constexpr std::string_view LogFileName = "bot.log";
    inline constexpr std::string_view LangDir = "./lang";
    inline constexpr auto DefaultLang = Scriptforge::LanguageCode::Language::English;
}

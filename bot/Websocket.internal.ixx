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
 * @file Websocket.internal.ixx
 * @brief 定义了 Websocket.internal 模块，包含默认值。
 * @author Scriptforge
 * @date 2026/7/1
 */

module;

#include<cstdint>

export module Websocket.internal;

import Scriptforge.Pch;

namespace Websocket {
	export namespace internal {
		inline constexpr std::string_view m_defaultAddress{ "127.0.0.1" };
		inline constexpr std::uint16_t m_defaultPort{ 3001 };
		inline constexpr std::optional<std::string> m_defaultToken{ std::nullopt };
	}
}
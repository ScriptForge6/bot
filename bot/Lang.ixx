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
 * @file Lang.ixx
 * @brief 定义了 Lang 模块，包含一个全局指针 `langPtr`，用于语言处理。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module Lang;
import Scriptforge.Local;

namespace Lang {
	export Scriptforge::Local::Lang* langPtr{ nullptr };
}
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
 * @file FileOstream.ixx
 * @brief 定义了 FileOstream 模块，包含一个全局指针 `fileStreamPtr`，用于文件输出流。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module FileOstream;

import Scriptforge.Pch;

namespace FileOstream {
	export std::ofstream* fileStreamPtr{ nullptr };
}
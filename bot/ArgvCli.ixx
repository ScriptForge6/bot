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
 * @file ArgvCli.ixx
 * @brief 定义了 ArgvCli 模块，包含一个全局指针 `argvCliPtr`，用于处理命令行参数。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module ArgvCli;
import Scriptforge.Argv;

namespace Argv {
	export Scriptforge::Argv::ArgvCli<Scriptforge::Argv::Hash::FNV_1a_32>* argvCliPtr{ nullptr };
}
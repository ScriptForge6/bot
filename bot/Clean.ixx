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
 * @file Clean.ixx
 * @brief 定义了 Clean 模块，用于清理。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module Clean;

import ArgvCli;
import FileOstream;
import Lang;

namespace Clean {
	export class CleanGuard {
	public:
		CleanGuard() = default;
		~CleanGuard();

	};
	export void clean() noexcept;
}

namespace Clean {
	void clean() noexcept {
		Argv::argvCliPtr = nullptr;
		FileOstream::fileStreamPtr = nullptr;
		Lang::langPtr = nullptr;
	}

	CleanGuard::~CleanGuard() {
		clean();
	}
}
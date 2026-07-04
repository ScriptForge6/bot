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
 * @file Log.ixx
 * @brief 定义了 Log 模块，包含一个日志记录函数模板。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module Log;

import Scriptforge.Pch;

namespace Log {
    export 
        template <typename... Args>
    void log(std::ostream& out1, std::ostream& out2, Args&&... args) {
        std::ostringstream buf;
        (buf << ... << std::forward<Args>(args));
        const std::string& log_text = buf.str();

        out1 << log_text << '\n';
        out2 << log_text << '\n';
    }
}

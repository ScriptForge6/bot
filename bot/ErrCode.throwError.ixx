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
 * @file ErrCode.throwError.ixx
 * @brief 定义了 ErrCode.throwError 模块，包含一个用于抛出错误的函数模板。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module ErrCode.throwError;
import Scriptforge.Msg;
import Scriptforge.LanguageCode;
import Scriptforge.Local;
import Scriptforge.Err;
import Scriptforge.Pch;
import ErrCode;

namespace ErrCode {
    export
        [[noreturn]] void throwError(
            ErrCode code,
            const std::string& func,
            const Scriptforge::Local::Lang& lang,
            Scriptforge::Msg::InformationLevel level = Scriptforge::Msg::InformationLevel::Error
        );
    export
        template <typename... Args>
    [[noreturn]] void throwError(
        ErrCode code,
        const std::string& func,
        const Scriptforge::Local::Lang& lang,
        Scriptforge::Msg::InformationLevel level = Scriptforge::Msg::InformationLevel::Error,
        Args&&... args
    );
}

namespace ErrCode {
    
    void throwError(
        ErrCode code,
        const std::string& func,
        const Scriptforge::Local::Lang& lang,
        Scriptforge::Msg::InformationLevel level
    ) {
        std::string baseStr = lang.atJ<std::string>("Error").at(to_string(code));
        throw Scriptforge::Err::BasicError<ErrCode> {
            code,
            func + ": " + baseStr,
            level
        };
    }

    template <typename... Args>
    void throwError(
        ErrCode code,
        const std::string& func,
        const Scriptforge::Local::Lang& lang,
        Scriptforge::Msg::InformationLevel level,
        Args&&... args
    ) {
        std::string baseStr = lang.atJ<std::string>("Error").format<std::string>(to_string(code), std::forward<Args>(args)...);
        throw Scriptforge::Err::BasicError<ErrCode> {
            code,
            func + ": " + baseStr,
			level
		};
    }

}
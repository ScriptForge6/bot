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
 * @file ErrCode.ixx
 * @brief 定义了 ErrCode 模块，包含错误码枚举和相关函数。
 * @author Scriptforge
 * @date 2026/7/1
 */

export module ErrCode;

import Scriptforge.Pch;

namespace ErrCode {
	export enum class ErrCode {
		UnknownError = 101,
		MissingArgument = 102,
		InvalidArgument = 103,
		DirectoryNotFound = 104,
		FileNotFound = 105,
		InvalidFile = 106
	};
	export std::string to_string(ErrCode code) {
		return std::to_string(static_cast<int>(code));
	}

	export std::ostream& operator<<(std::ostream& os, const ErrCode& errCode) {
		os << to_string(errCode);
		return os;
	}
}
export
template<>
struct std::formatter<ErrCode::ErrCode>
{
	constexpr auto parse(std::format_parse_context& ctx) {
		return ctx.begin();
	}
	template<typename FmtCtx>
	auto format(const ErrCode::ErrCode& code, FmtCtx& ctx) const {
		return std::format_to(ctx.out(), "{}", ErrCode::to_string(code));
	}
};
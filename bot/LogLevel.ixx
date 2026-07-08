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
 * @file LogLevel.ixx
 * @brief 定义了 Loglevel 模块，用于控制输出等级。
 * @author Scriptforge
 * @date 2026/7/8
 */

module;

#include<websocketpp\logger\levels.hpp>

export module LogLevel;

import Scriptforge.Msg;
import Scriptforge.Pch;

namespace Log {
	using namespace std::string_literals;
	export std::map<
		std::string,
		std::tuple<Scriptforge::Msg::InformationLevel,
			websocketpp::log::level,//alevel
			websocketpp::log::level//elevel
		>
		> 
		logLevels {
		{
			"Debug"s,
			std::make_tuple(
				Scriptforge::Msg::InformationLevel::Debug,
				websocketpp::log::alevel::all,
				websocketpp::log::elevel::all
			)
		},
		{
			"Info"s,
			std::make_tuple(
				Scriptforge::Msg::InformationLevel::Info,
				websocketpp::log::alevel::all,
				websocketpp::log::elevel::info
			)
		},
		{
			"Warning"s,
			std::make_tuple(
				Scriptforge::Msg::InformationLevel::Warning,
				websocketpp::log::alevel::disconnect |
					websocketpp::log::alevel::control |
					websocketpp::log::alevel::fail |
					websocketpp::log::alevel::http,
				websocketpp::log::elevel::warn |
					websocketpp::log::elevel::rerror |
					websocketpp::log::elevel::fatal
			)
		},
		{
			"Error",
			std::make_tuple(
				Scriptforge::Msg::InformationLevel::Error,
				websocketpp::log::alevel::fail |
					websocketpp::log::alevel::disconnect,
				websocketpp::log::elevel::rerror |
					websocketpp::log::elevel::fatal
			)
		}
	};
	export std::tuple<
		Scriptforge::Msg::InformationLevel,
		websocketpp::log::level,//alevel
		websocketpp::log::level//elevel
		>
		logLevel = 
#ifdef _DEBUG
		logLevels.at("Debug")
#else
		logLevels.at("Info")
#endif
		;
}
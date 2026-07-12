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
 * @file GetJson.ixx
 * @brief 定义了 GetJson 模块，包含 Get 类，用于获取 confg.json 的内容。
 * @author Scriptforge
 * @date 2026/7/1
 */

module;

#include<cstdint>

export module GetJson;

import Scriptforge.Msg;
import Scriptforge.Pch;

import nlohmann.json;

import ErrCode;
import ErrCode.throwError;
import Lang;
import Websocket.internal;

namespace GetJson {
	namespace fs = std::filesystem;
	using json = nlohmann::json;
	fs::path file = "config.json";
	export class Get {
	public:
		Get();
		Get(Get&) = delete;
		Get& operator=(const Get&) = delete;
		std::string getAddress() const;
		std::uint16_t getPort() const;
		std::optional<std::string> getToken() const;
	private:
		void loadFile();
		void fileIsLegal();
		json m_j;
		bool have{ false };
	};
}

namespace GetJson {
	Get::Get() {
		fileIsLegal();
		loadFile();
		
	}

	std::string Get::getAddress() const {
		return std::string(m_j.value("address", Websocket::internal::m_defaultAddress));
	}
	
	std::uint16_t Get::getPort() const {
		return std::uint16_t(m_j.value("port", Websocket::internal::m_defaultPort));
	}


	std::optional<std::string> Get::getToken() const {
		if (m_j.contains("token")) {
			return std::string(m_j.at("token"));
		}
		return Websocket::internal::m_defaultToken;
	}

	void Get::loadFile() {
		if (have) {
			std::ifstream jsoninput(file.string());
			if (!jsoninput.is_open()) {
				auto filestr = file.string();
				ErrCode::throwError(ErrCode::ErrCode::FileNotFound, __func__, *Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, filestr);
			}
			try {
				jsoninput >> m_j;
			}
			catch (const json::parse_error&) {
				auto filestr = file.string();
				ErrCode::throwError(ErrCode::ErrCode::InvalidFile, __func__, *Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, filestr);
			}
			jsoninput.close();
		}
		
	}

	void Get::fileIsLegal() {
		if (fs::exists(file) && fs::is_regular_file(file)) {
			have = true;
		}
	}
}
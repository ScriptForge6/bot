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
 * @file Websocket.ixx
 * @brief 定义了 Websocket 模块，包含一个用于启动 WebSocket 连接的函数。
 * @author Scriptforge
 * @date 2026/7/1
 */

module;

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/client.hpp>

export module Websocket;

import Scriptforge.Pch;

namespace Websocket {
	using wsClient = websocketpp::client<websocketpp::config::asio>;
	using wsMsgPtr = wsClient::message_ptr;
	using wsConnHdl = websocketpp::connection_hdl;

	class WsClient {
	public:
		WsClient();
		WsClient(std::string_view address = internal::m_defaultAddress, size_t port = internal::m_defaultPort, std::optional<std::string_view> proxy = internal::m_defaultProxy);
		WsClient(WsClient&) = delete;
	private:

	};
	namespace internal {
		WSserver server;
		std::string m_defaultAddress{ "127.0.0.1" };
		size_t m_defaultPort{ 3001 };
		std::optional<std::string> m_defaultProxy{ std::nullopt };
		std::string m_token;
		std::string m_buffer;
	}
	export void start(std::string_view address = internal::m_defaultAddress, size_t port = internal::m_defaultPort, std::optional<std::string_view> proxy = internal::m_defaultProxy);
}

namespace Websocket {
	export void start(std::string_view address, size_t port, std::optional<std::string_view> proxy) {
		
	}
}
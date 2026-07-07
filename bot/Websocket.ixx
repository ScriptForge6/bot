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
#include <websocketpp/server.hpp>
#include <asio.hpp>

export module Websocket;

import Scriptforge.Msg;
import Scriptforge.Pch;

import Lang;
import Log;
import LogLevel;

namespace Websocket {
	using ws_config = websocketpp::config::asio;
	using ws_server = websocketpp::server<ws_config>;
	using ws_connHdl = websocketpp::connection_hdl;

	namespace internal {
		inline constexpr std::string_view m_defaultAddress{ "127.0.0.1" };
		inline constexpr std::uint16_t m_defaultPort{ 3001 };
		inline constexpr std::optional<std::string> m_defaultProxy{ std::nullopt };
		inline constexpr std::optional<std::string> m_defaultToken{ std::nullopt };
	}
	export class WsServer {
	public:
		WsServer(
			std::string_view address = internal::m_defaultAddress, 
			std::uint16_t port = internal::m_defaultPort, 
			std::optional<std::string> token = internal::m_defaultToken, 
			websocketpp::log::level alevel = std::get<1>(Log::logLevel), 
			websocketpp::log::level elevel = std::get<2>(Log::logLevel), 
			std::optional<std::string> proxy = internal::m_defaultProxy
		);
		WsServer(WsServer&) = delete;
		void setAddress(const std::string& address);
		void setAddress(std::string&& address) noexcept;
		void setPort(const std::uint16_t& port) noexcept;
		void setPort(std::uint16_t&& port) noexcept;
		void setToken(const std::optional<std::string>& token);
		void setToken(std::optional<std::string>&& token) noexcept;
		void setProxy(const std::optional<std::string>& proxy);
		void setProxy(std::optional<std::string>&& proxy) noexcept;
		
	private:
		ws_server m_server;
		std::string m_address;
		std::uint16_t m_port;
		std::optional<std::string> m_token;
		std::optional<std::string> m_proxy;
	};
	
}

namespace Websocket {
	WsServer::WsServer(std::string_view address, std::uint16_t port, std::optional<std::string> token, websocketpp::log::level alevel, websocketpp::log::level elevel, std::optional<std::string> proxy)
		: m_address(address), m_port(port), m_token(token), m_proxy(proxy) {
		using namespace std::string_literals;
		auto printToken{ m_token.value_or("none") };
		auto printProxy{ m_proxy.value_or("none") };
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("CreatingWsServer"s, m_address, m_port, printToken, printProxy), Scriptforge::Msg::InformationLevel::Debug));
	}

	void WsServer::setAddress(const std::string& address) {
		m_address = address;
	}
	void WsServer::setAddress(std::string&& address) noexcept {
		m_address = std::move(address);
	}

	void WsServer::setPort(const std::uint16_t& port) noexcept {
		m_port = port;
	}
	void WsServer::setPort(std::uint16_t&& port) noexcept {
		m_port = std::move(port);
	}

	void WsServer::setToken(const std::optional<std::string>& token) {
		m_token = token;
	}
	void WsServer::setToken(std::optional<std::string>&& token) noexcept{
		m_token = std::move(token);
	}

	void WsServer::setProxy(const std::optional<std::string>& proxy) {
		m_proxy = proxy;
	}
	void WsServer::setProxy(std::optional<std::string>&& proxy) noexcept {
		m_proxy = std::move(proxy);
	}
}
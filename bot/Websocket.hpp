
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
 * @brief 定义了 Websocket 模块，包含一个用于启动 WebSocket 连接的类。
 * @author Scriptforge
 * @date 2026/7/1
 */

#if 0
module;

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>


export module Websocket;
#endif

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

import Scriptforge.Msg;
import Scriptforge.Pch;

import Lang;
import Log;
import LogLevel;
import Websocket.internal;

namespace Websocket {
	using ws_config = websocketpp::config::asio;
	using ws_server = websocketpp::server<ws_config>;
	using ws_connHdl = websocketpp::connection_hdl;
	using namespace std::string_literals;

	namespace internal {
		constexpr std::string_view AUTH_SCHEME = "Bearer ";
		constexpr size_t AUTH_SCHEME_LEN = AUTH_SCHEME.size();
		bool validateAuth(ws_server* server, ws_connHdl hdl, const std::optional<std::string>& token);
		/*void handleHttp(ws_server* server, ws_connHdl hdl, std::optional<std::string> token);*/
		std::string trim(const std::string& s);
	}

	/*export*/ class WsServer {
	public:
		WsServer(
			std::string_view address = internal::m_defaultAddress,
			std::uint16_t port = internal::m_defaultPort,
			std::optional<std::string> token = internal::m_defaultToken,
			websocketpp::log::level alevel = std::get<1>(Log::logLevel),
			websocketpp::log::level elevel = std::get<2>(Log::logLevel)
		);
		WsServer(WsServer&) = delete;
		WsServer& operator=(const WsServer&) = delete;
		void setAddress(const std::string& address);
		void setAddress(std::string&& address);
		void setPort(const std::uint16_t& port);
		void setPort(std::uint16_t&& port);
		void setToken(const std::optional<std::string>& token);
		void setToken(std::optional<std::string>&& token);
		ws_server& getServer();
		const std::string& getAddress() const;
		const std::uint16_t& getPort() const;
		const std::optional<std::string>& getToken() const;
		void init();
		void start();
	private:
		ws_server m_server;
		std::string m_address;
		std::uint16_t m_port;
		std::optional<std::string> m_token;
		websocketpp::log::level m_alevel;
		websocketpp::log::level m_elevel;
		asio::io_context m_ioContext;
	};

}

namespace Websocket {
	WsServer::WsServer(std::string_view address, std::uint16_t port, std::optional<std::string> token, websocketpp::log::level alevel, websocketpp::log::level elevel)
		: m_address(address), m_port(port), m_token(token), m_alevel(alevel), m_elevel(elevel) {

		auto printToken{ m_token.value_or("none") };
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("creatingWsServer"s, m_address, m_port, printToken), Scriptforge::Msg::InformationLevel::Debug));
	}

	void WsServer::setAddress(const std::string& address) {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("setAddress"s, address), Scriptforge::Msg::InformationLevel::Debug));
		m_address = address;
	}
	void WsServer::setAddress(std::string&& address) {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("setAddress"s, address), Scriptforge::Msg::InformationLevel::Debug));
		m_address = std::move(address);
	}

	void WsServer::setPort(const std::uint16_t& port) {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("setPort"s, port), Scriptforge::Msg::InformationLevel::Debug));
		m_port = port;
	}
	void WsServer::setPort(std::uint16_t&& port) {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("setPort"s, port), Scriptforge::Msg::InformationLevel::Debug));
		m_port = std::move(port);
	}

	void WsServer::setToken(const std::optional<std::string>& token) {
		auto printToken{ token.value_or("none") };
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("setToken"s, printToken), Scriptforge::Msg::InformationLevel::Debug));
		m_token = token;
	}
	void WsServer::setToken(std::optional<std::string>&& token) {
		auto printToken{ token.value_or("none") };
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("setToken"s, printToken), Scriptforge::Msg::InformationLevel::Debug));
		m_token = std::move(token);
	}

	ws_server& WsServer::getServer() {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).at("getServer"s), Scriptforge::Msg::InformationLevel::Debug));
		return m_server;
	}
	const std::string& WsServer::getAddress() const {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("getAddress"s, m_address), Scriptforge::Msg::InformationLevel::Debug));
		return m_address;
	}
	const std::uint16_t& WsServer::getPort() const {
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("getPort"s, m_port), Scriptforge::Msg::InformationLevel::Debug));
		return m_port;
	}
	const std::optional<std::string>& WsServer::getToken() const {
		auto printToken{ m_token.value_or("none") };
		Log::logMessage(Scriptforge::Msg::Message(Lang::langPtr->atJ("Debug"s).format("getToken"s, printToken), Scriptforge::Msg::InformationLevel::Debug));
		return m_token;
	}

	void WsServer::init() {
		m_server.set_access_channels(std::get<1>(Log::logLevel));
		m_server.set_error_channels(std::get<2>(Log::logLevel));

		m_server.init_asio(&m_ioContext);

		/*m_server.set_http_handler([&](ws_connHdl hdl) {
			internal::handleHttp(&m_server, hdl, m_token);
			});*/
		m_server.set_validate_handler([this](ws_connHdl hdl) -> bool {
			return internal::validateAuth(&m_server, hdl, m_token);
			});

	}

	void WsServer::start() {
		m_server.listen(m_port);
		m_server.start_accept();
		Log::logMessage(Scriptforge::Msg::Message("[Server] OneBot WS service listen on 0.0.0.0:", Scriptforge::Msg::InformationLevel::Info));
		// 阻塞运行asio异步事件循环
		m_ioContext.run();
	}

	std::string internal::trim(const std::string& s) {
		auto start = s.begin();
		while (start != s.end() && std::isspace(static_cast<unsigned char>(*start)))
			++start;
		auto end = s.rbegin();
		while (end != s.rend() && std::isspace(static_cast<unsigned char>(*end)))
			++end;
		return std::string(start, end.base());
	}
#if 0
	void internal::handleHttp(ws_server* server, ws_connHdl hdl, std::optional<std::string> token) {
		auto conn = server->get_con_from_hdl(hdl);

		// 场景1：服务端未配置Token鉴权，直接放行升级WS
		if (!token.has_value()) {
			conn->set_status(websocketpp::http::status_code::ok);
			return;
		}

		// 场景2：开启Token鉴权，完整校验流程
		std::string authRaw = conn->get_request_header("Authorization");
		std::string authHeader = trim(authRaw);

		// 无鉴权头
		if (authHeader.empty()) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->set_body("Missing Authorization header");
			return;
		}

		// 长度不足，不可能是合法Bearer
		if (authHeader.size() < AUTH_SCHEME_LEN) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->set_body("Invalid Authorization format, use Bearer <token>");
			return;
		}

		// 校验Bearer前缀
		if (authHeader.substr(0, AUTH_SCHEME_LEN) != std::string(AUTH_SCHEME)) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->set_body("Unsupported auth scheme, only Bearer allowed");
			return;
		}

		// 提取并清理客户端token
		std::string clientToken = trim(authHeader.substr(AUTH_SCHEME_LEN));
		if (clientToken != token.value()) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->set_body("Token verification failed, mismatch");
			return;
		}

		// 全部校验通过，执行WebSocket升级
		conn->set_status(websocketpp::http::status_code::ok);
	}
#endif
	bool internal::validateAuth(ws_server* server, ws_connHdl hdl, const std::optional<std::string>& token) {
		auto conn = server->get_con_from_hdl(hdl);

		// 无Token配置，直接放行
		if (!token.has_value()) {
			return true;
		}

		std::string authRaw = conn->get_request_header("Authorization");
		std::string authHeader = trim(authRaw);

		// 缺失头
		if (authHeader.empty()) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->append_header("Connection", "close");
			conn->set_body("Missing Authorization: Bearer <token>");
			return false;
		}

		// 前缀长度不足
		if (authHeader.size() < AUTH_SCHEME_LEN) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->append_header("Connection", "close");
			conn->set_body("Invalid Bearer format");
			return false;
		}

		// 校验Bearer前缀
		if (authHeader.substr(0, AUTH_SCHEME_LEN) != std::string(AUTH_SCHEME)) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->append_header("Connection", "close");
			conn->set_body("Only Bearer auth supported");
			return false;
		}

		// 比对Token
		std::string clientToken = trim(authHeader.substr(AUTH_SCHEME_LEN));
		if (clientToken != token.value()) {
			conn->set_status(websocketpp::http::status_code::unauthorized);
			conn->append_header("WWW-Authenticate", "Bearer");
			conn->append_header("Connection", "close");
			conn->set_body("Token mismatch, access denied");
			return false;
		}

		// 全部校验通过
		return true;
	}
}
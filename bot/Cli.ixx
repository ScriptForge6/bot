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
 * @file Cli.ixx
 * @brief CLI模块定义
 * @author Scriptforge
 * @date 2026/7/1
 */

module;

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

export module Cli;
import Scriptforge.Msg;
import Scriptforge.Local;
import Scriptforge.LanguageCode;
import Scriptforge.Pch;

import ArgvCli;
import ErrCode;
import ErrCode.throwError;
import FileOstream;
import Lang;
import LegalArg;
import Log;
import LogLevel;
import Version;
import Websocket;

namespace Cli {
	using ws_config = websocketpp::config::asio;
	using ws_server = websocketpp::server<ws_config>;
	using ws_connHdl = websocketpp::connection_hdl;
	namespace fs = std::filesystem;
	using namespace std::string_literals;
	export 
		struct Unknown {
		static void run([[maybe_unused]] std::vector<std::string>::iterator it, std::string_view arg, [[maybe_unused]] std::ostream& os, [[maybe_unused]] std::ostream& err, [[maybe_unused]] std::istream& is) {
			Log::logMessage(Scriptforge::Msg::Message(::Lang::langPtr->atJ("Warning"s).format("unknownOpt"s, arg), Scriptforge::Msg::InformationLevel::Warning));
		}
	};

	export 
		struct Help {
		static constexpr std::string_view name = "--help";
		static constexpr std::string_view shortName = "-h";
		static void run([[maybe_unused]] std::vector<std::string>::iterator it, [[maybe_unused]] std::string_view arg, [[maybe_unused]] std::ostream& os, [[maybe_unused]] std::ostream& err, [[maybe_unused]] std::istream& is) {
			Log::logMessage(Scriptforge::Msg::Message(::Lang::langPtr->at<std::string>("help"), Scriptforge::Msg::InformationLevel::Info));
		}
	};
	
	export 
		struct Version {
		static constexpr std::string_view name = "--version";
		static constexpr std::string_view shortName = "-v";
		static void run([[maybe_unused]] std::vector<std::string>::iterator it, [[maybe_unused]] std::string_view arg, [[maybe_unused]] std::ostream& os, [[maybe_unused]] std::ostream& err, [[maybe_unused]] std::istream& is) {
			Log::logMessage(Scriptforge::Msg::Message(::Version::version.getVersion(), Scriptforge::Msg::InformationLevel::Info));
		}
	};
	export 
		struct Lang {
		static constexpr std::string_view name = "--lang";
		static constexpr std::string_view shortName = "-l";
		static void run(std::vector<std::string>::iterator it, std::string_view arg, [[maybe_unused]] std::ostream& os, [[maybe_unused]] std::ostream& err, [[maybe_unused]] std::istream& is) {
			auto nextArg = LegalArg::next(it, arg);
			auto langArg = LegalArg::next(nextArg, std::string(arg) + " " + *nextArg);
			if (*nextArg == "set") {
				if (!Scriptforge::LanguageCode::ISO639_1_TO_ENUM.contains(*langArg)) {
					Scriptforge::Local::throwErrWithoutJson(Scriptforge::ErrCode::ErrCode::LocalInvalidLanguageCode, __func__, "Invariant is not valid language codes for loading language files.");
				}
				auto langCode = Scriptforge::LanguageCode::ISO639_1_TO_ENUM.at(*langArg);
				::Lang::langPtr->setLocale(langCode);
			}
			else if (*nextArg == "dir") {
				if (!(fs::exists(*langArg) && fs::is_directory(*langArg))) {
					ErrCode::throwError(ErrCode::ErrCode::DirectoryNotFound, __func__, *::Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, *langArg);

				}
				else {
					::Lang::langPtr->setLangPath(*langArg);
				}
			}
			else {
				ErrCode::throwError(ErrCode::ErrCode::InvalidArgument, __func__, *::Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, *nextArg);
			}
		}
	};
	export
		struct LogLevel {
		static constexpr std::string_view name = "--loglevel";
		static constexpr std::string_view shortName = "-logl";
		static void run(std::vector<std::string>::iterator it, std::string_view arg, [[maybe_unused]] std::ostream& os, [[maybe_unused]] std::ostream& err, [[maybe_unused]] std::istream& is) {
			auto nextArg = std::next(it);
			if (nextArg == Argv::argvCliPtr->getArgv().end() || nextArg->starts_with('-')) {
				ErrCode::throwError(ErrCode::ErrCode::MissingArgument, __func__, *::Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, arg);
			}
			Log::logLevel = Log::logLevels.at(*nextArg);
		}
	};
	export 
		struct Start {
		static constexpr std::string_view name = "--start";
		static constexpr std::string_view shortName = "-s";
		static void run([[maybe_unused]] std::vector<std::string>::iterator it, [[maybe_unused]] std::string_view arg, [[maybe_unused]] std::ostream& os, [[maybe_unused]] std::ostream& err, [[maybe_unused]] std::istream& is) {
			Log::logMessage(Scriptforge::Msg::Message(::Lang::langPtr->atJ("Info"s).at("startingBot"s), Scriptforge::Msg::InformationLevel::Info));
			Websocket::WsServer server;
			auto& m_server = server.getServer();
			m_server.set_open_handler([](ws_connHdl hdl) {
				Log::logNormal("Server Open!");
				});
			m_server.set_message_handler([&](ws_connHdl hdl, ws_server::message_ptr msg) {
				Log::logNormal(msg->get_payload());
				});
			/*
			server.set_close_handler([](WsConnHdl hdl) {
				Log::logNormal("[Close] Client disconnect");
				});*/
		}
	};
}
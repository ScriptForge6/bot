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

#define LOG(...) Log::log(err, *FileOstream::fileStreamPtr, __VA_ARGS__)

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
import Log;
import Version;

namespace Cli {
	namespace fs = std::filesystem;
	export 
		struct Unknown {
		static void run(std::vector<std::string>::iterator it, std::string_view arg, std::ostream& os, std::ostream& err, std::istream& is) {
			LOG("Unknown command: ", arg);
		}
	};

	export 
		struct Help {
		static constexpr std::string_view name = "--help";
		static constexpr std::string_view shortName = "-h";
		static void run(std::vector<std::string>::iterator it, std::string_view arg, std::ostream& os, std::ostream& err, std::istream& is) {
			LOG(::Lang::langPtr->at<std::string>("help"));
		}
	};
	
	export 
		struct Version {
		static constexpr std::string_view name = "--version";
		static constexpr std::string_view shortName = "-v";
		static void run(std::vector<std::string>::iterator it, std::string_view arg, std::ostream& os, std::ostream& err, std::istream& is) {
			LOG(::Version::version.getVersion());
		}
	};
	export 
		struct Lang {
		static constexpr std::string_view name = "--lang";
		static constexpr std::string_view shortName = "-l";
		static void run(std::vector<std::string>::iterator it, std::string_view arg, std::ostream& os, std::ostream& err, std::istream& is) {
			auto nextArg = std::next(it);
			if (nextArg == Argv::argvCliPtr->getArgv().end() || nextArg->starts_with('-')) {
				ErrCode::throwError(ErrCode::ErrCode::MissingArgument, __func__, *::Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, arg);
			}
			auto langArg = std::next(nextArg);
			if(langArg == Argv::argvCliPtr->getArgv().end() || langArg->starts_with('-')) {
				auto allOptions = *nextArg + " " + *langArg;
				ErrCode::throwError(ErrCode::ErrCode::MissingArgument, __func__, *::Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, allOptions);
			}
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
		struct Start {
		static constexpr std::string_view name = "--start";
		static constexpr std::string_view shortName = "-s";
		static void run(std::vector<std::string>::iterator it, std::string_view arg, std::ostream& os, std::ostream& err, std::istream& is) {
			LOG(Scriptforge::Msg::Message("Starting bot...", Scriptforge::Msg::InformationLevel::Info));

		}
	};
}
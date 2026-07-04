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
 * @file bot.cpp
 * @brief bot项目的主入口文件，使用 Scriptforge::Argv 模块处理命令行参数。
 * @author Scriptforge
 * @date 2026/7/1
*/


import Scriptforge.Argv;
import Scriptforge.Err;
import Scriptforge.ErrCode;
import Scriptforge.Version;
import Scriptforge.Local;
import Scriptforge.LanguageCode;
import Scriptforge.Pch;

import ArgvCli;
import Cli;
import ErrCode;
import Version;
import Lang;

int main(int argc, char* argv[]) {
	try{
		std::cout << Version::version.getCopyright() << std::endl;
		Scriptforge::Argv::ArgvCli<Scriptforge::Argv::Hash::FNV_1a_32> argvCli(argc, argv,std::cout, std::cerr, std::cin);
		Argv::argvCliPtr = &argvCli;
		Scriptforge::Local::Lang lang(Scriptforge::LanguageCode::Language::English, "./lang");
		Lang::langPtr = &lang;
		argvCli.run<Cli::Unknown, Cli::Help, Cli::Version, Cli::Lang>();
	}
	catch (const Scriptforge::Err::BasicError<Scriptforge::ErrCode::ErrCode>& e) {
		std::cerr << e;
		return static_cast<int>(e.code());
	}
	catch (const Scriptforge::Err::BasicError<ErrCode::ErrCode>& e) {
		std::cerr << e;
		return static_cast<int>(e.code());
	}
	catch (const std::exception& e) {
		std::cerr << "[Error] " << e.what() << std::endl;
		return 1;
	}
	catch (...) {
		std::cerr << "[Error] An unknown error occurred." << std::endl;
		return 1;
	}
    return 0;
}
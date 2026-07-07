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
 * @brief bot项目主入口，基于Scriptforge.Argv实现命令行参数解析
 * @author Scriptforge
 * @date 2026/7/1
*/

// 框架标准模块
import Scriptforge.Argv;
import Scriptforge.Err;
import Scriptforge.Msg;
import Scriptforge.ErrCode;
import Scriptforge.Version;
import Scriptforge.Local;
import Scriptforge.LanguageCode;
import Scriptforge.Pch;

// 项目内部业务模块
import Boot;
import BotConfig;
import Clean;
import Cli;
import ErrCode;
import Log;
import LogLevel;

namespace Sf = Scriptforge;
using ArgvCliType = Sf::Argv::ArgvCli<Sf::Argv::Hash::FNV_1a_32>;
using SfError = Sf::Err::BasicError<Sf::ErrCode::ErrCode>;
using LocalError = Sf::Err::BasicError<ErrCode::ErrCode>;

// 程序启动核心逻辑，拆分出来简化main
static int RunProgram(int argc, char* argv[]) {
    // 1. 初始化日志文件
    std::ofstream logFile(std::string(BotConfig::LogFileName), std::ios::app);
    Boot::initLogger(logFile);

    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: ";
        return 1;
    }

    // 2. 构造命令行解析器 & 语言管理器
    ArgvCliType argvCli(argc, argv, std::cout, std::cerr, std::cin);
    Sf::Local::Lang lang(BotConfig::DefaultLang, BotConfig::LangDir);

    // 3. 全局初始化
    Boot::boot(lang, argvCli);

    // 4. 执行命令行子命令
    argvCli.run<
        Cli::Unknown,
        Cli::Help,
        Cli::Version,
        Cli::LogLevel,
        Cli::Lang,
        Cli::Start
    >();
    return 0;
}

int main(int argc, char* argv[]) {
    // RAII 全局资源自动清理守卫
    Clean::CleanGuard globalCleanGuard;

    try {
        return RunProgram(argc, argv);
    }
    catch (const SfError& err) {
        Log::logMessage(err);
        return static_cast<int>(err.code());
    }
    catch (const LocalError& err) {
        Log::logMessage(err);
        return static_cast<int>(err.code());
    }
    catch (const std::exception& err) {
        Log::logMessage(Scriptforge::Msg::Message(err.what(), Scriptforge::Msg::InformationLevel::Error));
        return 1;
    }
    catch (...) {
        Log::logMessage(Scriptforge::Msg::Message("An unknown error occurred.", Scriptforge::Msg::InformationLevel::Error));
        return 1;
    }
}
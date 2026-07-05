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
 * @file Boot.ixx
 * @brief 定义了 `Boot` 模块，用于初始化程序全局静态指针、启动流程
 * @author Scriptforge
 * @date 2026/7/1
 */
export module Boot;

import Scriptforge.Pch;
import Scriptforge.Argv;
import Scriptforge.Local;
import Scriptforge.Version;

import ArgvCli;
import FileOstream;
import Version;
import Lang;

namespace Boot
{
    // 类型别名简化超长模板
    using ArgvCliT = Scriptforge::Argv::ArgvCli<Scriptforge::Argv::Hash::FNV_1a_32>;

    void printCopyright();
    export void initLogger(std::ofstream& logFile);
    void initLang(Scriptforge::Local::Lang& lang);
    void initArgvCli(ArgvCliT& argvCli);
    void initOfstream();
    export void boot(Scriptforge::Local::Lang& lang, ArgvCliT& argvCli);
}

namespace Boot {
    void boot(Scriptforge::Local::Lang& lang, ArgvCliT& argvCli) {
        initOfstream();
        initLang(lang);
        initArgvCli(argvCli);
        printCopyright();
    }

    void printCopyright() {
        std::cout << Version::version.getCopyright() << std::endl;
    }

    void initLogger(std::ofstream& logFile) {
        FileOstream::fileStreamPtr = &logFile;
    }

    void initLang(Scriptforge::Local::Lang& lang) {
        Lang::langPtr = &lang;
    }

    void initArgvCli(ArgvCliT& argvCli) {
        Argv::argvCliPtr = &argvCli;
    }

	void initOfstream() {
        if (FileOstream::fileStreamPtr != nullptr) {
            *FileOstream::fileStreamPtr << std::format("{:=>30}", "\n");
        }
	}
}
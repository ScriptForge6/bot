export module Log;

import Scriptforge.Pch;

namespace Log {
    export 
        template <typename... Args>
    void log(std::ostream& out1, std::ostream& out2, Args&&... args) {
        std::ostringstream buf;
        (buf << ... << std::forward<Args>(args));
        const std::string& log_text = buf.str();

        out1 << log_text << '\n';
        out2 << log_text << '\n';
    }
}

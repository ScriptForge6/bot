export module ErrCode.throwError;
import Scriptforge.Msg;
import Scriptforge.LanguageCode;
import Scriptforge.Local;
import Scriptforge.Err;
import Scriptforge.Pch;
import ErrCode;

namespace ErrCode {
    export
        [[noreturn]] void throwError(
            ErrCode code,
            const std::string& func,
            const Scriptforge::Local::Lang& lang,
            Scriptforge::Msg::InformationLevel level = Scriptforge::Msg::InformationLevel::Error
        );
    export
        template <typename... Args>
    [[noreturn]] void throwError(
        ErrCode code,
        const std::string& func,
        const Scriptforge::Local::Lang& lang,
        Scriptforge::Msg::InformationLevel level = Scriptforge::Msg::InformationLevel::Error,
        Args&&... args
    );
}

namespace ErrCode {
    
    void throwError(
        ErrCode code,
        const std::string& func,
        const Scriptforge::Local::Lang& lang,
        Scriptforge::Msg::InformationLevel level
    ) {
        std::string baseStr = lang.atJ<std::string>("Error").at(to_string(code));
        throw Scriptforge::Err::BasicError<ErrCode> {
            code,
            func + ": " + baseStr,
            level
        };
    }

    template <typename... Args>
    void throwError(
        ErrCode code,
        const std::string& func,
        const Scriptforge::Local::Lang& lang,
        Scriptforge::Msg::InformationLevel level,
        Args&&... args
    ) {
        std::string baseStr = lang.atJ<std::string>("Error").format<std::string>(to_string(code), std::forward<Args>(args)...);
        throw Scriptforge::Err::BasicError<ErrCode> {
            code,
            func + ": " + baseStr,
			level
		};
    }

}
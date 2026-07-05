export module BotConfig;

import Scriptforge.Pch;
import Scriptforge.LanguageCode;

export namespace BotConfig {
    inline constexpr std::string LogFileName = "bot.log";
    inline constexpr std::string_view LangDir = "./lang";
    inline constexpr auto DefaultLang = Scriptforge::LanguageCode::Language::English;
    inline constexpr std::string_view Token = "token";
}

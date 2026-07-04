export module Token;

import Scriptforge.Pch;

import nlohmann.json;

namespace Token {
	export std::string getToken();
}

namespace Token {
	export std::string getToken() {
		nlohmann::json jsonData;
        std::ifstream jsoninput("config.json");

        if (!jsoninput.is_open()) {
            
        }

        try {
            jsoninput >> jsonData;
        }
        catch (const nlohmann::json::parse_error&) {
            
        }
        jsoninput.close();
	}
}
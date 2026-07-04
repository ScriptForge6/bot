export module ErrCode;

import Scriptforge.Pch;

namespace ErrCode {
	export enum class ErrCode {
		UnknownError = 101,
		MissingArgument = 102,
		InvalidArgument = 103,
		UnknownOption = 104,
		DirectoryNotFound = 105,
	};
	export std::string to_string(ErrCode code) {
		return std::to_string(static_cast<int>(code));
	}

	export std::ostream& operator<<(std::ostream& os, const ErrCode& errCode) {
		os << to_string(errCode);
		return os;
	}
}
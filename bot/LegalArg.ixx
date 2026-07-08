export module LegalArg;

import Scriptforge.Msg;
import Scriptforge.Pch;

import ArgvCli;
import Lang;
import ErrCode;
import ErrCode.throwError;

namespace LegalArg {
	export auto next(std::vector<std::string>::iterator it, std::string_view arg)
		-> std::vector<std::string>::iterator {
		auto nextArg = std::next(it);
		if (nextArg == Argv::argvCliPtr->getArgv().end() || nextArg->starts_with('-')) {
			ErrCode::throwError(ErrCode::ErrCode::MissingArgument, __func__, *::Lang::langPtr, Scriptforge::Msg::InformationLevel::Error, arg);
		}
		return nextArg;
	}
}
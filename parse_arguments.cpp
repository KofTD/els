#include "parse_arguments.h"
#include <algorithm>
#include <cctype>
#include <exception>
#include <map>
#include <string>

using std::map;
using std::string;

string to_full_argument(const string &arg) {
  if (arg == "h")
    return "hidden";
  if (arg == "d")
    return "dirs";
  if (arg == "l")
    return "links";

  string message = "Unknown argument: -" + arg;
  throw std::exception(message.data());
}

map<string, string> parse_arguments(int argc, char *argv[]) {
  map<string, string> arguments;

  for (int i = 1; i < argc; i++) {
    if (string arg = argv[i]; arg.substr(0, 2) == "--") {
      arg = arg.substr(2);
      string status = "ON";

      if (size_t equal_sign_pos = arg.find('=');
          equal_sign_pos != string::npos) {
        status = arg.substr(equal_sign_pos + 1);
        arg = arg.substr(0, equal_sign_pos);
      }

      auto to_low_char = [](char &sym) { sym = (char)tolower(sym); };
      std::for_each(arg.begin(), arg.end(), to_low_char);

      arguments.emplace(arg, status);
    } else if (arg.substr(0, 1) == "-") {
      arguments.emplace(to_full_argument(arg.substr(1)), "ON");
    } else {
      arguments["path"] = arg;
    }
  }

  return arguments;
}

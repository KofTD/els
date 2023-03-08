#include "files.h"
#include "grid.h"
#include "make_strings.h"
#include "parse_arguments.h"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  if (argc > 4) {
    cout << "\033[31mToo much arguments\033[0m" << endl; // 31 = RED; 0 = reset
    return 1;
  }

  if (argc == 2 && strcmp(argv[1], "--help") == 0) {
    cout << "--------------Functions--------------" << endl;
    cout << "-h --hidden - show hidden files" << endl;
    cout << "-d --dirs - show only directories" << endl;
    cout << "-l --links - show only links" << endl;
    return 0;
  }

  std::map<std::string, std::string> arguments;

  try {
    arguments = parse_arguments(argc, argv);
  } catch (std::exception &err) {
    std::cerr << "\033[31m" << err.what() << "\033[0m" << endl;
    return 1;
  }

  if (arguments["path"].empty())
    arguments["path"] = std::filesystem::current_path().string();

  if (!std::filesystem::exists(arguments["path"]) ||
      !std::filesystem::is_directory(arguments["path"])) {
    cout << "\033[31mPath isn't reliable\033[0m" << endl;
    return 1;
  }

  bool needs_hidden = arguments["hidden"] == "ON";

  item_type what_catch = item_type::all;

  if (arguments.count("dirs") == 1)
    what_catch = item_type::directories;
  else if (arguments.count("links") == 1)
    what_catch = item_type::links;

  auto items = get_items_in_dir(arguments["path"], what_catch, needs_hidden);

  auto strings = process_strings(items);

  grid_output(strings);

  return 0;
}

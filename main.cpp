#include "files.h"
#include "grid.h"
#include "make_strings.h"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  if (argc > 2) {
    cout << "\033[31mToo much arguments\033[0m" << endl; // 31 = RED; 0 = reset
    return 1;
  }

  std::filesystem::path path_to_dir =
      argc == 2 ? argv[1] : std::filesystem::current_path();

  if (!std::filesystem::exists(path_to_dir) ||
      !std::filesystem::is_directory(path_to_dir)) {
    cout << "\033[31mPath isn't reliable\033[0m" << endl;
    return 1;
  }

  auto items = get_items_in_dir(path_to_dir, item_type::all, false);

  auto strings = process_strings(items);

  grid_output(strings);

  return 0;
}

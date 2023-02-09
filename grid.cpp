#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;

enum { ASCII_SYMBOLS_NUMBER = 11, START_COLUMNS_NUMBER = 6 };

void grid_output(std::vector<std::string> strings) {
  CONSOLE_SCREEN_BUFFER_INFO console_info;
  BOOL result = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),
                                           &console_info);

  if (result == 0)
    throw std::exception("Can't get console width");

  auto max_length_string = std::max_element(
      strings.begin(), strings.end(), [](auto largest_str, auto another_str) {
        return largest_str.length() < another_str.length();
      });

  short columns_number = START_COLUMNS_NUMBER;
  int console_width = console_info.dwSize.X;
  int column_width = console_width / columns_number;
  while (column_width < max_length_string->length()) {
    columns_number--;
    column_width = console_width / columns_number;
  }

  short column = 0;
  for (const auto &str : strings) {
    cout.setf(std::ios::left, std::ios::adjustfield);
    cout.width(column_width + ASCII_SYMBOLS_NUMBER);
    cout << str;
    column++;
    if (column == columns_number) {
      cout << std::endl;
      column = 0;
    }
  }
}

#include "make_strings.h"
#include <array>
#include <filesystem>
#include <map>
#include <string>
#include <vector>

#define UNKNOWN_FILE_TYPE_PLACEHOLDER ""

using std::map;
using std::string;
using std::vector;

namespace fs = std::filesystem;

// NOLINTNEXTLINE (cppcoreguidlines-avoid-non-const-global-variables)
map<string, string> icons_of_extensions = {{".applescript", ""},
                                           {".script editor", ""},
                                           {".adoc", ""},
                                           {".asciidoc", ""},
                                           {".bat", ""},
                                           {".cmd", ""},
                                           {".exe", ""},
                                           {".sh", ""},
                                           {".bash", ""},
                                           {".zsh", ""},
                                           {".ash", ""},
                                           {".bash_aliases", ""},
                                           {".bash_completions", ""},
                                           {".bash_functions", ""},
                                           {".bash_login", ""},
                                           {".bash_logout", ""},
                                           {".bash_profile", ""},
                                           {".bash_variables", ""},
                                           {".bashrc", ""},
                                           {".profile", ""},
                                           {".textmate_init", ""},
                                           {".zlogin", ""},
                                           {".zlogout", ""},
                                           {".zprofile", ""},
                                           {".zshenv", ""},
                                           {".zshrc", ""},
                                           {".PKGBUILD", ""},
                                           {".ebuild", ""},
                                           {".eclass", ""},
                                           {".c", ""},
                                           {".cs", ""},
                                           {".csx", ""},
                                           {".cpp", "ﭱ"},
                                           {".cc", "ﭱ"},
                                           {".cp", "ﭱ"},
                                           {".cxx", "ﭱ"},
                                           {".c++", "ﭱ"},
                                           {".h", ""},
                                           {".hh", ""},
                                           {".hpp", ""},
                                           {".hxx", ""},
                                           {".h++", ""},
                                           {".inl", ""},
                                           {".ipp", ""},
                                           {".clj", ""},
                                           {".cljc", ""},
                                           {".cljs", ""},
                                           {".edn", ""},
                                           // Find another icon
                                           //{"CMakeLists.txt", "喝"},
                                           //{".cmake", "喝"},
                                           {".css", ""},
                                           {".css.erb", ""},
                                           {".css.liquid", ""},
                                           {".Dockerfile", ""},
                                           {".dockerfile", ""},
                                           {".go", ""},
                                           {".html", ""},
                                           {".htm", ""},
                                           {".shtml", ""},
                                           {".xhtml", ""},
                                           {".java", ""},
                                           {".bsh", ""},
                                           {".js", ""},
                                           {".mjs", ""},
                                           {".jsx", ""},
                                           {".babel", ""},
                                           {".es6", ""},
                                           {".cjs", ""},
                                           {".json", ""},
                                           {".kt", "ﱃ"},
                                           {".kts", "ﱃ"},
                                           {".log", ""},
                                           {".lua", ""},
                                           {".md", ""},
                                           {".mdown", ""},
                                           {".markdown", ""},
                                           {".markdn", ""},
                                           {".php", ""},
                                           {".php3", ""},
                                           {".php4", ""},
                                           {".php5", ""},
                                           {".php7", ""},
                                           {".phps", ""},
                                           {".phpt", ""},
                                           {".phtml", ""},
                                           {".txt", ""},
                                           {".png", ""},
                                           {".jpg", ""},
                                           {".gif", ""},
                                           {".ps1", ""},
                                           {".psm1", ""},
                                           {".psd1", ""},
                                           {".py", ""},
                                           {".rb", ""},
                                           {".rs", ""},
                                           {".scss", ""},
                                           {".swift", ""},
                                           {".syslog", ""},
                                           {".toml", ""},
                                           {".tml", ""},
                                           {".lock", ""},
                                           {".ts", ""},
                                           {".tsx", ""},
                                           {".vim", ""},
                                           {".vimrs", ""},
                                           {".xml", "謹"},
                                           {".yaml", ""},
                                           {".yml", ""},
                                           {".zip", ""},
                                           {".7z", ""},
                                           {"dir", ""},
                                           {"block", ""},
                                           {"pipe", "ﳣ"},
                                           {"socket", "ﳥ"},
                                           {"symlink", ""}};

// NOLINTNEXTLINE (cppcoreguidlines-non-const-variable-in-global-scope)
map<string, colors> colors_of_extensions = {{".applescript", colors::white},
                                            {".script editor", colors::white},
                                            {".adoc", colors::cyan},
                                            {".asciidoc", colors::cyan},
                                            {".bat", colors::red},
                                            {".cmd", colors::red},
                                            {".sh", colors::red},
                                            {".bash", colors::red},
                                            {".zsh", colors::red},
                                            {".ash", colors::red},
                                            {".bash_aliases", colors::red},
                                            {".bash_completions", colors::red},
                                            {".bash_functions", colors::red},
                                            {".bash_login", colors::red},
                                            {".bash_logout", colors::red},
                                            {".bash_profile", colors::red},
                                            {".bash_variables", colors::red},
                                            {".bashrc", colors::red},
                                            {".profile", colors::red},
                                            {".textmate_init", colors::red},
                                            {".zlogin", colors::red},
                                            {".zlogout", colors::red},
                                            {".zprofile", colors::red},
                                            {".zshenv", colors::red},
                                            {".zshrc", colors::red},
                                            {".PKGBUILD", colors::red},
                                            {".ebuild", colors::red},
                                            {".eclass", colors::red},
                                            {".c", colors::blue},
                                            {".cs", colors::violet},
                                            {".csx", colors::violet},
                                            {".cpp", colors::blue},
                                            {".cc", colors::blue},
                                            {".cp", colors::blue},
                                            {".cxx", colors::blue},
                                            {".c++", colors::blue},
                                            {".h", colors::blue},
                                            {".hh", colors::blue},
                                            {".hpp", colors::blue},
                                            {".hxx", colors::blue},
                                            {".h++", colors::blue},
                                            {".inl", colors::blue},
                                            {".ipp", colors::blue},
                                            {".clj", colors::green},
                                            {".cljc", colors::green},
                                            {".cljs", colors::green},
                                            {".edn", colors::green},
                                            {".css", colors::cyan},
                                            {".css.erb", colors::cyan},
                                            {".css.liquid", colors::cyan},
                                            {".Dockerfile", colors::cyan},
                                            {".dockerfile", colors::cyan},
                                            {".go", colors::cyan},
                                            {".html", colors::red},
                                            {".htm", colors::red},
                                            {".shtml", colors::red},
                                            {".xhtml", colors::red},
                                            {".java", colors::red},
                                            {".bsh", colors::red},
                                            {".js", colors::yellow},
                                            {".mjs", colors::yellow},
                                            {".jsx", colors::yellow},
                                            {".babel", colors::yellow},
                                            {".es6", colors::yellow},
                                            {".cjs", colors::yellow},
                                            {".json", colors::yellow},
                                            {".kt", colors::violet},
                                            {".kts", colors::violet},
                                            {".log", colors::green},
                                            {".lua", colors::blue},
                                            {".md", colors::white},
                                            {".mdown", colors::white},
                                            {".markdown", colors::white},
                                            {".markdn", colors::white},
                                            {".php", colors::blue},
                                            {".php3", colors::blue},
                                            {".php4", colors::blue},
                                            {".php5", colors::blue},
                                            {".php7", colors::blue},
                                            {".phps", colors::blue},
                                            {".phpt", colors::blue},
                                            {".phtml", colors::blue},
                                            {".txt", colors::cyan},
                                            {".ps1", colors::blue},
                                            {".psm1", colors::blue},
                                            {".psd1", colors::blue},
                                            {".py", colors::yellow},
                                            {".rb", colors::red},
                                            {".rs", colors::red},
                                            {".scss", colors::blue},
                                            {".swift", colors::red},
                                            {".syslog", colors::green},
                                            {".toml", colors::yellow},
                                            {".tml", colors::yellow},
                                            {".lock", colors::yellow},
                                            {".ts", colors::blue},
                                            {".tsx", colors::blue},
                                            {".vim", colors::green},
                                            {".vimrs", colors::green},
                                            {".xml", colors::green},
                                            {".yaml", colors::yellow},
                                            {".yml", colors::yellow}};

colors get_color(const fs::path &file) {
  if (auto color_pointer = colors_of_extensions.find(file.extension().string());
      color_pointer != colors_of_extensions.end())
    return color_pointer->second;

  if (fs::is_directory(file))
    return colors::green;

  return colors::white;
};

string get_icon(const fs::path &file) {
  if (auto icon_pointer = icons_of_extensions.find(file.extension().string());
      icon_pointer != icons_of_extensions.end())
    return icon_pointer->second;

  if (fs::is_directory(file))
    return icons_of_extensions["dir"];

  if (fs::is_block_file(file))
    return icons_of_extensions["block"];

  if (fs::is_fifo(file))
    return icons_of_extensions["pipe"];

  if (fs::is_socket(file))
    return icons_of_extensions["socket"];

  if (fs::is_symlink(file))
    return icons_of_extensions["symlink"];

  return UNKNOWN_FILE_TYPE_PLACEHOLDER;
};

vector<string> process_strings(const vector<fs::path> &files) {
  vector<string> ready_output_strings(files.size());

  for (size_t index = 0; index < files.size(); index++) {
    string icon = get_icon(files[index]);
    colors file_color = get_color(files[index]);

    string colored_string;
    switch (file_color) {
    case colors::black:
      colored_string = "\033[30m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::red:
      colored_string = "\033[31m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::green:
      colored_string = "\033[32m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::yellow:
      colored_string = "\033[33m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::blue:
      colored_string = "\033[34m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::violet:
      colored_string = "\033[35m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::cyan:
      colored_string = "\033[36m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    case colors::white:
      colored_string = "\033[37m" + icon + ' ' +
                       files[index].filename().string() + "\033[0m";
      break;
    }

    ready_output_strings[index] = colored_string;
  }

  return ready_output_strings;
}

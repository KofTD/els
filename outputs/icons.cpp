#define UNKNOWN_FILE_TYPE_PLACEHOLDER ""
#include "icons.hpp"
#include <filesystem>
#include <map>
#include <string>
namespace fs = std::filesystem;
using std::string;

std::map<string, string> icons = {
    {".applescript", ""},
    {".script editor", ""},
    {".adoc", ""},
    {".asciidoc", ""},
    {".bat", ""},
    {".cmd", ""},
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
    {".h", ""},
    {".hh", "ﭱ"},
    {".hpp", "ﭱ"},
    {".hxx", "ﭱ"},
    {".h++", "ﭱ"},
    {".inl", "ﭱ"},
    {".ipp", "ﭱ"},
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
    {"dir", ""},
    {"block", ""},
    {"pipe", "ﳣ"},
    {"socket", "ﳥ"},
    {"symlink", ""}};

string get_icon(fs::path path)
{
    auto icon = icons.find(path.string());

    if (icon != icons.end())
        return icon->second;
    else
        icon = icons.find(path.extension().string());

    if (icon != icons.end())
        return icon->second;

    if (fs::is_block_file(path))
        return icons["block"];

    if (fs::is_character_file(path))
        return icons[".txt"];

    if (fs::is_directory(path))
        return icons["dir"];

    if (fs::is_fifo(path))
        return icons["pipe"];

    if (fs::is_regular_file(path))
        return icons[".txt"];

    if (fs::is_socket(path))
        return icons["socket"];

    if (fs::is_symlink(path))
        return icons["symlink"];

    return UNKNOWN_FILE_TYPE_PLACEHOLDER;
}
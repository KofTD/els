#include "colors.hpp"
#include <map>
namespace fs = std::filesystem;

std::map<std::string, Colors> colors = {
    {".applescript", Colors::white},
    {".script editor", Colors::white},
    {".adoc", Colors::aqua},
    {".asciidoc", Colors::aqua},
    {".bat", Colors::red},
    {".cmd", Colors::red},
    {".sh", Colors::red},
    {".bash", Colors::red},
    {".zsh", Colors::red},
    {".ash", Colors::red},
    {".bash_aliases", Colors::red},
    {".bash_completions", Colors::red},
    {".bash_functions", Colors::red},
    {".bash_login", Colors::red},
    {".bash_logout", Colors::red},
    {".bash_profile", Colors::red},
    {".bash_variables", Colors::red},
    {".bashrc", Colors::red},
    {".profile", Colors::red},
    {".textmate_init", Colors::red},
    {".zlogin", Colors::red},
    {".zlogout", Colors::red},
    {".zprofile", Colors::red},
    {".zshenv", Colors::red},
    {".zshrc", Colors::red},
    {".PKGBUILD", Colors::red},
    {".ebuild", Colors::red},
    {".eclass", Colors::red},
    {".c", Colors::blue},
    {".cs", Colors::purple},
    {".csx", Colors::purple},
    {".cpp", Colors::blue},
    {".cc", Colors::blue},
    {".cp", Colors::blue},
    {".cxx", Colors::blue},
    {".c++", Colors::blue},
    {".h", Colors::blue},
    {".hh", Colors::blue},
    {".hpp", Colors::blue},
    {".hxx", Colors::blue},
    {".h++", Colors::blue},
    {".inl", Colors::blue},
    {".ipp", Colors::blue},
    {".clj", Colors::green},
    {".cljc", Colors::green},
    {".cljs", Colors::green},
    {".edn", Colors::green},
    {".css", Colors::aqua},
    {".css.erb", Colors::aqua},
    {".css.liquid", Colors::aqua},
    {".Dockerfile", Colors::aqua},
    {".dockerfile", Colors::aqua},
    {".go", Colors::aqua},
    {".html", Colors::red},
    {".htm", Colors::red},
    {".shtml", Colors::red},
    {".xhtml", Colors::red},
    {".java", Colors::light_red},
    {".bsh", Colors::light_red},
    {".js", Colors::yellow},
    {".mjs", Colors::yellow},
    {".jsx", Colors::yellow},
    {".babel", Colors::yellow},
    {".es6", Colors::yellow},
    {".cjs", Colors::yellow},
    {".json", Colors::yellow},
    {".kt", Colors::purple},
    {".kts", Colors::purple},
    {".log", Colors::green},
    {".lua", Colors::blue},
    {".md", Colors::white},
    {".mdown", Colors::white},
    {".markdown", Colors::white},
    {".markdn", Colors::white},
    {".php", Colors::blue},
    {".php3", Colors::blue},
    {".php4", Colors::blue},
    {".php5", Colors::blue},
    {".php7", Colors::blue},
    {".phps", Colors::blue},
    {".phpt", Colors::blue},
    {".phtml", Colors::blue},
    {".txt", Colors::aqua},
    {".ps1", Colors::blue},
    {".psm1", Colors::blue},
    {".psd1", Colors::blue},
    {".py", Colors::yellow},
    {".rb", Colors::red},
    {".rs", Colors::red},
    {".scss", Colors::blue},
    {".swift", Colors::red},
    {".syslog", Colors::green},
    {".toml", Colors::yellow},
    {".tml", Colors::yellow},
    {".lock", Colors::yellow},
    {".ts", Colors::blue},
    {".tsx", Colors::blue},
    {".vim", Colors::grey},
    {".vimrs", Colors::grey},
    {".xml", Colors::green},
    {".yaml", Colors::yellow},
    {".yml", Colors::yellow},
    {"dir", Colors::green},
    {"block", Colors::red},
    {"pipe", Colors::grey},
    {"socket", Colors::white},
    {"symlink", Colors::grey}};

Colors get_color(fs::path file)
{
    auto color = colors.find(file.extension().string());
    if (color == colors.end())
    {
        if (fs::is_directory(file))
            return colors["dir"];

        if (fs::is_block_file(file))
            return colors["block"];

        if (fs::is_character_file(file))
            return colors[".txt"];

        if (fs::is_directory(file))
            return colors["dir"];

        if (fs::is_fifo(file))
            return colors["pipe"];

        if (fs::is_regular_file(file))
            return colors[".txt"];

        if (fs::is_socket(file))
            return colors["socket"];

        if (fs::is_symlink(file))
            return colors["symlink"];
    }

    return color->second;
}
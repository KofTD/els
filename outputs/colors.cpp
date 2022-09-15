#include "colors.hpp"
#include <map>
#include <string>
namespace fs = std::filesystem;

std::map<std::string, Colors> colors = {
	{".applescript", Colors::white},
	{".script editor", Colors::white},
	{".adoc", Colors::cyan},
	{".asciidoc", Colors::cyan},
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
	{".css", Colors::cyan},
	{".css.erb", Colors::cyan},
	{".css.liquid", Colors::cyan},
	{".Dockerfile", Colors::cyan},
	{".dockerfile", Colors::cyan},
	{".go", Colors::cyan},
	{".html", Colors::red},
	{".htm", Colors::red},
	{".shtml", Colors::red},
	{".xhtml", Colors::red},
	{".java", Colors::red},
	{".bsh", Colors::red},
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
	{".txt", Colors::cyan},
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
	{".vim", Colors::green},
	{".vimrs", Colors::green},
	{".xml", Colors::green},
	{".yaml", Colors::yellow},
	{".yml", Colors::yellow},
	{"dir", Colors::green},
	{"block", Colors::red},
	{"pipe", Colors::white},
	{"socket", Colors::white},
	{"symlink", Colors::white}};

std::ostream &operator<<(std::ostream &os, const color_string &str)
{
	return os << "\x1b[" + std::to_string(str.color) + 'm' + str.text + "\x1b[0m";
}

Colors get_color(const fs::path& file)
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

color_string::color_string() : color{30} {}

color_string::color_string(const char *t) : text{t}, color{30} {}
color_string::color_string(const char *t, Colors c) : text{t}
{
	switch (c)
	{
	case Colors::black:
		color = 30;
		return;
	case Colors::red:
		color = 31;
		return;
	case Colors::green:
		color = 32;
		return;
	case Colors::yellow:
		color = 33;
		return;
	case Colors::blue:
		color = 34;
		return;
	case Colors::purple:
		color = 35;
		return;
	case Colors::cyan:
		color = 36;
		return;
	case Colors::white:
		color = 37;
		return;

	default:
		color = 30;
		return;
	}
}
color_string::color_string(std::string t, Colors c) : text{t}
{
	switch (c)
	{
	case Colors::black:
		color = 30;
		return;
	case Colors::red:
		color = 31;
		return;
	case Colors::green:
		color = 32;
		return;
	case Colors::yellow:
		color = 33;
		return;
	case Colors::blue:
		color = 34;
		return;
	case Colors::purple:
		color = 35;
		return;
	case Colors::cyan:
		color = 36;
		return;
	case Colors::white:
		color = 37;
		return;

	default:
		color = 30;
		return;
	}
}
color_string::~color_string()= default;
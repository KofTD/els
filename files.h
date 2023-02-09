#pragma once

#include <filesystem>
#include <vector>

enum class item_type { all, directories, links, pipes };

std::vector<std::filesystem::path>
get_items_in_dir(const std::filesystem::path &dir, item_type what_catch,
                 bool need_hidden_files);

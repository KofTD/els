#include "files.h"

#if defined WIN32 || defined _WIN32 || defined __WIN32__ || defined __NT__
#if !defined PLATFORM_WINDOWS
#define PLATFORM_WINDOWS
#include <Windows.h>
#include <fileapi.h>
#include <winnt.h>
#endif
#elif __linux__
#if !defined PLATFORM_LINUX
#define PLATFORM_LINUX
#include <filesystem>
#endif
#elif __unix__
#if !defined PLATFORM_UNIX
#define PLATFORM_UNIX
#include <filesystem>
#endif
#else
#error "Unknown platform"
#endif

using std::vector;
namespace fs = std::filesystem;

bool is_hidden(const fs::path &item) {
#if defined PLATFORM_WINDOWS
  auto itemAttributes = GetFileAttributesW(item.c_str());
  return (itemAttributes & FILE_ATTRIBUTE_HIDDEN) == FILE_ATTRIBUTE_HIDDEN;
#elif defined PLATFORM_LINUX
// TODO: Make Linux realization
#elif defined PLATFORM_UNIX
// TODO: Make UNIX realization
#else
#pragma error "Unknown plarform"
#endif
}

vector<fs::path> get_items_in_dir(const fs::path &dir, item_type what_catch,
                                  bool need_hidden_files) {

  vector<fs::path> items_in_dir;

  for (const fs::path &item : fs::directory_iterator(dir)) {

    if (!need_hidden_files && is_hidden(item))
      continue;

    bool is_what_catch = false;
    switch (what_catch) {
    case item_type::all:
      is_what_catch = true;
      break;
    case item_type::links:
      is_what_catch = fs::is_symlink(item);
      break;
    case item_type::pipes:
      is_what_catch = fs::is_fifo(item);
      break;
    case item_type::directories:
      is_what_catch = fs::is_directory(item);
      break;
    }

    if (is_what_catch)
      items_in_dir.push_back(item);
  }

  return items_in_dir;
}

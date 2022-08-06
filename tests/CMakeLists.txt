enable_testing()

add_subdirectory(parse_arguments_tests)
add_test(NAME "Nothing" COMMAND "Nothing")
add_test(NAME "OnlyPath" COMMAND "OnlyPath" C:/)
add_test(NAME "ShortArguments" COMMAND "ShortArguments" -O -a -D -C)
add_test(NAME "LongArguments" COMMAND "LongArguments" --level=1 --oneline --dirs)
add_test(NAME "OneDashString" COMMAND "OneDashString" -aOm)
add_test(NAME "ParseDifficultString" COMMAND "ParseDifficultString" -ams --level=11)
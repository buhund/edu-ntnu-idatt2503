# tests/CMakeLists.txt

add_executable(escape_test escape_test.c)
target_link_libraries(escape_test escape)
target_compile_options(escape_test PRIVATE -fsanitize=address)
target_link_options(escape_test PRIVATE -fsanitize=address)
add_test(NAME escape_test COMMAND escape_test)

add_executable(escape_fuzzer_test escape_fuzzer_test.c)
target_link_libraries(escape_fuzzer_test escape)
target_compile_options(escape_fuzzer_test PRIVATE -fsanitize=address,fuzzer)
target_link_options(escape_fuzzer_test PRIVATE -fsanitize=address,fuzzer)
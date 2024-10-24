project("comlpex_test")
add_executable("complex_test" "complex_doctest.cpp")
target_link_libraries(complex_test complex)
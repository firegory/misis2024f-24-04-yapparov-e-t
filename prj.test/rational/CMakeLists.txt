project("rational")
add_executable("rational_doctest" "rational_doctest.cpp")
target_link_libraries(rational_doctest rational)
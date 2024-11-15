project("rational")
add_executable("rational_doctest" "rational_doctest.cpp")
target_link_libraries(rational_doctest rational)

project("darray")
add_executable("darray_doctest" "darray_doctest.cpp")
target_link_libraries(darray_doctest darray)

project("comlpex_test")
add_executable("complex_doctest" "complex_doctest.cpp")
target_link_libraries(complex_doctest complex)
add_executable("complex_test" "complex_test.cpp")
target_link_libraries(complex_test complex)
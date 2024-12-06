project("rational")
add_executable("rational_doctest" "rational_doctest.cpp")
target_link_libraries(rational_doctest rational)

project("arrayd")
add_executable("arrayd_doctest" "arrayd_doctest.cpp")
target_link_libraries(arrayd_doctest arrayd)

project("arrayt")
add_executable("arrayt_doctest" "arrayt_doctest.cpp")
target_link_libraries(arrayt_doctest arrayt)

project("stackl")
add_executable("stackl_doctest" "stackl_doctest.cpp")
target_link_libraries(stackl_doctest stackl)

project("queuea")
add_executable("queuea_doctest" "queuea_doctest.cpp")
target_link_libraries(queuea_doctest queuea)

project("comlpex_test")
add_executable("complex_doctest" "complex_doctest.cpp")
target_link_libraries(complex_doctest complex)
add_executable("complex_test" "complex_test.cpp")
target_link_libraries(complex_test complex)
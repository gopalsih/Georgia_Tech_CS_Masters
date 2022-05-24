# CMake generated Testfile for 
# Source directory: C:/OMSCS/Georgia_Tech_CS_Masters/CS6515-Intro_To_Graduate_Algorithms/tests
# Build directory: C:/OMSCS/Georgia_Tech_CS_Masters/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(testlibtest "C:/OMSCS/Georgia_Tech_CS_Masters/build/tests/testlib.exe")
set_tests_properties(testlibtest PROPERTIES  _BACKTRACE_TRIPLES "C:/OMSCS/Georgia_Tech_CS_Masters/CS6515-Intro_To_Graduate_Algorithms/tests/CMakeLists.txt;25;add_test;C:/OMSCS/Georgia_Tech_CS_Masters/CS6515-Intro_To_Graduate_Algorithms/tests/CMakeLists.txt;0;")
subdirs("../_deps/catch2-build")

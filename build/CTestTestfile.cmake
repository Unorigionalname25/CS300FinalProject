# CMake generated Testfile for 
# Source directory: /workspaces/CS300FinalProject
# Build directory: /workspaces/CS300FinalProject/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(testing "/workspaces/CS300FinalProject/build/testing")
set_tests_properties(testing PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/CS300FinalProject/CMakeLists.txt;53;add_test;/workspaces/CS300FinalProject/CMakeLists.txt;0;")
subdirs("googletest")

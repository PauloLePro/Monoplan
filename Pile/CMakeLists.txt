project(TestPile)
add_executable(TestPile testpile.c pile.c pile.h)
target_link_libraries(TestPile m)
install(TARGETS TestPile RUNTIME DESTINATION ${BIN_DIR})
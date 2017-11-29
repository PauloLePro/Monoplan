project(TestCellule)
add_executable(TestCellule cellule.c cellule.h testcellule.c ../Pile/pile.h ../Pile/pile.c ../Liste/liste.c ../Liste/liste.h)
target_link_libraries(TestCellule m)
install(TARGETS TestCellule RUNTIME DESTINATION ${BIN_DIR})
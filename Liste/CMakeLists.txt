project(TestListe)
add_executable(TestListe testliste.c liste.c liste.h)
target_link_libraries(TestListe m)
install(TARGETS TestListe RUNTIME DESTINATION ${BIN_DIR})
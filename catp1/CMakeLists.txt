add_library(pessoa STATIC Pessoa.cpp)
add_library(aluno STATIC Aluno.cpp)
add_executable(exercicio1 main.cpp)
target_link_libraries(exercicio1 pessoa)
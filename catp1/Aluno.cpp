#include "Aluno.hpp"

// sobrecarga do operator<< para aceitar Alunos
std::ostream &operator<<(std::ostream &os, const Aluno &a) {
    os << "Aluno (";
    os << (Pessoa &)a;
    os << ")";
    return os;
}

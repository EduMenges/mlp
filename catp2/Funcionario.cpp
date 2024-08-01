#include "Funcionario.hpp"

// sobrecarga do operator<< para aceitar funcionários
std::ostream &operator<<(std::ostream &os, const Funcionario &a) {
    os << "Funcionario (";
    os << (Pessoa &)a;
    os << ")";
    return os;
}

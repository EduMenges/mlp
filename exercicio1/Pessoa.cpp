#include "Pessoa.hpp"

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream &operator<<(std::ostream &os, const Pessoa::GENERO g) {
    switch (g) {
        case Pessoa::INDEFINIDO:
            os << "INDEFINIDO";
            break;
        case Pessoa::HOMEM_CIS:
            os << "HOMEM_CIS";
            break;
        case Pessoa::MULHER_CIS:
            os << "MULHER_CIS";
            break;
        case Pessoa::NAO_BINARIO:
            os << "NAO_BINARIO";
            break;
        case Pessoa::TRANSGENERO:
            os << "TRANSGENERO";
            break;
        default:
            os.setstate(std::ios_base::failbit);
    }
    return os;
}

// sobrecarga do operator<< para aceitar Pessoas
std::ostream &operator<<(std::ostream &os, const Pessoa &p) {
    auto data = p.get_dt_nascimento();
    tm *ltm = localtime(&data.epoch_time);

    os << "Pessoa (Nome: " << p.get_nome() << ", Genero: " << p.get_genero()
       << ", Nascimento: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year
       << ")";
    return os;
}

#include <memory>

#include "catp1/Aluno.hpp"
#include "catp1/Pessoa.hpp"
#include "catp2/Funcionario.hpp"

using namespace std;

int main(void) {
    unique_ptr<Pessoa> p = make_unique<Aluno>(
        "Carlos Silva",
        time(0),
        Pessoa::Genero::HOMEM_CIS,
        Aluno::Nivel::GRADUACAO,
        "12345678"
    );

    cout << *p << endl;

    p = make_unique<Funcionario>(
        "Evagina Rosa",
        time(0),
        Pessoa::Genero::TRANSGenero,
        time(0),
        Funcionario::Cargo::GERENTE
    );

    cout << *p << endl;

    return 0;
}

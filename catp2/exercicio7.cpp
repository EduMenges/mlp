#include <memory>
#include <vector>

#include "catp1/Aluno.hpp"
#include "catp1/Pessoa.hpp"
#include "catp2/Funcionario.hpp"

using namespace std;

/*
Faça um vetor que aceite Pessoas, Alunos e Funcionários. Depois, inclua randomicamente algumas
pessoas, alunos e funcionários (10 no total). Finalmente, faça o laço imprimir os elementos
adequados (por vinculação dinâmica).
*/
int main() {
    vector<unique_ptr<Pessoa>> vetor;
    vetor.reserve(10);
    vetor.emplace_back(make_unique<Aluno>(
        "Carlos Silva",
        time(0),
        Pessoa::Genero::HOMEM_CIS,
        Aluno::Nivel::GRADUACAO,
        "12345678"
    ));
    vetor.emplace_back(make_unique<Funcionario>(
        "Evagina Rosa",
        time(0),
        Pessoa::Genero::TRANSGenero,
        time(0),
        Funcionario::Cargo::GERENTE
    ));
    vetor.emplace_back(make_unique<Aluno>(
        "Tomas Turbando",
        time(0),
        Pessoa::Genero::HOMEM_CIS,
        Aluno::Nivel::DOUTORADO,
        "81968487"
    ));
    vetor.emplace_back(make_unique<Pessoa>("Amavel Pinto", time(0), Pessoa::Genero::NAO_BINARIO));
    vetor.emplace_back(make_unique<Funcionario>(
        "Paula Tejando",
        time(0),
        Pessoa::Genero::MULHER_CIS,
        time(0),
        Funcionario::Cargo::ANALISTA
    ));
    vetor.emplace_back(make_unique<Aluno>(
        "Cuca Beludo",
        time(0),
        Pessoa::Genero::INDEFINIDO,
        Aluno::Nivel::ESPECIALIZACAO,
        "12345678"
    ));
    vetor.emplace_back(make_unique<Aluno>(
        "Ana Konda",
        time(0),
        Pessoa::Genero::NAO_BINARIO,
        Aluno::Nivel::MESTRADO,
        "69420360"
    ));
    vetor.emplace_back(make_unique<Funcionario>(
        "Jacinto Pinto",
        time(0),
        Pessoa::Genero::HOMEM_CIS,
        time(0),
        Funcionario::Cargo::ESTAGIARIO
    ));
    vetor.emplace_back(make_unique<Pessoa>("Zeca Gado", time(0), Pessoa::Genero::HOMEM_CIS));
    vetor.emplace_back(make_unique<Pessoa>("Paula Noku", time(0), Pessoa::Genero::MULHER_CIS));

    for (auto& pessoa : vetor) {
        cout << pessoa << endl;
    }
}

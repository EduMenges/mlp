#include "catp1/DataEHora.hpp"
#include "catp1/Pessoa.hpp"

/*
Crie uma classe Funcionario, filha de Pessoa. Essa classe, além dos herdados de Pessoa, tem os
seguintes atributos:
  - Data Ingresso (não pode ser anterior ao nascimento da pessoa nem posterior ao dia de hoje)
  - Cargo (uma enumeração com as seguintes possibilidades: ESTAGIARIO, PROGRAMADOR-JUNIOR,
PROGRAMADOR-PLENO, ANALISTA, GERENTE)
*/

class Funcionario : public Pessoa {
  public:
    enum class Cargo { ESTAGIARIO, PROGRAMADOR_JUNIOR, PROGRAMADOR_PLENO, ANALISTA, GERENTE };

    Funcionario(
        std::string &&nome,
        DataEHora dt_nascimento,
        Pessoa::Genero genero,
        DataEHora dt_ingresso,
        Cargo cargo
    )
        : Pessoa(nome, dt_nascimento, genero),
          dt_ingresso(dt_ingresso),
          cargo(cargo) {
        const auto chrono_nascimento =
            std::chrono::system_clock::from_time_t(dt_nascimento.epoch_time);
        const auto chrono_ingresso = std::chrono::system_clock::from_time_t(dt_ingresso.epoch_time);

        if (chrono_ingresso < chrono_nascimento) {
            throw std::invalid_argument(
                "A data de ingresso não pode ser menor do que a data de nascimento!"
            );
        }
        std::cout << "> [Funcionario] Construtor chamado." << std::endl;
    }

    DataEHora dt_ingresso;
    Cargo cargo;
};

std::ostream &operator<<(std::ostream &, const Funcionario &);

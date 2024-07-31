#pragma once

#include "exercicio1/Pessoa.hpp"

/**
5) Na classe Aluno, inclua um atributo para representar a data de matrícula e
garanta que os atributos obedeçam aos seguintes critérios, tanto no construtor
quanto nos setters (caso não obedeçam, gere exceções apropriadas):
  - matricula tem de ter 8 digitos numéricos (dentro da String)
  - data de matrícula não pode ser maior do que o dia atual nem menor do que a data de nascimento

Para tanto, você pode usar qualquer mecanismo.
*/
class Aluno : public Pessoa {
  public:
    enum NIVEL { INDEFINIDO, GRADUACAO, ESPECIALIZACAO, MESTRADO, DOUTORADO };

    Aluno(
        std::string = "INDEFINIDO",
        DataEHora = time(0),
        GENERO = Pessoa::INDEFINIDO,
        NIVEL = INDEFINIDO,
        std::string = "INDEFINIDO"
    ) {
        this->set_nome(nome);
        this->set_dt_nascimento(dt_nascimento);
        this->set_genero(genero);
        this->set_nivel(nivel);
        this->set_matricula(matricula);
        std::cout << "> [Aluno] Construtor chamado." << std::endl;
    }

    void set_nivel(NIVEL nivel) { this->nivel = nivel; }

    void set_matricula(std::string matricula) {
        if (matricula.length() != 8) {
            throw std::invalid_argument("A matrícula deve possuir exatamente 8 dígitos!");
        }

        for (auto ch : matricula) {
            if (!std::isdigit(ch)) {
                throw std::invalid_argument("A matrícula só pode ter dígitos numéricos!");
            }
        }

        this->matricula = matricula;
    }

    void set_dt_matricula(DataEHora dt_matricula) {
        const auto chrono_nascimento =
            std::chrono::system_clock::from_time_t(dt_nascimento.epoch_time);
        const auto chrono_matricula =
            std::chrono::system_clock::from_time_t(dt_matricula.epoch_time);

        if (chrono_nascimento > chrono_matricula) {
            throw std::invalid_argument(
                "A data de matrícula não pode ser menor do que a data de nascimento!"
            );
        }

        this->dt_nascimento = dt_nascimento;
    }

  private:
    NIVEL nivel;
    std::string matricula;
    time_t dt_matricula;
};

std::ostream &operator<<(std::ostream &, const Aluno &);

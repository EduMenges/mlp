#pragma once

#include <chrono>
#include <iostream>
#include <string>

#include "exercicio1/DataEHora.hpp"

/**
 2) Garanta que os atributos de uma Pessoa obedeçam aos seguintes critérios,
 tanto no construtor quanto nos setters (caso não obedeçam, gere exceções
 apropriadas):

  - nome deve ter o formato "Nome Sobrenome", não pode conter números
  - data de nascimento não pode ser maior do que o dia atual
*/
class Pessoa {
  public:
    enum GENERO { INDEFINIDO, HOMEM_CIS, MULHER_CIS, NAO_BINARIO, TRANSGENERO };

    Pessoa(
        std::string nome = "INDEFINIDO",
        DataEHora dt_nascimento = time(0),
        GENERO genero = INDEFINIDO
    ) {
        this->set_nome(nome);
        this->set_dt_nascimento(dt_nascimento);
        this->set_genero(genero);
        std::cout << "> [Pessoa] Construtor chamado." << std::endl;
    }

    /*
      3) Implemente um construtor de cópia e sobrecarregue o operador de
      atribuição (operator=) para que façam cópia profunda de Pessoas. Desenvolva
      exemplifique o uso de ambos no programa principal.
    */
    Pessoa(const Pessoa &outra) {
        std::cout << "> [Pessoa] Construtor de Cópia chamado." << std::endl;

        this->set_dt_nascimento(outra.dt_nascimento);
        this->set_genero(outra.genero);
        this->set_nome(outra.nome);
    }

    virtual Pessoa &operator=(const Pessoa &outra) {
        std::cout << "> [Pessoa] operator= chamado." << std::endl;

        if (this != &outra) {
            this->set_dt_nascimento(outra.dt_nascimento);
            this->set_genero(outra.genero);
            this->set_nome(outra.nome);
        }

        return *this;
    }

    std::string get_nome() const { return this->nome; }

    DataEHora get_dt_nascimento() const { return this->dt_nascimento; }

    GENERO get_genero() const { return this->genero; }

    void set_nome(const std::string nome) {
        for (auto ch : nome) {
            if (std::isdigit(ch)) {
                throw std::invalid_argument("O nome não pode possuir um número como carectere!");
            }
        }

        size_t spaces = 0;
        for (auto ch : nome) {
            if (std::isspace(ch)) {
                spaces += 1;
                if (spaces > 1) {
                    throw std::invalid_argument("O nome deve estar no formato 'Nome Sobrenome'!");
                }
            }
        }

        this->nome = nome;
    }

    void set_dt_nascimento(const DataEHora dt_nascimento) {
        const auto now = std::chrono::system_clock::now();
        const auto chrono_time = std::chrono::system_clock::from_time_t(dt_nascimento.epoch_time);

        if (chrono_time >= now) {
            throw std::invalid_argument("A data de nascimento não pode ser maior do que a atual!");
        }

        this->dt_nascimento = dt_nascimento;
    }

    void set_genero(const GENERO genero) { this->genero = genero; }

  protected:
    std::string nome;
    DataEHora dt_nascimento;
    GENERO genero;
};

// sobrecarga do operator<< para atuar com Pessoa::Genero
std::ostream &operator<<(std::ostream &, const Pessoa::GENERO);
std::ostream &operator<<(std::ostream &, const Pessoa &);

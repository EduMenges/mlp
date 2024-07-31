#include <iostream>
#include <string>

#include "exercicio1/Pessoa.hpp"

// 4) Prove que o código seguinte faz coisas diferentes. Modifique o código da
// classe, se necessário:

int main() {
    Pessoa p("Tomas Turbando");

    Pessoa p2 = p;
    p2.set_nome("Seuku Myadora");

    Pessoa p3;
    p3 = p;
    p3.set_nome("Sujiro Kimimame");

    std::cout << "`p` tem nome " << p.get_nome() << '\n'
              << "`p2` tem nome " << p2.get_nome() << '\n'
              << "`p3` tem nome " << p3.get_nome() << '\n';
}

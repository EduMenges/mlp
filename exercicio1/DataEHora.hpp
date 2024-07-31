#pragma once

#include <ctime>

// 1) Crie uma classe que represente datas e horas (de maneira agregada ou
// separada), facilitando o seu uso no programa. Use essa classe em Pessoa, para
// representar datas e horas.
class DataEHora {
  public:
    DataEHora(time_t time) : epoch_time(time) {}

    DataEHora() = default;

    time_t epoch_time = 0;
};

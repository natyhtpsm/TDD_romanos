#include "./romanos.hpp"
#include <string>
#include <iostream>

int valor_romano(char algarismo) {
  switch (algarismo) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return -1;
  }
}

std::string valor_decimal(int algarismo) {
  switch (algarismo) {
    case 1:
      return "I";
    case 5:
      return "V";
    case 10:
      return "X";
    case 50:
      return "L";
    case 100:
      return "C";
    case 500:
      return "D";
    case 1000:
      return "M";
    default:
      return 0;
  }
}

int romanos_para_decimal(const char* num_romano) {
  int resultado = 0;
  int tamanho = std::string(num_romano).length();
  int repeticao = 1;

  for (int i = 0; i < tamanho; i++) {
    int valor_atual = valor_romano(num_romano[i]);
      if (valor_atual == -1) {
        return -1;
      }

        if (i > 0 && num_romano[i] == num_romano[i - 1]) {
            repeticao++;
            if (repeticao > 3) {
                return -1;
            }
        } else {
            repeticao = 1;
        }

        if (i < tamanho - 1 && valor_romano(num_romano[i + 1]) > valor_atual) {
            resultado -= valor_atual;
        } else {
            resultado += valor_atual;
        }
    }

    std::string romano_convertido;
    for (int i = 0; i < resultado; i++) {
        romano_convertido += valor_decimal(resultado);
    }
    if (romano_convertido != num_romano) {
        return -1;
    }

  return resultado;
}

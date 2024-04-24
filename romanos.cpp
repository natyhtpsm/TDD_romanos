#include "romanos.hpp"

int valor_romano(char algarismo) {
  switch(algarismo) {
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
      return 0; 
  }
}

int romanos_para_decimal(const char* num_romano) {
  int resultado = 0;
  int i = 0; 
  while (num_romano[i]) {
    if (valor_romano(num_romano[i]) < valor_romano(num_romano[i + 1])) {
        resultado -= valor_romano(num_romano[i]);
      } else {
          resultado += valor_romano(num_romano[i]);
      }
      i++;
    }
    
  return resultado;
}

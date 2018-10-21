#ifndef NO_HPP
#define NO_HPP

#include <iostream>

struct No {
  int dado;
  int esquerda;
  int direita;
  int equilibrio;

  No(int i) {
    this->dado       = i;
    this->esquerda   = -1;
    this->direita    = -1;
    this->equilibrio = 0;
  }

  No() {
    this->dado        = -1;
    this->esquerda    = -1;
    this->direita     = -1;
    this->equilibrio = 0;
  }

  friend std::ostream& operator<<(std::ostream& os, const No& n) {
    os << "{ data: " << n.dado << ", left: " << n.esquerda << ", right: " << n.direita << ", factor:" << n.equilibrio << " }";
    return os;
  }
};

#endif

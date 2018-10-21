#include <iostream>
#include <fstream>
#include <string.h>
#include "ArvoreEmDisco.hpp"

using namespace std;

struct Aluno
{
    int ra;
    const char * nome;

    Aluno(int ra, const char * nome)
    {
        this->ra = ra;
        this->nome = nome;
    }

    Aluno(int ra)
    {
        this->ra = ra;
        this->nome = "";
    }

    Aluno()
    {
        this->ra = 0;
        this->nome = "";
    }

    bool operator<(const Aluno& comparado)
    {
        return this->ra < comparado.ra;
    }

    bool operator>(const Aluno& comparado)
    {
        return this->ra > comparado.ra;
    }

    friend ostream& operator<<(ostream& os, const Aluno& a)
    {
        os << "{ ra: " << a.ra << ", nome: " << a.nome << " }";

        return os;
    }
};

int main()
{
    ArvoreEmDisco<Aluno> arvore ("tabela.dat", "arvore.dat",Aluno(-1));
   // arvore.inserir(Aluno(16159,"Alexandre Ladeira"));

   cout << arvore.get(Aluno(16159));


    cout << "Hello world!" << endl;
    return 0;
}

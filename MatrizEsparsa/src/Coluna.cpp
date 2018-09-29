#include "Coluna.h"

Coluna::Coluna(unsigned int valor, InformacaoDeArvoreAVL * info)
{
    this->valor = valor;
    this->informacao = info;
}
unsigned int Coluna::getValor()
{
    return this->valor;
}
InformacaoDeArvoreAVL * Coluna::getInformacao()
{
    return this->informacao;
}

int Coluna::compareTo(InformacaoDeArvoreAVL * informacao)
{
 if(informacao == NULL)
       throw invalid_argument("A linha nao pode ser nula para comparar");

    Coluna* coluna = (Coluna*) informacao;

    if(this->getValor() > coluna->getValor())
        return 1;

    if(this->getValor() < coluna->getValor())
        return -1;

    return 0;
}

const char* Coluna::toString()
{
  return this->informacao->toString();
}


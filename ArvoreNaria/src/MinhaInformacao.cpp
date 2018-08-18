#include "MinhaInformacao.h"


MinhaInformacao::MinhaInformacao(int num)
{
    this->meuNumero = num;
}

int MinhaInformacao::getNumero()
{
    return this->meuNumero;
}

void MinhaInformacao::setNumero(int num)
{
    this->meuNumero = num;
}

int MinhaInformacao::compareTo(InformacaoDeArvoreNaria * informacao)
{
    if(informacao == NULL)
       throw "A informacao nao pode ser nula para comparar";

    MinhaInformacao* info = (MinhaInformacao*) informacao;

    if(this->meuNumero > info->getNumero())
        return 1;

    if(this->meuNumero < info->getNumero())
        return -1;

    return 0;


}

void MinhaInformacao::printar()
{
    std::cout << this->getNumero();
}

const char* MinhaInformacao::toString()
{
  std::stringstream strs;
  strs << this->meuNumero;
  std::string cadeiaTemporaria = strs.str();
  const char* cadeia = (char*) cadeiaTemporaria.c_str();

  return cadeia;
}





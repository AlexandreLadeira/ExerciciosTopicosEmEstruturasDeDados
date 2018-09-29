#include "Linha.h"

Linha::Linha(unsigned int valor)
{
   this->valor = valor;
}

unsigned int Linha::getValor()
{
    return this->valor;
}

Coluna * Linha::getColuna(unsigned int c)
{
    Coluna col(c,NULL);

    return (Coluna*)this->colunas.get(&col);
}


int Linha::compareTo(InformacaoDeArvoreAVL * informacao)
{
 if(informacao == NULL)
       throw invalid_argument("A linha nao pode ser nula para comparar");

    Linha* linha = (Linha*) informacao;

    if(this->getValor() > linha->getValor())
        return 1;

    if(this->getValor() < linha->getValor())
        return -1;

    return 0;
}

const char* Linha::toString()
{
  const char* cadeia = (const char*) this->valor;

  return cadeia;
}

bool Linha::insereColuna(unsigned int valor,InformacaoDeArvoreAVL * info)
{
    Coluna col(valor,info);

    if(this->colunas.tem(&col))
        return false;

    this->colunas.inserir(&col);

    return true;
}

bool Linha::excluiColuna(unsigned int c)
{
    Coluna col(c,NULL);

    if(this->colunas.tem(&col))
    {
         this->colunas.excluir(&col);
         return true;
    }

    return false;

}




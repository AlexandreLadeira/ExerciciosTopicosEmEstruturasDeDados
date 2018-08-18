#include "ArvoreNaria.h"


ArvoreNaria::ArvoreNaria(unsigned int n)
{
    if(n < 2)
        throw invalid_argument("O n da arvore deve ser de no minimo 2");

    this->n = n;
    this->raiz = NULL;
}



NoDeArvoreNaria* ArvoreNaria::getRaiz()
{
    return this->raiz;
}

void ArvoreNaria::guarde(InformacaoDeArvoreNaria* info)
{
    if(this->raiz == NULL)
        this->raiz = new NoDeArvoreNaria(this->n);

    this->raiz->guarde(info);
}

void ArvoreNaria::exclua(InformacaoDeArvoreNaria* info)
{
    if(this->raiz == NULL)
        throw invalid_argument("Nao existem informacoes para serem excluidas");

    this->raiz->exclua(info);
}


ostream& operator << (ostream& os, const ArvoreNaria& arv)
{
    arv.raiz->montaOsArvore(os);

    return os;
}







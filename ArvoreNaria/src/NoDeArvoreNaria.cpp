#include "NoDeArvoreNaria.h"

NoDeArvoreNaria::NoDeArvoreNaria(unsigned int n) throw()
{
   this->vetInfo    = new InformacaoDeArvoreNaria*[n-1];
   this->vetPtr     = new NoDeArvoreNaria*[n];
   this->n          = n;
   this->qtdInfos   = 0;

   int i = 0;

   for(;i < n; i++)
        this->vetPtr[i] = NULL;
}

InformacaoDeArvoreNaria* NoDeArvoreNaria::getInfo(unsigned int i) throw (char*)
{
    if( i > n-1)
        throw "Indice invalido";


   // cout << "{" << i << " : " << this->qtdInfos << " ";

   // for(int n = 0; n < this->qtdInfos; n++)
    //  this->vetInfo[n]->printar();
    //cout << " }";
    return this->vetInfo[i];
}


NoDeArvoreNaria* NoDeArvoreNaria::getPtr(unsigned int i) throw (char*)
{
    if( i > n)
        throw "Indice invalido";

    return this->vetPtr[i];
}

int NoDeArvoreNaria::haEspaco() throw()
{
    if(this->qtdInfos < n-1)
        return 1;

        return 0;
}

void NoDeArvoreNaria::inserirInformacao(InformacaoDeArvoreNaria* info) throw (char *)
{
    if(!this->haEspaco())
        throw "Nao ha espaco no no";


    if(this->qtdInfos == 0)
    {
        this->vetInfo[0] = info;
        this->qtdInfos++;
    }
    else
    {
        int i = 0;

        for(; i < this->qtdInfos; i++)
            if(this->vetInfo[i]->compareTo(info) > 0)
                break;

       int j = this->qtdInfos;

       for(; j >= i + 1; j--)
        this->vetInfo[j] = this->vetInfo[j -1];

       vetInfo[i] = info;
       this->qtdInfos++;

    }


}

void NoDeArvoreNaria::criaNoNaPosicao(unsigned int i)
{
    NoDeArvoreNaria novoNo(this->n);
    this->vetPtr[i] = &novoNo;
    this->qtdNos++;

}

int NoDeArvoreNaria::procuraInformacao(InformacaoDeArvoreNaria* info) throw(char*)
{
    if(info == NULL)
        throw "a informacao procurada nao pode ser nula";

    int incio,meio,fim;

    incio   = 0;
    fim     = this->qtdInfos;


    while(incio < fim)
    {
        meio = (incio+fim)/2;
        if(this->getInfo(meio)->compareTo(info) == 0)
            return meio;
        if(this->getInfo(meio)->compareTo(info) < 0)
            incio = meio + 1;
        else
            fim = meio -1;
    }

    return -1;



}

unsigned int NoDeArvoreNaria::getQtdNos() throw()
{
    return this->qtdNos;
}

void NoDeArvoreNaria::printaInfos() throw()
{
    int i = 0;

    for(;i < this->qtdInfos;i++)
      this->getInfo(i)->printar();

    //cout << "OI";


}

ostream& operator<<(ostream& os, const NoDeArvoreNaria& no)
{
    os << no.qtdInfos << endl;
    return os;
}







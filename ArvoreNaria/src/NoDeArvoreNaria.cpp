#include "NoDeArvoreNaria.h"

NoDeArvoreNaria::NoDeArvoreNaria(unsigned int n)
{
   this->vetInfo    = new InformacaoDeArvoreNaria*[n-1];
   this->vetPtr     = new NoDeArvoreNaria*[n];
   this->n          = n;
   this->qtdInfos   = 0;

   int i = 0;

   for(;i < n; i++)
        this->vetPtr[i] = NULL;
}

InformacaoDeArvoreNaria* NoDeArvoreNaria::getInfo(unsigned int i) const
{
    if( i > n-1)
        throw invalid_argument("Indice invalido");

    return this->vetInfo[i];
}


NoDeArvoreNaria* NoDeArvoreNaria::getPtr(unsigned int i)
{
    if( i > n)
        throw invalid_argument("Indice invalido");

    return this->vetPtr[i];
}

int NoDeArvoreNaria::haEspaco()
{
    if(this->qtdInfos < n-1)
        return 1;

        return 0;
}

unsigned int NoDeArvoreNaria::getQtdNos()
{
    return this->qtdNos;
}

void NoDeArvoreNaria::inserirInformacao(InformacaoDeArvoreNaria* info)
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


int NoDeArvoreNaria::procuraInformacao(InformacaoDeArvoreNaria* info)
{
    if(info == NULL)
        throw invalid_argument("a informacao procurada nao pode ser nula");

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

void NoDeArvoreNaria::guarde(InformacaoDeArvoreNaria* info)
{
    if(info == NULL)
        throw invalid_argument("A informacao nao pode ser nula");

    if(this->procuraInformacao(info) >= 0)
        throw invalid_argument("Informacoes repetidas nao podem ser inseridas");

    if(!this->haEspaco())
    {
        if(info->compareTo(this->getInfo(0)) < 0)
        {
            if(this->vetPtr[0] == NULL)
                this->vetPtr[0] = new NoDeArvoreNaria(this->n);

            this->vetPtr[0]->guarde(info);
        }
        else if(info->compareTo(this->getInfo(this->n - 2)) > 0)
        {
            if(this->vetPtr[n - 1] == NULL)
                this->vetPtr[n - 1] = new NoDeArvoreNaria(this->n);

            this->vetPtr[n - 1]->guarde(info);
        }
        else
        {
             int i = 0;

            for(; i < this->n-2; i++)
                if(info->compareTo(this->getInfo(i)) > 0 && info->compareTo(this->getInfo(i+1)) <0)
                {
                    if(this->getPtr(i+1) == NULL)
                        this->vetPtr[i+1] = new NoDeArvoreNaria(this->n);

                    this->vetPtr[i+1]->guarde(info);
                }
        }


    }
    else
    {
        this->inserirInformacao(info);

    }

}

void NoDeArvoreNaria::exclua(InformacaoDeArvoreNaria* info)
{

}




void NoDeArvoreNaria::montaOsArvore(ostream& os)
{
   os << "(";

   for(int i = 0; i < this->qtdInfos ; i++)
    {
        if(this->getPtr(i) != NULL)
            this->getPtr(i)->montaOsArvore(os);

        os << " ";
        os << this->getInfo(i)->toString();
        os << " ";

        if(this->getPtr(i + 1) != NULL)
        {
            this->getPtr(i + 1)->montaOsArvore(os);
        }
    }

    os << ")";
}

ostream& operator<<(ostream& os, const NoDeArvoreNaria& no)
{
    for(int i = 0;i < no.qtdInfos;i++)
    {
        cout<<" ";
        os << no.getInfo(i)->toString();
        cout<<" ";
    }

    return os;
}







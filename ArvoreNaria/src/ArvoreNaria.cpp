#include "ArvoreNaria.h"


ArvoreNaria::ArvoreNaria(unsigned int n) throw (char*)
{
    if(n < 2)
        throw "O n da arvore deve ser de no minimo 2";

    this->n = n;
    this->raiz = new NoDeArvoreNaria(n);
}



NoDeArvoreNaria* ArvoreNaria::getRaiz() throw()
{
    return this->raiz;
}

void ArvoreNaria::guarde(InformacaoDeArvoreNaria* info, NoDeArvoreNaria* no) throw (char*)
{
    if(info == NULL)
        throw "A informacao a ser inserida nao pode ser nula!";

    if(no == NULL)
    {
        no = new NoDeArvoreNaria(this->n);
        no->inserirInformacao(info);
        return;
    }

    if(no->procuraInformacao(info) >= 0)
            throw "A informacao ja existe";

    if(!no->haEspaco())
    {
        if(info->compareTo(no->getInfo(0)) < 0)
        {
            if(no->getPtr(0) == NULL)
                no->criaNoNaPosicao(0);

            guarde(info,no->getPtr(0));
        }

        else
            if(info->compareTo(no->getInfo(this->n - 2)) > 0 )
            {
                if(no->getPtr(this->n-1) == NULL)
                    no->criaNoNaPosicao(this->n - 1);

                //no->getPtr(this->ptr)
                guarde(info,no->getPtr(this->n - 1));
            }

            else
            {
                int i = 0;

                for(; i < this->n-2; i++)
                    if(info->compareTo(no->getInfo(i)) > 0 && info->compareTo(no->getInfo(i+1)) <0)
                    {
                        if(no->getPtr(i+1) == NULL)
                            no->criaNoNaPosicao(i+1);

                        guarde(info,no->getPtr(i+1));
                    }


            }
    }
    else
        no->inserirInformacao(info);

}


ostream& operator << (ostream& os, const ArvoreNaria& arv)
{
    os << "Teste";
    os << "Mais UmTestes";
    return os;
}

void ArvoreNaria::printaArvore(NoDeArvoreNaria* no) throw()
{
    if(no != NULL)
    {
        no->printaInfos();

        int i = 0;

        for(;i < no->getQtdNos();i++)
            printaArvore(no->getPtr(i));
    }


}






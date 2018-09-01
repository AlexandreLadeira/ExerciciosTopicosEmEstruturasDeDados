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

int NoDeArvoreNaria::ehFolha()
{
    for(int  i = 0; i < this->n; i++)
        if(this->getPtr(i) != NULL)
            return 0;

    return 1;
}

unsigned int NoDeArvoreNaria::getQtdNos()
{
    return this->qtdNos;
}

unsigned int NoDeArvoreNaria::getQtdInfos()
{
    return this->qtdInfos;
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
   /* for(int i = 0; i < this->qtdInfos; i++)
        if(this->vetInfo[i]->compareTo(info) == 0)
            return i;

    return -1; */

   if(info == NULL)
        throw invalid_argument("a informacao procurada nao pode ser nula");

    int incio,meio,fim;

    incio   = 0;
    fim     = this->qtdInfos - 1;


    while(incio <= fim)
    {
        meio = (incio+fim)/2;
        if(this->getInfo(meio) == NULL)
            return -1;
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
                    if(this->vetPtr[i+1] == NULL)
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
void NoDeArvoreNaria::removerInformacaoDaPosicao(unsigned int pos)
{
    if( pos > this->getQtdInfos())
       throw invalid_argument("Posicao inválida para excluir");

    int i = pos;

    for( ; i < this->qtdInfos - 1 ; i++ )
        this->vetInfo[i] = this->vetInfo[i + 1];

    this->vetInfo[i] = NULL;
    this->qtdInfos--;

}

void NoDeArvoreNaria::exclua(InformacaoDeArvoreNaria* info)
{
    int i = 0;

    for (; i < this->qtdInfos; i++)
        if (this->getInfo(i)->compareTo(info) >= 0) // definindo onde o nó pode estar.
            break;                                  // >  0; para e i fica com a posicao que devemos procurar no vet ptr.
                                                    // == 0; está nesse nó, logo precisamos remover dele.
                                                    // <  0; i fica com a qtdInfos; logo devemos procurar no vetPtr[i];
    if(!this->ehFolha())
    {   //Essas duas coindicoes garantem que se a informacao nao está no nó atual,
        //a procura irá pra o nó indicado por i (Se possivel)
        if( this->getPtr(i) != NULL && (
            (i < this->qtdInfos && this->getInfo(i)->compareTo(info) > 0) || i == this->qtdInfos ))
        {
            NoDeArvoreNaria* no = this->getPtr(i); // vai para o nó em que a informacao pode estar
            no->exclua(info);

            if(no->getQtdInfos() == 0) // se não exitem mais informações no nó libera o espaço na memoria
            {                          // e faz com que ponteiro indicado por vetPtr[i] para ele fique NULL
                delete this->getPtr(i);
                this->vetPtr[i] = NULL;
            }
        }
        else if(this->getInfo(i)->compareTo(info) == 0) // se está em um nó que não é folha
        {
            if(this->getPtr(i) != NULL) //Possibilidade I
                this->substituirInformacao(i,i,this->getPtr(i)->qtdInfos - 1);
            else if(this->getPtr(i + 1) != NULL)//Possibilidade I
                this->substituirInformacao(i + 1,i,0);
            else //Possibilidade II
            {
                if(this->escolherUmLado(i)) // tem filho na esquerda; desloca para a direita
                    for(int j = i ; j >= 0; j--)
                    {
                        if(this->getPtr(j) != NULL)
                        {
                            this->substituirInformacao(j,j,0);
                            break;
                        }
                        this->vetInfo[j] = this->vetInfo[j - 1];
                    }
                else // tem filho a direita, desloca para a esquerda
                    for(int j = i ; j <= this->qtdInfos ; j++)
                    {
                        if(this->getPtr(j + 1) != NULL)
                        {
                            this->substituirInformacao(j+1,j,this->getPtr(j+1)->qtdInfos - 1);
                            break;
                        }
                        this->vetInfo[j] = this->vetInfo[j + 1];
                    }
            }

            /*Possibildiade I: a informação a ser removida está em uma certa posição i
            do vetInfos e pelos menos um dos ponteiros que estão na posição i e na posição
            i+1 são diferentes de nulo. Aqui esncontramos na subarvore que se inicia no ponteiro
            i a MAIOR informação ou na subarvore que se inicia no ponteiro i+1 a menor informação,
            removendo tal informação  e usando-a para substituir a informação que desejavamos
            excluir no principio */

            /*Possibilidade II: A informação a ser excluida está em uma certa posição i do vetInfo
            e são nulos os ponteiros que estão na posição i e na posição i+1 do vetPtr. Aqui deslocamos
            as informações que estão a esquerda ou a direita ruma a informação que desejamos excluir;
            encerrando o deslocamento quando nos depararmos com uma informação que estava em uma certa
            posição j do vetInfo e não eram nulos um dos ponteiros, ou da posição j ou da posição j+1.
            (Escolhemos um lado levando em conta a existencia de filhos). Depois encontramos a  maior informação
            na subarvore que se inicia com na posicao j ou a menor na posicao j+1 para substituir a informação
            que desejavamos excluir no principio
            */

        }
    }       // se está em um nó que é folha, só devemos excluir
    else if(this->getPtr(i) != NULL && this->vetInfo[i]->compareTo(info) == 0)
                this->removerInformacaoDaPosicao(i);





}

//Escolhe um lado do nó que tenha filhos. Esquerda == true; Direita == false;
bool NoDeArvoreNaria::escolherUmLado(unsigned int indice)
{
    // percorre do indice esquerda do indice para a direita
    for(int i = indice + 1; i <= this->qtdInfos; i++ )
        if(this->getPtr(i) != NULL)
            return false;

    return true;
}

void NoDeArvoreNaria::substituirInformacao(unsigned int indicePtr,unsigned int indiceInfo, unsigned int limite)
{
    NoDeArvoreNaria* no = this->getPtr(indicePtr);

    //Pega a informação (maior ou menor, dependndo do indice e do limite).
    //Coloca ela por cima no vetInfo e exclui de sua posicao antiga
    InformacaoDeArvoreNaria* info = no->getInfo(limite);
    this->vetInfo[indiceInfo] = info;
    no->exclua(info);
    if(no->getQtdInfos() == 0)
    {
        delete this->getPtr(indicePtr);
        this->vetPtr[indicePtr] = NULL;
    }
}



void NoDeArvoreNaria::montaOsArvore(ostream& os)
{
   os << "(";

   int i;

   for(i = 0; i < this->qtdInfos; i++)
    {
        if(this->getPtr(i) != NULL)
            this->getPtr(i)->montaOsArvore(os);

        os << " ";
        os << this->getInfo(i)->toString();
        os << " ";
    }

    if(this->getPtr(this->n - 1) != NULL)
        this->getPtr(this->n - 1)->montaOsArvore(os);


    os << ")";
}

ostream& operator<<(ostream& os, const NoDeArvoreNaria& no)
{
    for(int i = 0;i < no.qtdInfos;i++)
    {
        os<<" ";
        os << no.getInfo(i)->toString();
        os<<" ";
    }

    return os;
}







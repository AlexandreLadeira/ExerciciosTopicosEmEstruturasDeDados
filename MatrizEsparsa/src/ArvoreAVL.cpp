#include "ArvoreAVL.h"

ArvoreAVL::ArvoreAVL()
{
    this->raiz = NULL;
    this->qtdNos = 0;
}

bool ArvoreAVL::tem(InformacaoDeArvoreAVL * procurada)
{
   return this->tem(this->raiz,procurada);
}

bool ArvoreAVL::tem(NoAVL * no, InformacaoDeArvoreAVL * procurada)
{
    if(no == NULL)
        return false;

    int comparacao = no->getInfo()->compareTo(procurada);

    // A info do no é maior, portanto deve ir para esquerda
    if(comparacao > 0)
        return this->tem(no->getEsquerda(), procurada);

    // A info do no é menor, portanto deve ir para direita
    if(comparacao < 0)
        return this->tem(no->getDireita(),procurada);

    //encontrou
    return true;

}

InformacaoDeArvoreAVL * ArvoreAVL::get(InformacaoDeArvoreAVL * procurada)
{
    return this->get(this->raiz,procurada);
}

InformacaoDeArvoreAVL * ArvoreAVL::get(NoAVL * no,InformacaoDeArvoreAVL * procurada)
{
    if(no == NULL)
        return NULL;

    int comparacao = no->getInfo()->compareTo(procurada);

    // A info do no é maior, portanto deve ir para esquerda
    if(comparacao > 0)
        return this->get(no->getEsquerda(), procurada);

    // A info do no é menor, portanto deve ir para direita
    if(comparacao < 0)
        return this->get(no->getDireita(),procurada);

    //encontrou
    return no->getInfo();
}

void ArvoreAVL::inserir(InformacaoDeArvoreAVL * novaInfo)
{

  if(novaInfo == NULL)
    throw invalid_argument("A informacao a ser inserida nao pode ser nula");

  if(!this->tem(this->raiz,novaInfo))
  {
      this->raiz = this->inserir(this->raiz,novaInfo);
      this->qtdNos++;

  }


}

NoAVL * ArvoreAVL::inserir(NoAVL * no, InformacaoDeArvoreAVL * novaInfo)
{
    // Fim da recursão, só cria um novo nó com a novaInfo
    if(no == NULL)
    {
         return new NoAVL(novaInfo);
    }

    //Se a nova info for menor dever inserir a esquerda
    if(novaInfo->compareTo(no->getInfo()) < 0)
        no->setEsquerda(this->inserir(no->getEsquerda(),novaInfo));
    else//insere na direita
        no->setDireita(this->inserir(no->getDireita(),novaInfo));

    //Mantendo o nó com altura e equilibrio corretos e
    //balanceando a arvore
    atualizaEquilibrioAltura(no);

    return this->balancear(no);
}

void ArvoreAVL::excluir(InformacaoDeArvoreAVL * info)
{
    if(info == NULL)
        throw invalid_argument("A informacao a asr excluida nao pode ser nula");

    if(tem(this->raiz,info))
    {
        this->raiz = excluir(this->raiz,info);
        this->qtdNos--;
    }
}

NoAVL * ArvoreAVL::excluir(NoAVL * no, InformacaoDeArvoreAVL * info)
{
    //Fim da recursão, devolve nulo para exlcuir o nó que chamou
    if(no == NULL)
        return NULL;

    int comparacao = info->compareTo(no->getInfo());

    //Está mais a esquerda.
    if(comparacao < 0)
        no->setEsquerda(this->excluir(no->getEsquerda(),info));
    // está mais a direita
    else if(comparacao > 0)
        no->setDireita(this->excluir(no->getDireita(),info));
    // O nó foi encontrado e n tem subavore a esquerda.
    else if(no->getEsquerda() == NULL)
        return no->getDireita();//Troca o nó que queremos excluir com o da direita
    // O nó foi encontrado e n tem subarvore a direita
    else if(no->getDireita() == NULL)
        return no->getEsquerda();//Troca o nó que queremos excluir com o da esquerda
    else // Se estamos removendo um nó que tem subarvores a direita e esquerda
    {
        //Vai remover da arvore que tiver a maior altura
        if(no->getEsquerda()->getAltura() > no->getDireita()->getAltura())
        {
            //Acha e troca o valor do nó com o Maior valor da arvore a esquerda
            InformacaoDeArvoreAVL * substituto = this->getMaiorInfo(no->getEsquerda());
            no->setInfo(substituto);

            no->setEsquerda(this->excluir(no->getEsquerda(),substituto));
        }
        else
        {
            //Acha e troca o valor do nó com o Maior valor da arvore a direita
            InformacaoDeArvoreAVL * substituto = this->getMenorInfo(no->getDireita());
            no->setInfo(substituto);
            no->setDireita(this->excluir(no->getDireita(),substituto));
        }
    }

    //Mantendo o nó com altura e equilibrio corretos e
    //balanceando a arvore
    this->atualizaEquilibrioAltura(no);

    return this->balancear(no);

}

//Retorna a maior info da arvore apontada pelo no
InformacaoDeArvoreAVL * ArvoreAVL::getMaiorInfo(NoAVL * no)
{
    while(no->getDireita() != NULL)
        no = no->getDireita();

    return no->getInfo();
}

//Retorna a menor info da arvore apontada pelo no
InformacaoDeArvoreAVL * ArvoreAVL::getMenorInfo(NoAVL * no)
{
     while(no->getEsquerda() != NULL)
        no = no->getEsquerda();

    return no->getInfo();
}


void ArvoreAVL::atualizaEquilibrioAltura(NoAVL * no)
{
    //Inicialização.
    int alturaEsquerda = -1;
    int alturaDireita  = -1;

    if(no->getEsquerda() != NULL && no->getEsquerda() != (void*) 0x1)
        alturaEsquerda = no->getEsquerda()->getAltura();

    if(no->getDireita() != NULL && no->getDireita() != (void*) 0x1)
        alturaDireita  = no->getDireita()->getAltura();

    int maior = (alturaDireita<alturaEsquerda)?alturaEsquerda:alturaDireita;

    // deixa a altura do no como 1 + a maior altura (esquerda ou direita)
    no->setAltura(1 + maior);

    //Atualiza o equlibrio do nó
    no->setEqulibrio(alturaDireita - alturaEsquerda);


}

//Balancei a arvore seguindo o paradigma de uma arvore AVL
NoAVL * ArvoreAVL::balancear(NoAVL * no)
{
    int equilibrio = no->getEquilibrio();

    if(equilibrio > 1)
        if(no->getDireita()->getEquilibrio() < 0)
            return rotacaoDuplaParaEsquerda(no);
        else
            return rotacaoParaEsquerda(no);
    else if(equilibrio < -1)
            if(no->getEsquerda()->getEquilibrio() > 0)
                return rotacaoDuplaParaDireita(no);
            else
                return rotacaoParaDireita(no);

    return no;

}

NoAVL* ArvoreAVL::rotacaoParaEsquerda(NoAVL * raiz)
{
    //Filho da direita vira nova raiz
    NoAVL * novaRaiz = raiz->getDireita();
    //O filho da esquerda da nova raiz vira o filho da direita da raiz original
    raiz->setDireita(novaRaiz->getEsquerda());
    //A raiz original vira o filha da esquerda da nova raiz
    novaRaiz->setEsquerda(raiz);
    //Atualiza o equilibrio da raiz e da nova raiz
    atualizaEquilibrioAltura(raiz);
    atualizaEquilibrioAltura(novaRaiz);
    //Retorna o trecho da arvore balanceado
    return novaRaiz;
}

NoAVL * ArvoreAVL::rotacaoParaDireita(NoAVL * raiz)
{
    //Filho da esquerda vira nova raiz
    NoAVL * novaRaiz = raiz->getEsquerda();
    //O filho da direta da nova raiz vira o filho da esquerda da raiz original
    raiz->setEsquerda(novaRaiz->getDireita());
    //A raiz original vira o filha da direita da nova raiz
    novaRaiz->setDireita(raiz);
    //Atualiza o equilibrio da raiz e da nova raiz
    atualizaEquilibrioAltura(raiz);
    atualizaEquilibrioAltura(novaRaiz);
    //Retorna o trecho da arvore balanceado
    return novaRaiz;

}

NoAVL * ArvoreAVL::rotacaoDuplaParaEsquerda(NoAVL * raiz)
{
    //Rotacionando para direita a subarvore da direita
    raiz->setDireita(rotacaoParaDireita(raiz->getDireita()));
    //Rotacionando para esquerda o todo
    return rotacaoParaEsquerda(raiz);

}

NoAVL * ArvoreAVL::rotacaoDuplaParaDireita(NoAVL * raiz)
{
    //Rotacionando para esquerda a subarvore da esquerda
    raiz->setEsquerda(rotacaoParaEsquerda(raiz->getEsquerda()));
    //Rotacionando para direita o todo
    return rotacaoParaDireita(raiz);
}

//Código traduzido do ingles para pt-br. Origem:
//https://stackoverflow.com/questions/41091382/how-to-print-in-console-a-tree-horizontally-with-links-using-c
void ArvoreAVL::desenhaArvore(NoAVL *no, int profundidade, char *caminho, int direita,ostream& os) const
{
    // fim da recursao
    if (no== NULL)
        return;

    // aumenta espacamento
    profundidade++;

    // comeca com o nó da direita
    desenhaArvore(no->getDireita(), profundidade, caminho, 1,os);

    // iniciando o caminho
    caminho[profundidade-2] = 0;

    if(direita)
        caminho[profundidade-2] = 1;

    if(no->getEsquerda())
        caminho[profundidade-1] = 1;

    // escreve a raiz depois de espacar
    os << "\n";

    for(int i=0; i<profundidade-1; i++)
    {
      if(i == profundidade-2)
          os <<("+");
      else if(caminho[i])
          os <<("|");
      else
          os <<(" ");

      for(int j=1; j<4; j++)
      if(i < profundidade-2)
          os <<(" ");
      else
          os <<("-");
    }

    os << ("%s\n",no->getInfo()->toString());



    // spaces na vertical de baixo
    for(int i=0; i<profundidade; i++)
    {
      if(caminho[i])
          os <<(" ");
      else
          os <<(" ");

      for(int j=1; j<4; j++)
          os <<(" ");
    }

    // vai para o nó da esquerda
    desenhaArvore(no->getEsquerda(), profundidade, caminho, 0,os);

}


void ArvoreAVL::desenhaArvore(ostream& os) const
{

    char path[255] = {};

    //profundidade inicial é 0
    desenhaArvore(this->raiz, 0, path, 0,os);
}



ostream& operator << (ostream& os, const ArvoreAVL& arv)
{
    if(arv.raiz != NULL)
        arv.desenhaArvore(os);

    return os;
}


//A estrutura e o funcionamento da arvore foram baseados no vídeo
//https://www.youtube.com/watch?v=tqFZzXkbbGY
//(AVL tree source cod, canal WilliamFiset, Publicado em 12 de nov de 2017)






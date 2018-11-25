
template <class T>
ArvoreAVL<T>::ArvoreAVL()
{
    this->raiz = NULL;
    this->qtdNos = 0;
}

template <class T>
bool ArvoreAVL<T>::tem(int chave)
{
   return this->tem(this->raiz,chave);
}

template <class T>
bool  ArvoreAVL<T>::tem(NoAVL<T> * no, int chaveProcurada)
{
    if(no == NULL)
        return false;

    // A info do no é maior, portanto deve ir para esquerda
    if(no->getChave() > chaveProcurada)
        return this->tem(no->getEsquerda(), chaveProcurada);

    // A info do no é menor, portanto deve ir para direita
    if(no->getChave() < chaveProcurada)
        return this->tem(no->getDireita(),chaveProcurada);

    //encontrou
    return true;

}

template <class T>
T* ArvoreAVL<T>::get(int chaveProcurada)
{
    return this->get(this->raiz,chaveProcurada);
}

template <class T>
T * ArvoreAVL<T>::get(NoAVL<T> * no,int chaveProcurada)
{
    if(no == NULL)
        return NULL;


    // A info do no é maior, portanto deve ir para esquerda
    if(no->getChave() > chaveProcurada)
        return this->get(no->getEsquerda(), chaveProcurada);

    // A info do no é menor, portanto deve ir para direita
    if(no->getChave() < chaveProcurada)
        return this->get(no->getDireita(),chaveProcurada);

    //encontrou
    return no->getInfo();
}

template <class T>
int ArvoreAVL<T>::getQtdNos()
{
   return this->qtdNos;
}

template <class T>
void ArvoreAVL<T>::inserir(int chave,T * novaInfo)
{

  if(novaInfo == NULL)
    throw invalid_argument("A informacao a ser inserida nao pode ser nula");

  if(!this->tem(this->raiz,chave))
  {
      this->raiz = this->inserir(this->raiz,novaInfo,chave);
      this->qtdNos++;

  }


}

template <class T>
NoAVL<T> * ArvoreAVL<T>::inserir(NoAVL<T> * no, T * novaInfo, int chave)
{
    // Fim da recursão, só cria um novo nó com a novaInfo
    if(no == NULL)
    {
         return new NoAVL<T>(chave,novaInfo);
    }

    //Se a nova info for menor dever inserir a esquerda
    if(chave < no->getChave())
        no->setEsquerda(this->inserir(no->getEsquerda(),novaInfo,chave));
    else//insere na direita
        no->setDireita(this->inserir(no->getDireita(),novaInfo,chave));

    //Mantendo o nó com altura e equilibrio corretos e
    //balanceando a arvore
    atualizaEquilibrioAltura(no);

    return this->balancear(no);
}

template <class T>
void ArvoreAVL<T>::excluir(int chave)
{
  //  if(chave == NULL)
  //      throw invalid_argument("A informacao a asr excluida nao pode ser nula");

    if(tem(this->raiz,chave))
    {
        this->raiz = excluir(this->raiz,chave);
        this->qtdNos--;
    }
}

template <class T>
NoAVL<T> * ArvoreAVL<T>::excluir(NoAVL<T> * no, int chave)
{
    //Fim da recursão, devolve nulo para exlcuir o nó que chamou
    if(no == NULL)
        return NULL;



    //Está mais a esquerda.
    if(no->getChave() > chave)
        no->setEsquerda(this->excluir(no->getEsquerda(),chave));
    // está mais a direita
    else if(no->getChave() < chave)
        no->setDireita(this->excluir(no->getDireita(),chave));
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
            T * substituto = this->getMaiorInfo(no->getEsquerda());
            int chaveSubstituto = this->getMaiorChave(no->getEsquerda());
            no->setInfo(substituto);
            no->setChave(chaveSubstituto);

            no->setEsquerda(this->excluir(no->getEsquerda(),chaveSubstituto));
        }
        else
        {
            //Acha e troca o valor do nó com o Maior valor da arvore a direita
            T * substituto = this->getMenorInfo(no->getDireita());
            int chaveSubstituto = this->getMenorChave(no->getDireita());
            no->setInfo(substituto);
            no->setChave(chaveSubstituto);
            no->setDireita(this->excluir(no->getDireita(),chaveSubstituto));
        }
    }

    //Mantendo o nó com altura e equilibrio corretos e
    //balanceando a arvore
    this->atualizaEquilibrioAltura(no);

    return this->balancear(no);

}

template <class T>
//Retorna a maior info da arvore apontada pelo no
T * ArvoreAVL<T>::getMaiorInfo(NoAVL<T> * no)
{
    while(no->getDireita() != NULL)
        no = no->getDireita();

    return no->getInfo();
}


template <class T>
//Retorna a menor info da arvore apontada pelo no
T * ArvoreAVL<T>::getMenorInfo(NoAVL<T> * no)
{
     while(no->getEsquerda() != NULL)
        no = no->getEsquerda();

    return no->getInfo();
}

template <class T>
//Retorna a maior info da arvore apontada pelo no
int ArvoreAVL<T>::getMaiorChave(NoAVL<T> * no)
{
    while(no->getDireita() != NULL)
        no = no->getDireita();

    return no->getChave();
}


template <class T>
//Retorna a menor info da arvore apontada pelo no
int ArvoreAVL<T>::getMenorChave(NoAVL<T> * no)
{
     while(no->getEsquerda() != NULL)
        no = no->getEsquerda();

    return no->getChave();
}


template <class T>
void ArvoreAVL<T>::atualizaEquilibrioAltura(NoAVL<T> * no)
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

template <class T>
//Balancei a arvore seguindo o paradigma de uma arvore AVL
NoAVL<T> * ArvoreAVL<T>::balancear(NoAVL<T> * no)
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

template <class T>
NoAVL<T>* ArvoreAVL<T>::rotacaoParaEsquerda(NoAVL<T> * raiz)
{
    //Filho da direita vira nova raiz
    NoAVL<T> * novaRaiz = raiz->getDireita();
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

template <class T>
NoAVL<T> * ArvoreAVL<T>::rotacaoParaDireita(NoAVL<T> * raiz)
{
    //Filho da esquerda vira nova raiz
    NoAVL<T> * novaRaiz = raiz->getEsquerda();
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

template <class T>
NoAVL<T>* ArvoreAVL<T>::rotacaoDuplaParaEsquerda(NoAVL<T> * raiz)
{
    //Rotacionando para direita a subarvore da direita
    raiz->setDireita(rotacaoParaDireita(raiz->getDireita()));
    //Rotacionando para esquerda o todo
    return rotacaoParaEsquerda(raiz);

}

template <class T>
NoAVL<T> * ArvoreAVL<T>::rotacaoDuplaParaDireita(NoAVL<T> * raiz)
{
    //Rotacionando para esquerda a subarvore da esquerda
    raiz->setEsquerda(rotacaoParaEsquerda(raiz->getEsquerda()));
    //Rotacionando para direita o todo
    return rotacaoParaDireita(raiz);
}

template <class T>
void ArvoreAVL<T>::printa()
{
    this->printa(this->raiz);
}

template <class T>
void ArvoreAVL<T>::printa(NoAVL<T>* no)
{

    if(no != NULL)
    {
    printa(no->getEsquerda());
    cout << no->getChave();
    printa(no->getDireita());
    }

}

template <class T>
//Código traduzido do ingles para pt-br. Origem:
//https://stackoverflow.com/questions/41091382/how-to-print-in-console-a-tree-horizontally-with-links-using-c
void ArvoreAVL<T>::desenhaArvore(NoAVL<T> *no, int profundidade, char *caminho, int direita,ostream& os) const
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

    os << ("%s\n",no->getChave());



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

template <class T>
NoAVL<T> * ArvoreAVL<T>::getRaiz()
{
   return this->raiz;
}

template <class T>
void ArvoreAVL<T>::desenhaArvore(ostream& os) const
{

    char path[255] = {};

    //profundidade inicial é 0
    desenhaArvore(this->raiz, 0, path, 0,os);
}

template <class T>
ostream& operator << (ostream& os, const ArvoreAVL<T>& arv)
{
    if(arv.raiz != NULL)
        arv.desenhaArvore(os);

    return os;
}

template <class T>
void ArvoreAVL<T>::montaOsSequencial(ostream& os)
{
   this->montaOsSequencial(this->raiz,os);
}
template <class T>
void ArvoreAVL<T>::montaOsSequencial(NoAVL<T> * no,ostream& os)
{
    if (no == NULL)
        return;

    this->montaOsSequencial(no->getEsquerda(),os);
    os << "(";
    os << no->getChave();
    os << ",";
    os << (*(no->getInfo()));
    os << ")";
    this->montaOsSequencial(no->getDireita(),os);
}


template <class T>
void ArvoreAVL<T>::montaOsSequencialGrafo(ostream& os,std::vector<Vertice> vertices)
{
   this->montaOsSequencialGrafo(this->raiz,os,vertices);
}

template <class T>
char * ArvoreAVL<T>::encontraNome(int indice, std::vector<Vertice> vertices)
{
    for(int i = 0; i < vertices.size(); i++)
        if(vertices[i].indice == indice)
            return vertices[i].nome;
}


template <class T>
void ArvoreAVL<T>::montaOsSequencialGrafo(NoAVL<T> * no,ostream& os,std::vector<Vertice> vertices)
{
    if (no == NULL)
        return;

    this->montaOsSequencialGrafo(no->getEsquerda(),os,vertices);
    os << "(";
    os << this->encontraNome(no->getChave(),vertices);
    os << ",";
    os << (*(no->getInfo()));
    os << ")";
    this->montaOsSequencialGrafo(no->getDireita(),os,vertices);
}






//A estrutura e o funcionamento da arvore foram baseados no vídeo
//https://www.youtube.com/watch?v=tqFZzXkbbGY
//(AVL tree source cod, canal WilliamFiset, Publicado em 12 de nov de 2017)






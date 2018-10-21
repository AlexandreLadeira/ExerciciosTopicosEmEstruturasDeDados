#include <stdexcept>
#include <stack>

template <class T>
ArvoreEmDisco<T>::ArvoreEmDisco(string arqTabela, string arqArvore, T padrao)
{
    //Definindo o nome do arquivo da tabela
    const char * tabelaNome = arqTabela.c_str();
    this->nomeTabela = strdup(tabelaNome);

    //Tenta abrir o arquivo binario da tabela, se não conseguir cria um
    this->arquivoTabela.open(tabelaNome, ios::out | ios::in | ios::binary);
    if(!this->arquivoTabela.is_open())
    {
        this->arquivoTabela.open(tabelaNome,ios::out);
        this->arquivoTabela.close();

        this->arquivoTabela.open(tabelaNome, ios::out | ios::in | ios::binary);
    }

    //Definindo o nome do arquivo da tabela
    const char * arvoreNome = arqArvore.c_str();
    this->nomeArvore = strdup(arvoreNome);

    //Tenta abrir o arquivo binario da tabela, se não conseguir cria um
    this->arquivoArvore.open(arvoreNome, ios::out | ios::in | ios::binary);
    if(!this->arquivoArvore.is_open())
    {
        this->arquivoArvore.open(arvoreNome,ios::out);
        this->arquivoArvore.close();

        this->arquivoArvore.open(arvoreNome, ios::out | ios::in | ios::binary);
    }

    this->valorPadrao = new T(padrao);

}

template <class T>
ArvoreEmDisco<T>::~ArvoreEmDisco()
{
    this->arquivoTabela.close();
    this->arquivoArvore.close();
    delete this->nomeTabela;
    delete this->nomeArvore;
}

template <class T>
void ArvoreEmDisco<T>::inserir(T dado)
{
    //Pega o tamanho do arquivo e divide pelo tamanho do registro,
    //assim fica com a quantidade de registros armazenada
    this->arquivoTabela.seekg(0,this->arquivoTabela.end);
    int quantidade = this->arquivoTabela.tellg() / sizeof(T);

    this->escreverDado(dado,quantidade);
    No n(quantidade);

    int prox = 0;
    stack<int> pilhaNos;

    this->arquivoArvore.seekg(0, this->arquivoArvore.end);
    int quantidadeArvore = this->arquivoArvore.tellg() / sizeof(No);

    if(quantidadeArvore > 0)
    {
        T tmp;
        No atual;

        while(prox != -1)
        {
            pilhaNos.push(prox);

            this->lerNo(atual,prox);
            this->lerDado(tmp,atual.dado);

            if(dado > tmp)
                if(atual.direita == -1)
                {
                    atual.direita = quantidade;
                    break;
                } else
                    prox = atual.direita;
                else if (dado < tmp)
                    if(atual.esquerda == -1)
                    {
                        atual.esquerda = quantidade;
                        break;
                    } else
                        prox = atual.esquerda;
                    else
                        throw invalid_argument("O dado ja existe");

        }
        this->escreverNo(atual,prox);

    }
    this->escreverNo(n,quantidadeArvore);
    while(!pilhaNos.empty())
    {
        int no = pilhaNos.top();
        pilhaNos.pop();

        if(abs(this->calcularEqulibrio(no)) > 1)
            this->balancear(no);
    }

}

template <class T>
T ArvoreEmDisco<T>::get(T dado)
{
   this->arquivoArvore.seekg(0, this->arquivoArvore.end);

    if(this->arquivoArvore.tellg() > 0)
    {
        T tmp;
        No atual;

        int prox = 0;
        while(prox != -1)
        {
            this->lerNo(atual,prox);
            this->lerDado(tmp,atual.dado);

            if(dado > tmp)
                prox = atual.direita;
            else if (dado < tmp)
                prox = atual.esquerda;
            else
                return tmp;
        }
    }

    return T(*this->valorPadrao);
}

template <class T>
void ArvoreEmDisco<T>::excluir(T dado)
{

}

template <class T>
int ArvoreEmDisco<T>::calcularEqulibrio(int indiceNo)
{
    //Le o nó apontado pelo indice
    No atual;
    this->lerNo(atual,indiceNo);

    //Pega as alturas à esquerda e à direita
    int alturaEsquerda = 0;
    if(atual.esquerda != -1)
        alturaEsquerda = this->calcularAltura(atual.esquerda);

    int alturaDireita = 0;
    if(atual.direita != -1)
        alturaDireita = this->calcularAltura(atual.direita);

    //Calculta e retona o equilibrio do nó
    atual.equilibrio = alturaDireita - alturaEsquerda;
    this->escreverNo(atual,indiceNo);

    return atual.equilibrio;
}

template <class T>
int ArvoreEmDisco<T>::calcularAltura(int indiceNo)
{
    //Le o nó apontado pelo indice
    No atual;
    this->lerNo(atual,indiceNo);

    //Pega as alturas à esquerda e à direita
    int alturaEsquerda = 0;
    if (atual.esquerda != -1)
        alturaEsquerda = this->calcularAltura(atual.esquerda);

    int alturaDireita = 0;
    if (atual.direita != -1)
        alturaDireita = this->calcularAltura(atual.direita);

    //Retorna a maior altura entre direita mais equerda
    //Somado a 1, para corresponder a altura do no
    return max(alturaEsquerda, alturaDireita) + 1;
}

template <class T>
void ArvoreEmDisco<T>::balancear(int indiceNo)
{
    No raiz;
    this->lerNo(raiz,indiceNo);

    if(raiz.equilibrio > 1)
    {
        No direita;
        this->lerNo(direita,raiz.direita);

        if(direita.direita == -1)
            this->rotacaoParaDireita(raiz.direita);

        this->rotacaoParaEsquerda(indiceNo);
    } else if(raiz.equilibrio < -1)
    {
        No esquerda;
        this->lerNo(esquerda,raiz.esquerda);

        if(esquerda.esquerda == -1)
            this->rotacaoParaEsquerda(raiz.esquerda);

        this->rotacaoParaDireita(indiceNo);
    }

    this->calcularEqulibrio(indiceNo);
}


template <class T>
void ArvoreEmDisco<T>::rotacaoParaEsquerda(int indiceNo)
{
    No atual;
    this->lerNo(atual,indiceNo);
    int indiceDireita = atual.direita;

    No direita;
    this->lerNo(direita,atual.direita);

    atual.direita = direita.esquerda;
    direita.esquerda = indiceDireita;

    this->escreverNo(atual,indiceDireita);
    this->escreverNo(direita,indiceNo);

    this->calcularEqulibrio(indiceDireita);
}

template <class T>
void ArvoreEmDisco<T>::rotacaoParaDireita(int indiceNo)
{
    No atual;
    this->lerNo(atual,indiceNo);
    int indiceEsquerda = atual.esquerda;

    No esquerda;
    this->lerNo(esquerda,atual.esquerda);

    atual.esquerda = esquerda.direita;
    esquerda.direita = indiceEsquerda;

    this->escreverNo(atual,indiceEsquerda);
    this->escreverNo(esquerda,indiceNo);

    this->calcularEqulibrio(indiceEsquerda);
}



template <class T>
void ArvoreEmDisco<T>::lerNo(No& no, int indiceNo)
{
    char * bytesNo = new char[sizeof(No)];

    this->arquivoArvore.seekg(indiceNo * sizeof(No), this->arquivoArvore.beg);
    this->arquivoArvore.read(bytesNo,sizeof(No));

     no = *reinterpret_cast<No*>(bytesNo);

     delete bytesNo;
}


template <class T>
void ArvoreEmDisco<T>::escreverNo(No& no, int indiceNo)
{
    char * bytes = new char[sizeof(No)];

    this->arquivoArvore.seekg(indiceNo * sizeof(No), this->arquivoArvore.beg);
    this->arquivoArvore.write(bytes,sizeof(No));

    delete bytes;
}

template <class T>
void ArvoreEmDisco<T>::lerDado(T& dado, int indiceDado)
{
    char * bytesDado = new char[sizeof(T)];

    this->arquivoTabela.seekg(indiceDado * sizeof(T), this->arquivoTabela.beg);
    this->arquivoTabela.read(bytesDado,sizeof(T));

    dado = *reinterpret_cast<T*>(bytesDado);

    delete bytesDado;
}


template <class T>
void ArvoreEmDisco<T>::escreverDado(T& no, int indiceDado)
{
    char * bytes = new char[sizeof(T)];

    this->arquivoTabela.seekg(indiceDado * sizeof(T), this->arquivoTabela.beg);
    this->arquivoTabela.write(bytes,sizeof(T));

    delete bytes;
}

template <class T>
void ArvoreEmDisco<T>::arrumarIndices(int noRemovido, int dadoRemovido)
{
    No atual;

    this->arquivoArvore.seekg(0, this->arquivoArvore.end);
    int ultimo = this->arquivoArvore.tellg() / sizeof(No);

    for(int i = 0; i < ultimo; i++)
    {
        this->lerNo(atual,i);

        if(atual.direita > noRemovido)
            atual.direita--;

         if(atual.esquerda > noRemovido)
            atual.esquerda--;

         if(atual.dado > dadoRemovido)
            atual.dado--;

        this->escreverNo(atual,i);
    }
}

template <class T>
void ArvoreEmDisco<T>::removerBytes(fstream& arq, const char * nomerArq, int bytesIniciais, int pular)
{
    arq.seekg(0, arq.end);
    int tamanhoArq = arq.tellg();
    int ultimosBytes = tamanhoArq - bytesIniciais - pular;

    char * primeiro = new char[bytesIniciais];
    char * ultimo = new char[ultimosBytes];

    arq.seekg(0, arq.beg);
    arq.read(primeiro, bytesIniciais);
    arq.seekg(-ultimosBytes, arq.end);
    arq.read(ultimo, ultimosBytes);
    arq.close();

    arq.open(nomerArq, ios::out | ios::binary | ios::trunc);
    arq.write(primeiro, bytesIniciais);
    arq.write(ultimo, ultimosBytes);
    arq.close();

    arq.open(nomerArq, ios::out | ios::in | ios::binary);

    delete primeiro;
    delete ultimo;
}


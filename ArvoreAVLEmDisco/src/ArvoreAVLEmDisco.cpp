#include "ArvoreAVLEmDisco.h"

ArvoreAVLEmDisco::ArvoreAVLEmDisco(const char* caminhoList, const char* caminhoArv)
{
    this->caminhoArvore = caminhoArv;
    this->caminhoLista  = caminhoList;
    this->raiz = {0};
    this->i    = {0};

    ifstream arqLista(this->caminhoLista, ios_base::binary);
    ifstream arqArvore(this->caminhoLista, ios_base::binary);

    if(arqLista.is_open())
        arqLista.read((char*)&this->i, sizeof(Indice));

    if(arqArvore.is_open())
        arqArvore.read((char*)&this->raiz, sizeof(Indice));

    arqLista.close();
    arqArvore.close();


}

int  ArvoreAVLEmDisco::procuraNaLista(int raProcurado)
{
   ifstream arqLista(this->caminhoLista, ios_base::binary);

   int tamanhoArquivo = arqLista.tellg() / sizeof(Aluno);

   for(int i = 1; i < tamanhoArquivo; i++)
   {
        arqLista.seekg(i);
        Aluno aLido;
        arqLista.read((char*)&aLido,sizeof(Aluno));

        if(aLido.ra == raProcurado)
            return i;
   }

   //O aluno não existe
   return -1;

   arqLista.close();
}

void ArvoreAVLEmDisco::inserir(Aluno novoAluno)
{
    if(this->raiz.i == -1) // nao existe raiz no arquivo
    {
       No novoNo = {-1,novoAluno.ra,-1,1};
       this->raiz = {1};
    }
}


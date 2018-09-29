#include <fstream>
#include <iostream>
#include "ArvoreAVLEmDisco.h"
#include <vector>
#include "Aluno.h"

using namespace std;


int main()
{
    Aluno a = {"Alexandre",16159,-1};
    const char* caminho = "aluninhos.data";
    //fstream arq(caminho, ios_base::binary |ios::in| ios::out | ios::trunc);
    ifstream arq(caminho, ios_base::binary);

    if(!arq.is_open())
        cout << "Erro ao abrir arquivo";
   // else
   //     arq.write((char*) &a, sizeof(Aluno));

    arq.seekg(0);

    Aluno aLido;

    arq.read((char*)&aLido,sizeof(Aluno));

    cout << aLido.ra;


    return 0;
}

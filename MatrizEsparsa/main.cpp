#include <iostream>
#include "ArvoreAVL.h"
#include "Info.h"
#include "MinhaInformacao.h"
#include "MatrizEsparsa.h"

using namespace std;

int main()
{
    MinhaInformacao padrao(0);
    MinhaInformacao nova(8);
    MinhaInformacao nova1(1);
    MinhaInformacao nova2(2);

    MatrizEsparsa<int>* matriz = new MatrizEsparsa<int>(0);

    matriz->put(1,1,5);
    matriz->put(3,7,8);
    matriz->put(2,1,8);

    matriz->put(1,1,7);
   // int numero = matriz->get(1,1);

   // cout << numero;



    return 0;
}

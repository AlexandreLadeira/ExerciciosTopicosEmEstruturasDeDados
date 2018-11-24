#include <iostream>
#include "ArvoreAVL.h"
#include "MatrizEsparsa.h"
#include "Coluna.h"

using namespace std;

int main()
{
    MatrizEsparsa<int>* matriz = new MatrizEsparsa<int>(0);


    matriz->put(1,1,5);
    matriz->put(1,2,5);
    matriz->put(3,7,13);
    matriz->put(2,1,8);
    matriz->put(4,9,10);

    //matriz->put(1,1,7);
   // cout << matriz->get(2, 1);
   // int numero = matriz->get(1,1);

    //matriz->put(2,1,0);


   // cout << matriz->get(2, 1);
    //cout << matriz->get(9, 3);
    //cout << matriz->get(3, 7);

   // cout << numero;

    cout << matriz;



    return 0;
}

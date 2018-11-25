#include <iostream>
#include "ArvoreAVL.h"
#include "MatrizEsparsa.h"
#include "Coluna.h"

using namespace std;

int main()
{
    try
    {
        MatrizEsparsa<int>* matriz = new MatrizEsparsa<int>(0);

        matriz->put(1,1,5);
        matriz->put(1,2,5);
        matriz->put(3,7,13);
        matriz->put(2,1,5);
        matriz->put(4,9,10);

        // cout << matriz->get(2, 1);
        // int numero = matriz->get(1,1);

        //matriz->put(2,1,0);


        // cout << matriz->get(2, 1);
        //cout << matriz->get(9, 3);
        //cout << matriz->get(3, 7);

        // cout << numero;

        cout << matriz;
        cout << "\n";

        matriz->put(1,2,0);



        cout << matriz;

        cout << "\n";

        cout << matriz->get(2,1);

    }
    catch  (std::invalid_argument err)
    {
        cerr << err.what();
    }




    return 0;
}

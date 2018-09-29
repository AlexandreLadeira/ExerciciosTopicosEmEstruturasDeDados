#include <iostream>
#include "ArvoreAVL.h"
#include "Info.h"
#include "MinhaInformacao.h"
#include "MatrizEsparsa.h"

using namespace std;

int main()
{
    MinhaInformacao padrao(0);
    MinhaInformacao nova(5);
    MinhaInformacao nova1(1);
    MinhaInformacao nova2(2);

    MatrizEsparsa matriz(&padrao);

    matriz.put(1,1,&nova1);
    matriz.put(3,7,&nova1);
    matriz.put(2,4,&nova2);

   // MinhaInformacao * teste = (MinhaInformacao*) matriz.get(1,1);
    cout << "oi";
   /* Info *i = (Info *) false;

    bool info = (bool) i;

    if(info)
        cout << "foi";
    else
        cout << "naoFoi";

    cout << "Hello world!" << endl;
    return 0;*/
}

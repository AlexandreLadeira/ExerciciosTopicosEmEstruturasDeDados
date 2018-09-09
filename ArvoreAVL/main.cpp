#include <iostream>
#include "MinhaInformacao.h"
#include "ArvoreAVL.h"

using namespace std;

int main()
{
   ArvoreAVL arvore;

   MinhaInformacao teste1(1);
   MinhaInformacao teste2(2);
   MinhaInformacao teste3(3);
   MinhaInformacao teste4(4);
   MinhaInformacao teste5(5);
   MinhaInformacao teste6(6);
   MinhaInformacao teste7(7);
   MinhaInformacao teste8(8);
   MinhaInformacao teste9(9);
   MinhaInformacao teste10(10);
   MinhaInformacao teste11(11);




   arvore.inserir(&teste6);
   arvore.inserir(&teste2);
   arvore.inserir(&teste5);
   arvore.inserir(&teste4);
   arvore.inserir(&teste3);
   arvore.inserir(&teste1);
   arvore.inserir(&teste7);
   arvore.inserir(&teste8);
   arvore.inserir(&teste9);
   arvore.inserir(&teste10);

  /* arvore.inserir(&teste1);
   arvore.inserir(&teste2);
   arvore.inserir(&teste3);
   arvore.inserir(&teste4);
   arvore.inserir(&teste5);
   arvore.inserir(&teste6);
   arvore.inserir(&teste7);
   arvore.inserir(&teste8);*/



   cout << arvore;
   /*if(arvore.tem(&teste6))
        cout << "tem";
   else
        cout << "n";*/

    //arvore.printar();
    cout << "\n-------------------------------\n";

    arvore.excluir(&teste3);

   // arvore.printar();

    cout << arvore;

    cout << "\n-------------------------------\n";

    arvore.excluir(&teste2);
    arvore.excluir(&teste10);

    cout << "\n-------------------------------\n";

    cout << arvore;

}

#include <iostream>
#include <MinhaInformacao.h>
#include <NoDeArvoreNaria.h>
#include <ArvoreNaria.h>

using namespace std;

int main()
{

    try{
        MinhaInformacao teste0(0);
        MinhaInformacao teste(1);
        MinhaInformacao teste2(2);
        MinhaInformacao teste3(3);
        MinhaInformacao teste4(4);
        MinhaInformacao teste5(5);
        MinhaInformacao teste6(6);
        MinhaInformacao teste7(7);
        MinhaInformacao teste8(8);

        ArvoreNaria arvore(3);

        arvore.guarde(&teste0);
        arvore.guarde(&teste4);
        arvore.guarde(&teste2);
        arvore.guarde(&teste8);
        arvore.guarde(&teste5);
        arvore.guarde(&teste7);
        arvore.guarde(&teste);
        arvore.guarde(&teste3);
        arvore.guarde(&teste6);



        cout << arvore;

        cout << "\n";
       /*arvore.guarde(&teste);
        arvore.guarde(&teste0);
        arvore.guarde(&teste7);
        arvore.guarde(&teste8);
        arvore.guarde(&teste5);*/

      // arvore.exclua(&teste6);

        cout << arvore;



        }
        catch (invalid_argument err)
        {
            cerr << err.what();
        }


    return 0;
}

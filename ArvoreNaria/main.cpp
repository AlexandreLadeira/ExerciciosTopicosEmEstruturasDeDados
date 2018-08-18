#include <iostream>
#include <MinhaInformacao.h>
#include <NoDeArvoreNaria.h>
#include <ArvoreNaria.h>

using namespace std;

int main()
{

    try{
        MinhaInformacao teste0(-4);
        MinhaInformacao teste(1);
        MinhaInformacao teste2(2);
        MinhaInformacao teste3(3);
        MinhaInformacao teste4(4);
        MinhaInformacao teste5(5);
        MinhaInformacao teste6(6);
        MinhaInformacao teste7(7);
        MinhaInformacao teste8(8);

        ArvoreNaria arvore(3);

        arvore.guarde(&teste4);
        arvore.guarde(&teste6);
        arvore.guarde(&teste);
        arvore.guarde(&teste0);
        arvore.guarde(&teste7);
        arvore.guarde(&teste8);
        arvore.guarde(&teste5);

        cout << arvore;






      /*  ArvoreNaria arvore(5);


        arvore.guarde(&teste2,arvore.getRaiz());
        arvore.guarde(&teste3,arvore.getRaiz());
        arvore.guarde(&teste4,arvore.getRaiz());
        arvore.guarde(&teste5,arvore.getRaiz());

        arvore.guarde(&teste0,arvore.getRaiz()); */
      //  arvore.guarde(&teste,arvore.getRaiz());
       // arvore.guarde(&teste7,arvore.getRaiz());
       // arvore.guarde(&teste8,arvore.getRaiz());

        //arvore.guarde(&teste2,arvore.getRaiz());


        //MinhaInformacao* info = (MinhaInformacao*)arvore.getRaiz()->getInfo(0);
        // MinhaInformacao* info2 = (MinhaInformacao*)arvore.getRaiz()->getInfo(1);
        // MinhaInformacao* info3 = (MinhaInformacao*)arvore.getRaiz()->getInfo(2);


       // arvore.getRaiz()->printaInfos();
        //cout << arvore;
       // arvore.printaArvore(arvore.getRaiz());

        //cout << info->getNumero()  << endl;






        /*;

        MinhaInformacao teste(1);
        MinhaInformacao teste2(2);
        MinhaInformacao teste3(3);
        MinhaInformacao teste4(4);
        MinhaInformacao teste5(5);
        MinhaInformacao teste6(6);
        MinhaInformacao teste7(7);
        MinhaInformacao teste8(8);

        NoDeArvoreNaria no(5);

        no.inserirInformacao(&teste3);
        no.inserirInformacao(&teste5);
        no.inserirInformacao(&teste4);
        no.inserirInformacao(&teste2);



        MinhaInformacao* info0 = (MinhaInformacao*) no.getInfo(0);
        MinhaInformacao* info1 = (MinhaInformacao*) no.getInfo(1);
        MinhaInformacao* info2 = (MinhaInformacao*) no.getInfo(2);
        MinhaInformacao* info3 = (MinhaInformacao*) no.getInfo(3);


        /*cout << info0->getNumero()  << endl;
        cout << info1->getNumero()  << endl;
        cout << info2->getNumero()  << endl;
        cout << info3->getNumero()  << endl;*/


        // cout << numero; */
        }
        catch (invalid_argument err)
        {
            cerr << err.what();
        }


    return 0;
}

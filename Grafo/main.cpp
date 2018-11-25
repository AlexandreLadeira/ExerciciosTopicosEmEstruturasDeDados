#include <iostream>
#include "Grafo.h"
#include "MatrizEsparsa.h"
#include "tipoOrientacao.h"
#include "Grafo.h"
#include <stdexcept>
#include <stdlib.h>

using namespace std;

int main()
{
    try
    {
    Grafo meuGrafo(naoDirigido);

    meuGrafo.addVertice("A");
    meuGrafo.addVertice("B");
    meuGrafo.addVertice("C");
    meuGrafo.addVertice("D");
    meuGrafo.addVertice("E");
    meuGrafo.addVertice("F");

    meuGrafo.addAresta("A","B",10);
    //meuGrafo.addAresta("B","A",10);
    meuGrafo.addAresta("A","C",4);
    meuGrafo.addAresta("B","D",8);
    meuGrafo.addAresta("C","D",7);
    meuGrafo.addAresta("D","E",9);
    meuGrafo.addAresta("A","E",13);


    cout << meuGrafo;

    //meuGrafo.delAresta("B","A");
    //meuGrafo.delAresta("A","B");
    meuGrafo.delVertice("D");

    cout << "================== \n";

    cout << meuGrafo;


    }
    catch (std::invalid_argument err)
    {
        cerr << err.what();
    }

    return 0;
}

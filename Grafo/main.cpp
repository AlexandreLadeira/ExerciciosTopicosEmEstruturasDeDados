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
    Grafo meuGrafo(dirigido);

    meuGrafo.addVertice("A");
    meuGrafo.addVertice("B");
    meuGrafo.addVertice("C");
    meuGrafo.addVertice("D");
    meuGrafo.addVertice("E");

    meuGrafo.addAresta("A","B",1);
    meuGrafo.addAresta("A","C",2);
    meuGrafo.addAresta("B","C",3);
    meuGrafo.addAresta("D","E",4);
    meuGrafo.addAresta("C","E",7);
    meuGrafo.addAresta("A","E",1);




    cout << meuGrafo;


    }
    catch (std::invalid_argument err)
    {
        cerr << err.what();
    }

    return 0;
}

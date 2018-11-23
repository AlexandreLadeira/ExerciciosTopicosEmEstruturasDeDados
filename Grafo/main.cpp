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
    Grafo meuGrafo(0,naoDirigido);

    meuGrafo.addVertice("A");
   // meuGrafo.delVertice("B");
    meuGrafo.addVertice("C");

    //meuGrafo.addAresta("A","C",10);
   // meuGrafo.addAresta("C","A",9);

    meuGrafo.delAresta("C","A");


    }
    catch (std::invalid_argument err)
    {
        cerr << err.what();
    }

    return 0;
}

#include "Grafo.h"

Grafo::Grafo(tipoOrientacao tip):tipo(tip)
{
   this->indiceNovoVertice = 0;
   this->arestas = new MatrizEsparsa<int>(0);
}

void Grafo::addVertice(char* nome)
{
    if(encontraVertice(nome) >= 0)
        throw invalid_argument("Um vertice com esse nome ja existe");

        this->vertices.push_back(Vertice(this->indiceNovoVertice,nome));
        this->indiceNovoVertice++;

}

void Grafo::delVertice(char* nome)
{
    int indiceRemovido = this->encontraVertice(nome);

    if(indiceRemovido >= 0)
    {   // Apaga o vertice indicado pela posi��o, realocando todo o vetor
        this->vertices.erase(this->vertices.begin() + indiceRemovido);

        //Remove todas a liga��es que o vertice possui
        for(int i = 0; i < this->vertices.size(); i++)
        {
            if(this->arestas->get(indiceRemovido,this->vertices[i].indice) != 0)
                this->arestas->put(indiceRemovido,this->vertices[i].indice,0);

            if(this->arestas->get(this->vertices[i].indice,indiceRemovido) != 0)
                this->arestas->put(this->vertices[i].indice,indiceRemovido,0);
        }


    }
    else
        throw invalid_argument("O vertice a ser removido nao existe");

}

void Grafo::addAresta(char* inicio, char* fim, int distancia)
{
    if(distancia <= 0)
        throw invalid_argument("A distancia de uma aresta deve ser maior que zero");

    int indiceInicio = this->encontraVertice(inicio);
    int indiceFim = this->encontraVertice(fim);

    if (indiceFim < 0 || indiceInicio < 0)
        throw invalid_argument("Nao eh permitido criar arestas para vertices inexistentes");

    if(this->arestas->get(indiceInicio, indiceFim) != 0 )
        throw invalid_argument("A aresta ja existe");

    if(this->tipo == naoDirigido && this->arestas->get(indiceFim, indiceInicio) != 0)
         throw invalid_argument("A aresta ja existe (Grafo nao dirigido)");

    if(this->tipo == naoDirigido)
         this->arestas->put(indiceFim,indiceInicio,distancia);

    this->arestas->put(indiceInicio,indiceFim,distancia);



}

void Grafo::delAresta(char* inicio, char* fim)
{
    int indiceInicio = this->encontraVertice(inicio);
    int indiceFim = this->encontraVertice(fim);

    //Se a aresta existir exclui ela
    if(this->arestas->get(indiceInicio,indiceFim) != 0)
    {
        this->arestas->put(indiceInicio,indiceFim,0);

        // se chegar aqui e o grafo for n�o dirigido, com certeza existira
        // uma aresta indiceFim->indiceInicio na matriz, portanto apagamos
        if(this->tipo == naoDirigido)
             this->arestas->put(indiceFim,indiceInicio,0);

    }
    else
        throw invalid_argument("A aresta a ser excluida nao existe");


}

int Grafo::encontraVertice(char* procurado)
{
    //Encontra o indice do vertice com o nome procurado, retornando -1 se n�o encontrar
    for(int i = 0; i < this->vertices.size(); i++)
        if(strcmp(procurado,this->vertices[i].nome) == 0)
            return i;

    return -1;
}

void Grafo::montaOsGrafo(ostream& os) const
{
    this->arestas->montaOsGrafo(os,this->vertices);
}

ostream& operator << (ostream& os, const Grafo& grafo)
{
    grafo.montaOsGrafo(os);
    return os;
}


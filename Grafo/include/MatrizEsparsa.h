#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"
#include "Linha.h"
#include "Coluna.h"
#include "NoAVL.h"
#include <string.h>
#include <vector>
#include "Vertice.h"


template <class T>

class MatrizEsparsa
{
    public:
        MatrizEsparsa(T);

        T get(unsigned int,unsigned int);
        void  put( int, int,T);

        void printaLinhas();
        void printaLinhas(NoAVL<Linha<T> >*);

        void montaOsMatriz(ostream&);
        void montaOsGrafo(ostream&,std::vector<Vertice>);

        char* encontraNome(int indice,std::vector<Vertice>);


        friend ostream& operator<<(ostream&, const MatrizEsparsa<T>*);

    protected:


    private:
        ArvoreAVL<Linha<T> >* linhas;
        void montaOsMatriz(ostream&,NoAVL<Linha<T> >*);
        void montaOsGrafo(ostream&,std::vector<Vertice>,NoAVL<Linha<T> >*);
        T  padrao;

};

#include "MatrizEsparsa.cpp"

#endif // MATRIZESPARSA_H

#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"
#include "Linha.h"
#include "Coluna.h"
#include "NoAVL.h"

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


        friend ostream& operator<<(ostream&, const MatrizEsparsa<T>*);

    protected:


    private:
        ArvoreAVL<Linha<T> >* linhas;
        void montaOsMatriz(ostream&,NoAVL<Linha<T> >*);
        T  padrao;

};

#include "MatrizEsparsa.cpp"

#endif // MATRIZESPARSA_H

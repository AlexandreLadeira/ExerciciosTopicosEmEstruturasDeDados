

template <class T>
Linha<T>::Linha(unsigned int i)
{
   this->indice = i;
   this->colunas = new ArvoreAVL<T>();
}

template <class T>
ArvoreAVL<T> * Linha<T>::getColunas()
{
    return this->colunas;
}

template <class T>
unsigned int Linha<T>::getIndice()
{
    return this->indice;
}

template <class T>
Coluna<T> * Linha<T>::getColuna(unsigned int c)
{
    Coluna<T> col(c,NULL);

    return (Coluna<T>*)this->colunas->get(c);
}

template <class T>
ostream& operator<<(ostream& os, Linha<T>* linha)
{
   linha->getColunas()->montaOsSequencial(os);
   return os;
}








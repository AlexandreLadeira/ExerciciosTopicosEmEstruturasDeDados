
template <class T>
Coluna<T>::Coluna(unsigned int i, T info)
{
    T* clone = new T(info);
    this->indice = i;
    this->informacao = clone;
}

template <class T>
unsigned int Coluna<T>::getIndice()
{
    return this->indice;
}

template <class T>
T  Coluna<T>::getInformacao()
{
    return *this->informacao;
}

template <class T>
int Coluna<T>::compareTo(T * informacao)
{
 if(informacao == NULL)
       throw invalid_argument("A linha nao pode ser nula para comparar");

    Coluna* coluna = (Coluna*) informacao;

    if(this->getValor() > coluna->getValor())
        return 1;

    if(this->getValor() < coluna->getValor())
        return -1;

    return 0;
}

template <class T>
const char* Coluna<T>::toString()
{
  return this->informacao->toString();
}

template <class T>
ostream& operator<<(ostream& os, Coluna<T>* coluna)
{
   os << coluna->getIndice();
   return os;
}

template <class T>
ostream& operator<<(ostream& os, const  Coluna<T>& coluna)
{
   os << coluna->getIndice();
   return os;
}





template <class T>
NoAVL<T>::NoAVL(int chave, T* info)
{
   this->info = info;
   this->altura     = 0;
   this->equilibrio = 0;
   this->chave      = chave;
   this->direita    = NULL;
   this->esquerda   = NULL;

}
template <class T>
T * NoAVL<T>::getInfo()
{
    return this->info;
}

template <class T>
NoAVL<T> * NoAVL<T>::getDireita()
{
    return this->direita;
}

template <class T>
NoAVL<T> * NoAVL<T>::getEsquerda()
{
    return this->esquerda;
}

template <class T>
int NoAVL<T>::getEquilibrio()
{
    return this->equilibrio;
}

template <class T>
int NoAVL<T>::getAltura()
{
    return this->altura;
}

template <class T>
void NoAVL<T>::setDireita(NoAVL<T> * no)
{
    this->direita = no;
}

template <class T>
void NoAVL<T>::setEsquerda(NoAVL<T> * no)
{
    this->esquerda = no;
}

template <class T>
void NoAVL<T>::setEqulibrio(int equilibrio)
{
    this->equilibrio = equilibrio;
}

template <class T>
void NoAVL<T>::setAltura(int altura)
{
    this->altura = altura;
}

template <class T>
void NoAVL<T>::setInfo(T * novaInfo)
{
    this->info = novaInfo;
}

template <class T>
int NoAVL<T>::getChave()
{
    return this->chave;
}

template <class T>
void NoAVL<T>::setChave(int novaChave)
{
    this->chave = novaChave;
}


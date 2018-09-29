#include "NoAvl.h"

NoAVL::NoAVL(InformacaoDeArvoreAVL * info)
{
   this->info = info;
   this->altura     = 0;
   this->equilibrio = 0;
   this->direita    = NULL;
   this->esquerda   = NULL;

}
InformacaoDeArvoreAVL * NoAVL::getInfo()
{
    return this->info;
}

NoAVL * NoAVL::getDireita()
{
    return this->direita;
}

NoAVL * NoAVL::getEsquerda()
{
    return this->esquerda;
}

int NoAVL::getEquilibrio()
{
    return this->equilibrio;
}

int NoAVL::getAltura()
{
    return this->altura;
}

void NoAVL::setDireita(NoAVL * no)
{
    this->direita = no;
}

void NoAVL::setEsquerda(NoAVL * no)
{
    this->esquerda = no;
}

void NoAVL::setEqulibrio(int equilibrio)
{
    this->equilibrio = equilibrio;
}

void NoAVL::setAltura(int altura)
{
    this->altura = altura;
}

void NoAVL::setInfo(InformacaoDeArvoreAVL * novaInfo)
{
    this->info = novaInfo;
}

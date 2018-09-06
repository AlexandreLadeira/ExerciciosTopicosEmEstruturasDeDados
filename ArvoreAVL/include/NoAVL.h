#ifndef NOAVL_H
#define NOAVL_H


class NoAVL
{
    public:
        NoAVL();
        virtual ~NoAVL();
    protected:
    private:
        NoAVL * direita;
        NoAVL * esquerda;
        InformacaoDeArvoreAVL * info;
};

#endif // NOAVL_H

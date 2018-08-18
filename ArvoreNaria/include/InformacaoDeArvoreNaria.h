#ifndef INFORMACAODEARVORENARIA_H
#define INFORMACAODEARVORENARIA_H


class InformacaoDeArvoreNaria
{
    public:
        virtual int compareTo(InformacaoDeArvoreNaria*){};
        virtual const char* toString(){};
        virtual void printar()  {};

    protected:
    private:
};

#endif // INFORMACAODEARVORENARIA_H

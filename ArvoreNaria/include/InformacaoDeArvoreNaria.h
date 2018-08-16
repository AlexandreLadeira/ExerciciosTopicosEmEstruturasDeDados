#ifndef INFORMACAODEARVORENARIA_H
#define INFORMACAODEARVORENARIA_H


class InformacaoDeArvoreNaria
{
    public:
        virtual int compareTo(InformacaoDeArvoreNaria*) throw(char*) {};
        virtual const char* toString() throw() {};
        virtual void printar()  {};

    protected:
    private:
};

#endif // INFORMACAODEARVORENARIA_H

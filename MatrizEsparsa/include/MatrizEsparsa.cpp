
template <class T>
MatrizEsparsa<T>::MatrizEsparsa(T padrao)
{
    this->padrao = padrao;
    this->linhas = new ArvoreAVL< Linha<T> >();
}

template <class T>
T  MatrizEsparsa<T>::get(unsigned int linha, unsigned int coluna)
{
    Linha<T> l(linha);
    Linha<T>* linhaProcurada = (Linha<T>*)this->linhas->get(linha);

    //se a linha existe
    if(linhaProcurada != NULL)
    {
        //pega a coluna indicada pelo parametro
        Coluna<T> * colunaProcurada = linhaProcurada->getColuna(coluna);

        //se ela existir retorna sua informacao
        if(colunaProcurada != NULL)
            return colunaProcurada->getInformacao();
    }

    //Se a linha nao existir, ou a coluna nao existir retona NULL
    return NULL;

}

template <class T>
void MatrizEsparsa<T>::put(int l,int c, T  informacao)
{
  Linha<T> linha(l);

  if(informacao == this->padrao)
  {
      Linha<T>* linhaProcurada = (Linha<T>*)this->linhas->get(l);

      //Se a linha nao existe retorna false
      if(linhaProcurada == NULL)
        throw invalid_argument("A linha a ser excluida não existe");

      // se ela existe, exclui a coluna c relacionada a ela
      linhaProcurada->getColunas()->excluir(c);

      //se não existe mais coluna associada a linha, excluir a linha
      if(linhaProcurada->getColunas()->getQtdNos() == 0)
        this->linhas->excluir(l);

  }
  else
  {
      if(!linhas->tem(l))
      { // se a linha nao existe na arvore, insere ela junto com a coluna
        linha.getColunas()->inserir(c,&informacao);
        linhas->inserir((int)l,&linha);
      }
      else
      {
      // se nao, pega a linha já existente
      Linha<T>* linhaProcurada = (Linha<T>*)this->linhas->get(l);

      //se ja existe uma coluna associada a essa linha retona false
      if(linhaProcurada->getColuna(c) != NULL)
            throw invalid_argument("Já existe uma coluna associada a essa linha");
      else // se nao insere a coluna na linha existente
        linhaProcurada->getColunas()->inserir(c,&informacao);
      }

  }


}

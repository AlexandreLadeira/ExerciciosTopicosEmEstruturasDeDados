#include "MatrizEsparsa.h"

MatrizEsparsa::MatrizEsparsa(InformacaoDeArvoreAVL * padrao)
{
    this->padrao = padrao;
}

InformacaoDeArvoreAVL * MatrizEsparsa::get(unsigned int linha, unsigned int coluna)
{
    Linha l(linha);
    Linha* linhaProcurada = (Linha*)this->linhas.get(&l);

    //se a linha existe
    if(linhaProcurada != NULL)
    {
        //pega a coluna indicada pelo parametro
        Coluna * colunaProcurada = linhaProcurada->getColuna(coluna);

        //se ela existir retorna sua informacao
        if(colunaProcurada != NULL)
            return colunaProcurada->getInformacao();
    }

    //Se a linha nao existir, ou a coluna nao existir retona NULL
    return NULL;

}

bool MatrizEsparsa::put(unsigned int l, unsigned int c, InformacaoDeArvoreAVL * informacao)
{
  Linha linha(l);

  if(informacao->compareTo(this->padrao) == 0)
  {
      Linha* linhaProcurada = (Linha*)this->linhas.get(&linha);

      //Se a linha nao existe retorna false
      if(linhaProcurada == NULL)
        return false;

      // se ela existe retorna true se exluir a coluna ou retorna false
      // se a coluna procurada não existir
      return linhaProcurada->excluiColuna(c);

  }
  else
  {
      if(!linhas.tem(&linha))
      { // se a linha nao existe na arvore insere ela junto com a coluna
        linha.insereColuna(c,informacao);
        linhas.inserir(&linha);
        return true;
      }

      // se nao pega a linha ja existente
      Linha* linhaProcurada = (Linha*)this->linhas.get(&linha);

      //se ja existe uma coluna associada a essa linha retona false
      if(linhaProcurada->getColuna(c) != NULL)
        return false;
      else // se nao insere a coluna na linha existente
        linhaProcurada->insereColuna(c,informacao);

  }

}

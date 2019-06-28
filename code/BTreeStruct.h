#ifndef BTREESTRUCT_H_INCLUDED
#define BTREESTRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ORDEM 5

typedef struct dados
{
    int trimestre,ddias,pestoque;
    double psemana, pcompartilhamento, ppreco, pretorno, aberto, alta, baixo, close, nopen, nclose,volume,pnegociacoes;
    char estoque[6],data[20],datai[20];

} dados;

typedef struct btree
{
    int TotalChaves;
    int EhFolha;
    int Chaves[ORDEM];
    struct btree* Filhos[ORDEM+1];
    struct btree* Pai;
} BTree;



BTree* NovaBTree();
BTree* Insere(BTree* No, int Chave);
BTree* BuscaBTree(BTree* No, int Chave);
void Imprime(BTree *raiz);
void listar(BTree *raiz,dados d[]);
void pesquisa(dados d[]);
int Altura(BTree *raiz);
int MenorChave(BTree *raiz);
void gotoxy(int x, int y);
void TextColor(int Cor);
void caixa(int x, int y, int x1, int y1);
int Menu();
void MostrarTela2();
void MostrarTela();
void Pesquisar();
void MostrarTela3();
int contbtree;



typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash_SemColisao(Hash *ha, struct regis v);
int buscaHash_SemColisao(Hash *ha, int mat, struct regis* v);
int insereHash_EnderAberto(Hash *ha, struct regis v);
int buscaHash_EnderAberto(Hash *ha, int mat, struct regis* v);
void imprimirHash_EnderAberto(Hash *ha, int pos);

#endif // BTREESTRUCT_H_INCLUDED

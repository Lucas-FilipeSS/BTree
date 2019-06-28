#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BTreeStruct.h"
#define MAXITENS 20
#include <locale.h>

void listar(BTree *raiz, dados d[])
{
    int i, t, tecla;
    static int nivel = 0, contpag = 0;
    if(raiz->Pai == NULL)
    {
        nivel = 0;
        contpag =0;
    }
    else
        nivel++;
    for(i = 0; i<raiz->TotalChaves; i++)
    {

        printf("\n\n");
        TextColor(7);
        printf("\t\t\t\t\t\t\t\tEmpresa: ");
        printf("%s\n", d[raiz->Chaves[i]].estoque);
        printf("\t\t\t\t\t\t\t\tData inicial: ");
        printf("%s\n", d[raiz->Chaves[i]].datai);
        printf("\t\t\t\t\t\t\t\tData final ");
        printf("%s\n", d[raiz->Chaves[i]].data);
        printf("\t\t\t\t\t\t\t\tAbertura: ");
        printf("R$%0.2lf\n", d[raiz->Chaves[i]].aberto);
        printf("\t\t\t\t\t\t\t\tAlta: ");
        printf("R$%0.2lf\n", d[raiz->Chaves[i]].alta);
        printf("\t\t\t\t\t\t\t\tBaixa: ");
        printf("R$%0.2lf\n", d[raiz->Chaves[i]].baixo);
        printf("\t\t\t\t\t\t\t\tFechamento: ");
        printf("R$%0.2lf\n", d[raiz->Chaves[i]].close);
        printf("\t\t\t\t\t\t\t\tVolume Medio: ");
        printf("%0.2lf\n", d[raiz->Chaves[i]].volume/24);
        printf("\t\t\t\t\t\t\t\tMaior Variacao: ");
        printf("%0.2lf\n", d[raiz->Chaves[i]].psemana);
        printf("\t\t\t\t\t\t\t\tCompartilhamento: ");
        printf("%0.2lf\n", d[raiz->Chaves[i]].pcompartilhamento);
        printf("\t\t\t\t\t\t\t\tMedia Negociacoes: ");
        printf("%0.2lf\n", d[raiz->Chaves[i]].pnegociacoes/24);
        printf("\t\t\t\t\t\t\t\tMaior Abertura: ");
        printf("R$%0.2lf\n", d[raiz->Chaves[i]].nopen);
        printf("\t\t\t\t\t\t\t\tMaior Fechamento: ");
        printf("R$%0.2lf\n", d[raiz->Chaves[i]].nclose);
        printf("\t\t\t\t\t\t\t\tMaior Alteracao: ");
        printf("%0.2lf%%\n", d[raiz->Chaves[i]].ppreco);
        printf("\n");

    }
    contpag++;
    /*system("pause");*/ contpag = 0;
    if(!raiz->EhFolha)
        for(i = 0; i <= raiz->TotalChaves; i++)
        {
            if(raiz->Filhos[i] != NULL)
                listar(raiz->Filhos[i],d);
        }
    nivel--;
}

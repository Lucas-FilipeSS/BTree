#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BTreeStruct.h"
#define MAXITENS 20
#include <locale.h>

void pesquisa(dados d[])
{
    char busca[6];
    int cod=0,k, acessos=0, tecla;
    caixa (69,3,100,5);
    caixa(67,2,105,10);
    TextColor(7);
    gotoxy(71, 4);
    printf("Chave de busca: ");
    strupr(gets(busca));

    for(k=0; k<856; k++)
    {
        if(d[k].volume!=0)
            acessos++;
        if(strcasecmp(busca,d[k].estoque)==0)
        {

            system("cls");
            MostrarTela();
            TextColor(7);
            gotoxy(76,4);
            printf("Busca sequencial: %s", d[k].estoque);
            gotoxy(52,8);
            printf("Data inicial");
            gotoxy(67,8);
            printf("%s", d[k].datai);
            gotoxy(54,11);
            printf("Data final");
            gotoxy(67,11);
            printf("%s", d[k].data);
            gotoxy(56,14);
            printf("Abertura");
            gotoxy(67,14);
            printf("R$%0.2lf", d[k].aberto);
            gotoxy(60,17);
            printf("Alta");
            gotoxy(67,17);
            printf("R$%0.2lf", d[k].alta);
            gotoxy(59,20);
            printf("Baixa");
            gotoxy(67,20);
            printf("R$%0.2lf", d[k].baixo);
            gotoxy(54,23);
            printf("Fechamento");
            gotoxy(67,23);
            printf("R$%0.2lf", d[k].close);
            gotoxy(52,26);
            printf("Volume Medio");
            gotoxy(67,26);
            printf("%0.2lf", d[k].volume/24);
            gotoxy(50,29);
            printf("Maior Variacao");
            gotoxy(67,29);
            printf("%0.2lf", d[k].psemana);
            gotoxy(48,32);
            printf("Compartilhamento");
            gotoxy(67,32);
            printf("%0.2lf", d[k].pcompartilhamento);
            gotoxy(47,35);
            printf("Media Negociacoes");
            gotoxy(67,35);
            printf("%0.2lf", d[k].pnegociacoes/24);
            gotoxy(50,38);
            printf("Maior Abertura");
            gotoxy(67,38);
            printf("R$%0.2lf", d[k].nopen);
            gotoxy(48,41);
            printf("Maior Fechamento");
            gotoxy(67,41);
            printf("R$%0.2lf", d[k].nclose);
            gotoxy(47,44);
            printf("Maior Alteracao %%");
            gotoxy(67,44);
            printf("%0.2lf%%", d[k].ppreco);
            TextColor(7);
            gotoxy(114,48);
            printf("Acessos: %d", acessos);
            gotoxy(47,48);
            printf("Pressione ESC para retornar ao menu");
            while(1)
            {
                tecla = getch();
                if (tecla == 27)
                    return;
            }
        }
    }
    gotoxy(69,7);
    printf("Chave nao encontrada!!\n");
    gotoxy(69,8);
    printf("Pressione ESC para retornar ao menu");
    while(1)
    {
        tecla = getch();
        if (tecla == 27)
            return;
    }

}

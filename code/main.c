#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BTreeStruct.h"
#define MAXITENS 20
#include <locale.h>

int main()
{
    char busca[6],testoque[6];
    int i=0, cont1=0, cont2=0,k,upcase=0,upcont=0, t=0, x=0, opcao, tecla;
    BTree* raiz, *Buscado;
    double auxaberto,auxalta=0,auxbaixo=0,auxvolume=0, auxpsemana=0, auxcompartilhamento=0, auxpnegociacoes=0,auxnopen=0,auxppreco=0;
    int buscasigla;
    char linha[1000];
    dados d[856];
    raiz = NovaBTree();
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "rt");
    fseek(arquivo, 0, SEEK_SET);
    fscanf(arquivo,"%[^\n]",linha);

//    sitetização dos dados
    while(!feof(arquivo))
    {
        fscanf(arquivo, "%d,", &d[i].trimestre);
        fscanf(arquivo, "%[^,]s", testoque);
        d[i].pestoque=0;
        for (k=0; k<strlen(testoque); k++)
        {
            d[i].pestoque+=testoque[k];
            if(k==1)
                d[i].pestoque*=testoque[k];

        }
        d[i].pestoque=d[i].pestoque%883;

        if(BuscaBTree(raiz, d[i].pestoque) == NULL)
        {
            raiz = InsereBTree(raiz, d[i].pestoque);
            t++;
            cont1++;

        }
        else
        {
            x++;
            cont2++;
        }

        strcpy(d[d[i].pestoque].estoque,testoque);

        fscanf(arquivo, ",%[^,]s", d[d[i].pestoque].data);
        if (cont1==1)
            strcpy(d[d[i].pestoque].datai,d[d[i].pestoque].data);

        fscanf(arquivo, ",$%lf", &auxaberto);
        if (cont1==1)
            d[d[i].pestoque].aberto=auxaberto;

        fscanf(arquivo, ",$%lf", &auxalta);
        if(cont1==1)
            d[d[i].pestoque].alta=0;
        if(auxalta>d[d[i].pestoque].alta)
            d[d[i].pestoque].alta=auxalta;


        fscanf(arquivo, ",$%lf", &auxbaixo);
        if(cont1==1)
            d[d[i].pestoque].baixo=150;
        if(auxbaixo<d[d[i].pestoque].baixo)
            d[d[i].pestoque].baixo=auxbaixo;

        fscanf(arquivo, ",$%lf", &d[d[i].pestoque].close);

        if(cont1==1)
            d[d[i].pestoque].volume=0;
        fscanf(arquivo, ",%lf", &auxvolume);
        d[d[i].pestoque].volume+=auxvolume;


        fscanf(arquivo, ",%lf", &auxpsemana);
        if(cont1==1)
            d[d[i].pestoque].psemana=0;
        if(auxpsemana>d[d[i].pestoque].psemana)
            d[d[i].pestoque].psemana=auxpsemana;


        fscanf(arquivo, ",%lf", &auxcompartilhamento);
        if(cont1==1)
            d[d[i].pestoque].pcompartilhamento=0;
        if(auxcompartilhamento>d[d[i].pestoque].pcompartilhamento)
            d[d[i].pestoque].pcompartilhamento=auxcompartilhamento;

        if(cont1==1)
            d[d[i].pestoque].pnegociacoes=0;
        fscanf(arquivo, ",%lf", &auxpnegociacoes);
        d[d[i].pestoque].pnegociacoes+=auxpnegociacoes;

        fscanf(arquivo, ",$%lf", &d[d[i].pestoque].nopen);
        if(cont1==1)
            d[d[i].pestoque].nopen=auxnopen;

        fscanf(arquivo, ",$%lf", &d[d[i].pestoque].nclose);

        fscanf(arquivo, ",%lf", &auxppreco);
        if(cont1==1)
            d[d[i].pestoque].ppreco=0;
        if(auxppreco>d[d[i].pestoque].ppreco)
            d[d[i].pestoque].ppreco=auxppreco;


        fscanf(arquivo, ",%d", &d[d[i].pestoque].ddias);
        fscanf(arquivo, ",%lf", &d[d[i].pestoque].pretorno);
        i++;
        cont1=0;
        cont2=0;

    }
//////////////////////////////////////////////////////////////////////////////////////////

    while(1)
    {
        opcao = Menu();
        if (opcao == 0)
        {
            system("cls");
            pesquisa(d);

        }
        if (opcao == 1)
        {
            system ("cls");
            caixa (69,3,100,5);
            caixa(67,2,105,10);
            TextColor(7);
            gotoxy(71, 4);
            printf("Chave de busca: ");
            strupr(gets(busca));
            buscasigla=0;
            for (k=0; k<strlen(busca); k++)
            {
                buscasigla+=busca[k];
                if(k==1)
                    buscasigla*=busca[k];
            }
            buscasigla=buscasigla%883;

            Buscado = BuscaBTree(raiz, buscasigla);
            if(Buscado == NULL)
            {
                gotoxy(69,7);
                printf("Chave nao encontrada!!\n");
                gotoxy(69,8);
                printf("Pressione ESC para retornar ao menu");
                while(1)
                {
                    tecla = getch();
                    if (tecla == 27)
                        break;
                }
            }
            else
            {
                system("cls");
                MostrarTela();
                TextColor(7);
                gotoxy(76,4);
                printf("Busca otimizada: %s", d[buscasigla].estoque);
                gotoxy(52,8);
                printf("Data inicial");
                gotoxy(67,8);
                printf("%s", d[buscasigla].datai);
                gotoxy(54,11);
                printf("Data final");
                gotoxy(67,11);
                printf("%s", d[buscasigla].data);
                gotoxy(56,14);
                printf("Abertura");
                gotoxy(67,14);
                printf("R$%0.2lf", d[buscasigla].aberto);
                gotoxy(60,17);
                printf("Alta");
                gotoxy(67,17);
                printf("R$%0.2lf", d[buscasigla].alta);
                gotoxy(59,20);
                printf("Baixa");
                gotoxy(67,20);
                printf("R$%0.2lf", d[buscasigla].baixo);
                gotoxy(54,23);
                printf("Fechamento");
                gotoxy(67,23);
                printf("R$%0.2lf", d[buscasigla].close);
                gotoxy(52,26);
                printf("Volume Medio");
                gotoxy(67,26);
                printf("%0.2lf", d[buscasigla].volume/24);
                gotoxy(50,29);
                printf("Maior Variacao");
                gotoxy(67,29);
                printf("%0.2lf", d[buscasigla].psemana);
                gotoxy(48,32);
                printf("Compartilhamento");
                gotoxy(67,32);
                printf("%0.2lf", d[buscasigla].pcompartilhamento);
                gotoxy(47,35);
                printf("Media Negociacoes");
                gotoxy(67,35);
                printf("%0.2lf", d[buscasigla].pnegociacoes/24);
                gotoxy(50,38);
                printf("Maior Abertura");
                gotoxy(67,38);
                printf("R$%0.2lf", d[buscasigla].nopen);
                gotoxy(48,41);
                printf("Maior Fechamento");
                gotoxy(67,41);
                printf("R$%0.2lf", d[buscasigla].nclose);
                gotoxy(47,44);
                printf("Maior Alteracao %%");
                gotoxy(67,44);
                printf("%0.2lf%%", d[buscasigla].ppreco);
                TextColor(7);
                gotoxy(114,48);
                printf("Acessos: %d", contbtree);
                gotoxy(47,48);
                printf("Pressione ESC para retornar ao menu");
                while(1)
                {
                    tecla = getch();
                    if (tecla == 27)
                        break;
                }
            }

        }
        if (opcao == 2)
        {
            system("cls");
            listar(raiz,d);
            printf("\t\t\t\t\t\t\t\tPressione ESC para retornar ao menu");
            while(1)
            {
                tecla = getch();
                if (tecla == 27)
                    break;
            }
        }
        if (opcao == 3)
        {
            system("cls");
            Imprime(raiz);
            printf("\n");
            printf("Pressione ESC para ver as caracteristicas da arvore");
            while(1)
            {
                tecla = getch();
                if (tecla == 27)
                    break;
                else
                    return;
            }
            system("cls");
            MostrarTela3();
            TextColor(7);
            gotoxy(61,8);
            printf("Inseridos");
            gotoxy(73,8);
            printf("%d\n",t);
            gotoxy(64,11);
            printf("Altura");
            gotoxy(73,11);
            printf("%d", Altura(raiz));
            gotoxy(59,14);
            printf("Menor Chave");
            gotoxy(73,14);
            printf("%d", MenorChave(raiz));
            gotoxy(52,19);
            printf("Pressione ESC para retornar ao menu");
            while(1)
            {
                tecla = getch();
                if (tecla == 27)
                    break;
            }
        }
        if (opcao == 4)
        {
            system("cls");
            return 0;
        }
    }

    gotoxy(8,50);
    return 0;
}

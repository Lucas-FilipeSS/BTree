//#include <stdio.h>
//#include <stdlib.h>
//#include "BTreeStruct.h"
//#include <locale.h>
//
//int main()
//{
//    int TAM=97, x, y, b, i=0,j=0,m,op,cont=0,c,n,soma=0;
//    float pu,pn,p;
//    char linha[1000];
//    Hash *h = criaHash(TAM);
//    titulo();
//    FILE *arquivo;
//    arquivo = fopen("ListadeVeiculosLeilao.txt", "rt");
//
//    fseek(arquivo, 0, SEEK_SET);
//    fscanf(arquivo,"%[^\n]",linha);
//    timeArq();
//    while(!feof(arquivo))
//    {
//        fscanf(arquivo, "%d; ", &veiculos[i].lote);
//        fscanf(arquivo, "%[^;]s", veiculos[i].placa);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].uf);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].motor);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].renavam);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].chassi);
//        fscanf(arquivo, " ; %d", &veiculos[i].ano);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].modelo);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].proprietario);
//        fscanf(arquivo, " ; %[^;]s", veiculos[i].financeira);
//        fscanf(arquivo, " ; %lf", &veiculos[i].valor);
//        i++;
//    }
//        cont=contColisoes(h, veiculos);
//    for(i=0; i<TAM; i++)
//    {
//        insereHash_EnderAberto(h, veiculos[i]);
//    }
//    menuOp();
//    printf("Operacao: ");
//    scanf("%d",&op);
//    system("cls");
//    while(op!=0)
//    {
//        if(op==1)
//        {
//            printf("Buscar (0-Voltar ao menu): ");
//            scanf("%d", &b);
//            system("cls");
//            while(b!=0)
//            {
//                timeBusca();
//                y = buscaHash_EnderAberto(h, b, veiculos);
//                imprimirHash_EnderAberto(h, y);
//                printf("Buscar (0-Voltar ao menu): ");
//                scanf("%d", &b);
//                system("cls");
//            }
//        }
//        if(op==2)
//        {
//            timeLista();
//            listaHash_EnderAberto(h);
//
//        }
//        if(op==3)
//        {
//            menuEsta();
//            printf("Opcao: ");
//            scanf("%d",&n);
//            system("cls");
//            while(n!=0)
//            {
//                if(n==1)
//                    usadasHash_EnderAberto(h);
//                else if(n==2)
//                    nusadasHash_EnderAberto(h);
//                else if(n==3)
//                {
//                    p=contaHash_EnderAberto(h);
//                    pu=(p/TAM)*100;
//                    pn=((TAM-p)/TAM)*100;
//                    printf("%.2f%% das posicoes foram utilizadas\n%.2f%% das posicoes nao foram utilizadas\n\n",pu,pn);
//                }
//                else if(n==4){
//                    printf("Numero de colisoes: %d\n",cont);
//                }
//                menuEsta();
//                printf("Opcao: ");
//                scanf("%d",&n);
//                system("cls");
//            }
//
//
//        }
//        if(op==4){
//            system("ListadeVeiculosLeilao.txt");
//        }
//        menuOp();
//        printf("Operacao: ");
//        scanf("%d",&op);
//        system("cls");
//    }
//    timeFinal();
//    fclose(arquivo);
//    return 0;
//
//}

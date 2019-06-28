#include "BTreeStruct.h"
#include <locale.h>
#include <conio.h>
#include <windows.h>
int Menu()
{
    char opcoes[7][30]= {"Pesquisa sequencial", "Pesquisa otimizada", "Listar", "Arvore", "Sair"};
    int cols[5] = {54, 76, 97, 106, 115};
    int opcao = 0, i, tecla;
    system("cls");
    MostrarTela2();
    TextColor(7);
    gotoxy(79,4);
    printf("Dow Jones Index");
    TextColor(7);
    for(i=0; i<5; i++)
    {
        gotoxy(cols[i], 10);
        printf("%-8s", opcoes[i]);
    }
    while(1)
    {
        TextColor(3);
        gotoxy(cols[opcao], 10);
        printf("%-8s", opcoes[opcao]);
        tecla = getch();
        if (tecla == 27)
            break;
        TextColor(7);
        gotoxy(cols[opcao],10);
        printf("%-8s", opcoes[opcao]);
        if (tecla == 77)
            opcao++;
        if (tecla == 75)
            opcao--;
        if (tecla == 13)
            return opcao;
        if (opcao < 0)
            opcao = 4;
        if (opcao > 4)
            opcao = 0;
    }
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor(int Cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Cor);
}
void caixa(int x, int y, int x1, int y1)
{
    int i;
    TextColor(3);
    gotoxy(x,y);
    printf("\xDA");
    for (i=x+1; i<x1; i++)
    {
        gotoxy(i,y);
        printf("\xC4");
        gotoxy(i,y1);
        printf("\xC4");
    }
    gotoxy(x1,y);
    printf("\xBF");
    for(i=y+1; i<y1; i++)
    {
        gotoxy(x,i);
        printf("\xB3");
        gotoxy(x1,i);
        printf("\xB3");
    }
    gotoxy(x,y1);
    printf("\xC0");
    gotoxy(x1,y1);
    printf("\xD9");
}
void MostrarTela2()
{
    caixa(70,3,102,5);
//    caixa(48,2,123,15);
}
void MostrarTela()
{
    caixa(45,2,126,50);
    caixa(66,3,105,5);
    caixa(65,7,106,9);
    caixa(65,10,106,12);
    caixa(65,13,106,15);
    caixa(65,16,106,18);
    caixa(65,19,106,21);
    caixa(65,22,106,24);
    caixa(65,25,106,27);
    caixa(65,28,106,30);
    caixa(65,31,106,33);
    caixa(65,34,106,36);
    caixa(65,37,106,39);
    caixa(65,40,106,42);
    caixa(65,43,106,45);
}
void MostrarTela3()
{
    caixa(64,3,106,5);
    TextColor(7);
    gotoxy(73,4);
    printf("Caracteristicas da Arvore");
    caixa(50,2,121,20);
    caixa(71,7,100,9);
    caixa(71,10,100,12);
    caixa(71,13,100,15);
}

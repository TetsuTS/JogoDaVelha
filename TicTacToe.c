#include <stdio.h>
void PrintTabuleiro(char tb[3][3]){
    system("cls");
    printf("%c|%c|%c\n", tb[0][0], tb[0][1], tb[0][2]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", tb[1][0], tb[1][1], tb[1][2]);
    printf("-+-+-\n");
    printf("%c|%c|%c\n", tb[2][0], tb[2][1], tb[2][2]);
}
void LerX(char tb[3][3], int cnf[3][3], int *vic){
    int b, h;
    do{
        do{
            printf("jogador \"X\" escolha uma posição: ");
            scanf("%d", &b); scanf("%d", &h);
        }while(b>3 || h>3);
        h--; b--;
    }while(cnf[h][b]==1);
    tb[h][b]='X';
    cnf[h][b]=1;
    *vic=vencedor(tb);
}
void LerO(char tb[3][3], int cnf[3][3], int *vic){
    int b, h;
    do{
        do{
            printf("jogador \"O\" escolha uma posição: ");
            scanf("%d", &b); scanf("%d", &h);
        }while(b>3 || h>3);
        h--; b--;
    }while(cnf[h][b]==1);
    tb[h][b]='O';
    cnf[h][b]=1;
    *vic=vencedor(tb);
}
int vencedor(char tb[3][3]){
    for(int x=0;x<3;x++){
        if(tb[x][0]=='X' && tb[x][1]=='X' && tb[x][2]=='X'){return 1;}
        if(tb[0][x]=='X' && tb[1][x]=='X' && tb[2][x]=='X'){return 1;}
        
        if(tb[x][0]=='O' && tb[x][1]=='O' && tb[x][2]=='O'){return 2;}
        if(tb[0][x]=='O' && tb[1][x]=='O' && tb[2][x]=='O'){return 2;}
    }
    if(tb[0][0]=='X' && tb[1][1]=='X' && tb[2][2]=='X'){return(1);}
    if(tb[2][0]=='X' && tb[1][1]=='X' && tb[0][2]=='X'){return(1);}

    if(tb[0][0]=='O' && tb[1][1]=='O' && tb[2][2]=='O'){return(2);}
    if(tb[2][0]=='O' && tb[1][1]=='O' && tb[0][2]=='O'){return(2);}

    return(0);
}
int empate(int cnf[3][3]){
    for(int b=0;b<3;b++){
        for(int h=0;h<3;h++){
            if(cnf[h][b]==0){return 0;}
        }
    }
    return 3;
}
int main(){
    int v=0, cnf[3][3]={{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    char tb[3][3]={{' ', ' ', ' ',}, {' ', ' ', ' ',}, {' ', ' ', ' ',}};
    printf("o premeiro valor informado será a posição horizontal e o segundo será a posição vertical\n");
    system("pause");
    PrintTabuleiro(tb);
    do{
        LerX(tb, cnf, &v);
        PrintTabuleiro(tb);
        if(v==1){break;}
        v=empate(cnf);
        if(v==3){break;}
        LerO(tb, cnf, &v);
        PrintTabuleiro(tb);
        if(v==2){break;}
        v=empate(cnf);
        if(v==3){break;}
    }while(1);
    if(v==1){
        printf("jogador \"X\" é o vencedor\n");
    }else if(v==2){
        printf("jogador \"O\" é o vencedor\n");
    }else if(v==3)
    {
        printf("empate\n");
    }
    system("pause");
    return 0;
}
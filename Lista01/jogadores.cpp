// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct tJogador{
    string nome;
    int gols;
    int idade;
    int chutes;
} tJogador;

int main(){
    tJogador jogador[2];
    int i;

    for(i = 0; i < 2; i++){
        getline(cin, jogador[i].nome);
        cin >> jogador[i].idade >> jogador[i].chutes >> jogador[i].gols;
        getchar();
    }

    if((double) jogador[0].gols / jogador[0].chutes > (double) jogador[1].gols / jogador[1].chutes)
        cout <<  jogador[0].nome << " (" <<  jogador[0].idade << ")";
    else
        cout <<  jogador[1].nome << " (" <<  jogador[1].idade << ")" << endl;

    return 0;
}
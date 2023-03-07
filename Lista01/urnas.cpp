// Ralf Dewrich Ferreira 😊

#include <stdio.h>
#include <string.h>

void Espaco(char *string){
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == '\n')
            string[i] = '\0';
    }
}

typedef struct tCandidatos{
    char nomeDosCandidatos[31];
    int numCandidatos;
    float qtdVotos;
} tCandidatos;

int main(void){
    int nCandidatos, i, e;
    int voto, j;
    float totalVotos = 0, votosNulos = 0, maiorQtdVotos = 0;
    scanf("%d", &nCandidatos);
    tCandidatos candidatos[nCandidatos];

    for(i = 0; i < nCandidatos; i++){
        scanf("%d\n", &candidatos[i].numCandidatos);
        fgets(candidatos[i].nomeDosCandidatos, 31, stdin);
        Espaco(candidatos[i].nomeDosCandidatos);
        candidatos[i].qtdVotos = 0;
    }
    while(1){
        scanf("%d", &voto);
        if(voto <= 0)
            break;
        else{
            for(int j = 0; j < i; j++){
                if(voto == candidatos[j].numCandidatos){
                    candidatos[j].qtdVotos++;
                    break;
                }if (j == i-1)
                    if(voto != candidatos[j].numCandidatos)
                        votosNulos++;
            }
        }
        totalVotos++;
    }

    for(e = 0; e < nCandidatos; e++){
        if(candidatos[e].qtdVotos > maiorQtdVotos){
            maiorQtdVotos = candidatos[e].qtdVotos;
            j = e;
        }
    }

    for(int k = 0; k < nCandidatos; k++){
        printf("%.2f - %d - %s",(candidatos[k].qtdVotos/totalVotos)*100, candidatos[k].numCandidatos,candidatos[k].nomeDosCandidatos);
        if(k == j)
            printf(" VENCEDOR\n");
        else
            printf("\n");
    }
    printf("%.2f - Nulos", (votosNulos/totalVotos)*100);

    return 0;
}

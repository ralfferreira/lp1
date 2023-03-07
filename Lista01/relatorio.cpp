// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>
using namespace std;

typedef struct Movel {
    string descricao;
    float peso;
    char tipo;
} tMovel;
    
int main()
{
    int acima10kgS = 0;
    float maisPesado = 0;
    int qtdReal = 0;
    int indMaisPesado;
    int N;
    cin >> N;
    getchar();
    tMovel moveis[N];
    
    
    for(int i= 0; i < N; i++) {
        getline(cin, moveis[i].descricao);
        cin >> moveis[i].peso;
        getchar();
        cin >> moveis[i].tipo;
        getchar();
    }
    
    for(int i = 0; i < N; i++) {
        if (moveis[i].peso > 10 && moveis[i].tipo == 's') {
            acima10kgS++;
        }
        if (moveis[i].peso > maisPesado) {
            maisPesado = moveis[i].peso;
            indMaisPesado = i;
        }
        if (moveis[i].descricao.find("Real") == moveis[i].descricao.size()-4) {
            qtdReal++;
        }
    }
    
    cout << "Tipo 's' acima de 10Kg: " << acima10kgS << endl;
    cout << "Termina em  \"Real\": " << qtdReal << endl;
    cout << "Mais pesado: \""<< moveis[indMaisPesado].descricao << "\"\n";
    
    
    return 0;
}
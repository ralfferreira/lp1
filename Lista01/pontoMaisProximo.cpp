// Ralf Dewrich Ferreira 😊

#include <iostream>

using namespace std;

typedef struct Ponto {
    int x;
    int y;
} tPonto;

double Distancia (tPonto p1, tPonto p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    tPonto p1;
    double menorDist;
    int iMenor = 0;
    int i, N;
    cin >> p1.x;
    cin >> p1.y;
    cin >> N;
    tPonto vet[N];

    for(i = 0; i < N; i++) {
        cin >> vet[i].x;
        cin >> vet[i].y;

        double distancia = Distancia(p1, vet[i]);
        if(i == 0)
            menorDist = distancia;
        if(distancia < menorDist) {
            menorDist = distancia;
            iMenor = i;
        }
    }

    cout << "Ponto mais perto é (";
    cout << vet[iMenor].x;
    cout << ", ";
    cout << vet[iMenor].y;
    cout << ")";
    cout << endl;

    
    return 0;
}
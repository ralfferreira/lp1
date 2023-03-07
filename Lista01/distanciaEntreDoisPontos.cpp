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
    tPonto p1, p2;
    double distancia;
    cin >> p1.x;
    cin >> p1.y;
    cin >> p2.x;
    cin >> p2.y;

    distancia = Distancia(p1, p2);
    cout << distancia;

    
    return 0;
}
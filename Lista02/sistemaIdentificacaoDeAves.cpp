// Ralf Dewrich Ferreira 😊

#include <iostream>

using namespace std;

int main() {
    int aquatica, predadora, domestica, voa, noturna;
    cin >> aquatica;
    cin >> predadora;
    cin >> domestica;
    cin >> voa;
    cin >> noturna;

    if (aquatica == 0 && predadora == 1 && domestica == 0 && voa == 1 && noturna == 1) {
        cout << "coruja" << endl;
    } else if (aquatica == 0 && predadora == 0 && domestica == 0 && voa == 0 && noturna == 0) {
        cout << "avestruz" << endl;
    } else if (aquatica == 0 && predadora == 0 && domestica == 0 && voa == 1 && noturna == 0) {
        cout << "pardal" << endl;
    } else if (aquatica == 0 && predadora == 0 && domestica == 1 && voa == 1 && noturna == 0) {
        cout << "galinha" << endl;
    } else if (aquatica == 0 && predadora == 1 && domestica == 0 && voa == 1 && noturna == 0) {
        cout << "falcão" << endl;
    } else if (aquatica == 1 && predadora == 0 && domestica == 0 && voa == 1 && noturna == 0) {
        cout << "pato" << endl;
    } else if (aquatica == 1 && predadora == 1 && domestica == 0 && voa == 0 && noturna == 0) {
        cout << "pinguim" << endl;
    } else if (aquatica == 1 && predadora == 1 && domestica == 0 && voa == 1 && noturna == 0) {
        cout << "gaivota" << endl;
    } else if (aquatica == 1 && predadora == 1 && domestica == 0 && voa == 1 && noturna == 1) {
        cout << "garça" << endl;
    } else if (aquatica == 0 && predadora == 1 && domestica == 0 && voa == 0 && noturna == 0) {
        cout << "ema" << endl;
    }

    return 0;
}

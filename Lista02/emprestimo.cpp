// Ralf Dewrich Ferreira 😊

#include <iostream>

using namespace std;

int main() {
    int salario = 0;
    int emprestimo = 0;
    int prestacao = 0;

    cin >> salario;

    if(salario <= 0) {
        while(salario <= 0) {
            cin >> salario;
        }
    }

    if(emprestimo <= 0) {
        while(emprestimo <= 0) {
            cin >> emprestimo;
        }
    }


    if(prestacao <= 0) {
        while(prestacao <= 0) {
            cin >> prestacao;
        }
    }
    double checkarPorcentagem = (float) salario * 0.3;

    if((double) emprestimo / prestacao < checkarPorcentagem) {
        cout << "Emprestimo pode ser concedido" << endl;
    } else {
        cout << "Emprestimo nao pode ser concedido" << endl;
    }

    return 0;
}

// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

class Data {
public:
    Data(int dia, int mes, int ano) {
        if (mes < 1 || mes > 12) {
            cout << "Atributo mês Inválido" << endl;
            mes = 1;
        }
        if (dia < 1 || dia > getDaysMonth(mes)) {
            cout << "Atributo dia Inválido" << endl;
            dia = 1;
        }
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    string getDia() {
        if (dia < 10) {
            return "0" + to_string(dia);
        }
        return to_string(dia);
    }

    string getMes() {
        if (mes < 10) {
            return "0" + to_string(mes);
        }
        return to_string(mes);
    }

    string getAno() {
        return to_string(ano);
    }

    void avancarDia() {
        int maxDias = getDaysMonth(mes);
        if (dia < maxDias) {
            dia++;
        } else {
            dia = 1;
            if (mes < 12) {
                mes++;
            } else {
                mes = 1;
                ano++;
            }
        }
    }

private:
    int dia;
    int mes;
    int ano;

    int getDaysMonth(int mes) {
        switch (mes) {
            case 2:
                if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
                    return 29;
                }
                return 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    }
};

int main() {
    int dia, mes, ano, qtdDias;
    cin >> dia >> mes >> ano >> qtdDias;
    Data data(dia, mes, ano);
    for (int i = 0; i < qtdDias; i++) {
        data.avancarDia();
    }
    cout << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << endl;
    return 0;
}

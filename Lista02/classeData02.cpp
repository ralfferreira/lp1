// Ralf Dewrich Ferreira

#include <iostream>

using namespace std;

class Data {
    public:
        Data() {
            this->dia = 1;
            this->mes = 1;
            this->ano = 1;
        }

        void printData() {
            string nomeMes[13] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro", "Indefinido"};

            if(mes > 12 || mes < 1) {
                mes = 13;
            }

            cout << dia << " de " << nomeMes[mes-1] << " de " << ano;
        };

        int getDia() {
            return dia;
        }

        void setDia(int dia) {
            this->dia = dia;
        }

        int getMes() {
            return mes;
        }

        void setMes(int mes) {
            this->mes = mes;
        }

        int getAno() {
            return ano;
        }

        void setAno(int ano) {
            this->ano = ano;
        }
    private:
        int dia;
        int mes;
        int ano;
};



int main() {
    Data data;
    int receiver;

    cin >> receiver;
    data.setDia(receiver);
    cin >> receiver;
    data.setMes(receiver);
    cin >> receiver;
    data.setAno(receiver);

    data.printData();

    return 0;
}

    // Ralf Dewrich Ferreira 😊

    #include <iostream>

    using namespace std;

    typedef struct tData {
        int dia;
        int mes;
        int ano;
    } tData;

    int MaisVelha(tData data1, tData data2) {
        if(data1.ano < data2.ano) {
            return 1;
        } else if (data2.ano < data1.ano)
            return -1;
        else {
            if(data1.mes < data2.mes) {
                return 1;
            } else if (data2.mes < data1.mes) {
                return -1;
            } else {
                if(data1.dia < data2.dia) {
                    return 1;
                } else if (data2.dia < data1.dia) {
                    return -1; }
                else {
                    return 0;
                }
            }
        }
    }

    int main() {
        tData data1, data2;

        cin >> data1.dia >> data1.mes >> data1.ano;
        cin >> data2.dia >> data2.mes >> data2.ano;    

        if(MaisVelha(data1, data2) == 1) {
            cout << "Pessoa 1 é mais velha";
        } else if(MaisVelha(data1, data2) == -1){
            cout << "Pessoa 2 é mais velha";
        } else{
            cout << "Pessoas são da mesma idade";
        }


        return 0;
    }
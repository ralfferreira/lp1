// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAX_PESSOAS = 100;

typedef struct tPessoa {
    string cpf;
    string nome;
    string sobrenome;
    string endereco;
    string telefone;
} tPessoa;

int main() {
    int n;
    cin >> n;
    tPessoa pessoas[MAX_PESSOAS];

    for (int i = 0; i < n; i++) {
        cin >> pessoas[i].cpf;
        cin >> pessoas[i].nome;
        cin >> pessoas[i].sobrenome;
        cin.ignore();
        getline(cin, pessoas[i].endereco);
        getline(cin, pessoas[i].telefone);
    }

    ofstream csv("pessoas.csv");
    csv << "CPF,nome,snome,endereço,telefone\n";
    for (int i = 0; i < n; i++) {
        csv << pessoas[i].cpf << "," << pessoas[i].nome << "," << pessoas[i].sobrenome << "," << pessoas[i].endereco << "," << pessoas[i].telefone << endl;
    }
    csv.close();

    ifstream csvLeitura("pessoas.csv");
    string linha;
    while (getline(csvLeitura, linha)) {
        cout << linha << endl;
    }
    csvLeitura.close();

    return 0;
}

// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pessoa {
public:
    int tipo;
    string nome;
    string telefone;
    string cpf;
};

void geraArquivo(string path, string data) {
    fstream fs;
    fs.open(path.c_str(), fstream::out);
    if (fs.is_open()) {
        fs.write(data.c_str(), data.size());
        fs.close();
    } else
        cout << "Nao foi possivel abrir o arquivo " << path;
}

void geraArquivos() {
    string data1 = "1\nJoao Pedro\n(83) 8888-8888\n"
                  "2\nMaria Teresa\n(83) 9999-9999\n000.000.000-00\n"
                  "2\nLuiz Pereira\n(83) 7777-7777\n111.111.111-11\n"
                  "1\nDenis Carlos\n(83) 5555-5555\n";
    string data2 = "2\nLuma Oliveira\n(83) 1111-1111\n222.222.222-22\n"
                  "2\nTercio Marquies\n(83) 2222-2222\n333.333.222-33\n"
                  "1\nJonas Luz\n(83) 3333-3333\n";
    geraArquivo("dados01.txt", data1);
    geraArquivo("dados02.txt", data2);
}

int main() {
    geraArquivos();
    string arquivo;
    getline(cin, arquivo);

    fstream fs;
    fs.open(arquivo.c_str(), fstream::in);

    if (fs.is_open()) {
        Pessoa p;
        while (fs >> p.tipo) {
            getline(fs >> ws, p.nome);
            getline(fs >> ws, p.telefone);
            if (p.tipo == 2) {
                getline(fs >> ws, p.cpf);
            } else {
                p.cpf = "";
            }
            cout << p.nome << ", tel: " << p.telefone;
            if (p.tipo == 2) {
                cout << ", CPF: " << p.cpf;
            }
            cout << endl;
        }
        fs.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo " << arquivo << endl;
    }

    return 0;
}
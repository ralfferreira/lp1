// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    string telefone;

public:
    Pessoa() {}

    Pessoa(string nome) {
        setNome(nome);
    }

    Pessoa(string nome, int idade, string telefone) {
        setNome(nome);
        setIdade(idade);
        setTelefone(telefone);
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return nome;
    }

    void setIdade(int idade) {
        this->idade = idade;
    }

    int getIdade() {
        return idade;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    string getTelefone() {
        return telefone;
    }

    bool pesquisaNome(string nome) {
        return this->nome.find(nome) != string::npos;
    }
};

int main() {
    int n;
    cin >> n;

    Pessoa* pessoas = new Pessoa[n];
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string nome, telefone;
        int idade;

        getline(cin, nome);
        cin >> idade;
        getchar();
        getline(cin, telefone);

        Pessoa pessoa(nome, idade, telefone);
        pessoas[i] = pessoa;
    }

    string nomePesquisa;
    getline(cin, nomePesquisa);

    bool encontrou = false;
    for (int i = 0; i < n; i++) {
        if (pessoas[i].pesquisaNome(nomePesquisa)) {
            cout << pessoas[i].getNome() << ", " << pessoas[i].getIdade() << ", " << pessoas[i].getTelefone() << endl;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Pessoa não encontrada" << endl;
    }

    delete[] pessoas;

    return 0;
}
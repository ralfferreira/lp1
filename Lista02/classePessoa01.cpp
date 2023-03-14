// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    public:
        string nome;
        string telefone;
        int idade;
};

int main() {
    Pessoa pessoa;
    int i;

    for(i = 0; i < 2; i++) {
        getline(cin, pessoa.nome);
        cin >> pessoa.idade;
        getchar();
        getline(cin, pessoa.telefone);
        cout << pessoa.nome << ", " << pessoa.idade << ", " << pessoa.telefone << endl;
    }

    return 0;
}

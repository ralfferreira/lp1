// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Endereco {
    private:
        string rua;
        int numero;
        string bairro;
        string cidade;
        string estado;
        string cep;

    public:
        Endereco() {}
        Endereco(string rua, int numero, string bairro, string cidade, string estado, string cep) {
            this->rua = rua;
            this->numero = numero;
            this->bairro = bairro;
            this->cidade = cidade;
            this->estado = estado;
            this->cep = cep;
        }

        string toString() {
            return rua + ", " + to_string(numero) + ", " + bairro + ". " +
                cidade + " - " + estado + ". CEP: " + cep;
        }
    };

class Pessoa {
    private:
        string nome;
        Endereco endereco;
        string telefone;
    public:
        Pessoa() {}
        Pessoa(string nome) {
            this->nome = nome;
        }

        Pessoa(string nome, Endereco endereco, string telefone) {
            this->nome = nome;
            this->endereco = endereco;
            this->telefone = telefone;
        }

        string toString() {
            return nome + ", " + telefone + "\n" + endereco.toString() + "\n";
        }
        string getNome() {
            return nome;
        }
        void setNome(string nome) {
            this->nome = nome;
        }
        Endereco getEndereco() {
            return endereco;
        }
        void setEndereco(Endereco endereco) {
            this->endereco = endereco;
        }
        string getTelefone() {
            return telefone;
        }
        void setTelefone(string telefone) {
            this->telefone = telefone;
        }
    };

int main() {
    int n;
    cin >> n;

    vector<Pessoa> agenda;
    for (int i = 0; i < n; i++) {
        string nome, rua, bairro, cidade, estado, cep, telefone;
        int numero;

        getline(cin >> ws, nome);
        getline(cin, telefone);
        getline(cin, rua);
        cin >> numero;
        getline(cin >> ws, bairro);
        getline(cin, cidade);
        getline(cin, estado);
        getline(cin, cep);

        Endereco endereco(rua, numero, bairro, cidade, estado, cep);
        Pessoa pessoa(nome, endereco, telefone);
        agenda.push_back(pessoa);
    }
    
    for (Pessoa p : agenda) {
        cout << p.toString() << endl;
    }

    return 0;
}

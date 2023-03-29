// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>
using namespace std;

class Funcionario {
private:
    string nome;
    string sobrenome;
    float salarioMensal;

public:
    Funcionario(string nome, string sobrenome, float salarioMensal) {
        setNome(nome);
        setSobrenome(sobrenome);
        setSalarioMensal(salarioMensal);
    }

    Funcionario() {
        nome = "";
        sobrenome = "";
        salarioMensal = 0.0;
    }

    void setNome(string nome) {
        this->nome = nome;
    }
    string getNome() {
        return nome;
    }

    void setSobrenome(string sobrenome) {
        this->sobrenome = sobrenome;
    }
    string getSobrenome() {
        return sobrenome;
    }

    void setSalarioMensal(float salarioMensal) {
        if (salarioMensal < 0) {
            this->salarioMensal = 0;
        } else {
            this->salarioMensal = salarioMensal;
        }
    }
    float getSalarioMensal() {
        return salarioMensal;
    }

    float getSalarioAnual() {
        return salarioMensal * 12;
    }

    void aumentaSalario(float percent) {
        salarioMensal *= (1 + percent);
    }
};

int main() {
    int n;
    cin >> n;

    Funcionario* funcionarios = new Funcionario[n];
    for (int i = 0; i < n; i++) {
        string nome, sobrenome;
        float salarioMensal;
        cin >> nome >> sobrenome >> salarioMensal;
        Funcionario funcionario(nome, sobrenome, salarioMensal);
        funcionarios[i] = funcionario;
    }

    for (int i = 0; i < n; i++) {
        cout << funcionarios[i].getNome() << " " << funcionarios[i].getSobrenome() << " - " << funcionarios[i].getSalarioMensal() << " - " << funcionarios[i].getSalarioAnual() << endl;
        funcionarios[i].aumentaSalario(0.1);
        cout << funcionarios[i].getSalarioAnual() << endl;
    }

    return 0;
}

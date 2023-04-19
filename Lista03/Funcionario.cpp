// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

class Funcionario {
  protected:
    string matricula;
    string nome;
    float salario;

  public:
    Funcionario() : matricula("0000"), nome("Sem nome"), salario(0.0) {}

    Funcionario(string matricula, string nome, float salario) {
      this->matricula = matricula;
      this->nome = nome;
      this->salario = salario;
    }

    void setMatricula(string matricula) {
      this->matricula = matricula;
    }

    void setNome(string nome) {
      this->nome = nome;
    }

    void setSalario(float salario) {
      this->salario = salario;
    }

    string getMatricula() const {
      return matricula;
    }

    string getNome() const {
      return nome;
    }

    float getSalario() const {
      return salario;
    }
};

class Consultor : public Funcionario {
  public:
    float getSalario(float percentual) const {
      return salario * (1 + percentual);
    }

    float getSalario() const {
      return salario * 1.1;
    }
};

int main() {
  string matricula, nome;
  float salario;

  Funcionario f1;
  Consultor c1;

  getline(cin, matricula);
  getline(cin, nome);
  cin >> salario;
  cin.ignore();

  f1.setMatricula(matricula);
  f1.setNome(nome);
  f1.setSalario(salario);

  getline(cin, matricula);
  getline(cin, nome);
  cin >> salario;

  c1.setMatricula(matricula);
  c1.setNome(nome);
  c1.setSalario(salario);

  cout << f1.getMatricula() << " - " << f1.getNome() << " - R$ " << f1.getSalario() << endl;
  cout << c1.getMatricula() << " - " << c1.getNome() << " - R$ " << c1.getSalario() << endl;

  return 0;
}
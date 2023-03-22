// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

using namespace std;

class Funcionario
{
    public:
        Funcionario();

        std::string nome;
        std::string snome;
        float salario;

        float getSalarioAnual();

    protected:

    private:
};

#endif // FUNCIONARIO_H

Funcionario::Funcionario() {
    //
}

float Funcionario::getSalarioAnual(){

    return salario * 12.0;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    Funcionario funcionario[n];
    
    for(int i = 0; i< n; i++){

        getline(cin, funcionario[i].nome);
        getline(cin, funcionario[i].snome);
        cin >> funcionario[i].salario;
        getchar();

    }
    
    for(int i = 0; i<n; i++){
        cout << funcionario[i].nome << " " << funcionario[i].snome << " - " << funcionario[i].salario << " - " << funcionario[i].getSalarioAnual() << endl;
    }
    
    return 0;
}

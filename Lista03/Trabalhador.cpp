// Ralf Dewrich Ferreira 😊

#include <iostream>
using namespace std;

class Trabalhador {
    protected:
        string nome;
        int salario;
    public:
        Trabalhador();
        Trabalhador(string n, int s);
        void setNome(string n);
        void setSalario(int s);
        string getNome();
        int getSalario();
};

Trabalhador::Trabalhador() : Trabalhador("", 0)
{
}

Trabalhador::Trabalhador(string n, int s)
{
    setNome(n);
    setSalario(s);
}

void Trabalhador::setNome(string n)
{
    nome = n;
}

void Trabalhador::setSalario(int s)
{
    salario = s;
}

string Trabalhador::getNome()
{
    return nome;
}

int Trabalhador::getSalario()
{
    return salario;
}

class TrabalhadorAssalariado : public Trabalhador {
    public:
        TrabalhadorAssalariado();
        TrabalhadorAssalariado(string n, int s);
        int calcularPagamentoSemanal();
};

TrabalhadorAssalariado::TrabalhadorAssalariado() : TrabalhadorAssalariado("", 0)
{
}

TrabalhadorAssalariado::TrabalhadorAssalariado(string n, int s) : Trabalhador(n, s)
{
}

int TrabalhadorAssalariado::calcularPagamentoSemanal()
{
    return salario / 4;
}

class TrabalhadorPorHora : public Trabalhador {
    private:
        int valorDaHora;
        int horasTrabalhadas;
    public:
        TrabalhadorPorHora();
        TrabalhadorPorHora(string n, int s, int h);
        void setHorasTrabalhadas(int h);
        int getHorasTrabalhadas();
        int calcularPagamentoSemanal(int horasSemanais);
};

TrabalhadorPorHora::TrabalhadorPorHora() : TrabalhadorPorHora("", 0.0, 0.0)
{
}

TrabalhadorPorHora::TrabalhadorPorHora(string n, int s, int h) : Trabalhador(n, s)
{
    setHorasTrabalhadas(h);
}

void TrabalhadorPorHora::setHorasTrabalhadas(int h)
{
    this->valorDaHora = h;
}

int TrabalhadorPorHora::getHorasTrabalhadas()
{
    return valorDaHora;
}

int TrabalhadorPorHora::calcularPagamentoSemanal(int horasSemanais)
{
    int total = 0;
    if(horasSemanais > 40){
        total+= valorDaHora * 40;
        total+= (valorDaHora * 1.5) * (horasSemanais - 40);
    }
    else{
        total = valorDaHora * horasSemanais;
    }
    setSalario(total*4);
    return total;
}

int main(void)
{
    int N, tipo;
    string nome;
    int salario, valorHora, horasSemanais;

    cin >> N;

    Trabalhador *trabalho[N];

    
    for(int i = 0; i < N; i++)
    {
        cin >> tipo;
        cin.ignore();
        getline(cin, nome);
        if(tipo == 1){
            cin >> salario;
            trabalho[i] = new TrabalhadorAssalariado(nome, salario);
        }
        else {
            cin >> valorHora;
            cin >> horasSemanais;
            trabalho[i] = new TrabalhadorPorHora(nome, 0, valorHora);
        }

        cout << trabalho[i]->getNome() << " - Semanal: R$ ";
        if(tipo == 1){
            cout << ((TrabalhadorAssalariado*)trabalho[i])->calcularPagamentoSemanal();
        }
        else {
            cout << ((TrabalhadorPorHora*)trabalho[i])->calcularPagamentoSemanal(horasSemanais);
        }
        cout << " - Mensal: R$ " << trabalho[i]->getSalario() << endl;
    }
    
    return 0;
}

// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

class Despesa {

    private:
        string nome;
        double valor;
        string tipoGasto;
    public:
        Despesa();
        void setNome(string name);
        void setValor(float val);
        void setTipo(string type);
        float getValor();
        string getTipoGasto();
        string getNome();
};

Despesa::Despesa() {

}

void Despesa::setNome(string name)
{
    nome = name;
}

void Despesa::setValor(float val)
{
    valor = val;
}

void Despesa::setTipo(string type)
{
    tipoGasto = type;
}

float Despesa::getValor()
{
    return valor;
}

string Despesa::getTipoGasto()
{
    return tipoGasto;
}

string Despesa::getNome()
{
    return nome;
}


class ControleDeGastos 
{
    private:
        Despesa despesa[100];
    public:
        ControleDeGastos();
        void setDespesa(Despesa d, int pos);
        Despesa getDespesa(int pos);
        float calculaTotalDespesa();
        float calculaTotalDespesa(string tipo);
        bool existeDespesaDoTipo(string tipo);
};

    ControleDeGastos::ControleDeGastos()
    {

    }

    void ControleDeGastos::setDespesa(Despesa d, int pos)
    {
        despesa[pos] = d;
    }

    Despesa ControleDeGastos::getDespesa(int pos)
    {
        return despesa[pos];
    }

    float ControleDeGastos::calculaTotalDespesa()
    {
        float total = 0;
        bool hasDespesa = false;
        for (Despesa desp : despesa) {
            if (desp.getValor() > 0) {
                hasDespesa = true;
                total += desp.getValor(); 
            }
        }
        return hasDespesa ? total : 0;
    }

    float ControleDeGastos::calculaTotalDespesa(string tipo)
    {
        float total=0;
        for(Despesa desp : despesa) {
            if(desp.getTipoGasto() == tipo){
                total += desp.getValor();
            }
        }
        return total;
    }

    bool ControleDeGastos::existeDespesaDoTipo(string tipo)
    {
        for(Despesa desp: despesa){
            if(desp.getTipoGasto() == tipo)
                return true;
        }
        return false;
    }

int main(void){
    int N;
    float valor;
    string nome, tipo;

    Despesa d;
    ControleDeGastos controleDeGastos;

    cin >> N;
    cin.ignore();

    for(int i = 0; i < N; i++){
        getline(cin, nome);
        cin >> valor;
        cin.ignore();
        getline(cin, tipo);
        
        d.setNome(nome);
        d.setTipo(tipo);
        d.setValor(valor);

        controleDeGastos.setDespesa(d, i);
    }

    cin >> tipo;
    if(controleDeGastos.existeDespesaDoTipo(tipo)){
        for(auto i=0; i<100; i++){
            d = controleDeGastos.getDespesa(i);
            if(d.getTipoGasto() == tipo){
                cout << d.getNome() << ", R$ "<< d.getValor() << endl;
            }
        }
    }

    else {
        cout << "Nenhuma despesa do tipo especificado" << endl;
    }

    cout << "Total: " << controleDeGastos.calculaTotalDespesa(tipo) << "/" << controleDeGastos.calculaTotalDespesa() << endl;

    return 0;
}
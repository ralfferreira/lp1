// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

class Pagamento {
private:
    float valorPagamento;
    string nomeDoFuncionario;

public:
    Pagamento() {
        valorPagamento = 0;
    }

    float getValorPagamento() {
        return valorPagamento;
    }

    void setValorPagamento(float v) {
        valorPagamento = v;
    }

    string getNomeDoFuncionario() {
        return nomeDoFuncionario;
    }

    void setNomeDoFuncionario(string n) {
        nomeDoFuncionario = n;
    }
};

class ControleDePagamentos {
private:
    Pagamento pagamentos[100];

public:
    void setPagamento(Pagamento p, int index) {
        pagamentos[index] = p;
    }

    Pagamento getPagamento(int pos) {
        return pagamentos[pos];
    }

    float calculaTotalDePagamentos() {
        float total = 0;
        for (int i = 0; i < 100; i++) {
            total += pagamentos[i].getValorPagamento();
        }
        return total;
    }

    int getIndexFuncionario(string nomeFuncionario) {
        for(int i = 0; i < 100; i++){
            if(pagamentos[i].getNomeDoFuncionario().find(nomeFuncionario) != std::string::npos){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int numPagamentos;
    string nomeFuncionario;

    ControleDePagamentos controle;

    cin >> numPagamentos;

    for (int i = 0; i < numPagamentos; i++) {
        float valorPagamento;
        string nomeDoFuncionario;

        cin >> valorPagamento;
        cin.ignore();

        getline(cin, nomeDoFuncionario);

        Pagamento p;
        p.setValorPagamento(valorPagamento);
        p.setNomeDoFuncionario(nomeDoFuncionario);

        controle.setPagamento(p, i);
    }
    
    getline(cin, nomeFuncionario);

    
    int index = controle.getIndexFuncionario(nomeFuncionario);
    if (index != -1) {
        Pagamento p = controle.getPagamento(index);
        cout << p.getNomeDoFuncionario() << ": R$ " << p.getValorPagamento() << endl;
    } else {
        cout << nomeFuncionario << " não encontrado(a)." << endl;
    }

    cout << "Total: R$ " << controle.calculaTotalDePagamentos() << endl;

    return 0;
}

// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    int numero;
    string descricao;
    int quantidade;
    float preco;

public:
    Invoice(int num, string desc, int quant, float prec){
        setNumero(num);
        setDescricao(desc);
        setQuantidade(quant);
        setPreco(prec);
    }

    int getNumero(){
        return numero;
    }

    void setNumero(int num){
        numero = num;
    }

    string getDescricao(){
        return descricao;
    }

    void setDescricao(string desc){
        descricao = desc;
    }

    int getQuantidade(){
        return quantidade;
    }

    void setQuantidade(int quant){
        if(quant < 0){
            quantidade = 0;
        } else {
            quantidade = quant;
        }
    }

    float getPreco(){
        return preco;
    }

    void setPreco(float prec){
        if(prec < 0){
            preco = 0.0;
        } else {
            preco = prec;
        }
    }

    float getInvoiceAmount(){
        return quantidade * preco;
    }

    void print(){
        cout << getNumero() << " - " << getDescricao() << " - " << getQuantidade() << " - " << getPreco() << " - " << getInvoiceAmount() << endl;
    }
};

int main(){
    int num1, quant1;
    float prec1;
    string desc1;

    int num2, quant2;
    float prec2;
    string desc2;

    cin >> num1;
    getchar();
    getline(cin, desc1);
    cin >> quant1;
    cin >> prec1;

    cin >> num2;
    getchar();
    getline(cin, desc2);
    cin >> quant2;
    cin >> prec2;

    Invoice invoice1(num1, desc1, quant1, prec1);
    Invoice invoice2(num2, desc2, quant2, prec2);

    invoice1.print();
    invoice2.print();

    return 0;
}
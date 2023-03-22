// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>
#ifndef INVOICE_H
#define INVOICE_H

using namespace std;

class Invoice {
    public:
        Invoice();
        int numero;
        std::string descricao;
        int quantidade;
        float preco;
        float getInvoiceAmount();
        void verificaAtributos();
};

#endif // INVOICE_H

Invoice::Invoice(){
    //
}

void Invoice::verificaAtributos(){
 if(quantidade < 0){
    quantidade = 0;
 }
 else if(preco < 0){
    preco = 0.0;
 }
}

float Invoice::getInvoiceAmount(){
    return quantidade * preco;
}


int main()
{
    Invoice invoice1, invoice2;
    cin >> invoice1.numero;
    getchar();
    getline(cin, invoice1.descricao);
    cin >> invoice1.quantidade;
    cin >> invoice1.preco;
    cin >> invoice2.numero;
    getchar();
    getline(cin, invoice2.descricao);
    cin >> invoice2.quantidade;
    cin >> invoice2.preco;
    invoice1.verificaAtributos();
    invoice2.verificaAtributos();

    cout << invoice1.numero << " - " << invoice1.descricao << " - " << invoice1.quantidade << " - " << invoice1.preco << " - " << invoice1.getInvoiceAmount() << endl;
    cout << invoice2.numero << " - " << invoice2.descricao << " - " << invoice2.quantidade << " - " << invoice2.preco << " - " << invoice2.getInvoiceAmount() << endl;

    return 0;
}

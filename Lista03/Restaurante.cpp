// Ralf Dewrich Ferreira 😊

#include <iostream>
using namespace std;
#define MAXIMO 10

class Pedido {
    int numero;
    string descricao;
    int quantidade;
    float preco;

    public:
        Pedido();
        Pedido(int numero, string descricao, int quantidade, float preco);
        float getTotal();
        int getNumero();
        string getDescricao();
        int getQuantidade();
        float getPreco();
        void setQuantidade(float quantidade);
};

Pedido::Pedido(): Pedido(0, "", 0, 0.0)
{
}

void Pedido::setQuantidade(float quantidade)
{
    this->quantidade = quantidade;
}

Pedido::Pedido(int numero, string descricao, int quantidade, float preco)
{
    this->numero = numero;
    this->descricao = descricao;
    setQuantidade(quantidade);
    this->preco = preco;
}

float Pedido::getTotal()
{
    return getQuantidade() * getPreco();
}

int Pedido::getNumero()
{
    return numero;
}

string Pedido::getDescricao()
{
    return descricao;
}

int Pedido::getQuantidade()
{
    return quantidade;
}

float Pedido::getPreco()
{
    return preco;
}

class MesaDeRestaurante 
{
    Pedido *pedidos[MAXIMO];
    int uso=0;

    public:
        MesaDeRestaurante();
        void adicionarPedido(Pedido pedido);
        void zeraPedidos();
        float calculaTotal();
        void exibeConta();
        int getUso();
        void setUso(int uso);
};

MesaDeRestaurante::MesaDeRestaurante()
{
    for(auto i = 0; i < MAXIMO; i++)
    {
        pedidos[i] = new Pedido();
    }
}

void MesaDeRestaurante::adicionarPedido(Pedido pedido)
{
    int repetido = 0;
    setUso(1);
    for(auto i = 0; i < MAXIMO; i++)
    {
        if(pedido.getNumero() == pedidos[i]->getNumero())
        {
            float qntd = 0;
            qntd = pedidos[i]->getQuantidade() + pedido.getQuantidade();
            pedidos[i]->setQuantidade(qntd);
            repetido = 1;
            break;
        }
    }

    if(repetido == 0)
    {
        for(int i = 0; i < MAXIMO; i++)
        {
            if(pedidos[i]->getNumero() == 0)
            {
                pedidos[i] = new Pedido(pedido);
                return;
            }
        }
    }
}

void MesaDeRestaurante::zeraPedidos()
{
    for(auto i = 0; i < MAXIMO; i++)
    {
        if(pedidos[i]->getNumero() != 0)
            delete pedidos[i];
    }
}

float MesaDeRestaurante::calculaTotal()
{
    float total = 0;
    for(auto i = 0; i < MAXIMO; i++)
    {
        if(pedidos[i]->getNumero() != 0)
            total+= pedidos[i]->getTotal();
    }
    return total;
}

void MesaDeRestaurante::exibeConta()
{
    for(auto i = 0; i < MAXIMO; i++)
    {
        if(pedidos[i]->getNumero() != 0)
            cout << pedidos[i]->getNumero() << " - " << pedidos[i]->getDescricao() << " - " 
            << pedidos[i]->getQuantidade() << " - " << pedidos[i]->getPreco() << " - R$ " << pedidos[i]->getTotal() << endl;
    }
}

int MesaDeRestaurante::getUso()
{
    return this->uso;
}

void MesaDeRestaurante::setUso(int uso)
{
    this->uso = uso;
}

class Restaurante 
{
    MesaDeRestaurante *mesas[MAXIMO];
    
    public:
        Restaurante();
        void adicionarPedido(Pedido pedido, int mesa);
        float calculaTotalRestaurante();
        MesaDeRestaurante *getMesa(int mesa);
};

Restaurante::Restaurante()
{
    for(auto i = 0; i < MAXIMO; i++)
    {
        mesas[i] = new MesaDeRestaurante();
    }
}

void Restaurante::adicionarPedido(Pedido pedido, int mesa)
{
    if(mesas[mesa] == nullptr)
    
    {
        mesas[mesa] = new MesaDeRestaurante();
    }
    mesas[mesa]->adicionarPedido(pedido);
}

float Restaurante::calculaTotalRestaurante()
{
    float total = 0;
    for(auto i = 0; i < MAXIMO; i++)
    {
        if(mesas[i]->getUso() != 0)
            total+= mesas[i]->calculaTotal();
    }
    return total;
}

MesaDeRestaurante *Restaurante::getMesa(int mesa)
{
    return mesas[mesa];
}

int main()
{
    int numero = 0, quantidade, mesa;
    string descricao;
    float preco;
    Restaurante restaurante;
    Pedido pedido;

    while (true)
    {
        cin >> numero;
        if(numero < 0) break; 
        cin.ignore();
        getline(cin, descricao);
        cin >> quantidade;
        cin >> preco;
        cin >> mesa;
        pedido = Pedido(numero, descricao, quantidade, preco);
        restaurante.adicionarPedido(pedido, mesa);
    }
    
    for(auto i = 0; i < MAXIMO; i++) 
    {
        if(restaurante.getMesa(i)->getUso() != 0)
        {
            cout << "Mesa " << i << endl;
            restaurante.getMesa(i)->exibeConta();
            cout << "Total: R$ " << restaurante.getMesa(i)->calculaTotal() << endl;
            cout << "\n";
        }
    }

    cout << "Total Restaurante: R$ " << restaurante.calculaTotalRestaurante() << endl;
    
    return 0;
}
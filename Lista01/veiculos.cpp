// Ralf Dewrich Ferreira 😊

#include <iostream>
#include <string>

using namespace std;

typedef struct tVeiculo {
    string modelo;
    string marca;
    int anoFabricacao;
    float preco;
} tVeiculo;

int main() {
    tVeiculo veiculo1, veiculo2;

    getline(cin, veiculo1.modelo);
    getline(cin, veiculo1.marca);
    cin >> veiculo1.anoFabricacao;
    cin >> veiculo1.preco;
    cin.ignore();
    getline(cin, veiculo2.modelo);
    getline(cin, veiculo2.marca);
    cin >> veiculo2.anoFabricacao;
    cin >> veiculo2.preco;

    if (veiculo1.anoFabricacao < veiculo2.anoFabricacao) {
        cout << veiculo1.marca << " " << veiculo1.modelo << endl;
    } else if (veiculo2.anoFabricacao < veiculo1.anoFabricacao) {
        cout << veiculo2.marca << " " << veiculo2.modelo << endl;
    } else {
        if (veiculo1.preco < veiculo2.preco) {
            cout << veiculo1.marca << " " << veiculo1.modelo << endl;
        }  
        else {
            cout << veiculo2.marca << " " << veiculo2.modelo << endl;
        }
    }

    return 0;
}

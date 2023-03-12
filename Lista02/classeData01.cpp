#include <iostream>

using namespace std;

class Data {
    public:
        int dia;
        int mes;
        int ano;
};

int main() {
    Data data;
    cin >> data.dia;
    cin >> data.mes;
    cin >> data.ano;

    cout << data.dia << "/" << data.mes << "/" << data.ano;

    return 0;
}

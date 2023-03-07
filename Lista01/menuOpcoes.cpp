#include <iostream>
using namespace std; 

int main() {

int op = 0;

while (op != 4) {

 cout << "1 - Item 1\n";
 cout << "2 - Item 2\n";
 cout << "3 - Item 3\n";
 cout << "4 - Sair\n";
 cin >> op;

switch (op) {
 case 1:
  cout << "Item 1\n";
 break;
 case 2:
  cout << "Item 2\n";
 break;
 case 3:
  cout << "Item 3\n";
 break;
 case 4:
  cout << "Sair\n";
 break;
 default:
  cout << "Opcao " << op << " Invalida\n";
}

}

}
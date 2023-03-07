// Ralf Dewrich Ferreira 😊

#include <iostream>

using namespace std;

void SomaDasMatrizes(int a[][101], int b[][101], int lin, int col) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[101][101], b[101][101];
    int lin, col;

    cin >> lin >> col;

    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    for(int k = 0; k < lin; k++) {
        for(int l = 0; l < col; l++) {
            cin >> b[k][l];
        }
    }

    SomaDasMatrizes(a, b, lin, col);

    return 0;
}

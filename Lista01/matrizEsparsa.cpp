// Ralf Dewrich Ferreira 😊

#include <iostream>

using namespace std;

bool isEsparca (float m[10][10], int lin, int col) {
    int qTotal = lin * col;
    int qZeros = 0;
    for (int x = 0; x < col; x++)
    for (int y = 0; y < lin; y++)
    if (m[x][y] == 0)
    qZeros++;
    
    
    if (qZeros > qTotal * 0.7)
    return true;
    else
    return false;
}

int main() {
    int lin, col;
    float mat[10][10];
    cin >> lin;
    cin >> col;
    
    for(int x = 0; x < col; x++) 
        for(int y = 0; y < lin; y++)
            cin >> mat[x][y];
    
    
    bool ret = isEsparca(mat, lin, col);
    if(ret)
        cout << "A matriz é esparsa";
    else
        cout << "A matriz não é esparsa";
}
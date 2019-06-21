#include <iostream>

using namespace std;
int ** transponir(const int* const* matr, int rows, int cols){
    int ** m = new int*[rows];
    for(int i = 0;i<rows;i++)
        m[i] = new int[cols];
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;i++){
            if(matr[i][j]!=0){
                m[j][i] = matr[i][j];
            }
        }
    }
    return m;
}

int main()
{
    int rows = 5;
    int cols = 6;
    int ** matr = new int*[rows];
    for(int i = 0;i<rows;i++)
        *(matr+i) = new int[cols];
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;i++){
            matr[i][j] = i+j;
        }
    }
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;i++){
            cout<<matr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    matr = transponir(matr, rows, cols);
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;i++){
            cout<<matr[i][j];
        }
        cout<<endl;
    }

    return 0;
}

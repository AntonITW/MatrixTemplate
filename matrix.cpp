#include <stdio.h>
#include <iostream>
#include <ctime>

template <class T>
class Matrix
{
public:
    T **data;
    int row,col;
    Matrix( int rows, int cols)
    {
        setRow(rows);
        setCol(cols);
        data = new T*[rows]; 
        for (int i = 0; i < row; i++) {
            data[i] = new T [cols]; 
        }
        srand(time(0));
        int s = 1;
        int e = 100;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < cols; j++) {
                data[i][j] = rand()%(e-s+1)+s;
            }
        }
    }

    void setRow(int r){
        row = r;
    }

    void setCol(int c){
        col = c;
    }
    
    void print(){
        int i,j;
        for (i=0;i < row;i++) 
        {
            for(j=0;j < col;j++) 
            {
                printf("%d    ",(T) data[i][j]);
            }
            printf("\n");
        }
    }
};

int main()
{
    int a, b;
    printf("Введите количество строк в матрице: \n");
    scanf("%d", &a);
    printf("Введите количество столбцов в матрице: \n");
    scanf("%d", &b);
    Matrix <int> m(a,b);
    m.print();
    return 0;
}


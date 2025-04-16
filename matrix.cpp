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
template<typename T>
void addition (T m1, T m2) {
    int rows = m1.row; int cols = m1.col;
    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
            arr[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)  {
                printf("%d    ", arr[i][j]);
            }
            printf("\n");
    }
}

int main()
{
    int rows, cols;
    printf("Введите количество строк в матрице: \n");
    scanf("%d", &rows);
    printf("Введите количество столбцов в матрице: \n");
    scanf("%d", &cols);
    
    Matrix <int> m1(rows, cols);
    m1.print();
    Matrix <int> m2(rows, cols);
    m2.print();
    addition(m1, m2);
    
    return 0;
}

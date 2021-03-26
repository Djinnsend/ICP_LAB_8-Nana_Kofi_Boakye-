#include <iostream>
#include <string>
#include <stdlib.h>                     //For the use of random numbers, thus the function rand()
using namespace std;



int LinearIndx(int mRow, int mCol){
    int index = (((mRow + 1) * mRow)/2) + mCol;
    return index;
}

void InverseIndex(int index){}

void printArrays(int** multiArray, int* B,int size){
    int A_count = 0, B_count = 0;
    int B_Size = (size+1)*size*0.5;
    cout <<"\n The values of array A: \n";
    for (int i = 0; i<size; i++){
        for (int j = 0; j < size; j++){
            if(A_count == 20)
                break;
            else{
                cout << multiArray[i][j] << "---";
            }
            A_count++;
        }
        cout << "\n";
    }
    cout <<"The values of array B: \n";
    for (int i = 0; i<B_Size; i++){
        if (B_count == 20)
            break;
        cout << B[i];
        cout << "\n";
        B_count++;
    }
    cout << "\n Iteration is over------ \n";
};

int elemCount = 0;
void Lower_Triangle(int size)
{
    int B_Size = (size+1)*size*0.5;
    cout << "Size of B is: " << B_Size << " and the multiArray size is " << size << "\n";
    int* B = new int[B_Size];
    int **multiArray = new int *[size]; //Declaring multi dimentional array by allocating dynamic memory since we are using parameters.
    for (int i = 0; i < size; i++)
    {
        multiArray[i] = new int[size]; //Making 2 Dimensional array by indexing with i and rows are the same number as column
    }

    /* 
    ** Now we are to loop through our 2-Dimensional array and allocate value based on the indices of i and j. We will use a nested loop.
    ** At this point our matrix is empty
    */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            if(j <= i){                 //If j <= i then we are either at the diagonal or below it. Thus we assign it a random number using rand.          
                multiArray[i][j] = rand() % (1000 + 1);
                int B_index = LinearIndx(i,j);
                B[B_index] = multiArray[i][j];
            }
            else{
                multiArray[i][j] = 0;
            }
        }
    }
    cout << ".... Processing. \n OVER------ \n";
    printArrays(multiArray, B, size);
    // return multiArray;
}

int main(int argc, char const *argv[])
{
    Lower_Triangle(8);
    Lower_Triangle(32);
    Lower_Triangle(128);
    return 0;
}



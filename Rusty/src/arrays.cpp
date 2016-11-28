#include "arrays.h"
#include "iostream"
using namespace std;

void rotateRight(int** A, int n){
    for(int j=0;j<n/2;j++){
        for(int i=j;i<n-1-j;i++){
            int t             =   A[j][i];
            A[j][i]           =   A[n-1-i][j];
            A[n-1-i][j]       =   A[n-1-j][n-1-i];
            A[n-1-j][n-1-i]   =   A[i][n-1-j];
            A[i][n-1-j]       =   t;
        }
    }
}
void rotateLeft(int** A, int n){
    for(int j=0;j<n/2;j++){
        for(int i=j;i<n-1-j;i++){
            int t           =   A[i][j];
            A[i][j]         =   A[j][n-1-i];
            A[j][n-1-i]     =   A[n-1-i][n-1-j];
            A[n-1-i][n-1-j] =   A[n-1-j][i];
            A[n-1-j][i]     =   t;
        }
    }
}
void spiralPrint(int** A, int n){
    for(int j=0;j<n/2;j++){
        for(int i=j;i<n-1-j;i++)
            cout<<A[j][i]<<" ";
        for(int i=j;i<n-1-j;i++)
            cout<<A[i][n-1-j]<<" ";
        for(int i=n-1-j;i>j;i--)
            cout<<A[n-1-j][i]<<" ";
        for(int i=n-1-j;i>j;i--)
            cout<<A[i][j]<<" ";
    }
    if(n%2)
        cout<<A[n/2][n/2];
}
int** createSpiral(int n){
    int** A = new int* [n];
    for(int i=0;i<n;i++)
        A[i] = new int[n];
    int a=0,b=n-1,c=0,d=n-1,k=1;
    while(a<=b&&c<=d){
        if(a<=b){
            for(int i=c;i<=d;i++)
                A[a][i] = k++;
            a++;
        }
        if(c<=d){
            for(int i=a;i<=b;i++)
                A[i][d] = k++;
            d--;
        }
        if(a<=b){
            for(int i=d;i>=c;i--)
                A[b][i] = k++;
            b--;
        }
        if(c<=d){
            for(int i=b;i>=a;i--)
                A[i][c] = k++;
            c++;
        }
    }
    return A;
}

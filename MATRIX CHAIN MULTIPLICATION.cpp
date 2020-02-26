#include<iostream>
#include<climits>
#define MAX 1000

void Print_Parenthesis(int i, int j, int n, int *bracket, char &name)
{
    if (i == j)
    {
        std::cout << name++;
        return;
    }

    std::cout << "(";
    Print_Parenthesis(i, *((bracket+i*n)+j), n, bracket, name);
    Print_Parenthesis(*((bracket+i*n)+j) + 1, j, n, bracket, name);
    std::cout << ")";
}

void Matrix_Chain_Multiplication(int p[], int n)
{
    int table[n][n], bracket[n][n];

    for(int i = 1; i < n; i++)
    {
        table[i][i] = 0;
    }

    for(int L = 2; L < n; L++)
    {
        for(int i = 1; i < n-L+1; i++)
        {
            int j = i+L-1;
            table[i][j] = INT_MAX;
            for(int k = i; k <= j-1; k++)
            {
                int q = table[i][k] + table[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < table[i][j])
                {
                    table[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    std::cout << "Total Number of Multiplication Costs :- " << table[1][n-1] << std::endl;

    char name = 'A';
    std::cout << "Optimal Parenthesization required is :- " << std::endl;
    Print_Parenthesis(1, n-1, n, (int *)bracket, name);
}

int main()
{
    int n, arr[MAX];
    std::cout << "Enter the size of the array :- ";
    std::cin >> n;

    std::cout << "Enter the elements :- " << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    Matrix_Chain_Multiplication(arr, n);
}

#include<iostream>
#include<climits>

int Matrix_Chain_Multiplication(int p[], int i, int j)
{
    if(i == j)
    {
        return 0;
    }
    int count = 0;
    int min = INT_MAX;
    for(int k = i; k < j; k++)
    {
        count = Matrix_Chain_Multiplication(p, i, k) + Matrix_Chain_Multiplication(p, k+1, j) + p[i-1]*p[k]*p[j];
        if(count < min)
        {
            min = count;
        }
    }

    return min;
}

int main()
{
    int arr[100], n;
    std::cout << "Enter the size of the array :- ";
    std::cin >> n;

    std::cout << "Enter the values of array :- " << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "The total cost is :- " << Matrix_Chain_Multiplication(arr, 1, n-1) << std::endl;
}

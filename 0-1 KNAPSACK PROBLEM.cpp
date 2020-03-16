#include<iostream>
#define MAX 1000

int max(int a, int b)
{
    return (a > b)? a : b;
}

void Knapsack_01(int maxWeigth, int val[], int weight[], int items)
{
    int knaksack[items+1][maxWeigth+1];

    for(int i = 0; i <= items; i++)
    {
        for(int w = 0; w <= maxWeigth; w++)
        {
            if(i == 0 || w == 0)
            {
                knaksack[i][w] = 0;
            }
            else if(weight[i-1] <= w)
            {
                knaksack[i][w] = max(val[i-1] + knaksack[i-1][w-weight[i-1]], knaksack[i-1][w]);
            }
            else
            {
                knaksack[i][w] = knaksack[i-1][w];
            }
        }
    }

    std::cout << "The max profit value is :- " << knaksack[items][maxWeigth] << std::endl;

    int i = items, k = maxWeigth, j = 0;

    std::cout << "The chossen items are :- " << std::endl;
    while(i != 0  && k > 0)
    {
        if(knaksack[i][k] != knaksack[i-1][k])
        {
            std::cout << i << std::endl;
            i--;
            k = k - weight[i];
            j++;
        }
        else
        {
            i--;
        }
    }
}

int main()
{
    int val[MAX], weight[MAX], items, maxWeigth;

    std::cout << "Enter the no of items :- ";
    std::cin >> items;

    std::cout << "Enter the " << items << " items and their weights :- " << std::endl;
    for(int i = 0; i < items; i++)
    {
        std::cin >> val[i];
        std::cin >> weight[i];
    }

    std::cout << "Enter the max weight of the Knapsack :- ";
    std::cin >> maxWeigth;

    Knapsack_01(maxWeigth, val, weight, items);
}

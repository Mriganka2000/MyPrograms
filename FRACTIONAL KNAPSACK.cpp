#include<iostream>
#include<algorithm>
#define MAX 1000

class Item
{
public:
    int value, weight;
};

bool compare(Item a, Item b)
{
    double a1 = (double)a.value / a.weight;
    double b1 = (double)b.value / b.weight;
    return a1 > b1;
}

void Fractional_Knapsack(Item arr[], int maxWeight, int n)
{
    int currentWeight = 0;
    double finalValue = 0.0;

    std::sort(arr, arr + n, compare);

    for(int i = 0; i < n; i++)
    {
        if(currentWeight + arr[i].weight <= maxWeight)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = maxWeight - currentWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    std::cout << "The maximum cost can be get :- " << finalValue << std::endl;
}

int main()
{
    Item arr[MAX];
    int maxWeight, n;

    std::cout << "Enter the number of items :- ";
    std::cin >> n;

    std::cout << "Enter the value and weight of the elements :- " << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i].value;
        std::cin >> arr[i].weight;
    }

    std::cout << "Enter the maximum weight of knapsack :- ";
    std::cin >> maxWeight;

    Fractional_Knapsack(arr, maxWeight, n);
}

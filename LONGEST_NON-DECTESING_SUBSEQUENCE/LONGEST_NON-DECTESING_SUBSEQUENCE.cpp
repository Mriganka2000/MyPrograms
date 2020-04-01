#include<iostream>
#include<vector>

const int MAX = 100;

void Solution(int arr[], int n)
{
    int table[MAX];
    std::vector<int> sequence[MAX];

    sequence[0].push_back(arr[0]);

    for (int i = 0; i < n; i++)
    {
        table[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] >= arr[j]) && (table[i] < table[j] + 1) && (sequence[i].size() < sequence[j].size()))
            {
                table[i] = table[j] + 1;
                sequence[i] = sequence[j];
            }
        }
        sequence[i].push_back(arr[i]);
    }

    int max = table[0];
    for (int i = 0; i < n; i++)
    {
        if (max < table[i])
        {
            max = table[i];
        }
    }

    int maxSequence = 0;
    for (int i = 0; i < n; i++)
    {
        if (sequence[i].size() > sequence[maxSequence].size())
        {
            maxSequence = i;
        }
    }

    std::cout << "The length of the longest non decreasing subsequence :- " << max << std::endl;

    std::cout << "The subsequence is :- " << std::endl;
    for (int i : sequence[maxSequence])
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    int n;
    int arr[MAX];

    std::cout << "Enter the size of the array :- ";
    std::cin >> n;

    std::cout << "Enter the elements of the array :- " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    Solution(arr, n);
}
#include<iostream>
#include<algorithm>

class Job
{
public:
    char id;
    int profit;
    int deadline;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

int getMax(Job j[], int n)
{
    int max = j[0].deadline;
    for(int i = 0; i < n; i++)
    {
        if(j[i].deadline > max)
        {
            max = j[i].deadline;
        }
    }
    return max;
}

void jobSequencing(Job j[], int n)
{
    int maxDeadline = getMax(j, n);
    int temp, maxProfit = 0;
    char sequence[maxDeadline+1];

    std::sort(j, j+n, compare);

    for(int i = 0; i <= maxDeadline; i++)
    {
        sequence[i] = '\0';
    }

    for(int i = 0; i < n; i++)
    {
        if(sequence[j[i].deadline] == '\0')
        {
            sequence[j[i].deadline] = j[i].id;
            maxProfit = maxProfit + j[i].profit;
        }
        else
        {
            temp = j[i].deadline;
            while(temp > 0)
            {
                if(sequence[temp] == '\0')
                {
                    sequence[temp] = j[i].id;
                    maxProfit = maxProfit + j[i].profit;
                    break;
                }
                else
                {
                    temp--;
                }
            }
        }
    }

    std::cout << "The sequence of jobs :- " << std::endl;
    for(int i = 1; i <= maxDeadline; i++)
    {
        std::cout << sequence[i] << "  ";
    }
    std::cout << std::endl;
    std::cout << "The max profit can be gained :- "<< maxProfit << std::endl;
}

int main()
{
    int n = 5;
    Job j[100];

    std::cout << "Enter the number of jobs :- ";
    std::cin >> n;

    std::cout << "Enter the job items :- " << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter the job id :- ";
        std::cin >> j[i].id;
        std::cout << "Enter the job profit :- ";
        std::cin >> j[i].profit;
        std::cout << "Enter the job deadline :- ";
        std::cin >> j[i].deadline;
    }

    jobSequencing(j, n);
}

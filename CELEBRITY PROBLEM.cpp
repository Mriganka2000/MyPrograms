#include<iostream>
#include<stack>
#include<list>

#define MAX 100

bool MATRIX[MAX][MAX];

bool knows(int a, int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n)
{
    std::stack<int> s;
    int celebrity;

    for(int i = 0; i < n; i++)
    {
        s.push(i);
    }

    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();

    while(s.size() > 1)
    {
        if(knows(A, B))
        {
            A = s.top();
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }

    celebrity = s.top();
    s.pop();

    if(knows(celebrity, B))
    {
        celebrity = B;
    }
    if(knows(celebrity, A))
    {
        celebrity = A;
    }

    for(int i = 0; i < n; i++)
    {
        if((i != celebrity) && (knows(celebrity, i) || !knows(i, celebrity)))
        {
            return -1;
        }
    }
    return celebrity;
}

int main()
{
    int n = 4;

    std::cout << "Enter the number of members :- ";
    std::cin >> n;

    std::cout << "Enter the reletions between them :- " << std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << "Enter the " << i << " " << j << " value :- ";
            std::cin >> MATRIX[i][j];
        }
        std::cout << std::endl;
    }
    int id = findCelebrity(n);

    if(id == -1)
    {
        std::cout << std::endl;
        std::cout << "No celebrity present." << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Celebrity ID is :- " << id << std::endl;
    }
}

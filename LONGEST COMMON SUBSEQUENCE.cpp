#include<iostream>
#include<string>

void Longest_Common_Subsequence(std::string s1, std::string s2)
{
    int m = s1.length();
    int n = s2.length();

    int c[m+1][n+1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                c[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
            }
            else
            {
                c[i][j] = std::max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    int index = c[m][n];
    char sequence[index+1];
    sequence[index] = '\0';

    int i = m, j = n;

    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            sequence[index-1] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(c[i-1][j] > c[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    std::cout << "The Longest Common Subsequence is :- " << sequence;
}

int main()
{
    std::string s1, s2;
    std::cout << "Enter the first string :- ";
    std::cin >> s1;
    std::cout << "Enter the second string :- ";
    std::cin >> s2;

    Longest_Common_Subsequence(s1, s2);
}

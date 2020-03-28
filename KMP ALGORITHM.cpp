#include<iostream>
#include<string>

void computeLPS(std::string pat, int n, int* lps)
{
    int i = 1, j = 0;

    lps[0] = 0;

    while(i < n)
    {
        if(pat[i] == pat[j])
        {
            lps[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP_algorithm(std::string text, std::string pattern)
{
    int n = pattern.length();
    int lps[n];
    int len = text.length();
    int i = 0, j = 0;
    computeLPS(pattern, n, lps);

    while(i < len)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if(j == n)
        {
            std::cout << "Pattern found at :- " << i-j << std::endl;
            j = lps[j-1];
        }

        else if(i < len && text[i] != pattern[j])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    std::string text;
    std::string pattern;

    std::cout << "Enter the text :- ";
    std::cin >> text;
    std::cout << "Enter the patten :- ";
    std::cin >> pattern;

    KMP_algorithm(text, pattern);
}

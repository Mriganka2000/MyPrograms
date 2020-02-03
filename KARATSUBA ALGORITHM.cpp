#include <iostream>
#include <math.h>

int getLength(long long value)
{
    int counter = 0;

    while(value != 0)
    {
        counter++;
        value = value / 10;
    }
    return counter;
}

long long power(int base, int exponent)
{
    long long result = 1;
    while(exponent != 0)
    {
        result = result*base;
        exponent--;
    }
    return result;
}

long long multiply(long long a, long long b)
{
    if(getLength(a) == 1 || getLength(b) == 1)
    {
        return a*b;
    }

    else
    {
        int n = fmax(getLength(a), getLength(b));
        int nby2 = n/2;

        long long aL = (a / power(10, nby2));
        long long aR = (a % power(10, nby2));

        long long bL = (b / power(10, nby2));
        long long bR = (b % power(10, nby2));

        long long x1 = multiply(aL, bL);
        long long x2 = multiply((aL+aR), (bL+bR));
        long long x3 = multiply(aR, bR);

        return (x1*power(10, n) + (x2 - x1 - x3)*power(10, nby2) + x3);
    }
}

int main()
{
    long long int a, b;

    std::cout << "Enter the first number :- ";
    std::cin >> a;
    std::cout << "Enter the second number :- ";
    std::cin >> b;

    std::cout << "The multiplication result :- " << multiply(a,b) << std::endl;
}

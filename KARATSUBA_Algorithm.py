def getLength(value):
    count = 0
    while (value != 0):
        count = count + 1
        value = value // 10
    return count


def karatsuba(x, y):
    if (getLength(x) == 1 or getLength(y) == 1):
        return x * y
    else:
        n = max(getLength(x), getLength(y))
        nby2 = n / 2
        a = x // 10 ** (nby2)
        b = x % 10 ** (nby2)
        c = y // 10 ** (nby2)
        d = y % 10 ** (nby2)
        ac = karatsuba(a, c)
        bd = karatsuba(b, d)
        ad_plus_bc = karatsuba(a + b, c + d) - ac - bd
        prod = ac * 10 ** (2 * nby2) + (ad_plus_bc * 10 ** nby2) + bd
        return prod


a = int(input("Enter the first number :- "))
b = int(input("Enter the second number :- "))

print(karatsuba(a, b))
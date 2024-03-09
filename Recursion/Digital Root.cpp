#include <iostream>
#include <string>

// Digital root is the recursive sum of all the digits in a number.

// Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

// Examples
//     16  -->  1 + 6 = 7

int digital_root(int n)
{
    std::string str = std::to_string(n);
    int sum;
    sum = 0;

    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        sum += str[i] - '0';
    }

    if (sum < 10)
        return sum;
    else
        return digital_root(sum);
}

int main()
{
    std::cout << digital_root(849);
}
// Markus Cisneros 7/17/2022 Convert Roman Numerals to integers
/* Functionality: Input then convert a string of roman numerals to int through summation
 * Constraints: Sum must be within valid Roman Numeral Range, 1 - 3999
 * Pitfalls: Does not distinguish between fake Roman numerals, i.e. VVV = 15, but Roman Numeral is actually XV
*/
#include <iostream>
#include <string.h>
int romanToInt(std::string s);
enum numerals // ASCII Numeration; easier to read code
{
    I = 73,
    V = 86,
    X = 88,
    L = 76,
    C = 67,
    D = 68,
    M = 77
};
int main()
{
    std::string mainString;
    std::cin >> mainString;
    int result = romanToInt(mainString);
    if(!(result <= 0))
    {
        std::cout << result << std::endl;
    }
    return 0;
}
int romanToInt(std::string s)
{
    int sum = 0;
    if(s.length() < 1 || s.length() > 15)
    {
        return -1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
            case I:
                switch(s[i + 1])
                {
                    case V:
                        sum += 4;
                        ++i;
                        break;
                    case X:
                        sum += 9;
                        ++i;
                        break;
                    default:
                        sum++;
                        break;
                }
                break;
            case V:
                sum += 5;
                break;
            case X:
                switch(s[i + 1])
                {
                    case L:
                        sum += 40;
                        ++i;
                        break;
                    case C:
                        sum += 90;
                        ++i;
                        break;
                    default:
                        sum += 10;
                        break;
                }
                break;
            case L:
                sum += 50;
                break;
            case C:
                switch(s[i + 1])
                {
                    case D:
                        sum += 400;
                        ++i;
                        break;
                    case M:
                        sum += 900;
                        ++i;
                        break;
                    default:
                        sum += 100;
                        break;
                }
                break;
            case D:
                sum += 500;
                break;
            case M:
                sum += 1000;
                break;
            default:
                return -2;
        }
    }
    return ((sum < 1 || sum > 3999) ? -3 : sum);
}
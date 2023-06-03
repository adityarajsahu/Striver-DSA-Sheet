#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int sign = 1, num = 0, i = 0;
    while (s[i] == ' ')
        i++;

    if (s[i] == '-' || s[i] == '+')
    {
        sign = s[i] == '-' ? -1 : 1;
        i++;
    }

    while (s[i] >= '0' and s[i] <= '9')
    {
        if ((num > INT_MAX / 10) || (num == INT_MAX / 10 and s[i] > 7 + '0'))
        {
            if (sign == 1)
                return INT_MAX;

            else
                return INT_MIN;
        }

        num = num * 10 + (s[i] - '0');
        i++;
    }

    return sign * num;
}
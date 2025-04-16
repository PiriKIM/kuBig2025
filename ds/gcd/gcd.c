#include "gcd.h"

int gcd(int a, int b)
{
    int remain;
    while (remain = a % b) {
        a = b;
        b = remain;
    }
    return b;
}
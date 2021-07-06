#include "numbers.h"

int isNegativeNumber(int number)
{
    return number < 0;
}

int subtractMinOnMax(int minInterval, int maxInterval)
{
    return minInterval > maxInterval ? minInterval - maxInterval : maxInterval - minInterval;
}
#include "int2str.h"
#include <limits.h>
#include <stdlib.h>


char* int2str(int number) {
    if (number == 0) {
        return "0";
    }

    if (number == INT_MIN) {
        return "-2147483648";
    }
    
    char* str = calloc(13, sizeof(char));
    int num_len = 0;

    if (number < 0) {
        num_len++;
        str[0] = '-';
        number *= -1;
    }

    int number_cl = number;
    while (number_cl > 0) {
        number_cl /= 10;
        num_len++;
    }

    int digit = 0;
    int count = 0;
    char ch = 0;
    while (number > 0) {
        digit = number % 10;
        number = number / 10;
        ch = digit + '0';
        str[num_len - 1 - count] = ch;
        count++;
    }
    str[num_len] = '\0';

    return str;
}

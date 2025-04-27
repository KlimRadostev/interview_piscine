#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT(x) (1 << (x))

typedef enum {
    NONE = 0,
    SHIFT_LEFT,
    SHIFT_RIGHT,
} operator_t;

uint8_t get_op(char *c)
{
    if (c[0] == '<' && c[1] == '<')
        return SHIFT_LEFT;
    if (c[0] == '>' && c[1] == '>')
        return SHIFT_RIGHT;
    return NONE;
}

uint32_t bit_sum(uint32_t x, uint32_t y)
{
    // rules
    // 1 + 1 + true = 1 true
    // 1 + 1 + false = 0 true
    // 1 + 0 + true = 0 true
    // 0 + 0 + true = 1 false
    // 1 + 0 + false = 1 false
    // 0 + 0 + false = 0

    bool carry = false;
    uint32_t i = 1;
    uint32_t r = 0;

    do {
        if ((x & i) != 0 && (y & i) != 0 && carry == true) {
            r |= i;
            carry = true;
        } else if ((x & i) != 0 && (y & i) != 0 && carry == false) {
            carry = true;
        } else if (((x & i) != 0 || (y & i) != 0) && carry == true) {
            carry = true;
        } else if ((x & i) == 0 && (y & i) == 0 && carry == true) {
            r |= i;
            carry = false;
        } else if (((x & i) != 0 || (y & i) != 0) && carry == false) {
            r |= i;
            carry = false;
        } else if ((x & i) == 0 && (y & i) == 0 && carry == false) {
            carry = false;
        }
        i <<= 1;
    } while (i < 0x80000000);

    return r;
}

uint32_t to_int(char *bits, size_t sz)
{
    uint32_t ret = 0;
    uint32_t ret_i = BIT(sz - 2);
    size_t i = 1;
    bool neg = false;
    char onesim = '1';
    if (bits[0] == '1') {
        neg = true;
        onesim = '0';
    }
    while (i < sz) {
        if (bits[i] == onesim) { ret |= ret_i; }
        i = bit_sum(i, 1);
        ret_i >>= 1;
    }
    if (neg == true) {
        ret *= -1;
        ret--;
    }
    return ret;
}

char *left_shift(char *bin, int k)
{
    for (int i = 0; i < 6; i++) {
        if ((i + k) > 5)
            bin[i] = '0';
        else
            bin[i] = bin[i + k];
    }
    return bin;
}

char *right_shift(char *bin, int k)
{
    for (int i = 5; i >= 0; i--) {
        if ((i - k) < 0)
            bin[i] = '1';
        else
            bin[i] = bin[i - k];
    }
    return bin;
}

int main(int ac, char *argv[])
{
    /* import libft helper library */

    if (ac != 4) {
        return -1;
    }

    char *result = NULL;

    uint8_t op = get_op(argv[2]);
    switch (op) {
        case SHIFT_LEFT:
            result = left_shift(argv[1], atoi(argv[3]));
            break;
        case SHIFT_RIGHT:
            result = right_shift(argv[1], atoi(argv[3]));
            break;
        default:
            break;
    }

    printf("%s (%d)\n", result, to_int(result, 6));

    return 0;
}
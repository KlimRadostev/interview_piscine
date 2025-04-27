#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define BIT(x) (1 << (x))

typedef enum {
    NONE = 0,
    AND,
    OR,
} operator_t;

uint8_t get_op(char c)
{
    switch(c) {
        case ('&'):
            return AND;
        case ('|'):
            return OR;
    }
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
    uint32_t ret_i = BIT(sz - 1);
    size_t i = 0;
    while (i < sz) {
        if (bits[i] == '1') { ret |= ret_i; }
        i = bit_sum(i, 1);
        ret_i >>= 1;
    }
    return ret;
}

char *hndl_ngtn(char *a)
{
    // rules
    // ~0 = 1
    // ~1 = 0
    if (a[0] != '~') {
        return a;
    }
    for (int i = 4; i >= 1; i--) {
        if (a[i] == '0')
            a[i-1] = '1';
        else if (a[i] == '1')
            a[i-1] = '0';
    }
    a[4] = '\0';
    return a;
}

char *get_and(char *a, char *b)
{
    // rules
    // 0 & 0 = 0
    // 0 & 1 = 0
    // 1 & 1 = 1
    for (int i = 3; i >= 0; i--) {
        if (a[i] == '0' || b[i] == '0')
            a[i] = '0';
    }
    return a;
}

char *get_or(char *a, char *b)
{
    // rules
    // 0 | 0 = 0
    // 0 | 1 = 1
    // 1 | 1 = 1
    for (int i = 3; i >= 0; i--) {
        if (a[i] == '1' || b[i] == '1')
            a[i] = '1';
    }
    return a;
}

int main(int ac, char *argv[])
{
    /* import libft helper library */

    if (ac != 4) {
        return -1;
    }

    char *result = NULL;

    uint8_t op = get_op(argv[2][0]);
    switch (op) {
        case AND:
            result = get_and(hndl_ngtn(argv[1]), hndl_ngtn(argv[3]));
            break;
        case OR:
            result = get_or(hndl_ngtn(argv[1]), hndl_ngtn(argv[3]));
            break;
        default:
            break;
    }

    printf("%s (%d)\n", result, to_int(result, 4));

    return 0;
}
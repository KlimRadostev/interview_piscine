#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    NONE = 0,
    ADD,
} operator_t;

uint8_t get_op(char c)
{
    switch(c) {
        case ('+'):
            return ADD;
    }
    return NONE;
}

uint32_t bit_sum(uint32_t x, uint32_t y)
{
    /*
    00001111
    +
    00000001
    =
    00010000

    01010101 : 0x55
    +
    00111111 : 0x3F
    =
    10010100 : 0x94
    */
    // rules
    // 1 + 0 = 1
    // 1 + 1 = 0 + carry_over
    // 1 + 1 + carry_over = 1 + carry_over

    bool carry = false;
    for (size_t i = 0; i < 6; i ++) {
        int a, b, c;
        a = b = c = 0;

        if (carry == true)
            a = 1;
        if (a[i] == '1')
            b = 1;
        if (b[i] == '1')
            c = 1;
        int total = a + b + c;
        if (total == 3) {
            carry = true;
            a[i] = 1;
        } else if (total == 2)
    }

    uint32_t res1 = x | y;
    uint32_t res2 = x & y;
    uint32_t res = 
}

uint32_t bit_increment(uint32_t x)
{
    x + 1;

    00001000
    00001001
    ...
    00001111
    00010000
}

uint32_t to_int(char *bits, size_t sz)
{
    uint32_t ret = 0;
    size_t i = 0;
    while (i < sz) {
        ret <<= 1;
        if (bits[i] == '1') { ret |= 1; }
        i = bit_increment(i);
    }
    return ret;
}

char *get_sum(char *a, char *b)
{

}

int main(int ac, char *argv[])
{
    /* import libft helper library */

    if (ac != 4) {
        return -1;
    }

    uint8_t op = get_op(argv[2][0]);

    return 0;
}
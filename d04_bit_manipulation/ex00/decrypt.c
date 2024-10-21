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

uint32_t to_int(char *bits, size_t sz)
{
    uint32_t ret = 0;
    for (size_t i = 0; i < sz; i++) {
        ret <<= 1;
        if (bits[i] == '1') { ret |= 1; }
    }
    return ret;
}

char *get_sum(char *a, char *b);

int main(int ac, char *argv[])
{
    /* import libft helper library */

    if (ac != 4) {
        return -1;
    }

    uint8_t op = get_op(argv[2][0]);
    FT_STATUS = 

    return 0;
}
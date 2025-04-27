#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define BIT(x) (1U << (x))
#define UNSET(x, y) ((x) & ~(BIT(y)))
#define SET(x, y) ((x) | BIT(y))
#define TOGGLE(x, y) ((x) ^ BIT(y))

uint32_t update_place(uint32_t parking_row, int pos, int value)
{
    return (UNSET(parking_row, pos) | (value << pos));
}

int main(int ac, char *argv[])
{
    if (ac != 4) {
        return -1;
    }

    uint32_t new_prow = update_place(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

    printf("New parking row: %d\n", new_prow);

    return 0;
}
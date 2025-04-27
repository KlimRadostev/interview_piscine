#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define BIT(x) (1U << (x))
#define UNSET(x, y) ((x) & ~(BIT(y)))

uint32_t clear_place(uint32_t parking_row, int pos)
{
    return UNSET(parking_row, pos);
}

int main(int ac, char *argv[])
{
    if (ac != 3) {
        return -1;
    }

    uint32_t new_prow = clear_place(atoi(argv[1]), atoi(argv[2]));

    printf("New parking row: %d\n", new_prow);

    return 0;
}
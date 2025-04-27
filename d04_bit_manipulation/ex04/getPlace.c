#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
20 parking positions
1 = place taken
0 = place vacant

0 0 0 0 1 0 1 0 0 ...

*/

#define BIT(x) (1 << (x))

int get_place(uint32_t parking_row, int pos)
{
    return parking_row & BIT(pos);
}

int main(int ac, char *argv[])
{
    if (ac != 3) {
        return -1;
    }

    int occupied = get_place(atoi(argv[1]), atoi(argv[2]));

    printf("Parking place 0: %s\n", (occupied == 0) ? "vacant" : "occupied");

    return 0;
}
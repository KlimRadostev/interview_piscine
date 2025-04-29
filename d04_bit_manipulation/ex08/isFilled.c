#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/*
    AND (x & y)
    0 0 = 0
    0 1 = 0
    1 0 = 0
    1 1 = 1

    OR (x | y)
    0 0 = 0
    0 1 = 1
    1 0 = 1
    1 1 = 1

    XOR (x ^ y)
    0 0 = 0
    0 1 = 1
    1 0 = 1
    1 1 = 0

    NAND ~(x & y)
    0 0 = 1
    0 1 = 1
    1 0 = 1
    1 1 = 0

    NOR ~(x | y)
    0 0 = 1
    0 1 = 0
    1 0 = 0
    1 1 = 0

    XNOR ~(x ^ y)
    0 0 = 1
    0 1 = 0
    1 0 = 0
    1 1 = 1

    
*/


#define BIT(x) (1U << (x))
#define UNSET(x, y) ((x) & ~(BIT(y)))
#define SET(x, y) ((x) | BIT(y))
#define TOGGLE(x, y) ((x) ^ BIT(y))

#define BITSHIFT(val, x) (((val) & BIT(x)) >> (x))

int is_filled(uint32_t prow)
{
    // right shift all 1s until not one anymore
    // if value equal 0 return 1 else 0
    // if (parking_row >> (1s));
    // // rightcount 1s from right
    // int rcos = 1;
    // parking_row 
    // return (parking_row >> (rcos));

    // 10000000 - 1 = 01111111
    // 01111111 + 1 = 10000000
    // 01111111

    // 0111
    // 0111 & 0001 = 1 = a
    // 0111 & 0010 = 1 & a = 1(a)
    // 0111 & 0100 = 1 & a = 1(a)
    // 0111 & 1000 = 0 & a = 0(a)
    // 10111 & 10000 = 1 & a = 1(a) bad already 

    // 0111 & 0001 = 1 (1) ^ 0 = 1
    // 0111 & 0010 = 1 (1 & 1) ^ 0 = 1
    // 0111 & 0100 = 1 (1 & 1) ^ 0 = 1
    // 0111 & 1000 = 0 (1 & 0) ^ 1 = 1


    // 1 & chk = res // for us 1
    // catch = ~(chk & ~res);
    // res & chk = res // everything should be 0 from here on
    // catch = ~(chk & ~res);
    // res & chk = res
    // catch = ~(chk & ~res);

    // now we need to check that if the chk value is
    // chk = 1 when res = 1 good = 1
    // chk = 0 when res = 1 good = 1
    // chk = 0 when res = 0 good = 1
    // chk = 1 when res = 0 bad! = 0


    // (1 and 1) stays 1
    // (1 and next 1) stays 1
    // (1 and next 0) first zero found needs to stay zero (carry over)
    // (0 and next 0) good condition (carry over)
    // (0 and next 1) violation found! (carry over bad)

    // 0111

    uint32_t a = BITSHIFT(prow, 0);
    uint32_t catch = ~(BITSHIFT(prow, 0) & ~(a));
    // printf("a %x,  BITSHIFT(prow, 0) %x, catch %x\n", a,  BITSHIFT(prow, 0), catch);

    a = a & BITSHIFT(prow, 1);
    catch = catch & ~(BITSHIFT(prow, 1) & ~(a));
    // printf("a %x,  BITSHIFT(prow, 1) %x, catch %x\n", a,  BITSHIFT(prow, 1), catch);
    
    a = a & BITSHIFT(prow, 2);
    catch = catch & ~(BITSHIFT(prow, 2) & ~(a));
    // printf("a %x,  BITSHIFT(prow, 0) %x, catch %x\n", a,  BITSHIFT(prow, 2), catch);

    a = a & BITSHIFT(prow, 3);
    catch = catch & ~(BITSHIFT(prow, 3) & ~(a));
    // printf("a %x,  BITSHIFT(prow, 3) %x, catch %x\n", a,  BITSHIFT(prow, 3), catch);

    a = a & BITSHIFT(prow, 4);
    catch = catch & ~(BITSHIFT(prow, 4) & ~(a));

    a = a & BITSHIFT(prow, 5);
    catch = catch & ~(BITSHIFT(prow, 5) & ~(a));

    a = a & BITSHIFT(prow, 6);
    catch = catch & ~(BITSHIFT(prow, 6) & ~(a));

    a = a & BITSHIFT(prow, 7);
    catch = catch & ~(BITSHIFT(prow, 7) & ~(a));

    a = a & BITSHIFT(prow, 8);
    catch = catch & ~(BITSHIFT(prow, 8) & ~(a));

    a = a & BITSHIFT(prow, 9);
    catch = catch & ~(BITSHIFT(prow, 9) & ~(a));

    a = a & BITSHIFT(prow, 10);
    catch = catch & ~(BITSHIFT(prow, 10) & ~(a));

    a = a & BITSHIFT(prow, 11);
    catch = catch & ~(BITSHIFT(prow, 11) & ~(a));

    a = a & BITSHIFT(prow, 12);
    catch = catch & ~(BITSHIFT(prow, 12) & ~(a));

    a = a & BITSHIFT(prow, 13);
    catch = catch & ~(BITSHIFT(prow, 13) & ~(a));

    a = a & BITSHIFT(prow, 14);
    catch = catch & ~(BITSHIFT(prow, 14) & ~(a));

    a = a & BITSHIFT(prow, 15);
    catch = catch & ~(BITSHIFT(prow, 15) & ~(a));

    a = a & BITSHIFT(prow, 16);
    catch = catch & ~(BITSHIFT(prow, 16) & ~(a));

    a = a & BITSHIFT(prow, 17);
    catch = catch & ~(BITSHIFT(prow, 17) & ~(a));

    a = a & BITSHIFT(prow, 18);
    catch = catch & ~(BITSHIFT(prow, 18) & ~(a));

    a = a & BITSHIFT(prow, 19);
    catch = catch & ~(BITSHIFT(prow, 19) & ~(a));

    a = a & BITSHIFT(prow, 20);
    catch = catch & ~(BITSHIFT(prow, 20) & ~(a));

    a = a & BITSHIFT(prow, 21);
    catch = catch & ~(BITSHIFT(prow, 21) & ~(a));

    a = a & BITSHIFT(prow, 22);
    catch = catch & ~(BITSHIFT(prow, 22) & ~(a));

    a = a & BITSHIFT(prow, 23);
    catch = catch & ~(BITSHIFT(prow, 23) & ~(a));

    a = a & BITSHIFT(prow, 24);
    catch = catch & ~(BITSHIFT(prow, 24) & ~(a));

    a = a & BITSHIFT(prow, 25);
    catch = catch & ~(BITSHIFT(prow, 25) & ~(a));

    a = a & BITSHIFT(prow, 26);
    catch = catch & ~(BITSHIFT(prow, 26) & ~(a));

    a = a & BITSHIFT(prow, 27);
    catch = catch & ~(BITSHIFT(prow, 27) & ~(a));

    a = a & BITSHIFT(prow, 28);
    catch = catch & ~(BITSHIFT(prow, 28) & ~(a));

    a = a & BITSHIFT(prow, 29);
    catch = catch & ~(BITSHIFT(prow, 29) & ~(a));

    a = a & BITSHIFT(prow, 30);
    catch = catch & ~(BITSHIFT(prow, 30) & ~(a));

    a = a & BITSHIFT(prow, 31);
    catch = catch & ~(BITSHIFT(prow, 31) & ~(a));



    // ffffffff = 1 GOAL
    // ~ffffffff = 0 ^ BIT(0)


    // fffffffe = 0 GOAL

    // ~fffffffe = 1 ^ BIT(0)

    return ~catch ^ BIT(0);

    // uint32_t c = a 


    // 0001 ^ 0010 = 0011 >> 1 = 1
    // 0100 ^ 0001 = 0101 >> 2 = 

    // 0 & 0 & 0 & 1 & 1 & 1 & 1 & 1 & 1

    // 0101
    // 1010 & 0001 = 0
    // 1010 & 0010 = 1
    // 1010 & 0100 = 0 (| 1 = 1)
    // 1010 & 1000 = 1 (| 1 = 1)

    // return (
    //     (prow & BIT(0)) |
    //     (prow & BIT(1)) | 
    //     (prow & BIT(2)) |
    //     (prow & BIT(3))
    // );
}

int main(int ac, char *argv[])
{
    if (ac != 2) {
        return -1;
    }

    int is_full = is_filled(atoi(argv[1]));

    printf("Parking row %s is %sfilled from right to left\n", argv[1], (is_full == 1) ? "" : "NOT ");

    return 0;
}
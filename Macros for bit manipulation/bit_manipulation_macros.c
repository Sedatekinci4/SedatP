#include <stdio.h>
//Macros
//Macro to set nth-bit
#define SET_BIT(x, pos) (x |= (1U << pos))

//Macro to clear nth-bit
#define CLEAR_BIT(x, pos) (x &= (~(1U<< pos)))

//Macro to toggle nth-bit
#define TOGGLE_BIT(x, pos) x ^= (1U<< pos)

//Macro to check nth-bit
#define CHECK_BIT(x, pos) (x & (1UL << pos) )

//Macro to swap nibbles
#define SWAP_NIBBLES(x) ((x & 0x0F)<<4 | (x & 0xF0)>>4)

//Macro to Get bit from the given position
#define GET_BITS(x, pos) ((x & ( 1 << pos)) >> pos)

#define SWAP_BYTES(u32Value) ((u32Value & 0x000000FF) << 24)\
|((u32Value & 0x0000FF00) << 8) \
|((u32Value & 0x00FF0000) >> 8) \
|((u32Value & 0xFF000000) >> 24)

//macro to swap odd-even bits
#define SWAP_ODD_EVEN_BIT(x) ((x & 0xAAAAAAAA)>>1 | (x & 0x55555555)<<1);

//macro to swap two numbers
#define SWAP(x, y) (x ^= y ^= x ^= y)

//macro to get low and high bytes
#define LOWBYTE(v)   ((unsigned char) (x))
#define HIGHBYTE(v)  ((unsigned char) (((unsigned int) (x)) >> 8))

int main()
{
    // examples
    int number1 = 10, number2 = 20;
    TOGGLE_BIT(number1, 4);
    printf("number1 = %d\n", number1);

    SWAP(number1, number2);
    printf("Swapped\nnumber1 = %d\n", number1);
    printf("number2 = %d\n", number2);

    return 0;
}
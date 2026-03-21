#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

void print_bits(const void* nums, size_t size);

int main()
{
    int x = INT_MAX;
    unsigned long long y = ULLONG_MAX;
    long long z = LLONG_MIN;

    print_bits(&x, sizeof(x));
    print_bits(&y, sizeof(y));
    print_bits(&z, sizeof(z));

    return 0;
}

// this implementation is independed on the `endiness` of the system
void print_bits(const void* nums, size_t size)
{
    if (!nums || size < 0) return;

    uintmax_t mask = (uintmax_t)1 << (size * CHAR_BIT - 1);

    for (size_t x = 1; x < size * CHAR_BIT; x++)
    {
        if (*(uintmax_t*)nums & mask) printf("1");
        else printf("0");
        mask >>= 1;
    }

    printf("\n");
}

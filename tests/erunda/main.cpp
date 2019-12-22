#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdlib.h>

void *read_stack(uint8_t *out, unsigned amount, ...)
{
    va_list a;
    va_start(a, amount);
    uint8_t *start = (uint8_t *) &out;
    for (unsigned i=0; i<amount; ++i)
        out[i] = start[i];
    va_end(a);
    return start;
}

void dump_stack(unsigned amount)
{
    assert(amount > 0);
    uint8_t *buf = (uint8_t *) malloc(amount);
    assert(buf != NULL);
    void *start = read_stack(buf, amount, 239, 240, 241, 242, 243);
    printf("Dumping %u bytes from address %p:\n", amount, start);
    for (unsigned i=0; i<amount; i++)
    {
        if (i%16==0)
            printf("[%04X] %p: ", i, (uint8_t *)start+i);
        else if (i%4==0)
            printf(".");
        printf("%02X", buf[i]);
        if (i%16==15 || i+1==amount)
            printf("\n");
    }
    printf("Bye\n");
}

int main(int argc, char **argv)
{
    // assert(argc > 1);
    unsigned amount = 1000;//(unsigned) atol(argv[1]);
    printf("Hello world, main=%p\n", main);
    dump_stack(amount);
    return 0;
}

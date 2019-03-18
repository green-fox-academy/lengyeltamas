#include <stdio.h>

int main()
{
    int i = 4096;
    int j = i << 1;
    printf("%d %d \n\n",i, j);

    int k = i >> 1;
    printf("%d %d \n\n",i, k);

    for (int m = 0; m < 5; ++m) {
        int temp = i >> m*2;
        printf("%d\n", temp);
    }

    // bitwise OR
    int a = 6; // bin: 110
    int b = 2; // bin: 010
    int c = a | b; //result: 110 that is 6 in dec
    printf("\n%d\n", c);
    int d = a << 1 | b >> 1;
    printf("%d\n", d);

    return 0;
}
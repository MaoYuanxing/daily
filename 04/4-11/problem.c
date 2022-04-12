#include <stdio.h>

int apple(int n)
{
    int n8 = n / 8;
    while (n8)
    {
        int tmp = n - 8 * n8;
        if (tmp % 6 == 0)
        {

            return tmp / 6 + n8;
        }
        n8--;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    printf("eight : %d\n", apple(100));
    return 0;
}
#include <cs50.h>
#include <stdio.h>

int get_size();
void print_pyramid(int n);

int main(void)
{
    int n = get_size();
    print_pyramid(n);
}

int get_size()
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_pyramid(int n)
{
    int b = 1;
    for (int j = 0; j < n; j++)
    {
        for (int k = n; k > b; k--)
        {
            printf(" ");
        }
        for (int i = 0; i < b; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int i = 0; i < b; i++)
        {
            printf("#");
        }
        printf("\n");
        b++;
    }
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

void decimalToBinary(int num);

int main(void)
{
    int i = 0;
    string str = get_string("Message: ");
    while (str[i])
    {
        int num = (int) str[i];
        decimalToBinary(num);
        i++;
        printf("\n");
    }
    return 0;
}

void decimalToBinary(int num)
{
    // Stores binary representation of number.
    int binaryNum[8]; // Assuming 8-bit ASCII characters.
    int i = 0;

    // Fill the binaryNum array
    while (num > 0)
    {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    // Pad with zeros if the binary representation is less than 8 bits
    while (i < 8)
    {
        binaryNum[i++] = 0;
    }

    // Printing emojis directly based on the binary representation.
    for (int j = 7; j >= 0; j--)
    {
        if (binaryNum[j] == 0)
        {
            // Dark emoji
            printf("\U000026AB");
        }
        else if (binaryNum[j] == 1)
        {
            // Light emoji
            printf("\U0001F7E1");
        }
    }
}

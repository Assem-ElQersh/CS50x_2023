#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_numeric(string s);

int main(int argc, string argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key is a non-negative integer
    if (!is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get the key from the command-line argument
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt and print the ciphertext
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            printf("%c", (c - base + key) % 26 + base);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");

    return 0;
}

// Function to check if a string contains only numeric characters
bool is_numeric(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

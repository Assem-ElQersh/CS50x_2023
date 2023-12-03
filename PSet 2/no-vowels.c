// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            char lowercaseChar = tolower(argv[i][j]); // Handling upper cases

            switch (lowercaseChar)
            {
                case 'a':
                    argv[i][j] = '6';
                    break;
                case 'e':
                    argv[i][j] = '3';
                    break;
                case 'i':
                    argv[i][j] = '1';
                    break;
                case 'o':
                    argv[i][j] = '0';
                    break;
                case 'u':
                    argv[i][j] = 'u';
                    break;
                default:
                    break;
            }
        }
    }

    // Print the modified strings
    for (int i = 0; i < argc; i++)
    {
        printf("%s \n", argv[i]);
    }

    return 0;
}

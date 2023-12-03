// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}
bool valid(string password)
{
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            hasLower = true;
        }
        else if (isupper(password[i]))
        {
            hasUpper = true;
        }
        else if (isdigit(password[i]))
        {
            hasNumber = true;
        }
        else if (!isalnum(password[i]))
        {
            // Assuming symbols are characters that are neither alphabetic nor numeric
            hasSymbol = true;
        }
    }
    return hasLower && hasUpper && hasNumber && hasSymbol;
}

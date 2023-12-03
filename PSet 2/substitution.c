#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function prototypes
bool is_valid_key(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get the key from the command-line argument
    string key = argv[1];

    // Check if the key is valid
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // Encrypt and print ciphertext
    string ciphertext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Function to check if the key is valid
bool is_valid_key(string key)
{
    // Check if the key has the correct length
    if (strlen(key) != ALPHABET_SIZE)
    {
        return false;
    }

    // Check if all characters are alphabetic and unique
    bool seen[ALPHABET_SIZE] = {false};
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        char c = key[i];

        // Check if the character is alphabetic
        if (!isalpha(c))
        {
            return false;
        }

        // Convert to uppercase for case-insensitivity
        c = toupper(c);

        // Check if the character is unique
        if (seen[c - 'A'])
        {
            return false;
        }

        seen[c - 'A'] = true;
    }

    return true;
}

// Function to encrypt plaintext using the substitution cipher
string encrypt(string plaintext, string key)
{
    string ciphertext = plaintext;

    // Iterate over each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Check if the character is alphabetic
        if (isalpha(c))
        {
            // Determine the case of the character
            bool is_upper = isupper(c);

            // Convert to uppercase for case-insensitivity
            c = toupper(c);

            // Map the character using the key
            int index = c - 'A';
            char mapped_char = key[index];

            // Convert back to the original case
            mapped_char = is_upper ? toupper(mapped_char) : tolower(mapped_char);

            // Update the ciphertext
            ciphertext[i] = mapped_char;
        }
    }

    return ciphertext;
}

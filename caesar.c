#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check exactly two commandline arguments
    while (argc != 2)
    {
        printf("Only non-negative integer is allowed as a commandline argument\n");
        return 1;
    }

    // Check for non-integer input from the user as key
    for (int i = 0, s = strlen(argv[1]); i < s; ++i)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Only non-negative integer is allowed as a commandline argument\n");
            return 1;
        }
    }

    // convert the argument given from string to an integer
    int k = atoi(argv[1]);

    // get text to be encreypted from user
    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    // Convert plaintext to ciphertext usin the user's key
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c", (((p[i] - 65) + k) % 26) + 65);
        }
        else if (islower(p[i]))
        {
            printf("%c", (((p[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}
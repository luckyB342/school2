#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check exactly two
    while (argc != 2)
    {
        printf("Only non-negative integer is allowed as a commandline argument\n");
        return 1;
    }

    // convert the argument given...
    int k = atoi(argv[1]);

    // get and...
    string p = get_string("plaintext: ");

    //printf("ciphertext: ");

    // Convert plaintext to ciphertext...
    for (int i = 0, n = strlen(p); i <= n; i++)
    {
        if (isupper(p[i]))
        {
            printf("ciphertext: %c", (((p[i] - 65) + k) % 26) + 65);
        }
        else if (islower(p[i]))
        {
            printf("ciphertext: %c", (((p[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("ciphertext: %c", p[i]);
        }
    }
    printf("\n");
    return 0;

}
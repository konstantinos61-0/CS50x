#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototypes
string encrypt(string, string, string);

// encrypts a given plaintext with a substitution cipher
int main(int argc, string argv[])
{
    // if argc != 2
    if (argc != 2)
    {
        printf("Usage: ./readability key\n");
        return 1;
    }

    // if argc = 2
    // key doenst contain 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("key must have a length of 26 characters\n");
        return 1;
    }
    // key contains 26 characters
    int keylen = 26;

    // accesing "key" string
    for (int i = 0; i < keylen; i++)
    {
        // if key contains non alphabetical char
        if (isalpha(argv[1][i]) == false)
        {
            printf("key must contain only alphabetic characters\n");
            return 1;
        }
    }

    // now, i'm sure key contains only alphabetic characters

    // if  key contains any one character twice
    for (int i = 0; i < keylen; i++)
    {
        for (int j = 0; j < keylen && j != i; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("key must contain every alphabetic character once!\n");
                return 1;
            }
        }
    }
    // now i'm sure key is valid. promt user text
    string plain = get_string("plaintext: ");

    // uppercase and lowercase keys created
    string upperkey = malloc(keylen + 1), lowerkey = malloc(keylen + 1);
    for (int i = 0; i < keylen; i++)
    {
        upperkey[i] = toupper(argv[1][i]);
        lowerkey[i] = tolower(argv[1][i]);
    }

    // encrypt the plaintext
    string cipher = encrypt(plain, upperkey, lowerkey);

    //  print appropriate message
    printf("ciphertext: %s\n", cipher);
}

// implementation of encrypt
string encrypt(string plain, string upperkey, string lowerkey)
{
    int len = strlen(plain);
    string cipher = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        if (isupper(plain[i]))
        {
            cipher[i] = upperkey[plain[i] - 'A'];
        }
        else if (islower(plain[i]))
        {
            cipher[i] = lowerkey[plain[i] - 'a'];
        }
        else
        {
            cipher[i] = plain[i];
        }
    }
    return cipher;
}

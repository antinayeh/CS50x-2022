#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }

    string key = argv[1];
    int key_size = strlen(key);

    if (key_size == 0)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    else if (key_size != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int i = 0;
    while (i < key_size)
    {
        if (!isalpha(key[i]))
        {
            printf("Key can only contain alphabets.\n");
            return 1;
        }
        else
        {
            for (int x = 0; x < i; x ++)
            {
                if (key[x] == key[i] || key[x] == toupper(key[i]) || key[x] == tolower(key[i]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        key[i] = toupper (key[i]);
        i++;
    }

    string plain = get_string("plaintext: " );
    string cipher = plain;
    for(int j = 0; j < strlen(plain); j++)
    {
        char c = plain[j];
        if(isalpha(c)!= 0)
        {
            int ascii = toupper (c) - 65;
            if (isupper(c) != 0)
            {
                cipher[j] = key[ascii];
            }
            else
            {
                 cipher[j] = tolower(key[ascii]);
            }
        }
        else
        {
            cipher[j] = c;
        }
    }

    printf("ciphertext: %s\n", cipher);
}



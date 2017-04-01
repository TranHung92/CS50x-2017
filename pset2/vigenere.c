#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) 
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    for (int i=0; i<strlen(argv[1]); i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    string k = argv[1];
    int arr[strlen(k)];
    for(int i=0; i<strlen(k); i++)
    {
        if(islower(k[i]))
        {
            arr[i] = (int) k[i]-97;
        }
        else
        {
            arr[i] = (int) k[i]-65;
        }
    }
    
    printf("plaintext:  ");
    string p = get_string();
    printf("ciphertext: ");
    int j = 0;
    for(int i=0; i<strlen(p); i++)
    {
        if(isalpha(p[i]))
        {
            if(islower(p[i]))
            {
                printf("%c", (((p[i]-97)+arr[j])%26)+97);
            }
            else
            {
                printf("%c", (((p[i]-65)+arr[j])%26)+65);
            }
            j++;
        }
        else
        {
            printf("%c", p[i]);
        }
        if(j == strlen(k))
        {
            j=0;
        }
    }
    printf("\n");
    return 0;
}
    
    
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int k = atoi(argv[1]);
    
    printf("plaintext:  ");
    string p = get_string();
    if(p != NULL)
    {
        printf("ciphertext: ");
        for(int i = 0; i < strlen(p); i++)
        {
            if(isalpha(p[i]) )
            {
                if(islower(p[i]))
                {
                    printf("%c", (((p[i]-97)+k)%26)+97);
                }
                else
                {
                    printf("%c", (((p[i]-65)+k)%26)+65);
                }
            }
            else
            {
                printf("%c", p[i]);
            }
        }   
    }   
    printf("\n");
    return 0;
}
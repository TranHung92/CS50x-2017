#include <stdio.h>
#include <cs50.h>

void blocks(int b);
void spaces(int s);

int main(void)
{
    
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
        
    }
    while (height < 0 || height > 23);
    for(int i=0; i<height; i++)
    {
        spaces(height - (i+1));
        blocks(i+1);
        spaces(2);
        blocks(i+1);
        printf("\n");
    }
    
}

void blocks(int b)
{
    for(int i=0; i<b; i++)
    {
        printf("#");
    }
}

void spaces(int s)
{
    for(int i=0; i<s; i++)
    {
        printf(" ");
    }
}
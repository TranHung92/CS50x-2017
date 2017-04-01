#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();
    int bottles = 12 * minutes;
    printf("Bottles: %i\n", bottles);
}
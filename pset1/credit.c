#include <stdio.h>
#include <cs50.h>
#include <math.h>
 
// Count the number of digits in a credit card number
int cardNumberLength(long long cardNumber)
{
    int lenght = 0;
    while (cardNumber >= 1)
    {
        cardNumber = cardNumber / 10;
        lenght++;
    }
    return lenght;
}
 
 
/**
* Returns the digit at a specific place of a number
*/
int getDigit(long long cardNumber, int location)
{   
    // Casting to a double so decimal places can be kept. Dec stands for with decimal.
    double cardNumberDec = (double) cardNumber;
    
    // Keeps dividing by 10 untill targeted digit is right behind the decimal point
    for (int i = 0; i < location; i++)
    {
        // Only keeps one number behind the decimal point to prevent double from running out of precision
        cardNumberDec = ((long long) cardNumberDec) / 10.0;
    }
    
    // No Dec stands for no decimal. 
    double cardNumberNoDec = (long long) cardNumberDec;
    
    // Subtracting to isolate digit we want (Ex: 789.7 - 789 = 0.7)
    double difference = cardNumberDec - cardNumberNoDec;
    
    // Rounding since computers don't multiply by 10 accurately (especially if there are many digits)
    int digit = round((difference * 10));
    
    return digit;
}
 
/**
* Checks validity of credit card through that Hans Peter Luhn's algorithm
*/
bool checkLuhn(long long cardNumber, int digits)
{
    // Calculating step 1 of Luhn's Algorithm
    int sum1 = 0;
    for (int i = 2; i <= digits; i += 2)
    {
        int digit = getDigit(cardNumber, i);
        
        // For a two digit number, we want make sure to add the sum of the digits
        if (2 * digit < 10) 
        {
            sum1 = sum1 + digit * 2;
        }
        else
        {
            sum1 = sum1 + 1 + (2 * digit - 10);
        }
    }
   
    // Calculating step 2 of Luhn's Algorithm   
    int sum2 = 0;
    for (int i = 1; i <= digits; i += 2)
    {
        int digit = getDigit(cardNumber, i);
        sum2 = sum2 + digit;
    }
    
    // Verifying that the last digit is 0 using modulo
    return ((sum1 + sum2) % 10) == 0;
}
 
int main(void)
{
    printf("Number Please: ");
    long long cardNumber = GetLongLong();
    
    // Number of digits in credit card number
    int digits = cardNumberLength(cardNumber); 
    
    // If the card has passed Luhn's algorithm
    bool pass = checkLuhn(cardNumber, digits);
    
    // The first two numbers of the credit card (which are used to determine the card's company)
    int companyIdentifier;
    int companyIdentifier2;
    
    // Checking if num of digits > 12 to protect agianst 1 digit long cardNumber
    if (digits > 12 && pass)
    {
        companyIdentifier = getDigit(cardNumber, digits);
        companyIdentifier2 = getDigit(cardNumber, digits - 1);
    }
    else
    {
        printf("INVALID\n");
        // We don't want to print INVALID twice (it'll be done in the next if statement)
        return 0;
    }
    
    // Checking if the card fits any of the companies's specifications
    if (digits == 15 && companyIdentifier == 3 && (companyIdentifier2 == 4 || companyIdentifier2 == 7))
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && companyIdentifier == 5 && (companyIdentifier2 >= 1 && companyIdentifier2 <= 5))
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && companyIdentifier == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;   
}
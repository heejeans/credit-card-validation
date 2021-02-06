#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long n;
    n = get_long("Card number:");
    long number = n; //to get digit count
    long numba = n; //to get first two digits of card number to check for company
    int digits = 0;
    while (number > 0)
        //long is integer so dividing by 10 each time, until the last digit, will give the number of digits there are in the card number
    {
        number = number / 10;
        digits ++;
    }
    if (digits != 15 && digits != 13 && digits != 16) //number invalid if the digit count doesn't match with any of the companies
    {
        printf("INVALID\n");
        exit(0); //stops the program, otherwise will do the next steps
    }
    number = n; //reset number to the card number
    int sum = 0;
    for (int i = 1; i <= digits; i++) //had to set i to 1 because we have to multiply every other digit starting from the second digit
    {
        int digit = number % 10; //gives the digit at the end of number
        if (i % 2 == 0) //ties in with line 25; formula used to multiply every other digit is i % 2 starting from second digit
        {
            digit *= 2;
        }
        if (digit > 9) //only applies to digits that got multiplied by 2; if the digit becomes double, have to add each digit in the product
        {
            sum += digit % 10; //adds the second digit to sum
            sum += digit / 10; //adds the first digit to the sum
        }
        else if (digit <= 9)
        {
            sum += digit; //all other digits just gets added to sum, had to do else if
        }
        number /= 10; //reduces card number by a digit every time
    }
    if (sum % 10 == 0) //if the sum of all the digits is number ending in 0
    {
        while (numba >= 100) //reduce the digits in the card number until remaining number is two digits
        {
            numba /= 10;
        }
        if (numba > 50 && numba < 56 && digits == 16) //checking which company
        {
            printf("MASTERCARD\n");
        }
        else if ((numba == 34 || numba == 37) && digits == 15)
        {
            printf("AMEX\n");
        }
        else if (numba / 10 == 4 && (digits == 13 || digits == 16))
        {
            printf("VISA\n");
        }
        else if (numba / 10 == 6 && digits == 16)
        {
            printf("DISCOVER\n");
        }
        else
        {
            printf("INVALID\n"); //if requirements aren't matched with any company, invalid number
        }
    }
    else //if the sum of all the digits does not end with digit 0, invalid number
    {
        printf("INVALID\n");
    }
}
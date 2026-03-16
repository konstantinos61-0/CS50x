#include <cs50.h>
#include <stdio.h>

// returns checksum for a credit card number
int get_checksum(long);
// returns the number of digits of an integer
int get_digits(long);
// returns the first digit of an integer(on the left)
int get_initial_1(long);
// returns the first 2 digits of an integer(on the left)
int get_initial_2(long);
// checks credit card numbers for validity and type (VISA, AMEX, ...)
int main(void)
{
    long number = get_long("Number: ");
    int checksum = get_checksum(number);
    int digits = get_digits(number);
    int initial_1 = get_initial_1(number);
    int initial_2 = get_initial_2(number);
    // if number is valid
    if (checksum % 10 == 0 && (digits == 13 || digits == 15 || digits == 16))
    {
        if (digits == 15)
        {
            if (initial_2 == 34 || initial_2 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digits == 16)
        {
            if (initial_2 == 51 || initial_2 == 52 || initial_2 == 53 || initial_2 == 54 ||
                initial_2 == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (initial_1 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (digits == 13)
        {
            if (initial_1 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    // if number is invalid
    else
    {
        printf("INVALID\n");
    }
}
// implementation of checksum
int get_checksum(long number)
{
    int sum = 0;
    long divided = number;
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 0)
        {
            sum += (divided % 10);
        }
        else
        {
            // accounting for the fact that i add the digits of the product by 2
            long digit = (divided % 10) * 2;
            sum += (digit % 10) + (digit / 10);
        }
        divided = divided / 10;
    }
    return sum;
}
// implementation of get_digits
int get_digits(long number)
{
    int digits = 0;
    while (number != 0)
    {
        number = number / 10;
        digits += 1;
    }
    return digits;
}
// implementation of get_initial_1
int get_initial_1(long number)
{

    while (get_digits(number) > 1)
    {
        number = number / 10;
    }
    return number;
}
// implementation of get_initial_2
int get_initial_2(long number)
{

    while (get_digits(number) > 2)
    {
        number = number / 10;
    }
    return number;
}

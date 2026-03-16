#include <cs50.h>
#include <stdio.h>

void print_row(int);
void print_inverse_row(int, int);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // promprts user for a height between 1 and 8, inclusive
    for (int j = 1; j <= height; j++) // builds the pyramids
    {
        print_inverse_row(height - j, j);
        printf("  ");
        print_row(j);
        printf("\n");
    }
}

void print_row(int a) // prints a row for a right alligned pyramid
{
    for (int i = 0; i < a; i++)
    {
        printf("#");
    }
}

void print_inverse_row(int spaces, int length) // prints a row for a left alligned pyramid
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    print_row(length);
}

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int compute_grade(string);

// calculates approximate grade level for a given text
int main(void)
{
    // get text from user
    string text = get_string("Text: ");

    // compute grade level
    int grade_level = compute_grade(text);

    // print the appropriate message
    if (grade_level < 16 && grade_level > 1)
    {
        printf("Grade %i\n", grade_level);
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// implement compute_grade
int compute_grade(string text)
{
    // calculating the number of letters in text
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // calculating number of spaces
    int spaces = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            spaces++;
        }
    }

    // number of words
    int words = spaces + 1;

    // number of sentences
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    float L = 100 * ((float) letters / (float) words);
    float S = 100 * ((float) sentences / (float) words);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}

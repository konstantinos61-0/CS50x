#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// computes the score of any word in scrabble
int compute_score(string);
// a quick scrabble game
int main(void)
{
    // prompt users for input
    string player[2];
    player[0] = get_string("Player 1: ");
    player[1] = get_string("Player 2: ");

    // Compute the score of each player
    int score[2];
    for (int i = 0; i < 2; i++)
    {
        score[i] = compute_score(player[i]);
    }

    // compare scores and print who wins
    if (score[0] > score[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (score[0] < score[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

// implement compute_score
int compute_score(string word)
{
    int score = 0;
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            // adding the correct point for every uppercase letter
            score += points[word[i] - 'A'];
        }
        if (islower(word[i]))
        {
            // adding the correct point for every lowercase letter
            score += points[word[i] - 'a'];
        }
    }
    return score;
}

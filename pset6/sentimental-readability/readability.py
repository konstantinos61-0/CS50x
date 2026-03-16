from cs50 import get_string
import re

# function to count words in a string


def words(string):
    to_words = string.split()
    return len(to_words)


# function to count letters in a string


def letters(string):
    to_letters = [char for char in string if char.isalpha()]
    return len(to_letters)


# function to count sentences in a string


def sentences(string):
    to_sentences = [s for s in re.split(r'[.!?]', string) if s.strip(' "')]
    return len(to_sentences)


# main


def main():

    # get text from user
    text = get_string("Text: ")

    # Calculate letters, words and sentences
    le = letters(text)
    wo = words(text)
    se = sentences(text)

    # Calculate averages
    L = 100 * (le / wo)
    S = 100 * (se / wo)

    # Calculate Coleman-Liau index
    coli_index = round(0.0588 * L - 0.296 * S - 15.8)

    # Print Resulting Grade
    if coli_index >= 1 and coli_index < 16:
        print(f"Grade {coli_index}")
    elif coli_index >= 16:
        print(f"Grade 16+")
    elif coli_index < 1:
        print("Before Grade 1")


# run main program
if __name__ == "__main__":
    main()

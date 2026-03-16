import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable

    # database list of dictionaries for each person's dna
    people = []

    # Open database, fill people with database and STRs with all str's
    with open(sys.argv[1], "r") as file:
        csvreader = csv.DictReader(file)
        STRs = []
        for key in csvreader.fieldnames:
            if key == "name":
                continue
            STRs.append(key)
        for row in csvreader:
            people.append(row)

    # TODO: Read DNA sequence file into sequence variable

    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence

    # Fill longest_repeat for each subsequence
    longest_repeat = {}
    for str in STRs:
        longest_repeat[str] = longest_match(sequence, str)

    # TODO: Check database for matching profiles

    for person in people:
        check = 0
        for key in person:
            if key == "name":
                continue
            if int(person[key]) == longest_repeat[key]:
                check += 1
        if check == len(STRs):
            print(f"{person["name"]}")
            break
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        if sequence[i:i + subsequence_length] == subsequence:
            # Initialize count of consecutive runs
            count = 1
            # If a match, move substring to next potential match in sequence
            # Continue moving substring and checking for matches until out of consecutive matches
            while True:
                # Adjust substring start and end
                start = i + count * subsequence_length
                end = start + subsequence_length

                # If there is a match in the substring
                if sequence[start:end] == subsequence:
                    count += 1

                # If there is no match in the substring
                else:
                    break

            # Update most consecutive matches found
            longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

## Week 5 — Data Structures
This week covers the following topics: abstract data structures as forms of organization of data in memory, stacks, queues, linked lists, trees, hashing, hash tables and tries.
### Inheritance
A C program that simulates the inheritance of blood types for each member of a family. The program creates a family of a specified generation size (in the code this number is set to 3 but can be changed) and assigns blood type alleles to each family member. The oldest generation will have alleles assigned randomly to them. It then creates the family in memory, simulates the inheritance and prints the results.
**Usage**: ./inheritance  
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/5/inheritance.zip (accessed 16/3/2026). I read and understood it and then moved on to complete the following functions: create_family and free_family.

### Speller
A C program that spell-checks a text file using a dictionary of words implemented as a hash table. The program loads the dictionary from disk into memory and then performs the spell-checking. Finally, the program reports each misspelling in that file along with some statistical data about the execution. Running `make` or `make speller` will create the executable named `speller`.
**Usage**: `./speller [dictionary] text` where dictionary is assumed to be a file containing a list of lowercase words, one per line, and text is the file to be spell-checked. If dictionary is omitted, speller will use dictionaries/large by default. 
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/5/speller.zip (accessed 16/3/2026). The distribution code includes the following  files:
- `dictionary.h`: Contains all the shared definitions/declarations and function prototypes for the source files of the program
- `dictionary.c`: Contains an early dictionary implementation with just enough code to compile. It includes the functions load, check, size, unload and hash.
- `speller.c`: Contains the main function that performs the spell-checking after loading the dictionary onto memory.
- `texts/`: Contains text files that are used for testing the program.
- `Makefile`: Configuration file for the `make` command.
- `dictionaries/`: Contains the dictionary text files to be used in the dictionary command-line arguement. Each dictionary is alphabetically sorted from top to bottom with one word per line, each of which ends with \n.
- `keys/`: Contains the answer keys. They are text files with the correct output for each file inside `text/`. Useful for checking the correctness of my solution, for example by redirecting output into a student.txt file and running the `diff` command between that and the key.

I read and understood the distribution code and then moved on to implement the following functions in dictionary.c: load, check, size, unload and hash. 

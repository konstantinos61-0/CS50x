## Week 6 — Python
An introduction/overview to Python. Core topics covered are: variables and variable types, control flow statements in Python (Loops and conditionals), function definitions and function parameters, Object Oriented Programming, Libraries, Modules, Packages, Exceptions and Command Line Arguements. As we learn this new language, it is obvious how much easier it now is to teach ourselves a new language that includes all those same fundamentals of programming that we learned in C. 
### Sentimental-X
In the sentimental problems, I re-implement some problems from the earlier sets, only this time they are written as python scripts. Specifically, problems hello, mario and credit from set 1 and readability from set 2 are included.  
**Usage**: `python X.py` where X can be one of: `hello`, `mario`, `credit`, `readability`. 

### dna
A python script that identifies to whom a sequence of DNA belongs.  The program takes a sequence of DNA and a CSV file containing DNA data (STR counts) for a list of individuals and then output to whom the DNA (most likely) belongs to. 
**Usage**: `python dna.py database sequence` where database specifies the CSV database and sequence specifies which DNA sequence to identify.  
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/6/dna.zip (accessed 16/3/2026). This includes the following:
- `sequences/`: This directory contains text files, each of which is a DNA sequence from an unidentified individual.
- `databases/`: This directory containts the CSV file databases including DNA data for a list of individuals.
- `dna.py`: Defines a helper function `longest_match`

I read and understood the above and then moved on to implement the entirety of the main function of this script. 

## Week 3 — Algorithms
This week covers the following topics: design and efficacy (Big O Notation) of algorithms through pseudocode and code, search algorithms (binary, linear), sort algorithms (selection, bubble, merge) and recursion.
### Sort
In this problem, I analyzed three (compiled) sorting C programs, each implementing a different sorting algorithm for a sequence of numbers. I had to find out which sorting algorithm each program uses. My answers are recorded inside `PSET3/sort/answers.txt` along with an explanation for each program.  
**Distribution Code**: Availble at:  https://cdn.cs50.net/2026/x/psets/3/sort.zip (accessed 16/3/2026). It includes the 3 compiled programs sort1, sort2, sort3 as well as several .txt files used as input and the answers.txt file to fill in my answers. The input files contain `n` lines of integer values, either reversed, shuffled, or sorted. 
### Plurality
A C program that runs a plurality election using the candidates provided at execution time. It asks for the number of voters as input and then prompts each voter to input their vote. After that, the program prints the winner (or winners).  
**Usage**: `./plurality [candidate...]`  
**Distribution code**: Available at: https://cdn.cs50.net/2026/x/psets/3/plurality.zip (accessed 16/3/2026).  I read and understood it and then moved on to implement the following functions: vote, print_winner
### Runoff
A C program than simulates a runoff election using the candidates provided at execution time. It asks for the number of voters as input and then prompts each voter to input their vote. After that, the program prints the winner (or winners).  
**Usage**: `./runoff [candidate...]`  
**Distribution code**: Available at: https://cdn.cs50.net/2026/x/psets/3/runoff.zip (accessed 16/3/2026). I read and understood it and then moved on to implement the following functions: vote, tabulate, print_winner, find_min, is_tie, eliminate.

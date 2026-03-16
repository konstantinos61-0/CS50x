# CS50x
This repository contains all of my solutions for the 9 Problem Sets of HarvardX's CS50x: Introduction to Computer Science.  

## Week 1 — C
An introduction to the C programming language and the Linux CLI. The first two problems (mario and me) are very simple introductory material.
### Credit
A program in C that checks the validity of a given credit card number, using the Luhn's Algorithm to calculate its "checksum". It takes as input a credit card number and outputs whether its a valid American Express, MasterCard or Visa credit card number. 

## Week 2 — Arrays
This week covers the following topics: debugging, compiling, Command Line Arguements, Arrays and strings.
### Scrabble
A program in C that determines the winner of a short Scrabble-like game. The program prompts the user for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. Then, depending on which player scores the most points, the program prints “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
### Readability
A C program that calculates the approximate grade level needed to comprehend some input text. It prints as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. It outputs "Before Grade 1" or "Grade 16+" when X < 1 and X >= 16 accordingly. 
### Substitution
A C program that enables the user to encrypt messages using a substitution cipher. The key should be provided at runtime as a command-line argument. The user provides a plaintext as input and the program outputs the encrypted ciphertext.  
**Usage**: ./substitution key

## Week 3 — Algorithms
This week covers the following topics: design and efficacy (Big O Notation) of algorithms through pseudocode and code, search algorithms (binary, linear), sort algorithms (selection, bubble, merge) and recursion.
### Sort
In this problem, I analyzed three (compiled) sorting C programs, each implementing a different sorting algorithm for a sequence of numbers. I had to find out which sorting algorithm each program uses. My answers are recorded inside `PSET3/sort/answers.txt` along with an explanation for each program.
**Distribution Code**: Availble at:  https://cdn.cs50.net/2026/x/psets/3/sort.zip (accessed 16/3/2026). It includes the 3 compiled programs sort1, sort2, sort3 as well as several .txt files used as input and the answers.txt file to fill in my answers. The input files contain `n` lines of integer values, either reversed, shuffled, or sorted. 
### Plurality
A C program that runs a plurality election using the candidates provided at execution time. It asks for the number of voters as input and then prompts each voter to input their vote. After that, the program prints the winner (or winners). 
**Usage**: ./plurality [candidate...]  
**Distribution code**: Available at: https://cdn.cs50.net/2026/x/psets/3/plurality.zip (accessed 16/3/2026).  I read and understood it and then moved on to implement the following functions: vote, print_winner
### Runoff
A C program than simulates a runoff election using the candidates provided at execution time. It asks for the number of voters as input and then prompts each voter to input their vote. After that, the program prints the winner (or winners).  
**Usage**: ./runoff [candidate...]  
**Distribution code**: Available at: https://cdn.cs50.net/2026/x/psets/3/runoff.zip (accessed 16/3/2026). I read and understood it and then moved on to implement the following functions: vote, tabulate, print_winner, find_min, is_tie, eliminate.
## Week 4 — Memory 
## Week 5 — Data Structures
## Week 6 — Python
## Week 7 — SQL
## Week 8 — HTML, CSS, JavaScript
## Week 9 — Flask

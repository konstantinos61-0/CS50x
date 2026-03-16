## Week 4 — Memory
This week covers the following core topics: binary data representation, computer memory, pointers, strings as char pointers, pointer arithmetic, malloc, valgrind, overflow and FILE I/O.
### Volume
A C program that modifies the volume of an input WAV audio file by a given factor and writes it to an output WAV file.  
**Usage**: ./volume input.wav output.wav factor  
**Distribution Code**: Availble at https://cdn.cs50.net/2026/x/psets/4/volume.zip (accessed 16/3/2026). I read and understood it and then moved on to write code that handles the following functionality:
- Copy WAV header from input file to output file.
- Write updated data to output file.

### Filter
A C program to apply filters to BMP audio files. The flags -b, -e, -g, and -r specify the filters blur, edge detection, grayscale, and reflection respectively.  
**Usage**: ./filter [flag] infile outfile  
**Distribution Code**: Availble at:  https://cdn.cs50.net/2026/x/psets/4/filter-more.zip (accessed 16/3/2026). I read and understood it and then moved on to modify the helpers.c file. I added the functions that enable the user to apply the filters to their image: 
- grayscale
- reflect
- blur
- edges

### PROBLEM TITLE
In this problem, TODO.  
**Distribution Code**: Availble at:  (accessed ). I read and understood it and then moved on to implement the following: TODO 

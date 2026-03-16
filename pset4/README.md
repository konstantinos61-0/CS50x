## Week 4 — Memory
This week covers the following core topics: binary data representation, computer memory, pointers, strings as char pointers, pointer arithmetic, malloc, valgrind, overflow and FILE I/O.
### Volume
A C program that modifies the volume of an input WAV audio file by a given factor and writes it to an output WAV file. The executable is built by executing the `make` or `make filter` to produce an executable named `filter`. 
**Usage**: `./volume input.wav output.wav factor`  
**Distribution Code**: Availble at https://cdn.cs50.net/2026/x/psets/4/volume.zip (accessed 16/3/2026). I read and understood it and then moved on to write code that handles the following functionality:
- Copy WAV header from input file to output file.
- Write updated data to output file.

### Filter
A C program to apply filters to BMP audio files. The flags -b, -e, -g, and -r specify the filters blur, edge detection, grayscale, and reflection respectively.  
**Usage**: `./filter [flag] infile outfile`  
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/4/filter-more.zip (accessed 16/3/2026). I read and understood it and then moved on to modify the helpers.c file. I added the functions that enable the user to apply the filters to their image: 
- grayscale
- reflect
- blur
- edges

### Recover
A C program that recovers JPEGs from a memory card (forensic image). Specifically, the program takes one command-line arguement, the name of the input file containing the raw memory card data.  
**Usage**: `./recover card`  
**Distribution Code**: Availble at: https://cdn.cs50.net/2026/x/psets/4/recover.zip (accessed 16/3/2026). This time the distrubution code doesn't include any actual code, only the RAW data file. I implemented the entirety of the source code inside recover.c.

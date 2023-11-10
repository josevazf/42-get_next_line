# 42 Common Core / get_next_line
This project is about coding a function that reads and returns a line from one (/mandatory) or multiple (/bonus) file descriptors.
###
Repeated calls to the function allow to read the text file pointed to by the file descriptor, one line at a time.
The returned line includes the terminating character `\n` except if the end of the file was reached and does not end with it. 
###
External functions allowed: read(), malloc() and free().

## Norminette
This project was written in accordance with the Norm, which is the coding standard of the 42 school.

The Norm includes:
- Forbidden: for, do...while, switch, case, goto, ternary operators and variable-length arrays 
- Maximum of 25 lines per function
- Maximum line length: 80 columns
- Maximum 4 parameters per function 
- Variable assignments and declarations must be on separate lines
- etc...

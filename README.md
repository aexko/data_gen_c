# Hello, correctors!

## How to run the code
1. compile: gcc -o run tablegen.c generate.c io.c sort.c  
2. run: ./run

## Presence of print

I am aware that I left a lot of printf, but it is intentional. I could have
commented them, but I thought it would be useful for you guys!

## Poor memory management

I know, the memory management is a little bad?

## Maximum of rows possible

The maximum of rows I could test was 130k, I think it would
be possible if you had specific flags that would unlock the limit by default
on the compiler.

## No header in the csv file

Yeah, I have not found an efficient way. I know also that I have a coma extra at
the end of the line, but I did not have the time to fix it.

## Code not clean

I know that my code is ugly (generate.c), but it works, and I did not have the 
time to
refactor.

## qsort is not working
I thought it would work because when I printed it in the console it worked? 
But not in the csv file and I did not have the time to fix it. 

Thank you,  
Alex Kao (40286533)
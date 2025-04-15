/***************************************************************************
 * Mad Mad Programmer's Escape Room, Version 2
 * Copyright 2014, Mad and Mad Incorporated. All rights reserved.
 *
 * LICENSE:
 *
 * Mad Mad Incorporated hereby grants you (the VICTIM) explicit 
 * permission to use this escape room (the ROOM).  
 * The VICTIM may not distribute this escape room source code to
 * any enemies of Mad Mad Incorporated.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and solve the ROOM.  The
 * escape room manager will not apologize for their poor sense of
 * humor.  This license is null and void where the ROOM is prohibited
 * by law.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "puzzles.h"

/* 
 * Note to self: Remember to erase this file so my victims will have no
 * idea what is going on, and so they will not be able to escape any of our
 * spectaculary fiendish rooms. -- Mad Mad Programmer
 */

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* Note to self: remember to port this room to Windows and put a 
     * fantastic GUI on it. */

    /* When run with no arguments, the room reads its input lines 
     * from standard input. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* When run with one argument <file>, the room reads from <file> 
     * until EOF, and then switches to standard input. Thus, as you 
     * solve each puzzle, you can add its solution string to <file> and
     * avoid having to retype it. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* You can't call the room with more than 1 command line argument. */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* Do all sorts of secret stuff that makes the room harder to solve. */
    initialize_room();

    printf("Welcome to the CS 2130 Escape Room. You have 6 puzzles\n");
    printf("to solve to escape the room. Thankfully, there is no\n");
    printf("time limit! Have a nice day!\n");

    /* Hmm...  Six puzzles must be more secure than one puzzle! */
    input = read_line();             /* Get input                   */
    puzzle_1(input);                 /* Run the puzzle               */
    puzzle_solved();                 /* Drat!  They figured it out!
				      * Let me know how they did it. */
    printf("Puzzle 1 solved. One down, so many to go!\n");

    /* The second puzzle is harder.  No one will ever figure out
     * how to solve this... */
    input = read_line();
    puzzle_2(input);
    puzzle_solved();
    printf("Puzzle 2 solved. We're getting closer!\n");

    /* I guess this is too easy so far.  Some more complex code will
     * confuse people. */
    input = read_line();
    puzzle_3(input);
    puzzle_solved();
    printf("Halfway! Just 3 more puzzles... maybe?\n");

    /* Oh yeah?  Well, how good is your math?  Try on this saucy problem! */
    input = read_line();
    puzzle_4(input);
    puzzle_solved();
    printf("You solved puzzle 4?! On to the next one...\n");
    
    /* Round and 'round in memory we go, where we stop, who knows! */
    input = read_line();
    puzzle_5(input);
    puzzle_solved();
    printf("Nice work on puzzle 5! One more to go... or is it?\n");

    /* This puzzle will never be used, since no one will get past the
     * earlier ones.  But just in case, make this one extra hard. */
    input = read_line();
    puzzle_6(input);
    puzzle_solved();

    /* Wow, they got it!  But isn't something... missing?  Perhaps
     * something they overlooked?  Mua ha ha ha ha! */
    
    return 0;
}

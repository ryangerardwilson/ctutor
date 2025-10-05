/*=============================================================================
                    = W e l c o m e t o t h e C T U T O R =
===============================================================================

This is a no-bullshit C tutor ripped off from that VimTutor insanity, but for C
newbies who think 'printf("hello");' is some quantum entanglement bullshit.
Cooked up because stock tutorials make me want to hurl my keyboard at the wall
with their pussyfooting crap. We're sticking to K&R
    
Chapter 1: the absolute basics you'll actually use without your code
segfaulting into the abyss. Variables, types, printf/scanf, loops,
conditionals, arrays, functions—nothing fancy, just enough to not be a complete
scripting zombie in C. Edit this file in vim (duh), uncomment and fill in the
blanks as told, save, then from terminal: gcc this_file.c -o ctutor && ./ctutor
to see if you're not a total moron. It'll compile and run only the uncommented
parts, spitting output or errors (errors mean you fucked up—fix it, don't
whine).
    
Each run starts fresh if you copy from original, but hack around or die bored.
Takes 30-45 mins if you're not drooling on your keyboard. Make a copy to trash;
this one's your boot camp. Type the code, compile, feel the pain—or just read
like a wimp and wonder why your programs core dump.

Hit vim, scroll to Lesson 1.1, uncomment that shit, edit, save, compile from
terminal. Let's make you not a C poser.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    VIM BASIC REVISION: SELECTING TEXT TO WRITE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        ** To save part of the file, type v motion :w FILENAME **

  1. Move the cursor to this line.

  2. Press v and move the cursor to the fifth item below. Notice that the
     text is highlighted.

  3. Press the : character. At the bottom of the screen :'<,'> will appear.

  4. Type w TEST , where TEST is a filename that does not exist yet. Verify
     that you see :'<,'>w TEST before you press <ENTER>.

  5. Vim will write the selected lines to the file TEST. Use :!ls to see it.
     Do not remove it yet! We will use it in the next lesson.

    NOTE: Pressing v starts Visual selection. You can move the cursor around
    to make the selection bigger or smaller. Then you can use an operator
    to do something with the text. For example, d deletes the text.
    QUICK TIP FOR THIS TUTOR: After uncommenting and editing a lesson's code,
    select just that uncommented block (v, move to cover it), then :w! run.c
    to dump it to run.c. Then :!gcc run.c -o run && ./run to execute it right
    in Vim. See your output or errors without leaving the editor. Efficient,
    no? Do this per lesson—keeps shit isolated, no global link-time fuckups.
*/
//
// =============================================================================
// PART I: CONVENTIONAL CORE OF C
// ============================================================================= 
// Lesson 1.1: VARIABLES, ASSIGNMENT AND FORMATTING
/*
// man 7 man-pages --> spells out what every section in the man pages is for
#include "stdio.h"  // man 3 stdio

int main() {
    char name[10] = "Linus";  // man 3 strlen
    int age = 55;
    float height = 5.11f;
    double pi = 3.14159;
    long net_worth = 1000000000000L;

    // man 3 printf
    printf("Name: %s\n", name);         // %s: null or segfault.
    printf("Age: %d\n", age);           // %d decimal.
    printf("Width: %3d\n", age);        // Pads spaces.
    printf("Height: %f\n", height);     // Default 6 dec—ugly.
    printf("Prec: %.2f\n", height);     // Post-decimal.
    printf("Full: %6.2f\n", height);    // Width+prec.
    printf("Pi: %lf\n", pi);            // Not %f—man says %lf.
    printf("Worth: %ld\n", net_worth);  // Big nums need %ld.

    return 0; 
}
*/







// Lesson 1.2: BASIC ARITHMETIC EXPRESSIONS
// In C, operators have a strict order of precedence (like most sane languages):
// 1. Parentheses () override everything—evaluate inside first.
// 2. Multiplication (*) and division (/) next, left-to-right associativity.
// 3. Addition (+) and subtraction (-) last, also left-to-right.
// No parentheses? The compiler doesn't care about your "natural" order; it follows this hierarchy.
// Example: Compute 2 * (2 + 3) / 4.0 - 1
// Step-by-step (with floats for precision):
// - First: 2 + 3 = 5
// - Then: 5 / 4.0 = 1.25
// - Then: 2 * 1.25 = 2.5
// - Finally: 2.5 - 1 = 1.5
/*
#include "stdio.h"

int main() {
    double result;  
    result = 2 * (2 + 3) / 4.0 - 1; 
    printf("%f\n", result);
    return 0;
}
*/








// Lesson 1.3: IF-ELSE - DECISIONS, NOT RANDOM CRAP
/*
#include "stdio.h"

int main() {
    int age = 25;
    if (age >= 18) {
        printf("Adult\n");
    } else {
        printf("Kid\n");
    }
    return 0;
}
*/







// Lesson 1.4: WHILE LOOP - UNTIL YOU'RE DONE, YOU PIG
/*
#include "stdio.h"

int main() {
    char s[] = "hello";
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    printf("Length: %d\n", i);  
    return 0;
}
*/







// Lesson 1.5: FOR LOOP - REPEAT WITHOUT BEING A LOOP IDIOT
/*
#include "stdio.h"

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i * i);  
    }
    return 0;
}
*/







// Lesson 1.6: GETCHAR, PUTCHAR, EOF
/*
#include "stdio.h"

int main() {
    int c;
    printf("Type text, Ctrl+D to end:\n");
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
*/







// Lesson 1.7: SCANF - READ INPUT, DON'T HARDWIRE EVERYTHING
/*
#include "stdio.h"

int main() {
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Hello, %s\n", name);
    return 0;
}
*/






// Lesson 1.8: ARRAYS - LISTS OF STUFF, DON'T OVERFLOW YOU MORON (Restructured: 
// Manual Loop-Zero First, Then Concise)

// Truth bomb: Local arrays spawn as garbage. Manual loop teaches pain; {0} is 
// the shortcut for sane people.

// Step 1: Manually zero the array (feel the burn). 
// Step 2: Concisely zero the array {0}. 
/*
#include "stdio.h"

int main() {
    int i;

    // Manual zero: tedious, but you learn.
    int marr[5];
    for (i = 0; i < 5; i++) marr[i] = 0;
    printf("Manually zeroed array: ");
    for (i = 0; i < 5; i++) printf("%d ", marr[i]);
    printf("\n");

    // Concise zero: {0} does the job.
    int carr[5] = {0};
    printf("Concisely zeroed array: ");
    for (i = 0; i < 5; i++) printf("%d ", carr[i]);
    printf("\n");

    return 0;
}
*/







// Lesson 1.9: FUNCTIONS - Reuse code, skip copy-paste crap.
// Globals: Visible everywhere, avoid like plague.
// Locals: Function/block scope only.
// Constants: Use #define or const, no magic numbers.
/*
#include <stdio.h>

#define INC 1  // Preprocessor constant.
const int G_CONST = 42;  // Global const.

int global = 0;  // Mutable global: mostly bad.

int add(int a, int b) {
    const int L_CONST = 10;  // Local const.
    int sum = a + b + L_CONST;
    global += INC;
    return sum;
}

int main() {
    printf("%d\n", add(3, 4));  // 17
    {
        const int b_const = G_CONST;  // Block const.
        printf("Block: %d\n", b_const);
    }
    printf("Global: %d\n", global);  // 1
    return 0;
}
*/








// =============================================================================
// PART II: HIGH SEA
// ============================================================================= 












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
// 
// Lesson 1.1: VARIABLES, ASSIGNMENT AND FORMATTING - **Lesson 1.1: Variables,
// Assignment, and Formatting** Straight from K&R sections 1.2-1.3: Declare
// variables of different types, slap values into 'em, and print that shit
// properly. No half-assing it.
//
// - **Strings? What a joke.** In C, strings aren't a real goddamn data type,
// you naive fool. They're just arrays of chars, null-terminated if you don't
// want your program to crash like a bad hangover.
//
// - **int: For your basic whole-number bullshit.** No fractions here—just
// integers. Simple, fast, and won't lie to you about decimals.
//
// - **float: Decimals, but don't trust 'em blindly.** Floating-point numbers
// for when you need fractions, but precision is a myth—it's approximate as
// hell. Use it for quick and dirty calc, but expect rounding errors to bite
// you in the ass.
//
// - **char: A single byte pretending to be special.** Basically a tiny int for
// one character. Don't overthink it; it's glorified ASCII.
//
// - **double: Float on steroids.** Beefed-up float with 64 bits of
// double-precision glory instead of float's wimpy 32. Use doubles when your
// calculations need actual accuracy—don't be the idiot who uses float for
// anything serious and ends up with drunk-monkey math. Otherwise, save the
// memory and stick to float, you hog.
//
// - **long int: For when ints feel too small.** Bigger integers for your
// massive numbers or oversized ego. Print 'em with %ld, moron, or watch it all
// go to shit.
//
// - **Pro Tip: printf Formatting Magic** The format string is
// %[flags][width][.precision][length]type.  - Example: %6.2f — Total width 6
// (padded with spaces on the left, right-aligned), 2 digits after decimal for
// floats.  - Width: Pads with spaces by default; slap a 0 flag (%06d) for
// zero-padding.  - Precision: For floats, it's post-decimal digits; for %d or
// %ld, it's minimum digits (pads with zeros if short).  - Golden Rule: Match
// the type exactly (%d for int, %f for float, %ld for long, etc.), or your
// program's gonna puke undefined behavior all over your screen. Don't be that
// clown.

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
    printf("Zero: %03d\n", age);        // 0 flag pads zeros.
    printf("Height: %f\n", height);     // Default 6 dec—ugly.
    printf("Prec: %.2f\n", height);     // Post-decimal.
    printf("Full: %6.2f\n", height);    // Width+prec.
    printf("ZeroF: %08.2f\n", height);  // Zeros, dot counts.
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







// Lesson 1.3: FOR LOOP - REPEAT WITHOUT BEING A LOOP IDIOT
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







// Lesson 1.4: IF-ELSE - DECISIONS, NOT RANDOM CRAP
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







// Lesson 1.5: WHILE LOOP - UNTIL YOU'RE DONE, YOU PIG
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







// Lesson 1.6: ARRAYS - LISTS OF STUFF, DON'T OVERFLOW YOU MORON (Restructured: 
// Manual Loop-Zero First, Then Concise)

// Truth bomb: Local arrays spawn as garbage. Manual loop teaches pain; {0} is 
// the shortcut for sane people.

// Step 1: Manually zero the array (feel the burn). 
// Step 2: Concisely zero the array {0}. 
/*
#include "stdio.h"

int main() {
    int i;
    // manually zeroed array
    int marr[5];
    for (i = 0; i < 5; i++) {
        marr[i] = 0;
    }
    int msum = 0;
    printf("Manually-zeroed array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", marr[i]);
        msum += marr[i];
    }
    printf("\nManually-zeroed sum: %d\n", msum);
    
    // concisely zeroed array
    int carr[5] = {0}; // 0 propagates to all.
    int csum = 0;
    printf("Concisely-zeroed array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", carr[i]);
        csum += carr[i];
    }
    printf("\nConcisely-zeroed sum: %d\n", csum);
    return 0;
}
*/







// Lesson 1.7: FUNCTIONS - REUSE CODE, DON'T COPY-PASTE LIKE AN AMATEUR
/*
#include "stdio.h"

int add(int a, int b) {
    // Fix: return sum
    return a + b;
}

int main() {
    printf("%d\n", add(3, 4)); // Should be 7
    return 0;
}
*/







// Lesson 1.8: SCANF - READ INPUT, DON'T HARDWIRE EVERYTHING
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







// Lesson 1.9: GETCHAR, PUTCHAR, EOF, AND #DEFINE - SINGLE-CHAR I/O AND
// PREPROCESSOR BASICS Wake up, you fumbling newbies: K&R 1.5-1.6 and 1.9 hit
// you with getchar()/putchar() for char I/O and EOF (-1) for end-of-input.
// #define swaps text pre-compile—use for constants to avoid hardcoded garbage.
// It's basic; skip it and your loops hang like a bad patch.  getchar() reads
// one char as int (for EOF), putchar() outputs it. #define: uppercase
// constants, no semicolons, or your code explodes.
//
// Pro Tip: Store getchar() in int for EOF. Use #define IN 1, OUT 0 for
// states—beats magic numbers.
//
// Example: K&R word/line/char counter with getchar till EOF. State: OUT
// (whitespace), IN (word). Counts lines (NL), words, chars. EOF with Ctrl+D/Z.
// Uncomment putchar(c) for echo.
//
/*
#include "stdio.h" 
#define IN 1 
#define OUT 0

int main() {
    int c, nl, nw, nc, state = OUT;
    nl = nw = nc = 0;
    printf("Type text, Ctrl+D/Z to end:\n");
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') ++nl;
        if (c == ' ' || c == '\n' || c == '\t') state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}
*/







// Lesson 1.10: SCANF DEEP DIVE - FORMATTED INPUT, NO CHAR GRIND Getchar
// fanboys, face facts: K&R 1.5's scanf parses formatted input like printf's
// mirror. Returns successful reads or EOF. Unlike getchar's raw chars, it
// skips whitespace (except %c), handles types at once, but leaves newlines
// lurking—mix wrong, and loops infinite.
//
// Pro Tip: & for non-strings; array for strings. %10s limits buffers. Check
// return value. For chars: scanf("%c", &c) mimics getchar, returns 1/EOF.
//
// Example: Same counter, but scanf("%c") loop. No whitespace skip, like
// getchar, but better error check.
//
/*
#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state = OUT;
    char ch;  // Temp for scanf's char* bullshit
    nl = nw = nc = 0;
    printf("Type text, Ctrl+D to end:\n");
    while (scanf("%c", &ch) == 1) {
        c = (unsigned char)ch;  // Safe cast to int, handles signed char crap
        ++nc;
        if (c == '\n') ++nl;
        if (c == ' ' || c == '\n' || c == '\t') state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
        // putchar(c);  // Echo
    }
    printf("\n%d %d %d\n", nl, nw, nc);
    return 0;
}
*/







// Lesson 1.11: GETCHAR VS SCANF - RAW VS FUSSY, PICK OR PERISH Char junkies,
// reality check: getchar's raw char hose—no skips, just stream till EOF. scanf
// apes it with %c (returns 1/EOF), but for %d/%s? Skips whitespace, parses
// types, chokes on mismatches, leaves buffer junk. getchar: manual parsing
// hell for nums/strings. scanf: clean but opinionated.
//
// Pro Tip: getchar for exact streams; scanf for types—check returns, drain
// buffers when mixing. Word counter? Both fine with %c; scanf("%d") fails on
// letters, leaves crud.
//
// Example: Read num then char. getchar: manual digit slurp. scanf("%d %c"):
// auto-skip space. Bad input "abc"? getchar grinds; scanf bails.
//
/*
#include "stdio.h"

int main() {
    int num;
    char ch;

    printf("GETCHAR: Num then char (e.g., 42 a), enter:\n");
    num = 0;
    while ((ch = getchar()) != EOF && ch != ' ' && ch != '\n') {
        if (ch >= '0' && ch <= '9') num = num * 10 + (ch - '0');
    }
    if (ch == ' ') ch = getchar();
    if (ch != EOF && ch != '\n') printf("Num %d, char '%c' (getchar).\n", num, ch);
    else printf("EOF/empty.\n");

    printf("\nSCANF: Same:\n");
    if (scanf("%d %c", &num, &ch) == 2) {
        printf("Num %d, char '%c' (scanf).\n", num, ch);
    } else {
        printf("Failed.\n");
    }
    return 0;
}
*/




// ~/Apps/ctutor/tutorial.c
/*
===============================================================================
              = W e l c o m e t o t h e C T U T O R B A S I C S =
===============================================================================
    This is a no-bullshit C tutor ripped off from that VimTutor insanity, but
    for C newbies who think 'printf("hello");' is some quantum entanglement
    bullshit. Cooked up because stock tutorials make me want to hurl my
    keyboard at the wall with their pussyfooting crap. We're sticking to K&R
    
    Chapter 1: the absolute basics you'll actually use without your code
    segfaulting into the abyss. Variables, types, printf/scanf, loops, conditionals,
    arrays, functions—nothing fancy, just enough to not be a complete scripting
    zombie in C. Edit this file in vim (duh), uncomment and fill in the blanks as
    told, save, then from terminal: gcc this_file.c -o ctutor && ./ctutor to see
    if you're not a total moron. It'll compile and run only the uncommented parts,
    spitting output or errors (errors mean you fucked up—fix it, don't whine).
    
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

// Lesson 1.1: VARIABLES, ASSIGNMENT AND FORMATTING
// - **Lesson 1.1: Variables, Assignment, and Formatting**
//   Straight from K&R sections 1.2-1.3: Declare variables of different types, slap
//   values into 'em, and print that shit properly. No half-assing it.
//
// - **Strings? What a joke.**
//   In C, strings aren't a real goddamn data type, you naive fool. They're just arrays
//   of chars, null-terminated if you don't want your program to crash like a bad hangover.
//
// - **int: For your basic whole-number bullshit.**
//   No fractions here—just integers. Simple, fast, and won't lie to you about decimals.
//
// - **float: Decimals, but don't trust 'em blindly.**
//   Floating-point numbers for when you need fractions, but precision is a myth—it's
//   approximate as hell. Use it for quick and dirty calc, but expect rounding errors to bite
//   you in the ass.
//
// - **char: A single byte pretending to be special.**
//   Basically a tiny int for one character. Don't overthink it; it's glorified ASCII.
//
// - **double: Float on steroids.**
//   Beefed-up float with 64 bits of double-precision glory instead of float's wimpy 32. Use
//   doubles when your calculations need actual accuracy—don't be the idiot who uses float for
//   anything serious and ends up with drunk-monkey math. Otherwise, save the memory and stick
//   to float, you hog.
//
// - **long int: For when ints feel too small.**
//   Bigger integers for your massive numbers or oversized ego. Print 'em with %ld, moron, or
//   watch it all go to shit.
//
// - **Pro Tip: printf Formatting Magic**
//   The format string is %[flags][width][.precision][length]type.
//   - Example: %6.2f — Total width 6 (padded with spaces on the left, right-aligned), 2 digits
//   after decimal for floats.
//   - Width: Pads with spaces by default; slap a 0 flag (%06d) for zero-padding.
//   - Precision: For floats, it's post-decimal digits; for %d or %ld, it's minimum digits
//   (pads with zeros if short).
//   - Golden Rule: Match the type exactly (%d for int, %f for float, %ld for long, etc.), or
//   your program's gonna puke undefined behavior all over your screen. Don't be that clown.

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
// K&R 1.4-1.5: Understanding operator precedence in expressions.
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
// K&R 1.6? Nah, but basics: Loop from 0 to 9, print i*i
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
// K&R 1.7ish: Set int age=25; if age>=18 printf("Adult\n"); else printf("Kid\n");
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
// K&R 1.8? Loop while c != EOF, but simple: count chars in string "hello"
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
// K&R 1.10? Def simple add(int a, int b) { return a+b; } then main calls and prints add(3,4)
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
// K&R 1.11? Prompt for name with scanf, print "Hello, %s"
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












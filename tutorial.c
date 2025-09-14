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
// K&R 1.2-1.3: Declare variables of different types, assign values, and print 'em
// like you mean it. Strings? Pfft, not a real type—see below.

// In C, a string ain't a real data type, dipshit. We got ints for integers (whole numbers,
// no fractions), floats for floating-point crap (decimals, but watch the precision, it's a lie),
// chars (glorified ints for single bytes), and doubles—oh yeah, doubles are just beefed-up floats
// with more bits for your decimal-loving ass, like 64 bits of double-precision floating-point
// glory instead of float's puny 32. Use 'em when you need accuracy that doesn't make your
// calculations look like they were done by a drunk monkey; otherwise, stick to float and save
// the memory, you wasteful bastard. Long ints? Just bigger ints for your oversized ego or actual
// big numbers—use %ld, moron. Strings? Just arrays of those basic char fuckers, null-terminated
// if you don't wanna segfault like a noob.

// Pro tip: %[flags][width][.precision][length]type — like %6.2f (width 6 total, 2 decimals for float).
// Width pads with spaces (right-aligned); 0 flag pads with zeros. Precision? For floats, it's post-decimal digits;
// for %d/%ld, it's minimum digits (pads with zeros if less). Don't be a clown—match types or watch it barf.
/*
#include <stdio.h>

int main() {
    char name[10] = "Linus";  
    int age = 55;            
    float height = 5.11f;    
    double pi = 3.14159;
    long net_worth = 1000000000000L;  

    printf("Plain name: %s\n", name);                    // "Linus"

    printf("Plain age: %d\n", age);                      // "55"
    printf("Width 3 age: %3d\n", age);                   // " 55" (spaces).
    printf("Zero-pad age: %03d\n", age);                 // "055"

    printf("Plain height: %f\n", height);                // "5.110000"
    printf("2 decimals: %.2f\n", height);                // "5.11"
    printf("Width 6, 2 dec: %6.2f\n", height);           // "  5.11" (right-aligned).
    printf("Zero-pad float: %08.2f\n", height);          // "0005.11" (zeros, but watch the dot eat space).

    printf("Plain pi: %lf\n", pi);                       // "3.141590"
    printf("Plain net: %ld\n", net_worth);               // "1000000000000"

    return 0;
}
*/
















// Lesson 1.2: BASIC ARITHMETIC EXPRESSIONS
// K&R 1.4-1.5: Compute 2 + 2 * 3 / 4 - 1 (should be 1.5 with floats), print it
/*
#include <stdio.h>

int main() {
    double result;  
    result = 2 + 2 * 3 / 4.0 - 1; 
    printf("%f\n", result);
    return 0;
}
*/



















// Lesson 1.3: FOR LOOP - REPEAT WITHOUT BEING A LOOP IDIOT
// K&R 1.6? Nah, but basics: Loop from 0 to 9, print i*i
/*
#include <stdio.h>

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
#include <stdio.h>

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
#include <stdio.h>

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

// Step 1: Manual loop-zero (feel the burn). 
// Step 2: Concise {0}. 
/*
#include <stdio.h>

int main() {
    int i;
    // MANUAL LOOP-ZERO
    printf("\n--- MANUAL LOOP-ZERO: EARN YOUR ZEROS ---\n");
    int marr[5];
    for (i = 0; i < 5; i++) {
        marr[i] = 0;
    }
    int msum = 0;
    printf("Manual-zeroed array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", marr[i]);
        msum += marr[i];
    }
    printf("\nManual zero sum: %d (boring but correct)\n", msum);
    // NOW THE CONCISE WAY
    printf("\n--- CONCISE {0}: LAZY BUT SMART ---\n");
    int carr[5] = {0}; // Magic: First 0 propagates to all.
    int csum = 0;
    printf("Concise-zeroed array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", carr[i]);
        csum += carr[i];
    }
    printf("\nConcise zero sum: %d (same result, less typing)\n", csum);
    return 0;
}
*/













// Lesson 1.7: FUNCTIONS - REUSE CODE, DON'T COPY-PASTE LIKE AN AMATEUR
// K&R 1.10? Def simple add(int a, int b) { return a+b; } then main calls and prints add(3,4)
/*
#include <stdio.h>

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
#include <stdio.h>

int main() {
    char name[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Hello, %s\n", name);
    return 0;
}
*/












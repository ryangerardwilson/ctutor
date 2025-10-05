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
#include "stdio.h"

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
// PART II: HIGH SEA - MAKING C LESS OF A PAIN FOR SCRIPTING
// =============================================================================

// You survived basic C? Pathetic. HighSea is my hack to make C scriptable
// without the usual malloc-induced aneurysms. Dynamic strings, auto-growing
// lists, braindead maps, file ops that don't require a PhD in fopen, errors
// that actually tell you what went wrong, and a nuke-all cleanup. Types are
// opaque—fuck with internals and segfault your own face. Allocs tracked;
// hs_free_all() for lazy bastards.

// Lesson 2.1: OVERVIEW OF HIGHSEA TYPES - DON'T BE A TYPE IDIOT
// hs_str: Dynamic strings, append/concat without buffer overflow hell.
// hs_list: Growable lists of void*, append/get/len.
// hs_map: String-key void*-value maps, set/get.
// hs_file: File handles, open/read/write/close with sane modes.
// hs_err_t: Error enum, check after ops.
// hs_debug: Spew internals of any hs_* thing—type and guts, no recursion because C ain't magic.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_str* s = hs_str_new("HighSea");
    hs_list* l = hs_list_new();
    hs_map* m = hs_map_new();
    hs_file* f = hs_file_open("test.txt", HS_FILE_WRITE);
    if (!f) return 1;

    hs_str_append(s, " rules");
    hs_list_append(l, s);
    hs_map_set(m, "key", s);

    printf("\n");
    hs_debug(s, HS_STR);
    printf("\n");
    hs_debug(l, HS_LIST);
    printf("\n");
    hs_debug(m, HS_MAP);
    printf("\n");
    hs_debug(f, HS_FILE);

    hs_file_close(f);
    hs_free_all();
    return 0;
}
*/







// Lesson 2.2: DEEP DIVE INTO HS_STR - STRINGS WITHOUT THE USUAL C CRAP
// New from char*, append, concat (new str), get char*/len, free. Dynamic resize, null-term'd.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_str* s = hs_str_new("Kernel");
    hs_str_append(s, " panic?");  // Mutates s.
    hs_str* c = hs_str_concat(s, " Fix your shit.");  // New str.
    printf("%s (len %zu)\n", hs_str_get(c), hs_str_len(c));
    if (hs_str_append(s, NULL) != HS_ERR_OK) printf("Append fail: %s\n", hs_err_str(hs_err_last()));
    hs_str_free(s);
    hs_str_free(c);
    return 0;
}
*/







// Lesson 2.3: DEEP DIVE INTO HS_LIST - LISTS THAT GROW, UNLIKE YOUR STATIC ARRAYS
// New empty, append void*, get by index, len, free. Doesn't own items—free 'em yourself.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_list* l = hs_list_new();
    int* i1 = malloc(sizeof(int)); *i1 = 42;
    int* i2 = malloc(sizeof(int)); *i2 = 69;
    hs_list_append(l, i1);
    hs_list_append(l, i2);
    printf("Len: %zu\n", hs_list_len(l));
    printf("Item 0: %d\n", *(int*)hs_list_get(l, 0));
    if (hs_list_get(l, 99) == NULL) printf("Out of bounds: %s\n", hs_err_str(hs_err_last()));
    free(i1); free(i2);
    hs_list_free(l);
    return 0;
}
*/







// Lesson 2.4: DEEP DIVE INTO HS_MAP - MAPS FOR KEY-VALUE WITHOUT REINVENTING HASHES
// New empty, set string key to void*, get by key, free. Linear search—fine for small. Dup's keys, doesn't own values.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_map* m = hs_map_new();
    char* v1 = "Torvalds";
    hs_map_set(m, "creator", v1);
    hs_map_set(m, "creator", "Linus");  // Overwrites.
    printf("Value: %s\n", (char*)hs_map_get(m, "creator"));
    if (hs_map_get(m, "nope") == NULL) printf("Missing: %s\n", hs_err_str(hs_err_last()));
    hs_map_free(m);  // Frees keys, not values.
    return 0;
}
*/







// Lesson 2.5: DEEP DIVE INTO HS_FILE - FILES WITHOUT FOPEN MODE BULLSHIT
// Open with mode (READ/WRITE/APPEND), write hs_str, read_all to hs_str, close. Check errors.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_file* f = hs_file_open("out.txt", HS_FILE_APPEND);
    if (!f) { printf("Open fail: %s\n", hs_err_str(hs_err_last())); return 1; }
    hs_str* d = hs_str_new("Appended line.\n");
    if (hs_file_write(f, d) != HS_ERR_OK) printf("Write fail: %s\n", hs_err_str(hs_err_last()));
    hs_file_close(f);
    f = hs_file_open("out.txt", HS_FILE_READ);
    hs_str* r = hs_file_read_all(f);
    printf("Content: %s", hs_str_get(r));  // May lack \n at end.
    hs_file_close(f);
    hs_str_free(d);
    hs_str_free(r);
    return 0;
}
*/







// Lesson 2.6: DEEP DIVE INTO HS_ERR_T - ERRORS THAT DON'T LEAVE YOU GUESSING
// Enum: OK/NO_MEM/INVALID/IO. Last err global, get str. Reset on free_all.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_map_set(NULL, "key", "val");  // Invalid.
    hs_err_t e = hs_err_last();
    printf("Err: %s (%d)\n", hs_err_str(e), e);
    hs_str* s = malloc(1);  // Fake OOM, but actually check real fails.
    if (!hs_str_new("too big maybe")) printf("OOM: %s\n", hs_err_str(hs_err_last()));
    return 0;
}
*/







// Lesson 2.7: DEEP DIVE INTO HS_FREE_ALL - NUKE YOUR LEAKS, LAZY ASS
// Tracks all hs allocs, frees 'em all. Call at end for script cleanup. Resets err.
/*
#include "hs.h"
#include "stdio.h"

int main() {
    hs_str_new("Leak me");
    hs_list_new();
    hs_map_new();
    hs_file_open("dummy.txt", HS_FILE_WRITE);  // Close manually if open.
    hs_free_all();  // All gone, pointers invalid.
    printf("Cleaned.\n");
    return 0;
}
*/









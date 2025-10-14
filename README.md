# CTutor: Because Stock C Tutorials Are for Morons Who Think Pointers Are Optional

This repo isn't some hand-holding kindergarten bullshit—it's a no-nonsense C
tutor hacked together to teach you actual code that doesn't segfault every time
you sneeze. Basics? Ripped straight from K&R vibes because why reinvent the
wheel when you can just steal it. But then it dives into HighSea, my little
hack to make C less of a memory-leak nightmare for scripting without malloc-
induced therapy sessions. If you're still using Python for everything in 2025,
GTFO and learn C already—it's the kernel's language, you lazy script kiddie.

## Requirements
- Python 3.x (duh, if you're on Omarchy, it's already there—pacman -S python if
  you're that incompetent.)
- Vim (because nano is for wimps who can't escape properly. On Omarchy: sudo
  pacman -S vim. This ain't VS Code territory.)
- GCC (comes with Omarchy base-devel, but if not: sudo pacman -S base-devel. No
  compiler? Go back to Windows.)

## Getting Started
1. **Clone this crap:**

    git clone https://github.com/yourusername/ctutor.git
    cd ctutor

2. **Run the damn thing:**

    python main.py

- It'll whine if `tutorial.c` is missing (it shouldn't—fix your clone, idiot).
- Fires up Vim on a temp copy of the tutor. Hack away: uncomment lessons, fill
in blanks, screw up like a pro. - Quit Vim (`:q` or `ZZ`, if you don't know,
you're not ready for C). - Your botched edits? Stay in the temp file. Original
remains untouched. - No Vim? It'll scream at you to install it, then bail. -
Compile manually: `gcc temp.c -o temp && ./temp`. Errors? Fix your shit—welcome
to C.

3. **Pro Tip:** Use a virtualenv if you're paranoid about Python (on Omarchy,
just `python -m venv env && source env/bin/activate`). But seriously, run
it—it's moron-resistant.

## What's in the Box?
- `tutorial.c`: The meat. Lessons 1.x: basic C crap like types, loops,
  functions—stuff that keeps you from being a total poser. 2.x: HighSea for
dynamic strings, lists, maps, files without the usual fopen hell.
- `main.py`: The launcher. Copies `tutorial.c` to temp, spawns Vim, waits for
  you to quit, then tells you to compile like an adult. No auto-execution—do
the work, build character.

## Why Bother?  Because stock C tutorials stop at "hello world" and leave you
malloc-ing your way to valgrind therapy. This one teaches you to *code* in C
without RSI from buffer overflows. HighSea? My hack for scriptable C—dynamic
types, error handling that doesn't suck, and a free-all to nuke leaks.
Battle-tested for kernels that don't crash on Wednesdays. Experiment, or
don't—C doesn't give a fuck, but your segfaults will.

## Credits
- Original K&R vibes: Kernighan and Ritchie (bless 'em, they made Unix
  possible).
- This overhaul: Whoever the hell you are, but if it's gold, thank me for the
  README. If it sucks, blame the user.

## License
MIT, or whatever—fork it, break it, just don't sue when your code core dumps.

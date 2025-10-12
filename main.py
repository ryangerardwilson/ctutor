#!/usr/bin/env python3
# ~/Apps/ctutor/main.py
# Yeah, because why the fuck not keep it in Python? It's a wrapper, not the goddamn program itself.
# This is the no-bullshit launcher for your C boot camp. It copies tutorial.c to a temp file,
# fires up vim (because nano is for pussies who can't handle real editors), lets you hack away,
# then reminds you to compile and run that crap yourself. No hand-holding—gcc it or die trying.
# Run this: python main.py, edit, save, then in terminal: gcc temp.c -o temp && ./temp.
# Errors? Fix your shit. Segfaults? Welcome to C, moron.

import tempfile
import subprocess
import os
import shutil

script_dir = os.path.dirname(os.path.realpath(__file__))
tutorial_path = os.path.join(script_dir, "tutorial.c")

if not os.path.exists(tutorial_path):
    print(
        f"No tutorial.c in {script_dir}? What kind of half-assed clusterfuck setup is this? Clone the damn repo properly or GTFO."
    )
    exit(1)

with open(tutorial_path, "r", encoding="utf-8") as f:
    original_content = f.read()


def main():
    # Copy to temp so you can screw it up royally without mercy. Fresh start every goddamn time.
    with tempfile.NamedTemporaryFile(
        mode="w", suffix=".c", encoding="utf-8", delete=False
    ) as tmp:
        tmp.write(original_content)
        temp_file = tmp.name

    print(
        f"Opening {temp_file} in vim. Uncomment, edit the code per lessons, save your ass off."
    )
    print(
        "Quit when done with a lesson, then from terminal: gcc {temp_file} -o temp_ctutor && ./temp_ctutor"
    )
    print(
        "See output or errors. Fuck up? Good, learn. Repeat till you're not a total C newbie disaster."
    )

    # Vim, because real programmers don't click around like lab rats.
    editor = ["vi", temp_file]  # Swap to 'nano' if vim makes you cry, wimp.
    try:
        subprocess.call(editor)
    except FileNotFoundError:
        print(
            "Vim missing? Install it: sudo apt install vim. This ain't for finger-painting in GUIs."
        )
        os.unlink(temp_file)
        return 1

    print(
        f"Editor closed. Now compile and run: gcc {temp_file} -Wall -Wextra -o temp_ctutor && ./temp_ctutor"
    )
    print(
        "Warnings? Heed 'em, you sloppy bastard. When you're bored, rm the temp files or run this again for a clean slate."
    )
    print(
        "Pro tip: Add -g for debugging if your code barfs mysteriously. Happy compiling, asshole."
    )

    # No auto-run; you do the heavy lifting. Cleanup? User handles it—builds character.
    return 0


if __name__ == "__main__":
    exit(main())

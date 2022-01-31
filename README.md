# Wordle-solver

Janky brute force wordle solver, works most of the time :P

Wordle is six tries complete for this implementation, WIP for some edge cases.

Usage:
- Run it with `words.txt` in the same directory.
- After every word suggested, input the feedback from wordle
e.g. `bbygb` for ⬛️⬛️🟨🟩⬛️
- If the word matches, don't forget to input `ggggg` to ensure all allocated memory is freed and the program quits correctly.

I tested the code on UNIX based systems, which might not work correctly on Windows.

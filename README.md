# Wordle-solver

Janky brute force wordle solver
Works most of the times :P
WIP for some edge cases.

Usage:
- Run it with `words.txt` in the same directory.
- After every word suggested, input the feedback from wordle
eg. `bbygb` for ⬛️⬛️🟨🟩⬛️
- If the word matches, don't forget to input `ggggg` to ensure all allocated memory is freed and the program quits correctly.

The code was tested on UNIX based systems, mkight not work correctly on Windows.

# Wordle-solver

Janky brute force wordle solver, works most of the time :P

Wordle is six tries complete for this implementation, WIP for some edge cases. (Number of edge cases substantially reduced with the new update).

Usage:
- Run it with `words.txt` in the same directory.
- After every word suggested, input the feedback from wordle, e.g. `bbygb` for ⬛️⬛️🟨🟩⬛️
- If the code gets stuck, do `ctrl+c` to quit. 
- If the word matches, don't forget to input `ggggg` to ensure all allocated memory is freed and the program quits correctly.

Example usage:
```
2314 words read
First word is saute
bybbb
Second word is chair
bbgby
Third word is brawl
bygyb
Fourth word is dwarf
ggggg
We are done
```

Please share any failing edge cases in the issues tab. Hack around to improve accuracy, e.g. modify the word file, change the start word, etc.

I tested the code on UNIX based systems, which might not work correctly on Windows. Thanks to a fix pointed out by @thatcatfromspace, additional Windows support has been added with the new update. Please raise any issues if you face any OS problems.

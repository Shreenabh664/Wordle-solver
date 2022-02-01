# Wordle-solver

<p align="center">
    <img src="https://user-images.githubusercontent.com/62369422/151929524-eaee0d20-26b9-4118-8a7c-0cf4b23d464f.png">
</p>
<p align="center">
     <i> Image credit: https://medium.com/@yotamyachmoorgafni </i>
</p>

Easy to use Wordle Solver, tested extensively on 100+ Wordles. Flaunts a minimalist UI and UX. 
The new implementation is complete for (almost) all Wordles. \[All known edge cases have been fixed.]

Usage:
- Run it with `words.txt` in the same directory.
- After every word suggested, input the feedback from wordle, e.g. `bbygb` for ⬛️⬛️🟨🟩⬛️
- The code should quit automatically when it is sure that it has suggested the winning word.
- If it doesn't quit automatically, input `ggggg` to ensure it quits correctly.
- If a `floating point exception` is raised, it means you have entered incorrect feedback at some stage.

Example usage 1 (Automatic quitting):

`2314 words read`\
`saute`\
bybby\
`wreak`\
bbgyb\
`hyena`\
bbgyg\
`enema`

Example usage 2 (Manually quitting):

`2314 words read`\
`saute`\
bggyb\
`vaunt`\
bgggg\
`jaunt`\
ggggg

Please share any failing edge cases in the issues tab. Hack around to improve accuracy, e.g. modify the word file, change the start word, etc.

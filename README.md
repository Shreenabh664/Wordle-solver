# Wordle-solver

<p align="center">
    <img src="https://user-images.githubusercontent.com/62369422/151929524-eaee0d20-26b9-4118-8a7c-0cf4b23d464f.png">
</p>
<p align="center">
     <i> Image credit: https://medium.com/@yotamyachmoorgafni </i>
</p>

Easy to use Wordle Solver. Flaunts a minimalist UI and UX. The new implementation is complete for all Wordles and optimizes for minimum tries.

Usage:
- Clone and `cd` into this repo.
- Compile `wordle.c` (uses `math.h` header for entropy calculations so use `-lm` flag with `gcc`).
- After every word suggested, input the feedback from wordle, e.g. `bbygb` for ⬛️⬛️🟨🟩⬛️
- Input `ggggg` to ensure it quits correctly when the word matches.
- If a `floating point exception` is raised, it means you have entered incorrect feedback at some stage.


Example usage:\
`soare`\
byybb\
`bloat`\
bggyg\
`aloft`\
ggggg

Result:\
Wordle 231 3/6

⬛🟨🟨⬛⬛\
⬛🟩🟩🟨🟩\
🟩🟩🟩🟩🟩

New optimizations significantly reduce the number of steps needed (in most cases).
Read more about the information theory approach here: https://markmliu.medium.com/what-in-the-wordle-5dc5ed94fe2

# POGS: Program Synthesis for Optimal Game Strategy
The goal of this work is to synthesize a provably optimal strategy for simple turn-based games (for example, the 21 Game).

---
## Related Resources
POGS (codebase): [https://github.com/jxin31415/pogs](https://github.com/jxin31415/pogs)

Report: https://drive.google.com/file/d/1zAkxrNeTHW1-8B9e7bujdEBBgFZTnq_2/view?usp=sharing

Poster: https://drive.google.com/file/d/1l_SZ9LNJi8MrgMEsywf-bZCjy_z6iYoZ/view?usp=sharing

---
## Description
### Input
A sketch of a program representing a simple game $\pi_0$.

### Output
An expression that completes the sketch, representing a strategy for the target player that is provably optimal.

---
### Dependencies & Setup
The only dependencies are in the submodule **fun_verifier/**. Please follow the instructions there.

---
## Usage Guide
To define a problem instance, you'll need to change three files. We provide a basic working example with the 21 Game.
* In **game.fun**, define the sketch for the game. Note the specific syntax:
  * *fun* denotes the declaration of a game sketch.
  * Square brackets *[]* are inserted before the while loop body to indicate the need to generate loop invariants.
  * Question marks *??* denote a hole: this is the program that we wish to synthesize.
  * The assertion encodes the notion of player B winning the game.
* In **game.h**, re-define the sketch for the game. Please use the same format as the example provided:
  * The function should take in a vector input, which is the list of player A moves. 
  * Instead of assertions, we return true or false when the game has been won or lost, respectively.
  * The hole should take the form given in the example, including the names and values of the variables which should be used as roots in the synthesis step.
* In **main.cpp**, re-define the variables *vars*, the constants *consts*, and the list of valid moves *valid_moves*.

Then, just run *make* to run the algorithm. As an example, the current setup (the 21 Game) gives the following output:
```
Now enumerating over programs...
Enumerated over 108 programs so far
Enumerated over 128296 programs so far
(4-a) strategy passes random opponent!
(4-a) strategy passes formal verification with invariant (sum==(iter*4))!
Strategy found and verified!
Elapsed(s)=768
```
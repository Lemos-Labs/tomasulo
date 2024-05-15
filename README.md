# Developer - Must READ
## Architecture

We have `32 registers` (0-31) that can be used, every one starts with a `0` value.
A few assumptions in this code, are the clock cicle for a instruction, that is defined in the `Instruction.h`, fell free to change it in the code:
* Read/Write - 2
* Add/Sub - 3
* Mult/Div - 8

_The architecture can be changed at `main.c` at `reservationStations` variable_
* 2 Adder
* 1 Multiplier
* 2 Load
* 2 Store


## How does it work.
Since we wanted to make all of it single-thread, all of the tomasulo functions are inside a `while(true)`, where every iteration is a new `clock`.
There is a "TodoOperations", simply a `Station runtimeList[]`, that is responsable for storing all the operations that are running. In every clock we check the `runtimeList[]` to see if we can do anything with the operations yet.

### Step-by-Step
1. Parse instructions _(initializating instructionsList)_
2. Initialize structures _(such as `registers`, `runtimeList`, `reservationStations`, etc...)_
3. While(true):
   a. Dispatch a new instruction. _If it's successfully, we add to the `runtimeList` and set the `reservationStation` as busy. If it cannot be dispatch yet, we don't do anything with it. We decided to block the dispatch untill it's free to go_.
   b. Searches all the `runtimeList` to check if we can do anything with a instruction. In this stage, we also check the `registers` dependencies.
      * Here the magic happens, writing/reading registers, adding, subtracting, etc...


## Parser
### Supported Instructions
```assembly
SW Rx,y(Rz)
LW Rx,y(Rz)

SUBD Rx,Ry,Rz
DIVD Rx,Ry,Rz
MULD Rx,Ry,Rz
ADDD Rx,Ry,Rz
```

### Adding a new Instruction support
When adding a new instruction type such as `SW`, `LW`, `SUBD`, `DIVD`, make sure to add it on the _Instruction.h_.

1. Add on the `Operation` enum. 
2. Create a `else if` condition on the `_getOperation` function.
3. Define if the instruction is a `TwoReg` or `ThreeReg`
* `TwoReg` instruction follows this pattern: `LW R11,200(R2)`. `INSTRUCTION Rx, y(Rz)`
* `ThreeReg` instruction follows this pattern: `MULD R20,R14,R19`, `SUBD R2,R9,R8`. `INSTRUCTION Rx, Ry, Rz`
4. After you figure it out which instruction type this new instruction is, add it on the function `getInstructionType`, to return the correct _intruction type_

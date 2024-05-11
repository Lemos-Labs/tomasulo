# Developer - Must READ

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

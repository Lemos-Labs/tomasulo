# Developer - Must READ
## Architecture

![WhatsApp Image 2024-05-12 at 17 14 20_b6336279](https://github.com/Lemos-Labs/tomasulo/assets/49888082/15eeac3a-e080-4eda-a47c-c686327ab6c9)

* 1 Load/Store
* 1 Multiplicador de PF
* 1 Somador de PF


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


---

Fazer uma lista de operacoes TODO. 

1 coisa a se fazer eh um despache
Se ele for bem sucessido (se nao retornar targetStationIndex = -1)
Vai adicionar na lista 
[
 {
    Instruction,
    CicloAtual,
    CicloNecessario // Nao precisa definir, pq vai saber pela instrucaoo
 }
]

A CADA CICLO DE CLOCK
A gente chama a funcao de despache. 
Percorre a lista vendo se da pra fazer alguma coisa. 

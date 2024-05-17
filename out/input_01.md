# CICLE 1
## Log
* [1] Dispatched

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 1,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 2
## Log
* [2] Dispatched
* [1] Started

## Registers
```json
[
{"id": 10, "busyByStation": 5, "busyByInst": 1, "v": 10},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 3
## Log
* [3] Dispatched
* [2] Started

## Registers
```json
[
{"id": 10, "busyByStation": 5, "busyByInst": 1, "v": 10},
{"id": 11, "busyByStation": 3, "busyByInst": 2, "v": 11},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 4
## Log
* [4] Cannot be dispatched, waiting for a station to be free
* [3] Started
* [1] Completed

## Registers
```json
[
{"id": 10, "busyByStation": 5, "busyByInst": 1, "v": 14},
{"id": 11, "busyByStation": 3, "busyByInst": 2, "v": 11},
{"id": 15, "busyByStation": 4, "busyByInst": 3, "v": 15},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": 4,
        "writtenAt": 5
    }},
]
```
---

# CICLE 5
## Log
* [4] Cannot be dispatched, waiting for a station to be free
* [2] Completed
* [1] Wrote in memory

## Registers
```json
[
{"id": 11, "busyByStation": 3, "busyByInst": 2, "v": 2},
{"id": 15, "busyByStation": 4, "busyByInst": 3, "v": 15},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": 5,
        "writtenAt": 6
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 6
## Log
* [4] Cannot be dispatched, waiting for a station to be free
* [2] Wrote in memory
* [3] Completed

## Registers
```json
[
{"id": 15, "busyByStation": 4, "busyByInst": 3, "v": 19},
]
```

## Stations
```json
[
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": 6,
        "writtenAt": 7
    }},
]
```
---

# CICLE 7
## Log
* [4] Dispatched
* [3] Wrote in memory

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 7,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 8
## Log
* [5] Dispatched
* [4] Started

## Registers
```json
[
{"id": 30, "busyByStation": 3, "busyByInst": 4, "v": 30},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 9
## Log
* [6] Dispatched
* [5] Started

## Registers
```json
[
{"id": 19, "busyByStation": 4, "busyByInst": 5, "v": 19},
{"id": 30, "busyByStation": 3, "busyByInst": 4, "v": 30},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 9,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 10
## Log
* [7] Dispatched
* [6] Started
* [4] Completed

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 6, "v": 2},
{"id": 19, "busyByStation": 4, "busyByInst": 5, "v": 19},
{"id": 30, "busyByStation": 3, "busyByInst": 4, "v": 6},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 9,
        "startedAt": 10,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": 10,
        "writtenAt": 11
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 11
## Log
* [8] Dispatched
* [7] Started
* [4] Wrote in memory
* [5] Completed

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 6, "v": 2},
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
{"id": 19, "busyByStation": 4, "busyByInst": 5, "v": 16},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 9,
        "startedAt": 10,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (4)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": 9,
        "finishedAt": 11,
        "writtenAt": 12
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 12
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [5] Wrote in memory
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 6, "v": 2},
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 9,
        "startedAt": 10,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 13
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [6] Completed
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 6, "v": 8},
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 9,
        "startedAt": 10,
        "finishedAt": 13,
        "writtenAt": 14
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 14
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [6] Wrote in memory
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 15
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 16
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 17
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 18
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 14},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 19
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [7] Completed
* [8] Cannot start, it's waiting for Register 10

## Registers
```json
[
{"id": 10, "busyByStation": 2, "busyByInst": 7, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "DIV",
        "issuedAt": 10,
        "startedAt": 11,
        "finishedAt": 19,
        "writtenAt": 20
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 20
## Log
* [9] Cannot be dispatched, waiting for a station to be free
* [7] Wrote in memory
* [8] Started

## Registers
```json
[
{"id": 10, "busyByStation": 5, "busyByInst": 8, "v": 0},
]
```

## Stations
```json
[
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": 20,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 21
## Log
* [9] Dispatched

## Registers
```json
[
{"id": 10, "busyByStation": 5, "busyByInst": 8, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": 20,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 22
## Log
* [10] Dispatched
* [9] Started
* [8] Completed

## Registers
```json
[
{"id": 10, "busyByStation": 5, "busyByInst": 8, "v": 8},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 22,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 11,
        "startedAt": 20,
        "finishedAt": 22,
        "writtenAt": 23
    }},
]
```
---

# CICLE 23
## Log
* [11] Dispatched
* [10] Started
* [8] Wrote in memory

## Registers
```json
[
{"id": 3, "busyByStation": 0, "busyByInst": 10, "v": 3},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 22,
        "startedAt": 23,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 23,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 24
## Log
* [12] Dispatched
* [11] Started

## Registers
```json
[
{"id": 2, "busyByStation": 1, "busyByInst": 11, "v": 8},
{"id": 3, "busyByStation": 0, "busyByInst": 10, "v": 3},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 22,
        "startedAt": 23,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 23,
        "startedAt": 24,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 25
## Log
* [13] Dispatched
* [12] Cannot start, it's waiting for Register 2

## Registers
```json
[
{"id": 2, "busyByStation": 1, "busyByInst": 11, "v": 8},
{"id": 3, "busyByStation": 0, "busyByInst": 10, "v": 3},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 22,
        "startedAt": 23,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 23,
        "startedAt": 24,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 25,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 26
## Log
* [14] Cannot be dispatched, waiting for a station to be free
* [10] Completed
* [12] Cannot start, it's waiting for Register 2
* [13] Started

## Registers
```json
[
{"id": 2, "busyByStation": 1, "busyByInst": 11, "v": 8},
{"id": 3, "busyByStation": 0, "busyByInst": 10, "v": 8},
{"id": 7, "busyByStation": 6, "busyByInst": 13, "v": 7},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 22,
        "startedAt": 23,
        "finishedAt": 26,
        "writtenAt": 27
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 23,
        "startedAt": 24,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 25,
        "startedAt": 26,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 27
## Log
* [14] Cannot be dispatched, waiting for a station to be free
* [10] Wrote in memory
* [11] Completed
* [12] Cannot start, it's waiting for Register 2

## Registers
```json
[
{"id": 2, "busyByStation": 1, "busyByInst": 11, "v": 1},
{"id": 7, "busyByStation": 6, "busyByInst": 13, "v": 7},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 23,
        "startedAt": 24,
        "finishedAt": 27,
        "writtenAt": 28
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 25,
        "startedAt": 26,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 28
## Log
* [14] Cannot be dispatched, waiting for a station to be free
* [11] Wrote in memory
* [12] Started
* [13] Completed

## Registers
```json
[
{"id": 2, "busyByStation": 5, "busyByInst": 12, "v": 1},
{"id": 7, "busyByStation": 6, "busyByInst": 13, "v": 0},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": 28,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 25,
        "startedAt": 26,
        "finishedAt": 28,
        "writtenAt": 29
    }},
]
```
---

# CICLE 29
## Log
* [14] Cannot be dispatched, waiting for a station to be free
* [13] Wrote in memory

## Registers
```json
[
{"id": 2, "busyByStation": 5, "busyByInst": 12, "v": 1},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 20},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": 28,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 30
## Log
* [14] Dispatched
* [9] Completed
* [12] Completed

## Registers
```json
[
{"id": 2, "busyByStation": 5, "busyByInst": 12, "v": 0},
{"id": 20, "busyByStation": 2, "busyByInst": 9, "v": 224},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 21,
        "startedAt": 22,
        "finishedAt": 30,
        "writtenAt": 31
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 24,
        "startedAt": 28,
        "finishedAt": 30,
        "writtenAt": 31
    }},
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 30,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 31
## Log
* [9] Wrote in memory
* [12] Wrote in memory
* [14] Started

## Registers
```json
[
{"id": 10, "busyByStation": 6, "busyByInst": 14, "v": 8},
]
```

## Stations
```json
[
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 30,
        "startedAt": 31,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 32
## Log

## Registers
```json
[
{"id": 10, "busyByStation": 6, "busyByInst": 14, "v": 8},
]
```

## Stations
```json
[
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 30,
        "startedAt": 31,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 33
## Log
* [14] Completed

## Registers
```json
[
{"id": 10, "busyByStation": 6, "busyByInst": 14, "v": 0},
]
```

## Stations
```json
[
    {"type": "STORE (6)", "Instruction": {
        "operation": "SW",
        "issuedAt": 30,
        "startedAt": 31,
        "finishedAt": 33,
        "writtenAt": 34
    }},
]
```
---

# CICLE 34
## Log
* [14] Wrote in memory

## Registers
```json
[
]
```

## Stations
```json
[
]
```
---


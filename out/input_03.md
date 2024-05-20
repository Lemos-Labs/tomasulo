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
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
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
{"id": 1, "busyByStation": 3, "busyByInst": 1, "v": 1},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 3
## Log
* [3] Dispatched
* [2] Cannot start, it's waiting for Register 1

## Registers
```json
[
{"id": 1, "busyByStation": 3, "busyByInst": 1, "v": 1},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 4
## Log
* [4] Dispatched
* [3] Cannot start, it's waiting for Register 1
* [1] Completed
* [2] Cannot start, it's waiting for Register 1

## Registers
```json
[
{"id": 1, "busyByStation": 3, "busyByInst": 1, "v": 0},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": 4,
        "writtenAt": 5
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 5
## Log
* [5] Dispatched
* [3] Cannot start, it's waiting for Register 1
* [4] Started
* [1] Wrote in memory
* [2] Started

## Registers
```json
[
{"id": 1, "busyByStation": 5, "busyByInst": 2, "v": 0},
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 4},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 5,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 2,
        "startedAt": 5,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 6
## Log
* [3] Cannot start, it's waiting for Register 1
* [5] Cannot start, it's waiting for Register 1

## Registers
```json
[
{"id": 1, "busyByStation": 5, "busyByInst": 2, "v": 0},
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 4},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 5,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 2,
        "startedAt": 5,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 7
## Log
* [3] Cannot start, it's waiting for Register 1
* [5] Cannot start, it's waiting for Register 1
* [2] Completed

## Registers
```json
[
{"id": 1, "busyByStation": 5, "busyByInst": 2, "v": 0},
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 4},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 5,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 2,
        "startedAt": 5,
        "finishedAt": 7,
        "writtenAt": 8
    }},
]
```
---

# CICLE 8
## Log
* [3] Cannot start, it's waiting for Register 1
* [4] Completed
* [5] Cannot start, it's waiting for Register 1
* [2] Wrote in memory

## Registers
```json
[
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": -3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 5,
        "finishedAt": 8,
        "writtenAt": 9
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 9
## Log
* [3] Started
* [4] Wrote in memory
* [5] Started

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 3, "v": 2},
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 10
## Log

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 3, "v": 2},
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 11
## Log

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 3, "v": 2},
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 12
## Log
* [3] Completed

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 3, "v": 3},
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 3,
        "startedAt": 9,
        "finishedAt": 12,
        "writtenAt": 13
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 13
## Log
* [3] Wrote in memory

## Registers
```json
[
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 14
## Log

## Registers
```json
[
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 15
## Log

## Registers
```json
[
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 16
## Log

## Registers
```json
[
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 6},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 17
## Log
* [5] Completed

## Registers
```json
[
{"id": 6, "busyByStation": 2, "busyByInst": 5, "v": 0},
]
```

## Stations
```json
[
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 5,
        "startedAt": 9,
        "finishedAt": 17,
        "writtenAt": 18
    }},
]
```
---

# CICLE 18
## Log
* [5] Wrote in memory

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


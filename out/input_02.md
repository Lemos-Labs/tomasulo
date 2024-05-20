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
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
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
        "issuedAt": 2,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
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
]
```
---

# CICLE 4
## Log
* [4] Dispatched
* [2] Cannot start, it's waiting for Register 1
* [3] Started
* [1] Completed

## Registers
```json
[
{"id": 1, "busyByStation": 3, "busyByInst": 1, "v": 0},
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
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
]
```
---

# CICLE 5
## Log
* [5] Cannot be dispatched, waiting for a station to be free
* [2] Cannot start, it's waiting for Register 1
* [4] Cannot start, it's waiting for Register 3
* [1] Wrote in memory

## Registers
```json
[
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
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
* [5] Cannot be dispatched, waiting for a station to be free
* [2] Started
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 2, "v": 2},
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 6,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 7
## Log
* [5] Cannot be dispatched, waiting for a station to be free
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 2, "v": 2},
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 6,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 8
## Log
* [5] Cannot be dispatched, waiting for a station to be free
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 2, "v": 2},
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 6,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 9
## Log
* [5] Cannot be dispatched, waiting for a station to be free
* [2] Completed
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 2, "busyByStation": 0, "busyByInst": 2, "v": 0},
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 6,
        "finishedAt": 9,
        "writtenAt": 10
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 10
## Log
* [5] Cannot be dispatched, waiting for a station to be free
* [2] Wrote in memory
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 11
## Log
* [5] Dispatched
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 11,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 12
## Log
* [6] Dispatched
* [5] Started
* [4] Cannot start, it's waiting for Register 3
* [3] Completed

## Registers
```json
[
{"id": 3, "busyByStation": 2, "busyByInst": 3, "v": 0},
{"id": 5, "busyByStation": 0, "busyByInst": 5, "v": 5},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 11,
        "startedAt": 12,
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
    {"type": "MULTIPLIER (2)", "Instruction": {
        "operation": "MUL",
        "issuedAt": 3,
        "startedAt": 4,
        "finishedAt": 12,
        "writtenAt": 13
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 13
## Log
* [7] Dispatched
* [4] Cannot start, it's waiting for Register 3
* [3] Wrote in memory
* [6] Cannot start, it's waiting for Register 5

## Registers
```json
[
{"id": 5, "busyByStation": 0, "busyByInst": 5, "v": 5},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 11,
        "startedAt": 12,
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
        "issuedAt": 13,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 14
## Log
* [4] Started
* [7] Started
* [6] Cannot start, it's waiting for Register 5

## Registers
```json
[
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 4},
{"id": 5, "busyByStation": 0, "busyByInst": 5, "v": 5},
{"id": 31, "busyByStation": 3, "busyByInst": 7, "v": 31},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 11,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 14,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 13,
        "startedAt": 14,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 15
## Log
* [5] Completed
* [6] Cannot start, it's waiting for Register 5

## Registers
```json
[
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 4},
{"id": 5, "busyByStation": 0, "busyByInst": 5, "v": 4},
{"id": 31, "busyByStation": 3, "busyByInst": 7, "v": 31},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 11,
        "startedAt": 12,
        "finishedAt": 15,
        "writtenAt": 16
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 14,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 13,
        "startedAt": 14,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 16
## Log
* [5] Wrote in memory
* [7] Completed
* [6] Started

## Registers
```json
[
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 4},
{"id": 5, "busyByStation": 5, "busyByInst": 6, "v": 4},
{"id": 31, "busyByStation": 3, "busyByInst": 7, "v": 0},
]
```

## Stations
```json
[
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 14,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 13,
        "startedAt": 14,
        "finishedAt": 16,
        "writtenAt": 17
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": 16,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 17
## Log
* [4] Completed
* [7] Wrote in memory

## Registers
```json
[
{"id": 4, "busyByStation": 1, "busyByInst": 4, "v": 0},
{"id": 5, "busyByStation": 5, "busyByInst": 6, "v": 4},
]
```

## Stations
```json
[
    {"type": "ADDER (1)", "Instruction": {
        "operation": "SUB",
        "issuedAt": 4,
        "startedAt": 14,
        "finishedAt": 17,
        "writtenAt": 18
    }},
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": 16,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 18
## Log
* [4] Wrote in memory
* [6] Completed

## Registers
```json
[
{"id": 5, "busyByStation": 5, "busyByInst": 6, "v": 0},
]
```

## Stations
```json
[
    {"type": "STORE (5)", "Instruction": {
        "operation": "SW",
        "issuedAt": 12,
        "startedAt": 16,
        "finishedAt": 18,
        "writtenAt": 19
    }},
]
```
---

# CICLE 19
## Log
* [6] Wrote in memory

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


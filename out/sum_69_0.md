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
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
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
{"id": 1, "busyByStation": 0, "busyByInst": 1, "v": 1},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "ADD",
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
* [3] Cannot be dispatched, waiting for a station to be free
* [2] Started

## Registers
```json
[
{"id": 1, "busyByStation": 0, "busyByInst": 1, "v": 1},
{"id": 2, "busyByStation": 1, "busyByInst": 2, "v": 2},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 4
## Log
* [3] Cannot be dispatched, waiting for a station to be free

## Registers
```json
[
{"id": 1, "busyByStation": 0, "busyByInst": 1, "v": 1},
{"id": 2, "busyByStation": 1, "busyByInst": 2, "v": 2},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 5
## Log
* [3] Cannot be dispatched, waiting for a station to be free
* [1] Completed

## Registers
```json
[
{"id": 1, "busyByStation": 0, "busyByInst": 1, "v": 50},
{"id": 2, "busyByStation": 1, "busyByInst": 2, "v": 2},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 1,
        "startedAt": 2,
        "finishedAt": 5,
        "writtenAt": 6
    }},
    {"type": "ADDER (1)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 6
## Log
* [3] Cannot be dispatched, waiting for a station to be free
* [1] Wrote in memory
* [2] Completed

## Registers
```json
[
{"id": 2, "busyByStation": 1, "busyByInst": 2, "v": 19},
]
```

## Stations
```json
[
    {"type": "ADDER (1)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 2,
        "startedAt": 3,
        "finishedAt": 6,
        "writtenAt": 7
    }},
]
```
---

# CICLE 7
## Log
* [3] Dispatched
* [2] Wrote in memory

## Registers
```json
[
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
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
* [4] Dispatched
* [3] Started

## Registers
```json
[
{"id": 3, "busyByStation": 0, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
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
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 3, "busyByStation": 0, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 10
## Log
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 3, "busyByStation": 0, "busyByInst": 3, "v": 3},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": -1,
        "writtenAt": -1
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 11
## Log
* [3] Completed
* [4] Cannot start, it's waiting for Register 3

## Registers
```json
[
{"id": 3, "busyByStation": 0, "busyByInst": 3, "v": 69},
]
```

## Stations
```json
[
    {"type": "ADDER (0)", "Instruction": {
        "operation": "ADD",
        "issuedAt": 7,
        "startedAt": 8,
        "finishedAt": 11,
        "writtenAt": 12
    }},
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": -1,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 12
## Log
* [3] Wrote in memory
* [4] Started

## Registers
```json
[
{"id": 4, "busyByStation": 3, "busyByInst": 4, "v": 4},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 13
## Log

## Registers
```json
[
{"id": 4, "busyByStation": 3, "busyByInst": 4, "v": 4},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": 12,
        "finishedAt": -1,
        "writtenAt": -1
    }},
]
```
---

# CICLE 14
## Log
* [4] Completed

## Registers
```json
[
{"id": 4, "busyByStation": 3, "busyByInst": 4, "v": 69},
]
```

## Stations
```json
[
    {"type": "LOAD (3)", "Instruction": {
        "operation": "LW",
        "issuedAt": 8,
        "startedAt": 12,
        "finishedAt": 14,
        "writtenAt": 15
    }},
]
```
---

# CICLE 15
## Log
* [4] Wrote in memory

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


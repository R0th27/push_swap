# push_swap — Constrained Stack-Based Sorting in C

## Overview

`push_swap` is a constrained sorting program developed as part of the **42 Bangkok** curriculum.
The objective is to sort a list of integers using **two stacks** and a limited instruction set, while minimizing the number of operations.

This implementation emphasizes **algorithmic clarity**, **predictable data structures**, and **explicit memory ownership**, with a strict separation between instruction generation (`push_swap`) and instruction validation (`checker`).

---

## Project Structure

```bash
.
├── srcs/
│   ├── main/          # push_swap entry point and algorithm
│   ├── checker/       # checker entry point (stdin-driven)
│   ├── ops/           # stack operations (swap, push, rotate)
│   └── stacks/        # stack, indexing, input, and cleanup logic
├── include/
│   └── push_swap.h    # public API
├── libft/
├── Makefile
└── objs/
```

* `main/`
  Sorting algorithm logic and program entry for `push_swap`.

* `checker/`
  Reads instructions from standard input and validates final stack state.

* `ops/`
  Shared stack operations with silent/verbose execution control.

* `stacks/`
  Stack initialization, input parsing, indexing, and memory cleanup.

* `push_swap.h`
  Public interface shared between executables.

---

## Executables

### `push_swap`

* Generates a sequence of operations that sorts stack **A**
* Writes instructions to standard output
* Silent execution is disabled (instructions are printed)

### `checker`

* Reads instructions from standard input
* Executes operations silently
* Outputs:

  * `OK` if stack A is sorted and stack B is empty
  * `KO` otherwise
  * `Error` on invalid input or instruction

---

## Supported Operations

* `sa`, `sb`, `ss` — swap
* `pa`, `pb` — push
* `ra`, `rb`, `rr` — rotate
* `rra`, `rrb`, `rrr` — reverse rotate

All operations are implemented once and reused via a `silent` flag.

---

## Design Decisions

### Doubly Linked Stack Representation

Each stack is implemented as a **doubly linked list** with explicit metadata:

```c
typedef struct s_psstack
{
    t_psnode *top;
    t_psnode *bottom;
    int       size;
} t_psstack;
```

This allows:

* O(1) access to top and bottom
* Efficient rotate and reverse-rotate operations
* Explicit and verifiable pointer transitions

---

### Strict Input Validation

Input handling enforces:

* Numeric-only tokens
* Proper sign placement
* Overflow detection (`INT_MIN` / `INT_MAX`)
* Duplicate value rejection

Conversion is performed using a **strict custom atoi**, rejecting ambiguous or malformed input.

---

### Merge-Sort–Based Indexing

Before sorting, values are normalized by index:

* Node pointers are copied into an auxiliary array
* Merge sort is applied on pointer values (by `val`)
* Each node receives a unique index based on sorted order

This provides:

* Stable ordering
* Efficient duplicate detection
* Algorithm-independent value normalization

---

### Chunk-Based Sorting Strategy

The sorting algorithm operates in two phases:

#### Phase 1 — Push to Stack B

* Values are pushed from A to B in **index-based chunks**
* Lower indices are rotated to the bottom of B
* Chunk size adapts based on input size

This distributes values evenly while keeping future maximums accessible.

---

#### Phase 2 — Restore to Stack A

* The maximum indexed element in B is rotated to the top
* Elements are pushed back to A in descending order
* Final state results in A being fully sorted

This strategy balances simplicity and performance for medium to large inputs.

---

### Instruction Dispatcher (Checker)

Instructions read from standard input are:

* Trimmed and validated
* Compared using null-terminated `strncmp`
* Dispatched to the corresponding operation

Invalid instructions immediately trigger an error state.

---

### Memory Management Discipline

* No global variables
* All heap allocations are explicitly freed
* Stack nodes and auxiliary arrays are cleaned deterministically
* Tested with **Valgrind** (no leaks, no invalid access)

---

## Build & Usage

### Compilation

```bash
make
```

Builds:

* `push_swap`
* `checker`

---

### Example

```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

Expected output:

```text
OK
```

---

## Error Handling

* Invalid input → `Error`
* Duplicate values → `Error`
* Invalid instructions → `Error`
* Already sorted input → optimized early exit

All errors are handled deterministically without undefined behavior.

---

## Key Technical Skills

* Stack-based algorithm design
* Doubly linked list manipulation
* Merge sort implementation
* Input validation and overflow detection
* UNIX standard input/output pipelines
* Instruction parsing and dispatch
* Manual memory management in C
* Clean build system organization (Makefile)

---
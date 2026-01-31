# push_swap — Constrained Stack-Based Sorting in C

## Overview

`push_swap` is a constrained sorting program written in C, built around **explicit data structures**, **manual memory management**, and **algorithmic decision-making under tight operational limits**.

The program sorts a list of integers using only two stacks and a restricted instruction set.
Rather than relying on a single generic strategy, the implementation **adapts its approach based on input size**, combining specialized routines for small inputs with a scalable chunk-based algorithm for larger datasets.

The project also includes a standalone `checker` program that validates instruction sequences through standard input, enabling UNIX-style pipelines.

---

## Project Structure

```bash
.
├── srcs/
│   ├── main/          # sorting logic and push_swap entry
│   ├── checker/       # stdin-driven instruction validator
│   ├── ops/           # stack operations (swap, push, rotate)
│   └── stacks/        # stack, indexing, input, cleanup
├── include/
│   └── push_swap.h    # shared public interface
├── libft/
├── Makefile
└── objs/
```

Each directory corresponds to a **single responsibility**, keeping parsing, data representation, operations, and algorithms decoupled.

---

## Executables

### `push_swap`

* Generates a sequence of stack operations that sorts stack **A**
* Writes instructions to standard output
* Prioritizes correctness, predictability, and operation count

### `checker`

* Reads operations from standard input
* Executes them silently
* Verifies final stack state

Outputs:

* `OK` — sorted successfully
* `KO` — incorrect result
* `Error` — invalid input or instruction

---

## Performance Metrics

* **100 integers**

  * Max operations: **662**
  * Min operations: **534**
  * Average: **583**

* **500 integers**

  * Max operations: **5311**
  * Min operations: **4874**
  * Average: **5092**

Measured using randomized inputs with the chunk-based butterfly algorithm and small-sort optimization.

---

## Core Data Model

Stacks are implemented as **doubly linked lists** with explicit metadata:

```c
typedef struct s_psstack
{
    t_psnode *top;
    t_psnode *bottom;
    int       size;
} t_psstack;
```

This design:

* Allows constant-time access to both ends
* Simplifies rotate and reverse-rotate logic
* Makes pointer transitions explicit and auditable

---

## Input Handling Philosophy

Input parsing is intentionally strict:

* Numeric-only tokens
* Controlled sign handling
* Overflow detection (`INT_MIN` / `INT_MAX`)
* Duplicate rejection

All conversion is performed via a custom `atoi` implementation designed to **fail fast** on malformed input rather than attempting recovery.

---

## Value Normalization (Indexing)

Before sorting, values are normalized using **index compression**:

1. Stack nodes are copied into an auxiliary pointer array
2. The array is sorted using **merge sort**
3. Each node is assigned a unique index based on sorted order

Benefits:

* Removes dependency on raw integer magnitude
* Enables uniform comparison logic
* Makes the algorithm value-agnostic

---

## Sorting Strategy

The program selects its sorting strategy based on input size rather than forcing a one-size-fits-all solution.

---

### Specialized Sorting for Small Inputs (≤ 5)

Very small inputs are handled using **dedicated routines**:

* **2 elements** — conditional swap
* **3 elements** — minimal rotations and swaps
* **4–5 elements**

  * Push smallest values to stack B
  * Sort remaining stack A
  * Reinsert values in correct order

This avoids unnecessary abstraction and guarantees near-minimal operation counts.

---

### General Case — Chunk-Based (Butterfly-Style) Sorting

For larger inputs, the algorithm proceeds in two phases.

#### Phase 1 — Distribute to Stack B

* Values are pushed from A to B in index-based chunks
* Lower indices are rotated deeper into B
* Chunk size adapts to input size

This balances distribution while keeping higher values accessible.

---

#### Phase 2 — Reconstruct Stack A

* The maximum indexed element in B is located
* Stack B is rotated in the cheapest direction
* Elements are pushed back to A in descending order

This results in a fully sorted stack A without post-processing.

---

## Checker Design

The checker acts as a **pure instruction interpreter**:

* Reads from `stdin`
* Validates each instruction
* Dispatches via shared operation functions
* Terminates immediately on invalid input

This separation ensures that correctness validation is independent of instruction generation.

---

## Memory Management

* No global variables
* Clear ownership rules for every allocation
* Deterministic cleanup paths
* Verified with Valgrind (no leaks, no invalid accesses)

Memory safety is treated as a first-class concern.

---

## Build & Usage

```bash
make
```

Example:

```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

---

## Error Handling

* Non-numeric input → `Error`
* Integer overflow / underflow → `Error`
* Duplicate values → `Error`
* Invalid instructions (checker) → `Error`
* Memory allocation failure → immediate exit
* Already sorted input → early exit (no operations)
* Single-element input → handled without execution

All error cases are handled deterministically with no undefined behavior or memory leaks.

---

## Key Technical Skills

* Stack-based sorting algorithms
* Chunk-based (butterfly) strategy for large inputs
* Specialized small-input sorting (≤ 5 elements)
* Doubly linked list implementation
* Merge-sort–based indexing
* Strict input parsing and validation
* Instruction parsing and dispatch (stdin-driven)
* Manual memory management in C
* Pointer-heavy data structure manipulation
* Multi-target Makefile organization

---

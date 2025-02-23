# Push Swap

## Introduction

Push Swap is a sorting algorithm project from the 42 School curriculum. The goal is to sort a stack of integers using two stacks (`A` and `B`) and a set of predefined operations, with the least number of moves possible.

## Features

- Implements an efficient sorting algorithm using stack operations.
- Optimized to use the minimal number of operations for sorting.
- Handles edge cases such as duplicate numbers and already sorted lists.

## Compilation & Installation

To compile the project, use the following command:

```sh
make
```

This will generate the `push_swap` executable.

## Usage

Run the program with a list of space-separated integers:

```sh
./push_swap 4 67 3 87 23
```

It will output the necessary stack operations to sort the numbers in ascending order.

### Example Output

```sh
pb
ra
pb
sa
pa
pa
```

## Available Operations

- `sa` : Swap the first two elements of stack A.
- `sb` : Swap the first two elements of stack B.
- `ss` : Swap the first two elements of both stacks.
- `pa` : Push the top element of stack B onto stack A.
- `pb` : Push the top element of stack A onto stack B.
- `ra` : Rotate stack A upwards.
- `rb` : Rotate stack B upwards.
- `rr` : Rotate both stacks upwards.
- `rra` : Reverse rotate stack A.
- `rrb` : Reverse rotate stack B.
- `rrr` : Reverse rotate both stacks.

## Evaluation Criteria

- The program must produce the correct output for all valid inputs.
- The number of moves should be minimized for optimal efficiency.
- The program must handle errors properly (e.g., non-numeric input, duplicates).

## Error Handling

If an invalid input is provided (e.g., non-numeric characters, duplicates, or numbers outside the `int` range), the program should output an error message:

```sh
Error
```

## Bonus

The project may include a checker program (`checker`) that verifies if a given sequence of operations correctly sorts the stack.

To compile the checker:

```sh
make bonus
```

Usage:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

The checker outputs:

- `OK` if the sequence is correct.
- `KO` if the sequence does not sort the numbers properly.

## Resources

- [42 Project PDF](https://github.com/qst0/42cursus/tree/main/push_swap)
- [Sorting Algorithm Basics](https://en.wikipedia.org/wiki/Sorting_algorithm)

## Author

- GitHub: https\://github.com/moel-yag
- Email: [your.email@example.com](mailto\:your.email@example.com)


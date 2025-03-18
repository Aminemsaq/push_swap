# 🚀 push_swap Project: Implementing Radix Sort

## 📖 Table of Contents

- [📌 Project Overview](#-project-overview)
- [🧮 Radix Sort Algorithm](#-radix-sort-algorithm)
  - [🔢 Step 1: Indexing](#-step-1-indexing)
  - [🖥️ Step 2: Binary Representation](#-step-2-binary-representation)
  - [🔄 Step 3: Sorting Process](#-step-3-sorting-process)
- [📊 Performance Results](#-performance-results)
- [⚙️ Usage](#-usage)
- [🏁 Conclusion](#-conclusion)
- [⚠️ Limitations and Future Improvements](#-limitations-and-future-improvements)

## 📌 Project Overview

The `push_swap` project is a sorting algorithm challenge that requires sorting data using two stacks (`a` and `b`) with a predefined set of operations:

- 🔹 **sa**: Swap the first two elements of stack `a`.
- 🔹 **sb**: Swap the first two elements of stack `b`.
- 🔹 **ss**: Perform `sa` and `sb` simultaneously.
- 🔹 **pa**: Push the top element from stack `b` to stack `a`.
- 🔹 **pb**: Push the top element from stack `a` to stack `b`.
- 🔹 **ra**: Rotate stack `a` upwards (first element becomes the last).
- 🔹 **rb**: Rotate stack `b` upwards.
- 🔹 **rr**: Perform `ra` and `rb` simultaneously.
- 🔹 **rra**: Reverse rotate stack `a` (last element becomes the first).
- 🔹 **rrb**: Reverse rotate stack `b`.
- 🔹 **rrr**: Perform `rra` and `rrb` simultaneously.

The goal is to sort stack `a` using the fewest possible operations. Given the constraints, we implemented the **Radix Sort** algorithm, which is efficient for sorting integers and well-suited for this problem.

## 🧮 Radix Sort Algorithm

Radix Sort is a non-comparative sorting algorithm that processes numbers digit by digit, starting from the least significant digit to the most significant. In `push_swap`, we adapted Radix Sort to work with binary representations and two stacks.

### 🔢 Step 1: Indexing

To simplify sorting, we assign an index to each number based on its position in the sorted list. This process, known as coordinate compression, transforms the list into a sequence of integers starting from 0.

**Example:**

Original list: `[42, 7, 19, 84, 23, 3]`

Sorted list: `[3, 7, 19, 23, 42, 84]`

Indexing: `3→0, 7→1, 19→2, 23→3, 42→4, 84→5`

Transformed list: `[4, 1, 2, 5, 3, 0]`

### 🖥️ Step 2: Binary Representation

Next, we represent each indexed number in binary form. This allows us to process each bit individually during sorting.

**Example:**

```
4  → 100
1  → 001
2  → 010
5  → 101
3  → 011
0  → 000
```

### 🔄 Step 3: Sorting Process

We sort numbers by processing each bit from the least significant to the most significant:

- **For each bit position:**
  - If the bit is `0`, push the number to stack `b` (`pb`).
  - If the bit is `1`, rotate stack `a` (`ra`).
- After processing all numbers for the current bit, push all elements from stack `b` back to stack `a` (`pa`).

This process is repeated for each bit position until the entire list is sorted.

## 📊 Performance Results

| 📏 Number of Elements | ⚡ Maximum Operations |
|----------------------|------------------|
| 🎲 **3**            | **3**            |
| 🎲 **4**            | **7**            |
| 🎲 **5**            | **11**           |
| 🎲 **100**          | **1084**         |
| 🎲 **500**          | **6784**         |

## ⚙️ Usage

### 🛠️ Compilation

To compile the program, run:

```bash
make
```

### ▶️ Running the Program

To test the program with a set of numbers:

```bash
./push_swap 4 1 2 5 3 0
```

To check if the output is sorted:

```bash
./push_swap 4 1 2 5 3 0 | ./checker 4 1 2 5 3 0
```

To count the number of operations used:

```bash
./push_swap 4 1 2 5 3 0 | wc -l
```

## 🏁 Conclusion

By implementing the **Radix Sort** algorithm, we successfully optimized sorting operations within the constraints of the `push_swap` project. The use of bitwise operations and stack manipulation allowed us to achieve an efficient sorting process, ensuring that the number of moves remains minimal even for large datasets. 🚀🔥

## ⚠️ Limitations and Future Improvements

Although Radix Sort is an efficient approach for `push_swap`, it has some limitations:

- **Bitwise Processing**: While efficient, Radix Sort is not the most intuitive method for small datasets where a more direct sorting strategy (e.g., insertion sort) could be optimal.
- **Optimization**: Further optimizations can be made by reducing unnecessary rotations and improving the decision process for `pb` and `ra` operations.

### 🚀 Possible Enhancements

- Implementing hybrid sorting strategies for small sets (e.g., brute force for `N ≤ 5`).
- Using heuristics to minimize the number of operations further.
- Exploring alternative sorting methods like quicksort or mergesort adapted to stack constraints.

By refining these aspects, we can further optimize the `push_swap` project for better performance and efficiency. 🔥

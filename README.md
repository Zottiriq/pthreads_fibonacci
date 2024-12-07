# Multi-Threaded Fibonacci Calculator

This project demonstrates the use of **POSIX threads (pthread)** to calculate Fibonacci numbers up to a given value using multithreading. Each Fibonacci number in the sequence is calculated in a separate thread.

---

## Description

The program uses:
- **Threads** to calculate Fibonacci numbers concurrently.
- A recursive function `fib(int b)` to compute the Fibonacci sequence.
- Error handling for user input to ensure valid operation.

Each thread calculates one Fibonacci number in the sequence and prints the result to the console.

---

## How It Works

1. **Input Validation**: The program accepts a single command-line argument, which specifies the number up to which Fibonacci numbers will be calculated.
    - The input must be an integer greater than or equal to 1.

2. **Thread Creation**:
    - For each Fibonacci index from `0` to the user-provided value, a separate thread is created.
    - Each thread computes the Fibonacci value using the recursive `fib()` function.

3. **Thread Joining**:
    - After creating a thread, the program waits for it to complete using `pthread_join()`.

4. **Output**:
    - The program prints the Fibonacci sequence values to the console, separated by spaces.

---

## Compilation

To compile the program, use the following command:

```bash
gcc -pthread -o fibonacci_calculator main.c

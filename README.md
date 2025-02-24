# Parallelized Merge Sort

Using the power of multithreading and recursion to speed up Merge Sort.

Each thread will handle an independent chunk of the array without Mutex,we will spin more threads as we go down the recursion tree.

To avoid hitting the resource limit warning due to overspawning threadswe will use a threshold to switch to regular merge sort once the array is small enough.

### Test Environment
- Device: Macbook Pro 2024
- Chip: M4
- Cores: 14
- RAM: 24GB

### Performance Comparison

| Input Size | Sequential Time (ms) | Parallel Time (ms) |
|------------|---------------------|-------------------|
| 10^3       | 2                   | 0               |
| 10^4       | 21                  | 9               |
| 10^5       | 136                 | 19              |
| 10^6       | 1,151               | 165             |
| 10^7       | 14,428              | 2017            |


### Analysis:
The parallel implementation shows dramatic performance improvements, especially for larger datasets. With 14 cores available, the algorithm can process multiple segments simultaneously, leading to a ~7x speedup for arrays of size 10^7. The efficiency gains come from dividing the sorting workload across multiple threads, allowing independent sections to be sorted concurrently. The threshold of 5000 elements ensures we don't create too many threads for small arrays where the overhead would outweigh the benefits.
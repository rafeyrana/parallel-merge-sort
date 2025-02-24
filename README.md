# Parallelized Merge Sort

Using the power of multithreading and recursion to speed up Merge Sort.

Each thread will handle an independent chunk of the array without Mutex,we will spin more threads as we go down the recursion tree.

Once we hit the resource limit warning we make use of a thread pool to bottleneck thenumber of threads to not exceed the resources.

### Test Environment
- Device: Macbook Pro 2024
- Chip: M4
- Cores: 14
- RAM: 24GB

### Performance Comparison

| Input Size | Sequential Time (ms) | Parallel Time (ms) |
|------------|---------------------|-------------------|
| 10^3       | 2                   | TBD               |
| 10^4       | 21                  | TBD               |
| 10^5       | 118                 | TBD               |
| 10^6       | 1,151               | TBD               |
| 10^7       | 14,428              | TBD               |

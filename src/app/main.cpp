#include <iostream>
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"
int main(int argc, char *argv[]){
    srand(time(0));
   const int SIZE = 10000000;
   std::vector<int> nums(SIZE);
   std::vector<int> nums1(SIZE);

   // random number generator
   for (int i = 0; i < SIZE; ++i){
    nums[i] = rand() % SIZE;
    nums1[i] = nums[i];
   }

    MergeSort* mergeSort = new MergeSort(&nums);
    
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Merge Sort Duration: " << duration.count() << " milliseconds" << std::endl;
    delete mergeSort;



    ParallelMergeSort* parallelMergeSort = new ParallelMergeSort(&nums1);
    
    auto startParallel = std::chrono::high_resolution_clock::now();
    parallelMergeSort->sort();
    auto endParallel = std::chrono::high_resolution_clock::now();
    auto durationParallel = std::chrono::duration_cast<std::chrono::milliseconds>(endParallel - startParallel);
    
    std::cout << "Parallel Merge Sort Duration: " << durationParallel.count() << " milliseconds" << std::endl;
    delete parallelMergeSort;


   return 0;
}
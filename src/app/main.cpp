#include <iostream>
#include "sorting/mergeSort.hpp"

int main(int argc, char *argv[]){
    srand(time(0));
   const int SIZE = 1000000;
   std::vector<int> nums(SIZE);
   // random number generator
   for (int i = 0; i < SIZE; ++i){
    nums[i] = rand() % SIZE;
   }
  // print the array
  std::cout << "Original array: ";
  for (int i = 0; i < SIZE; ++i){
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
   MergeSort* mergeSort = new MergeSort(&nums);

   // benchmarking
   auto start = std::chrono::high_resolution_clock::now();
   mergeSort->sort();
   auto end = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

   std::cout << "Sorted array: ";
   for (int i = 0; i < SIZE; ++i){
    std::cout << nums[i] << " ";
   }
   std::cout << std::endl;

   std::cout << "Merge Sort Duration: " << duration.count() << " milliseconds" << std::endl;

   delete mergeSort; // oops dont want no memory leaks

   return 0;
}
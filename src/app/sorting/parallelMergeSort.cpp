#include "parallelMergeSort.hpp"
#include "mergeSort.hpp"
ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums)
    : nums(nums)
{
}

ParallelMergeSort::~ParallelMergeSort() {}


void ParallelMergeSort::recursiveSort(int left, int right){
    // threshold for when to use regular merge sort
    int THRESHOLD = 5000;
    if (right - left <= THRESHOLD){
        MergeSort mergeSort(nums);
        mergeSort.recursiveSort(left, right);
        return;
    }


    if (left >= right){
        return;
    }
    int mid = left + (right - left) / 2;

    // multithreading
    std::thread leftThread([this, left, mid] {this -> recursiveSort(left, mid); }); // passing this instance of the class to another thread using lambda function
    std::thread rightThread([this, mid, right] {this -> recursiveSort(mid + 1, right); });


    leftThread.join();
    rightThread.join();

    std::vector<int> result;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right){
        if((*nums)[i] <= (*nums)[j]){
            result.push_back((*nums)[i]);
            i++;
        }else{
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while(i <= mid){
        result.push_back((*nums)[i]);
        i++;
    }

    while(j <= right){
        result.push_back((*nums)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++){
        (*nums)[left + k] = result[k];
    }

    return;

}


void ParallelMergeSort::sort(){
    if((*nums).size() == 0){
        exit(1);
    }
    std::thread sortThread([this] {this -> recursiveSort(0, (*nums).size() - 1); });
    sortThread.join();
    return;
}
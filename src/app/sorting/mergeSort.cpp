#include "mergeSort.hpp"

MergeSort::MergeSort(std::vector<int> *nums){
    this->nums = nums;
}

MergeSort::~MergeSort(){}

void MergeSort::recursiveSort(int left, int right){
    // base case
    if (left >= right){
        return;
    }

    int mid = left + (right - left)/2; // to avoid overflow we will use this syntax over the (right + left) / 2

    recursiveSort(left, mid);
    recursiveSort(mid + 1, right);

    std::vector<int> result;

    int i = left;
    int j = mid + 1;

    // left and right iteration on the chunks of the original array as they have been sorted in place already because we passed the indexes not a copy of the array
    while(i <= mid && j <= right){
        if((*nums)[i] <= (*nums)[j]){
            result.push_back((*nums)[i]);
            i++;
        }else{
            result.push_back((*nums)[j]);
            j++;
        }
    }

    // if there are any remaining elements in the left chunk
    while(i <= mid){
        result.push_back((*nums)[i]);
        i++;
    }

    // if there are any remaining elements in the right chunk
    while(j <= right){
        result.push_back((*nums)[j]);
        j++;
    }

    // making sure we copy the sorted elements back into the original array
    for (int k = 0; k < result.size(); k++){
        (*nums)[left + k] = result[k];
    }

    return;
}

void MergeSort::sort(){
    if((*nums).size() == 0){
        exit(1);
    }
    int lengthOfArray = (*nums).size();
    recursiveSort(0, lengthOfArray - 1);
}
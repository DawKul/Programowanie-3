
#include "pch.h"
#include <vector>

class MergeSort {
public:
    static void sort(std::vector<int>& arr);
private:
    static void mergeSort(std::vector<int>& arr, int left, int right);
    static void merge(std::vector<int>& arr, int left, int mid, int right);
};



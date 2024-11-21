#include <iostream>
#include <vector>
#include "MergeSort.h"
#include "pch.h"

int main() {
    std::vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "Przed sortowaniem: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Wywołanie funkcji sortującej z klasy MergeSort
    MergeSort::sort(arr);

    std::cout << "Po sortowaniu: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

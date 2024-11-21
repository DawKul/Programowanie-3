#include "MergeSort.h"
#include "pch.h"

void MergeSort::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Rekurencyjne wywołanie dla lewej i prawej części
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Scalanie posortowanych części
        merge(arr, left, mid, right);
    }
}

void MergeSort::merge(std::vector<int>& arr, int left, int mid, int right) {
    // Obliczanie rozmiarów dwóch podtablic
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tworzymy tymczasowe tablice
    std::vector<int> leftArr(n1), rightArr(n2);

    // Kopiowanie danych do tymczasowych tablic
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Scalanie tablic
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów, jeśli istnieją
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Funkcja publiczna do uruchomienia algorytmu MergeSort
void MergeSort::sort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        mergeSort(arr, 0, arr.size() - 1);
    }
}

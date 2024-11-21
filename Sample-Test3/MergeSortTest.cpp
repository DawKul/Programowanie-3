#include "gtest/gtest.h"
#include "MergeSort.h"
#include "pch.h"

TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = { 1, 2, 3 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3}));
}

TEST(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = { 3, 2, 1 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3}));
}

TEST(MergeSortTest, MixedNumbers) {
    std::vector<int> arr = { -3, 5, 0, -1, 2 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3, -1, 0, 2, 5}));
}

TEST(MergeSortTest, EmptyArray) {
    std::vector<int> arr = {};
    MergeSort::sort(arr);
    EXPECT_EQ(arr, std::vector<int>{});
}

TEST(MergeSortTest, SingleElement) {
    std::vector<int> arr = { 1 };
    MergeSort::sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1}));
}

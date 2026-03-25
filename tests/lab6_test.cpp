#include <gtest/gtest.h>
#include "Sorts.h"
#include "RaceAnalyzer.h"
#include <vector>
#include <algorithm>

// =============================================================================
// Helper: verify a vector is sorted ascending
// =============================================================================
static void expect_sorted(const std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        EXPECT_LE(data[i - 1], data[i]) << "at index " << i;
    }
}

// =============================================================================
// Macro to generate sort tests (4 tests per sort = 24 total)
// =============================================================================
#define SORT_TESTS(SuiteName, sort_fn)                                        \
                                                                              \
TEST(SuiteName, BasicSort) {                                                  \
    std::vector<int> data = {5, 2, 8, 1, 4, 9, 3, 7, 6};                     \
    sort_fn(data);                                                            \
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}));          \
}                                                                             \
                                                                              \
TEST(SuiteName, EmptyAndSingle) {                                             \
    std::vector<int> empty = {};                                              \
    sort_fn(empty);                                                           \
    EXPECT_TRUE(empty.empty());                                               \
    std::vector<int> single = {42};                                           \
    sort_fn(single);                                                          \
    EXPECT_EQ(single, (std::vector<int>{42}));                                \
}                                                                             \
                                                                              \
TEST(SuiteName, AlreadySorted) {                                              \
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8};                        \
    sort_fn(data);                                                            \
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}));             \
}                                                                             \
                                                                              \
TEST(SuiteName, ReverseSortedAndDuplicates) {                                 \
    std::vector<int> rev = {9, 7, 5, 3, 1};                                  \
    sort_fn(rev);                                                             \
    EXPECT_EQ(rev, (std::vector<int>{1, 3, 5, 7, 9}));                       \
    std::vector<int> dups = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};                 \
    sort_fn(dups);                                                            \
    expect_sorted(dups);                                                      \
    EXPECT_EQ(dups.size(), 10u);                                              \
}

// --- Generate sort test suites ---
SORT_TESTS(BubbleSortTest, bubble_sort)
SORT_TESTS(InsertionSortTest, insertion_sort)
SORT_TESTS(SelectionSortTest, selection_sort)
SORT_TESTS(MergeSortTest, merge_sort)
SORT_TESTS(QuickSortTest, quick_sort)
SORT_TESTS(HeapSortTest, heap_sort)

// =============================================================================
// RaceAnalyzer: is_sorted_ascending
// =============================================================================

TEST(IsSortedTest, SortedVector) {
    EXPECT_TRUE(is_sorted_ascending({1, 2, 3, 4, 5}));
}

TEST(IsSortedTest, UnsortedVector) {
    EXPECT_FALSE(is_sorted_ascending({1, 3, 2, 4}));
}

TEST(IsSortedTest, EmptyAndSingle) {
    EXPECT_TRUE(is_sorted_ascending({}));
    EXPECT_TRUE(is_sorted_ascending({42}));
}

TEST(IsSortedTest, AllEqual) {
    EXPECT_TRUE(is_sorted_ascending({5, 5, 5, 5}));
}

// =============================================================================
// RaceAnalyzer: find_median
// =============================================================================

TEST(MedianTest, OddSize) {
    EXPECT_EQ(find_median({1, 3, 5, 7, 9}), 5);
}

TEST(MedianTest, EvenSize) {
    // Average of 3 and 5 = 4 (integer division)
    EXPECT_EQ(find_median({1, 3, 5, 7}), 4);
}

TEST(MedianTest, SingleElement) {
    EXPECT_EQ(find_median({42}), 42);
}

TEST(MedianTest, ThrowsOnEmpty) {
    EXPECT_THROW(find_median({}), std::runtime_error);
}

// =============================================================================
// RaceAnalyzer: remove_duplicates
// =============================================================================

TEST(RemoveDuplicatesTest, HasDuplicates) {
    auto result = remove_duplicates({1, 1, 2, 3, 3, 3, 4});
    EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4}));
}

TEST(RemoveDuplicatesTest, NoDuplicates) {
    auto result = remove_duplicates({1, 2, 3, 4, 5});
    EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(RemoveDuplicatesTest, AllSame) {
    auto result = remove_duplicates({7, 7, 7, 7});
    EXPECT_EQ(result, (std::vector<int>{7}));
}

TEST(RemoveDuplicatesTest, Empty) {
    auto result = remove_duplicates({});
    EXPECT_TRUE(result.empty());
}

// =============================================================================
// RaceAnalyzer: merge_sorted
// =============================================================================

TEST(MergeSortedTest, TwoNonEmpty) {
    auto result = merge_sorted({1, 3, 5}, {2, 4, 6});
    EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5, 6}));
}

TEST(MergeSortedTest, OneEmpty) {
    auto result = merge_sorted({1, 2, 3}, {});
    EXPECT_EQ(result, (std::vector<int>{1, 2, 3}));
    auto result2 = merge_sorted({}, {4, 5, 6});
    EXPECT_EQ(result2, (std::vector<int>{4, 5, 6}));
}

TEST(MergeSortedTest, BothEmpty) {
    auto result = merge_sorted({}, {});
    EXPECT_TRUE(result.empty());
}

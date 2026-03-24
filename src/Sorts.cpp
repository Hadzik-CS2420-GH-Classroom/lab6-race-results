#include "Sorts.h"
#include <iostream>
#include <algorithm>  // std::swap

// =============================================================================
// Lab 6: Sorting Algorithms — Race Results Manager
// =============================================================================
//
// Implement all six sorting algorithms below. Review your CT12 and CT13
// code if you get stuck, but try to write them from memory first.
//

// =============================================================================
// O(n^2) Quadratic Sorts
// =============================================================================

// ---------------------------------------------------------------------------
// TODO 1: bubble_sort (8 pts)
// ---------------------------------------------------------------------------
// Compare adjacent pairs, swap if out of order. Largest bubbles to end each pass.
// Include early exit: if a full pass makes no swaps, the array is already sorted.
// Time: O(n^2) avg/worst, O(n) best | Space: O(1) | Stable: Yes
//
void bubble_sort(std::vector<int>& data) {
    // TODO: Implement bubble sort with early exit
}

// ---------------------------------------------------------------------------
// TODO 2: insertion_sort (8 pts)
// ---------------------------------------------------------------------------
// Save the key, shift larger elements right, place key in the gap.
// Builds a sorted region from left to right.
// Time: O(n^2) avg/worst, O(n) best | Space: O(1) | Stable: Yes
//
void insertion_sort(std::vector<int>& data) {
    // TODO: Implement insertion sort
}

// ---------------------------------------------------------------------------
// TODO 3: selection_sort (8 pts)
// ---------------------------------------------------------------------------
// Find the minimum in the unsorted region, swap it to the front.
// Time: O(n^2) always | Space: O(1) | Stable: No
//
void selection_sort(std::vector<int>& data) {
    // TODO: Implement selection sort
}

// =============================================================================
// O(n log n) Efficient Sorts
// =============================================================================

// ---------------------------------------------------------------------------
// TODO 4: merge helper (10 pts)
// ---------------------------------------------------------------------------
// Merge two sorted halves: data[left..mid] and data[mid+1..right].
// Copy each half into temp vectors, then merge back using two pointers.
// This is where merge sort's O(n) extra space comes from.
//
static void merge(std::vector<int>& data, int left, int mid, int right) {
    // TODO: Implement the merge step
}

// ---------------------------------------------------------------------------
// TODO 5: merge_sort_recursive + public wrapper (11 pts)
// ---------------------------------------------------------------------------
// Base case: 0 or 1 elements (left >= right).
// Recursive case: find mid, sort left half, sort right half, merge.
//
static void merge_sort_recursive(std::vector<int>& data, int left, int right) {
    // TODO: Implement recursive merge sort
}

void merge_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    merge_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

// ---------------------------------------------------------------------------
// TODO 6: partition helper (10 pts)
// ---------------------------------------------------------------------------
// Use median-of-three to pick a good pivot, then partition:
// elements <= pivot go left, elements > pivot go right.
// Return the pivot's final index.
//
static int partition(std::vector<int>& data, int low, int high) {
    // TODO: Implement partition with median-of-three pivot
    return low;  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 7: quick_sort_recursive + public wrapper (10 pts)
// ---------------------------------------------------------------------------
// Base case: low >= high.
// Partition, then recursively sort left and right sides.
//
static void quick_sort_recursive(std::vector<int>& data, int low, int high) {
    // TODO: Implement recursive quick sort
}

void quick_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    quick_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

// ---------------------------------------------------------------------------
// TODO 8: heapify_down helper (8 pts)
// ---------------------------------------------------------------------------
// Restore max-heap property from index downward.
// Compare with left (2i+1) and right (2i+2) children.
// Swap with the largest child and recurse if needed.
//
static void heapify_down(std::vector<int>& data, int heap_size, int index) {
    // TODO: Implement heapify_down
}

// ---------------------------------------------------------------------------
// TODO 9: heap_sort (7 pts)
// ---------------------------------------------------------------------------
// Phase 1: Build max-heap (heapify_down on every non-leaf, from n/2-1 to 0).
// Phase 2: Extract max repeatedly (swap root with last, shrink heap, heapify).
// Time: O(n log n) always | Space: O(1) | Stable: No
//
void heap_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    if (n <= 1) return;

    // TODO Phase 1: Build max-heap

    // TODO Phase 2: Extract max repeatedly
}

// ---------------------------------------------------------------------------
// Utility: print a vector
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) std::cout << label;
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(data.size()); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]\n";
}

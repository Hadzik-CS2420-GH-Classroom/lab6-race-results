#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <string>

// =============================================================================
// Lab 6: Sorting Algorithms — Race Results Manager
// =============================================================================
//
// Six sorting algorithms from CT12 (quadratic) and CT13 (efficient).
// All take std::vector<int>& and sort in ascending order, in-place.
//
// Review your CT12 and CT13 implementations — this lab has you rebuild
// them independently with only brief comments as guidance.
// =============================================================================

// --- O(n^2) Quadratic Sorts (CT12) ---

void bubble_sort(std::vector<int>& data);
void insertion_sort(std::vector<int>& data);
void selection_sort(std::vector<int>& data);

// --- O(n log n) Efficient Sorts (CT13) ---

void merge_sort(std::vector<int>& data);
void quick_sort(std::vector<int>& data);
void heap_sort(std::vector<int>& data);

// --- Utility ---

void print_vector(const std::vector<int>& data, const std::string& label = "");

#endif // SORTS_H

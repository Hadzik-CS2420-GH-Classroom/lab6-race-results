#ifndef RACE_ANALYZER_H
#define RACE_ANALYZER_H

#include <vector>
#include <string>
#include <stdexcept>

// =============================================================================
// Lab 6: Race Analyzer — Utility functions that operate on sorted data
// =============================================================================
//
// These functions demonstrate WHY sorting matters: once data is sorted,
// many useful operations become fast and simple.
//
// All functions assume the input is already sorted in ascending order
// unless otherwise noted.
// =============================================================================

// Returns true if data is sorted in ascending order (non-decreasing).
// An empty vector or single-element vector is considered sorted.
bool is_sorted_ascending(const std::vector<int>& data);

// Binary search on a sorted vector.
// Returns the index of target, or -1 if not found.
// Must use the divide-and-conquer approach (not linear scan).
int binary_search(const std::vector<int>& data, int target);

// Returns the median value of a sorted vector.
// Odd size: return the middle element.
// Even size: return the average of the two middle elements (integer division).
// Throws std::runtime_error if the vector is empty.
int find_median(const std::vector<int>& data);

// Returns a new vector with consecutive duplicates removed from sorted input.
// The original vector is not modified.
// Example: {1, 1, 2, 3, 3, 3} -> {1, 2, 3}
std::vector<int> remove_duplicates(const std::vector<int>& data);

// Merges two already-sorted vectors into one sorted vector.
// This is the merge step from merge sort, but as a standalone utility.
// Neither input vector is modified.
std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b);

// Returns the value at the given percentile (0-100) of a sorted vector.
// Uses nearest-rank method: index = ceil(percentile / 100.0 * n) - 1
// Throws std::runtime_error if empty or percentile is out of [0, 100] range.
int percentile(const std::vector<int>& data, int p);

#endif // RACE_ANALYZER_H

#include "RaceAnalyzer.h"
#include <cmath>  // std::ceil

// =============================================================================
// Lab 6: Race Analyzer — Utility functions on sorted data
// =============================================================================
//
// These functions demonstrate the practical payoff of sorting:
// binary search, median, deduplication, merging, and percentile
// all become fast and simple once the data is in order.
//

// ---------------------------------------------------------------------------
// TODO 10: is_sorted_ascending (5 pts)
// ---------------------------------------------------------------------------
// Walk through the vector and check that each element is <= the next.
// Empty and single-element vectors are considered sorted.
//
bool is_sorted_ascending(const std::vector<int>& data) {
    // TODO: Implement
    return false;  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 11: binary_search (10 pts)
// ---------------------------------------------------------------------------
// Use divide-and-conquer (not linear scan) to find target in sorted data.
// Maintain low and high indices. Compare target to the midpoint:
//   - equal: found it, return mid
//   - target < mid: search left half
//   - target > mid: search right half
// Return -1 if not found.
//
int binary_search(const std::vector<int>& data, int target) {
    // TODO: Implement binary search
    return -1;  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 12: find_median (5 pts)
// ---------------------------------------------------------------------------
// Odd size: return the middle element.
// Even size: return the average of the two middle elements (integer division).
// Throw std::runtime_error("empty vector") if empty.
//
int find_median(const std::vector<int>& data) {
    // TODO: Implement
    return 0;  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 13: remove_duplicates (10 pts)
// ---------------------------------------------------------------------------
// Build and return a new vector containing only unique values from the
// sorted input. Since the input is sorted, duplicates are always adjacent.
// The original vector is not modified.
//
std::vector<int> remove_duplicates(const std::vector<int>& data) {
    // TODO: Implement
    return {};  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 14: merge_sorted (10 pts)
// ---------------------------------------------------------------------------
// Merge two already-sorted vectors into one sorted vector using the
// two-pointer technique. This is the same merge logic from merge sort,
// but as a standalone utility.
//
std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b) {
    // TODO: Implement
    return {};  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 15: percentile (10 pts)
// ---------------------------------------------------------------------------
// Return the value at the given percentile (0-100) using nearest-rank:
//   index = ceil(p / 100.0 * n) - 1
// Throw std::runtime_error("empty vector") if empty.
// Throw std::runtime_error("percentile out of range") if p < 0 or p > 100.
//
int percentile(const std::vector<int>& data, int p) {
    // TODO: Implement
    return 0;  // placeholder
}

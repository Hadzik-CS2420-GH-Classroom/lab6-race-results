#include "RaceAnalyzer.h"

// =============================================================================
// Lab 6: Race Analyzer -- Utility functions on sorted data
// =============================================================================
//
// These functions demonstrate the practical payoff of sorting:
// median, deduplication, and merging all become fast and simple
// once the data is in order.
//

// ---------------------------------------------------------------------------
// TODO 10: is_sorted_ascending (6 pts)
// ---------------------------------------------------------------------------
// Walk through the vector and check that each element is <= the next.
// Empty and single-element vectors are considered sorted.
//
bool is_sorted_ascending(const std::vector<int>& data) {
    // TODO: Implement
    return false;  // placeholder
}

// ---------------------------------------------------------------------------
// TODO 11: find_median (8 pts)
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
// TODO 12: remove_duplicates (10 pts)
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
// TODO 13: merge_sorted (14 pts)
// ---------------------------------------------------------------------------
// Merge two already-sorted vectors into one sorted vector using the
// two-pointer technique. This is the same merge logic from merge sort,
// but as a standalone utility.
//
std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b) {
    // TODO: Implement
    return {};  // placeholder
}

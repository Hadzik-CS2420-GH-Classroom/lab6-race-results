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
bool is_sorted_ascending(const std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

// ---------------------------------------------------------------------------
// TODO 11: find_median (8 pts)
// ---------------------------------------------------------------------------
int find_median(const std::vector<int>& data) {
    if (data.empty()) throw std::runtime_error("empty vector");
    int n = static_cast<int>(data.size());
    if (n % 2 == 1) return data[n / 2];
    return (data[n / 2 - 1] + data[n / 2]) / 2;
}

// ---------------------------------------------------------------------------
// TODO 12: remove_duplicates (10 pts)
// ---------------------------------------------------------------------------
std::vector<int> remove_duplicates(const std::vector<int>& data) {
    if (data.empty()) return {};
    std::vector<int> result;
    result.push_back(data[0]);
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] != data[i - 1]) result.push_back(data[i]);
    }
    return result;
}

// ---------------------------------------------------------------------------
// TODO 13: merge_sorted (14 pts)
// ---------------------------------------------------------------------------
std::vector<int> merge_sorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    result.reserve(a.size() + b.size());
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

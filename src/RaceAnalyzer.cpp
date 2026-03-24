#include "RaceAnalyzer.h"
#include <cmath>

bool is_sorted_ascending(const std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

int binary_search(const std::vector<int>& data, int target) {
    int low = 0, high = static_cast<int>(data.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid] == target) return mid;
        else if (data[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int find_median(const std::vector<int>& data) {
    if (data.empty()) throw std::runtime_error("empty vector");
    int n = static_cast<int>(data.size());
    if (n % 2 == 1) return data[n / 2];
    return (data[n / 2 - 1] + data[n / 2]) / 2;
}

std::vector<int> remove_duplicates(const std::vector<int>& data) {
    if (data.empty()) return {};
    std::vector<int> result;
    result.push_back(data[0]);
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] != data[i - 1]) result.push_back(data[i]);
    }
    return result;
}

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

int percentile(const std::vector<int>& data, int p) {
    if (data.empty()) throw std::runtime_error("empty vector");
    if (p < 0 || p > 100) throw std::runtime_error("percentile out of range");
    int n = static_cast<int>(data.size());
    int index = static_cast<int>(std::ceil(p / 100.0 * n)) - 1;
    if (index < 0) index = 0;
    return data[index];
}

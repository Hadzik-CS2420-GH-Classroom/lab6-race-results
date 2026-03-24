#include "Sorts.h"
#include <iostream>
#include <algorithm>

// =============================================================================
// O(n^2) Quadratic Sorts
// =============================================================================

void bubble_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertion_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

void selection_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[min_idx]) min_idx = j;
        }
        if (min_idx != i) std::swap(data[i], data[min_idx]);
    }
}

// =============================================================================
// O(n log n) Efficient Sorts
// =============================================================================

static void merge(std::vector<int>& data, int left, int mid, int right) {
    std::vector<int> left_half(data.begin() + left, data.begin() + mid + 1);
    std::vector<int> right_half(data.begin() + mid + 1, data.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < static_cast<int>(left_half.size()) && j < static_cast<int>(right_half.size())) {
        if (left_half[i] <= right_half[j]) data[k++] = left_half[i++];
        else data[k++] = right_half[j++];
    }
    while (i < static_cast<int>(left_half.size())) data[k++] = left_half[i++];
    while (j < static_cast<int>(right_half.size())) data[k++] = right_half[j++];
}

static void merge_sort_recursive(std::vector<int>& data, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort_recursive(data, left, mid);
    merge_sort_recursive(data, mid + 1, right);
    merge(data, left, mid, right);
}

void merge_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    merge_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

static int partition(std::vector<int>& data, int low, int high) {
    int mid = low + (high - low) / 2;
    if (data[mid] < data[low]) std::swap(data[low], data[mid]);
    if (data[high] < data[low]) std::swap(data[low], data[high]);
    if (data[mid] < data[high]) std::swap(data[mid], data[high]);
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

static void quick_sort_recursive(std::vector<int>& data, int low, int high) {
    if (low >= high) return;
    int pivot_idx = partition(data, low, high);
    quick_sort_recursive(data, low, pivot_idx - 1);
    quick_sort_recursive(data, pivot_idx + 1, high);
}

void quick_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    quick_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

static void heapify_down(std::vector<int>& data, int heap_size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap_size && data[left] > data[largest]) largest = left;
    if (right < heap_size && data[right] > data[largest]) largest = right;
    if (largest != index) {
        std::swap(data[index], data[largest]);
        heapify_down(data, heap_size, largest);
    }
}

void heap_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    if (n <= 1) return;
    for (int i = n / 2 - 1; i >= 0; --i) heapify_down(data, n, i);
    for (int i = n - 1; i > 0; --i) {
        std::swap(data[0], data[i]);
        heapify_down(data, i, 0);
    }
}

void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) std::cout << label;
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(data.size()); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]
";
}

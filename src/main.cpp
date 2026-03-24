#include "Sorts.h"
#include "RaceAnalyzer.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "=== Lab 6: Race Results Manager ===\n\n";

    // --- Part 1: Sorting Race Times ---
    std::vector<int> heat1 = {342, 298, 415, 301, 356, 278, 390, 310, 425, 288};

    std::cout << "--- Part 1: Sorting Race Times ---\n";
    print_vector(heat1, "Unsorted heat 1 (seconds): ");

    std::vector<int> copy = heat1;
    merge_sort(copy);
    print_vector(copy, "Sorted with merge sort:    ");
    std::cout << "\n";

    // --- Part 2: Analyzing Results ---
    std::cout << "--- Part 2: Analyzing Sorted Results ---\n";
    std::cout << "Is sorted? " << (is_sorted_ascending(copy) ? "true" : "false") << "\n";
    std::cout << "Median time: " << find_median(copy) << " seconds\n";
    std::cout << "25th percentile: " << percentile(copy, 25) << " seconds\n";
    std::cout << "75th percentile: " << percentile(copy, 75) << " seconds\n";

    int target = 356;
    int idx = binary_search(copy, target);
    if (idx >= 0) {
        std::cout << "Binary search for " << target << ": found at index " << idx << "\n";
    } else {
        std::cout << "Binary search for " << target << ": not found\n";
    }

    std::vector<int> unique = remove_duplicates(copy);
    print_vector(unique, "Unique times:              ");
    std::cout << "\n";

    // --- Part 3: Merging Two Race Heats ---
    std::cout << "--- Part 3: Merging Race Heats ---\n";
    std::vector<int> heat2 = {275, 310, 330, 400, 450};
    std::sort(heat2.begin(), heat2.end());  // ensure sorted

    std::vector<int> sorted_heat1 = copy;
    print_vector(sorted_heat1, "Heat 1 (sorted): ");
    print_vector(heat2, "Heat 2 (sorted): ");

    std::vector<int> combined = merge_sorted(sorted_heat1, heat2);
    print_vector(combined, "Merged results:  ");
    std::cout << "\n";

    // --- Part 4: All Sorts Demo ---
    std::cout << "--- Part 4: All Sorts Demo ---\n";
    std::vector<int> demo = {5, 2, 8, 1, 4, 9, 3, 7, 6};

    auto run_sort = [&](const std::string& name, void(*sort_fn)(std::vector<int>&)) {
        std::vector<int> d = demo;
        sort_fn(d);
        print_vector(d, name + ": ");
    };

    run_sort("Bubble sort   ", bubble_sort);
    run_sort("Insertion sort", insertion_sort);
    run_sort("Selection sort", selection_sort);
    run_sort("Merge sort    ", merge_sort);
    run_sort("Quick sort    ", quick_sort);
    run_sort("Heap sort     ", heap_sort);

    std::cout << "\n=== Lab 6 Complete ===\n";
    return 0;
}

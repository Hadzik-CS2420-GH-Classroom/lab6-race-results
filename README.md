# Lab 6: Race Results Manager

## Overview

A local running club needs software to sort and analyze 5K race finish times. You will implement all six sorting algorithms from CT12 and CT13, then build utility functions that demonstrate why sorting matters — binary search, median, percentile, deduplication, and merging race heats.

## Learning Objectives

By completing this lab, you will:

- Independently implement bubble, insertion, and selection sort (O(n^2))
- Independently implement merge, quick, and heap sort (O(n log n))
- Implement binary search on sorted data (O(log n))
- Build practical utilities that operate on sorted vectors
- Reinforce understanding of when and why each algorithm is used

## Project Structure

```
lab6-race-results/
  include/
    Sorts.h              <- sort function declarations (do not modify)
    RaceAnalyzer.h       <- analyzer function declarations (do not modify)
  src/
    Sorts.cpp            <- TODOs 1-9: implement all six sorts
    RaceAnalyzer.cpp     <- TODOs 10-15: implement analysis utilities
    main.cpp             <- demo driver (do not modify)
  tests/
    lab6_test.cpp        <- Google Test suite (do not modify)
  CMakeLists.txt
```

## What You'll Do

**Part 1 (Sorts.cpp):** Re-implement all six sorting algorithms from CT12 and CT13. The TODO stubs have brief descriptions — review your CT code if needed, but try from memory first.

**Part 2 (RaceAnalyzer.cpp):** Implement utility functions that work on sorted data. These are new — they weren't in any CT.

## Grading (130 points)

| TODO | Function | Points |
|------|----------|--------|
| 1 | `bubble_sort` | 8 |
| 2 | `insertion_sort` | 8 |
| 3 | `selection_sort` | 8 |
| 4 | `merge` helper | 10 |
| 5 | `merge_sort_recursive` + wrapper | 11 |
| 6 | `partition` helper | 10 |
| 7 | `quick_sort_recursive` + wrapper | 10 |
| 8 | `heapify_down` helper | 8 |
| 9 | `heap_sort` | 7 |
| 10 | `is_sorted_ascending` | 5 |
| 11 | `binary_search` | 10 |
| 12 | `find_median` | 5 |
| 13 | `remove_duplicates` | 10 |
| 14 | `merge_sorted` | 10 |
| 15 | `percentile` | 10 |
| | **Total** | **130** |

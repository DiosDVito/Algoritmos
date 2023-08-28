# NOTES

## Running Time for Insertion Sort

Calculating the exact running time of an insertion sort algorithm can involve analyzing its worst-case, best-case, and average-case scenarios. The running time can be influenced by factors such as the input size, the initial order of elements, and the specific implementation of the algorithm.

Insertion sort is a simple sorting algorithm that works by iteratively inserting elements from an unsorted portion of the array into their correct positions within a sorted portion of the array.

1. **Worst-Case Scenario:**
   In the worst-case scenario, the array is sorted in reverse order. For each element in the unsorted portion of the array, insertion sort will need to compare it with all previous elements in the sorted portion before finding its correct position. This results in roughly \(O(n^2)\) comparisons and swaps, where \(n\) is the number of elements in the array.

2. **Best-Case Scenario:**
   In the best-case scenario, the array is already sorted. In this case, insertion sort only needs to compare each element with the previous element until it finds an element that is smaller. This results in \(O(n)\) comparisons and no swaps.

3. **Average-Case Scenario:**
   The average-case time complexity of insertion sort is also \(O(n^2)\) due to the nature of its algorithm. On average, each element will need to be compared with approximately half of the sorted elements, resulting in \(O(n^2)\) total comparisons.

When calculating the running time, it's essential to consider the number of comparisons and swaps performed by the algorithm. While insertion sort's worst-case and average-case time complexities are the same (\(O(n^2)\)), in practice, it tends to perform better on small arrays or partially sorted arrays due to its efficient nature for small inputs.



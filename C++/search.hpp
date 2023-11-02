/**
 * @brief Linear Search
 * 
 * @tparam T Data type
 * @param arr Array of type T
 * @param n Size of the array
 * @param target Target element to search for
 * @return Index of the target element if found, -1 if not found
*/
template <typename T>
int linear_search(T arr[], int n, T target) {
    for (int i = 0; i < n; i++) if (arr[i] == target) return i;
    return -1;
}

/**
 * @brief Binary Search
 * 
 * @tparam T Data type
 * @param arr Sorted array of type T
 * @param left Left index of the search range
 * @param right Right index of the search range
 * @param target Target element to search for
 * @return Index of the target element if found, -1 if not found
*/
template <typename T>
int binary_search(T arr[], int left, int right, T target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

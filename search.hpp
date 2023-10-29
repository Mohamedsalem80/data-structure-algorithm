/**
 * @brief Linear Search
 * @attention best: n | average: n | worst: n
 * 
 * @tparam T 
 * @param arr array T pointer
 * @param n int
 * @param target T
 * @return int
 */
template <typename T>
int linearSearch(T arr[], int n, T target) {
    for (int i = 0; i < n; i++) if (arr[i] == target) return i;
    return -1;
}

/**
 * @brief Binary Search
 * 
 * @tparam T 
 * @param arr array T pointer
 * @param left int
 * @param right int
 * @param target T
 * @return int
 */
template <typename T>
int binarySearch(T arr[], int left, int right, T target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

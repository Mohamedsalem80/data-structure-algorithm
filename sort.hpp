/**
 * @brief Bubble Sort 
 * @attention
 * 
 * @tparam T
 * @param arr array template pointer
 * @param size int
 */
template <typename T>
void bubble_sort(T arr[], int size) {
    T temp;
    int sort = 1;
    for (int i = 0; i < size; i++) {
        sort = 1;
        for (int j = 1; j < (size - i); j++) {
            if (arr[j] < arr[j - 1]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                sort = 0;
            }
        }
        if (sort)
            break;
    }
}

/**
 * @brief Selection Sort
 * @attention best: n^2 | average: n^2 | worst: n^2
 * 
 * @tparam T 
 * @param arr array template pointer
 * @param size int
 */
template <typename T>
void selection_sort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

/**
 * @brief Insertion Sort
 * @attention best: n | average: n^2 | worst: n^2
 * 
 * @tparam T 
 * @param arr array template pointer
 * @param size int
 */
template <typename T>
void insertion_sort(T arr[], int size) {
    for (int i = 1; i < size; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Merge Sort Helper
 * @tparam T 
 * 
 * @param arr array template pointer
 * @param l int
 * @param m int
 * @param r int
 */
template <typename T>
void merge(T arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1];
    T R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Merge Sort
 * @attention best: nlog(n) | average: nlog(n) | worst: nlog(n)
 * 
 * @tparam T 
 * @param arr array template pointer
 * @param l int
 * @param r int
 */
template <typename T>
void merge_sort(T arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * @brief Quick Sort partitioner
 * 
 * @tparam T 
 * @param arr array pointer
 * @param low int
 * @param high int
 * @return int
 */
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    T temp_ = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp_;
    return (i + 1);
}

/**
 * @brief Quick Sort
 * @details Quick Sort Using Two Arrays
 * @attention best: nlog(n) | average: nlog(n) | worst: n^2
 * 
 * @tparam T 
 * @param arr array template pointer
 * @param low int
 * @param high int
 */
template <typename T>
void quick_sort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}
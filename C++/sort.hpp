/**
 * @brief Bubble Sort
 * @attention best: n | average: n^2 | worst: n^2.
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param size The size of the array.
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
 * @attention best: n^2 | average: n^2 | worst: n^2.
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param size The size of the array.
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
 * @attention best: n | average: n^2 | worst: n^2.
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param size The size of the array.
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
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param l Index of the left subarray.
 * @param m Index of the middle element.
 * @param r Index of the right subarray.
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
 * @attention best: nlog(n) | average: nlog(n) | worst: nlog(n).
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param l Index of the left subarray.
 * @param r Index of the right subarray.
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
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param low Index of the lower boundary.
 * @param high Index of the upper boundary.
 * @return Index of the pivot element.
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
 * @details This function sorts an array using another.
 * @attention best: nlog(n) | average: nlog(n) | worst: n^2.
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param low Index of the lower boundary.
 * @param high Index of the upper boundary.
 */
template <typename T>
void quick_sort(T arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Hypird Sorting
/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Shell Sort
 * @attention best: nlog(n) | average: nlog(n) | worst: n^2.
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param size The size of the array.
 */
template<typename T>
void shellSort(T arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

/**
 * @brief Tim Sort
 * @attention best: n | average: nlog(n) | worst: nlog(n).
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param size The size of the array.
 */
template <typename T>
void tim_sort(T arr[], int size) {
    const int minRun = 32;

    for (int i = 0; i < size; i += minRun) insertion_sort(arr + i, std::min(minRun, size - i));

    for (int run = minRun; run < size; run = 2 * run) {
        for (int start = 0; start < size; start += 2 * run) {
            int mid = std::min(start + run, size);
            int end = std::min(start + 2 * run, size);
            if (mid < end) {
                merge_sort(arr + start, mid - start, end - start - 1);
            }
        }
    }
}


/**
 * @brief Bucket Sort
 * @attention best: n | average: k+n | worst: n^2.
 * 
 * @tparam T The data type of the array.
 * @param arr Pointer to the array to be sorted.
 * @param size The size of the array.
 */
template <typename T>
void bucketSort(T arr[], int size) {
    if (size <= 1) return; 
    T maxVal = arr[0];
    T minVal = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        else minVal = arr[i];
    }

    int bucketRange = (maxVal - minVal) / size + 1;

    int** buckets = new int*[size];
    for (int i = 0; i < size; i++) buckets[i] = new int[size];

    int bucketSizes[size] = {0};

    for (int i = 0; i < size; i++) {
        int index = (arr[i] - minVal) / bucketRange;
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    for (int i = 0; i < size; i++) insertionSort(buckets[i], bucketSizes[i]);

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < bucketSizes[i]; j++)
            arr[index++] = buckets[i][j];

    for (int i = 0; i < size; i++) delete[] buckets[i];
    delete[] buckets;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// Special Case Sorting
/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Radix Count (Radix Sort) Helper
 * 
 * @param arr Pointer to the array to be sorted.
 * @param n The size of the array.
 * @param exp The exponent for the radix sort.
 */
void radix_count(long long arr[], int n, long exp) {
    const int RANGE = 10;
    long long output[n];
    int count[RANGE] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % RANGE]++;
    for (int i = 1; i < RANGE; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % RANGE] - 1] = arr[i];
        count[(arr[i] / exp) % RANGE]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

/**
 * @brief Radix Sort
 * @attention best: kn | average: kn | worst: kn.
 * 
 * @param arr Pointer to the array to be sorted.
 * @param n The size of the array.
 */
void radix_sort(long long arr[], int n) {
    long long max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    for (long exp = 1; max / exp > 0; exp *= 10) radix_count(arr, n, exp);
}
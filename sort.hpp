/**
 * @brief Bubble Sort 
 * @attention best: n | average: n^2 | worst: n^2
 * 
 * @param arr array pointer
 * @param size int
 */
void bubble_sort(int * arr, int size){
    int temp, sort = 1;
    for (int i = 0; i < size; i++){
        sort = 1;
        for (int j = 1; j < (size-i); j++){
            if (arr[j] < arr[j-1]){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                sort = 0;
            }
        }
        if (sort) break;
    }
}

/**
 * @brief Selection Sort
 * @attention best: n^2 | average: n^2 | worst: n^2
 * 
 * @param arr array pointer
 * @param size int
 */
void selection_sort(int * arr, int size){
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) if (arr[j] < arr[minIndex]) minIndex = j;
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

/**
 * @brief Insertion Sort
 * @attention best: n | average: n^2 | worst: n^2
 * 
 * @param arr array pointer
 * @param size int
 */
void insertion_sort(int * arr, int size){
    for (int i = 1; i < size; i++) {
        int key = arr[i], j = i - 1;
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
 * @param arr array pointer
 * @param l int
 * @param m int
 * @param r int
 */
void merge(int * arr, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

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
		}
		else {
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
 * @param arr array pointer
 * @param l int
 * @param r int
 */
void merge_sort(int * arr, int l, int r){
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
 * @param arr array pointer
 * @param low int
 * @param high int
 * @return int 
 */
int partition(int * arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp_ = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp_;
    return (i + 1);
}

/**
 * @brief Quick Sort
 * @details Quick Sort Using Two Arrays
 * @attention best: nlog(n) | average: nlog(n) | worst: n^2
 * 
 * @param arr array pointer
 * @param low int
 * @param high int
 */
void quick_sort(int * arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}
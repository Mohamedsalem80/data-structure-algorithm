public class Sort {

    /**
     * Bubble Sort
     *
     * @param arr   Array to be sorted
     * @param <T>   Type of elements in the array
     */
    public static <T extends Comparable<T>> void bubbleSort(T[] arr) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }

    /**
     * Selection Sort
     *
     * @param arr   Array to be sorted
     * @param <T>   Type of elements in the array
     */
    public static <T extends Comparable<T>> void selectionSort(T[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j].compareTo(arr[minIndex]) < 0) {
                    minIndex = j;
                }
            }
            T temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }

    /**
     * Insertion Sort
     *
     * @param arr   Array to be sorted
     * @param <T>   Type of elements in the array
     */
    public static <T extends Comparable<T>> void insertionSort(T[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].compareTo(key) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    /**
     * Merge Sort
     *
     * @param arr   Array to be sorted
     * @param <T>   Type of elements in the array
     */
    public static <T extends Comparable<T>> void mergeSort(T[] arr) {
        int n = arr.length;
        if (n > 1) {
            int mid = n / 2;
            T[] left = copyOfRange(arr, 0, mid);
            T[] right = copyOfRange(arr, mid, n);

            mergeSort(left);
            mergeSort(right);

            int i = 0, j = 0, k = 0;
            while (i < left.length && j < right.length) {
                if (left[i].compareTo(right[j]) < 0) {
                    arr[k] = left[i];
                    i++;
                } else {
                    arr[k] = right[j];
                    j++;
                }
                k++;
            }

            while (i < left.length) {
                arr[k] = left[i];
                i++;
                k++;
            }

            while (j < right.length) {
                arr[k] = right[j];
                j++;
                k++;
            }
        }
    }

    /**
     * Quick Sort
     *
     * @param arr   Array to be sorted
     * @param <T>   Type of elements in the array
     */
    public static <T extends Comparable<T>> void quickSort(T[] arr) {
        quickSort(arr, 0, arr.length - 1);
    }

    private static <T extends Comparable<T>> void quickSort(T[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    private static <T extends Comparable<T>> int partition(T[] arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].compareTo(pivot) <= 0) {
                i++;
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        T temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    public static <T> T[] copyOfRange(T[] original, int from, int to) {
        int newLength = to - from;
        if (newLength < 0) {
            throw new IllegalArgumentException(from + " > " + to);
        }
        T[] copy = (T[]) new Object[newLength];
        System.arraycopy(original, from, copy, 0, Math.min(original.length - from, newLength));
        return copy;
    }

    public static void main(String[] args) {
        Integer[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.print("Original array: ");
        printArray(arr);

        bubbleSort(arr);
        System.out.print("Bubble Sorted array: ");
        printArray(arr);

        Integer[] arr2 = {64, 34, 25, 12, 22, 11, 90};
        selectionSort(arr2);
        System.out.print("Selection Sorted array: ");
        printArray(arr2);

        Integer[] arr3 = {64, 34, 25, 12, 22, 11, 90};
        insertionSort(arr3);
        System.out.print("Insertion Sorted array: ");
        printArray(arr3);

        Integer[] arr4 = {64, 34, 25, 12, 22, 11, 90};
        mergeSort(arr4);
        System.out.print("Merge Sorted array: ");
        printArray(arr4);

        Integer[] arr5 = {64, 34, 25, 12, 22, 11, 90};
        quickSort(arr5);
        System.out.print("Quick Sorted array: ");
        printArray(arr5);
    }

    private static <T> void printArray(T[] arr) {
        for (T element : arr) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}
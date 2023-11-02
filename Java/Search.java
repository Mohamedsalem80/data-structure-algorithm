public class Search {

    /**
     * Linear Search
     *
     * @param arr    Array to search
     * @param target Element to find in the array
     * @param <T>    Type of elements in the array
     * @return Index of the target element or -1 if not found
     */
    public static <T> int linearSearch(T[] arr, T target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals(target)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Binary Search
     *
     * @param arr    Array to search (must be sorted)
     * @param target Element to find in the array
     * @param <T>    Type of elements in the array
     * @return Index of the target element or -1 if not found
     */
    public static <T extends Comparable<T>> int binarySearch(T[] arr, T target) {
        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int comparison = arr[mid].compareTo(target);
            if (comparison == 0) {
                return mid;
            } else if (comparison < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Integer[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int linearResult = linearSearch(arr, 5);
        System.out.println("Linear Search: Element 5 found at index " + linearResult);

        int binaryResult = binarySearch(arr, 5);
        System.out.println("Binary Search: Element 5 found at index " + binaryResult);
    }
}

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(1, n - i):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                swapped = True
        if not swapped:
            break

def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = [0] * n1
    R = [0] * n2

    for i in range(n1):
        L[i] = arr[l + i]
    for j in range(n2):
        R[j] = arr[m + 1 + j]

    i = j = 0
    k = l

    while i < n1 and j < n2:
        if L[i] < R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr):
    if len(arr) > 1:
        m = len(arr) // 2
        L = arr[:m]
        R = arr[m:]

        merge_sort(L)
        merge_sort(R)

        i = j = k = 0

        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pivotIndex = partition(arr, low, high)
        quick_sort(arr, low, pivotIndex - 1)
        quick_sort(arr, pivotIndex + 1, high)

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

def tim_sort(arr):
    min_run = 32
    n = len(arr)
    for i in range(0, n, min_run):
        insertion_sort(arr[i:i + min_run])

    run = min_run
    while run < n:
        for start in range(0, n, 2 * run):
            mid = min(start + run, n)
            end = min(start + 2 * run, n)
            if mid < end:
                merge_sort(arr, start, mid, end)
        run *= 2

def bucket_sort(arr):
    if len(arr) <= 1:
        return

    max_val = max(arr)
    min_val = min(arr)

    bucket_range = (max_val - min_val) // len(arr) + 1
    buckets = [[] for _ in range(len(arr))]

    for num in arr:
        index = (num - min_val) // bucket_range
        buckets[index].append(num)

    index = 0
    for bucket in buckets:
        insertion_sort(bucket)
        for num in bucket:
            arr[index] = num
            index += 1

def radix_sort(arr):
    max_num = max(arr)
    exp = 1
    while max_num // exp > 0:
        radix_count(arr, exp)
        exp *= 10

def radix_count(arr, exp):
    range_val = 10
    output = [0] * len(arr)
    count = [0] * range_val

    for i in range(len(arr)):
        count[(arr[i] // exp) % range_val] += 1

    for i in range(1, range_val):
        count[i] += count[i - 1]

    i = len(arr) - 1
    while i >= 0:
        output[count[(arr[i] // exp) % range_val] - 1] = arr[i]
        count[(arr[i] // exp) % range_val] -= 1
        i -= 1

    for i in range(len(arr)):
        arr[i] = output[i]

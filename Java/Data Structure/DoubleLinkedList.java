class DoubleListNode<T> {
    T data;
    DoubleListNode<T> next;
    DoubleListNode<T> prev;

    public DoubleListNode(T data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

interface CustomComparator<T> {
    int compare(T o1, T o2);
}

public class DoubleLinkedList<T> {
    private DoubleListNode<T> front;
    private DoubleListNode<T> rear;
    private int size;
    private CustomComparator<T> comparator;

    public DoubleLinkedList(CustomComparator<T> comparator) {
        front = rear = null;
        size = 0;
        this.comparator = comparator;
    }

    public void insertInOrder(T data) {
        DoubleListNode<T> newNode = new DoubleListNode<>(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            DoubleListNode<T> current = front;
            while (current != null && comparator.compare(data, current.data) > 0) {
                current = current.next;
            }
            if (current == null) {
                // Insert at the end
                newNode.prev = rear;
                rear.next = newNode;
                rear = newNode;
            } else {
                // Insert before the current node
                newNode.next = current;
                newNode.prev = current.prev;
                current.prev = newNode;
                if (newNode.prev == null) {
                    front = newNode;
                } else {
                    newNode.prev.next = newNode;
                }
            }
        }
        size++;
    }

    public boolean deleteItem(T data) {
        if (isEmpty()) {
            return false;
        }

        DoubleListNode<T> current = front;
        while (current != null) {
            if (comparator.compare(data, current.data) == 0) {
                // Found the node to delete
                if (current == front) {
                    front = current.next;
                    if (front != null) {
                        front.prev = null;
                    }
                } else {
                    current.prev.next = current.next;
                }

                if (current == rear) {
                    rear = current.prev;
                    if (rear != null) {
                        rear.next = null;
                    }
                } else {
                    current.next.prev = current.prev;
                }

                size--;
                return true;
            }

            current = current.next;
        }
        return false;
    }

    // The rest of the methods (get_item_index, delete_index, insert_index, etc.) remain the same

    // You can implement other methods and the main function here
    public static void main(String[] args) {
        // Example usage of DoubleLinkedList
        CustomComparator<Integer> comparator = (o1, o2) -> o1.compareTo(o2);
        DoubleLinkedList<Integer> list = new DoubleLinkedList<>(comparator);

        list.insertInOrder(5);
        list.insertInOrder(2);
        list.insertInOrder(8);

        list.print();
    }
    
    public void print() {
        DoubleListNode<T> current = front;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public boolean isEmpty() {
        return size == 0;
    }
}

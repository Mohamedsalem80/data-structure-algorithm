public class LinkedList<T> {
    private Node<T> front;
    private Node<T> rear;
    private int size;

    public LinkedList() {
        front = rear = null;
        size = 0;
    }

    public void insertInOrder(T datum) {
        Node<T> temp, dtemp;
        temp = new Node<T>(datum);

        if (rear == null) {
            rear = front = temp;
        } else {
            for (dtemp = front; (dtemp.next != null && ((Comparable<T>)dtemp.data).compareTo(datum) <= 0); dtemp = dtemp.next) {
                this.front = temp;
                temp.next = dtemp;
            }
            size++;
        }
    }

    public boolean deleteItem(T datum) {
        Node<T> temp, dtemp;

        for (temp = front; (temp.next != null && ((Comparable<T>)temp.next.data).compareTo(datum) != 0); temp = temp.next);

        dtemp = temp.next;

        if (dtemp != null && ((Comparable<T>)dtemp.data).compareTo(datum) == 0) {
            temp.next = dtemp.next;
            dtemp = null;
            size--;
            return true;
        } else {
            return false;
        }
    }

    public int getItemIndex(T datum) {
        Node<T> temp;
        int i = 0;

        for (temp = front; temp != null; temp = temp.next, i++) {
            if (((Comparable<T>)temp.data).compareTo(datum) == 0) {
                return i;
            }
        }

        return -1;
    }

    public void deleteIndex(int index) {
        if (front == null) {
            throw new IndexOutOfBoundsException("Linked List is empty");
        }

        Node<T> temp, dtemp;
        int i = 0;

        for (temp = front; (temp.next != null && i != (index - 1)); temp = temp.next, i++) {
            dtemp = temp.next;
            temp.next = dtemp.next;
            dtemp = null;
            size--;
        }
    }

    public void insertIndex(T item, int index) {
        Node<T> temp, dtemp, itemp;
        itemp = new Node<T>(item);
        int i = 0;

        if (rear == null) {
            front = rear = itemp;
        } else {
            for (temp = front; (temp.next != null && i != (index - 1)); temp = temp.next, i++) {
                dtemp = temp.next;
                temp.next = itemp;
                itemp.next = dtemp;
                size++;
            }
        }
    }

    public void insertFirst(T datum) {
        Node<T> temp = new Node<T>(datum);

        if (rear == null) {
            front = rear = temp;
        } else {
            temp.next = front;
            front = temp;
        }

        size++;
    }

    public void insertLast(T datum) {
        Node<T> temp = new Node<T>(datum);

        if (rear == null) {
            front = rear = temp;
        } else {
            rear.next = temp;
            rear = temp;
        }

        size++;
    }

    public T deleteFirst() {
        if (front == null) {
            throw new NoSuchElementException("Linked List is empty");
        }

        Node<T> temp = front;
        T datum = temp.data;
        front = temp.next;
        temp = null;

        if (front == null) {
            rear = null;
        }

        size--;

        return datum;
    }

    public T deleteLast() {
        if (front == null) {
            throw new NoSuchElementException("Linked List is empty");
        }

        Node<T> temp, dtemp;
        T datum = rear.data;
        dtemp = rear;

        for (temp = front; temp.next != rear; temp = temp.next) {
            rear = temp;
            rear.next = null;
            dtemp = null;
            size--;
        }

        return datum;
    }

    public T peekFirst() {
        return front.data;
    }

    public T peekLast() {
        return rear.data;
    }

    public boolean isEmpty() {
        return front == null;
    }

    public void clear() {
        while (front != null) {
            deleteFirst();
        }
    }

    public int getSize() {
        return size;
    }

    public void print() {
        Node<T> temp;

        for (temp = front; temp != null; temp = temp.next) {
            System.out.print(temp.data + "\t");
        }

        System.out.println();
    }
}

class Node<T> {
    T data;
    Node<T> next;

    public Node(T datum) {
        data = datum;
        next = null;
    }
}

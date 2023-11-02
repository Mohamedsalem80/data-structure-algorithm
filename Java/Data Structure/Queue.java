public class Queue<T> {
    private T[] queue;
    private int front;
    private int rear;
    private int size;

    public Queue(int size) {
        this.front = 0;
        this.rear = -1;
        this.size = size;
        this.queue = (T[]) new Object[size];
    }

    public void enqueue(T item) {
        if (rear == size - 1) {
            resize(size * 2);
        }
        queue[++rear] = item;
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        T temp = queue[front++];
        if (front > size / 4) {
            resize(size / 2);
        }
        return temp;
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return queue[front];
    }

    public boolean isEmpty() {
        return front > rear;
    }

    public int getSize() {
        return size;
    }

    private void resize(int newSize) {
        T[] newQueue = (T[]) new Object[newSize];
        for (int i = front, j = 0; i <= rear; i++, j++) {
            newQueue[j] = queue[i];
        }
        queue = newQueue;
        rear -= front;
        front = 0;
        size = newSize;
    }

    public void print() {
        for (int i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.println();
    }
}
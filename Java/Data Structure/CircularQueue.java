public class CircularQueue<T> {
    private T[] circularQueue;
    private int front;
    private int rear;
    private int size;

    public CircularQueue(int size) {
        this.front = -1;
        this.rear = -1;
        this.size = size;
        this.circularQueue = (T[]) new Object[size];
    }

    public void enqueue(T item) {
        if (isFull()) {
            throw new RuntimeException("Circular Queue is full");
        } else if (isEmpty()) {
            front = rear = 0;
            circularQueue[rear] = item;
        } else {
            rear = (rear + 1) % size;
            circularQueue[rear] = item;
        }
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("Circular Queue is empty");
        } else {
            T removedValue = circularQueue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return removedValue;
        }
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Circular Queue is empty");
        }
        return circularQueue[front];
    }

    public boolean isEmpty() {
        return front == -1 && rear == -1;
    }

    public boolean isFull() {
        return (rear + 1) % size == front;
    }

    public void print() {
        if (!isEmpty()) {
            int current = front;
            while (true) {
                System.out.print(circularQueue[current] + " ");
                if (current == rear) {
                    break;
                }
                current = (current + 1) % size;
            }
        }
        System.out.println();
    }
}
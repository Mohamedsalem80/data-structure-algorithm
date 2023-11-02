public class Stack<T> {
    private T[] stack;
    private int top;
    private int size;

    public Stack(int size) {
        this.top = -1;
        this.size = size;
        this.stack = (T[]) new Object[size];
    }

    public void push(T item) {
        if (top == size - 1) {
            resize(size * 2);
        }
        stack[++top] = item;
    }

    public T pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        T temp = stack[top--];
        if (top < size / 4) {
            resize(size / 2);
        }
        return temp;
    }

    public T peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return stack[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int getSize() {
        return size;
    }

    private void resize(int newSize) {
        T[] newStack = (T[]) new Object[newSize];
        for (int i = 0; i <= top; i++) {
            newStack[i] = stack[i];
        }
        stack = newStack;
        size = newSize;
    }

    public void print() {
        for (int i = top; i >= 0; i--) {
            System.out.print(stack[i] + " ");
        }
        System.out.println();
    }
}
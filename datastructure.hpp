/**
 * @brief Stack Data Structure Using Template Data Type
 * 
 * @tparam T 
 */
template <typename T>
class Stack {
private:
    T* stack;
    int top;
    int size;

public:
    Stack(int size = 1) {
        this->top = -1;
        this->size = size;
        this->stack = new T[size];
    }

    ~Stack() {
        delete[] stack;
    }

    void push(const T& item) {
        if (this->top == this->size - 1) resize(this->size * 2);
        this->stack[++this->top] = item;
    }

    T pop() {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        T temp = this->stack[this->top--];
        if (this->top < this->size / 4) resize(this->size / 2);
        return temp;
    }

    T& peek() const {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        return this->stack[this->top];
    }

    bool isEmpty() const {
        return this->top == -1;
    }

    void resize(int newSize) {
        T* newStack = new T[newSize];
        for (int i = 0; i <= top; ++i) newStack[i] = this->stack[i];
        delete[] stack;
        this->stack = newStack;
        this->size = newSize;
    }

    int stackSize() const {
        return this->size;
    }
};

/**
 * @brief Queue Data Structure Using Template Data Type
 * 
 * @tparam T 
 */
template <typename T>
class Queue {
private:
    T* queue;
    int front;
    int rear;
    int size;

public:
    Queue(int size = 1) {
        this->size = size;
        this->queue = new T[size];
        this->front = 0;
        this->rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(const T& item) {
        if (this->rear == this->size - 1) resize(this->size * 2);
        this->queue[++this->rear] = item;
    }

    T dequeue() {
        if (isEmpty()) throw std::out_of_range("Queue is empty");
        T temp = this->queue[this->front++];
        if (this->front > this->size / 4) resize(this->size / 2);
        return temp;
    }

    T& peek() const {
        if (isEmpty()) throw std::out_of_range("Queue is empty");
        return this->queue[this->front];
    }

    bool isEmpty() const {
        return this->front > this->rear;
    }

    void resize(int newSize) {
        T* newQueue = new T[newSize];
        for (int i = front, j = 0; i <= rear; ++i, ++j) {
            newQueue[j] = this->queue[i];
        }
        delete[] queue;
        this->queue = newQueue;
        this->rear -= this->front;
        this->front = 0;
        this->size = newSize;
    }

    int queueSize() const {
        return this->size;
    }
};

/**
 * @brief Linked List (Single) Node Sturct Containing Template data and Template Pointer next
 * 
 * @tparam T 
 */
template <typename T>
struct linkedNode {
    T data;
    linkedNode<T>* next;
};
/**
 * @brief Linked List (Single) Data Structure Using Template Data Type
 * 
 * @tparam T 
 */
template <typename T>
class LinkedList {
private:
    linkedNode<T>* top;

public:
    LinkedList() {
        top = NULL;
    }

    ~LinkedList() {
        while (top != NULL) {
            linkedNode<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(const T& item) {
        linkedNode<T>* temp = new linkedNode<T>;
        temp->data = item;
        temp->next = top;
        top = temp;
    }

    T pop() {
        if (isEmpty()) throw std::out_of_range("Linked List is empty");
        linkedNode<T>* temp = top;
        T data = top->data;
        top = top->next;
        delete temp;
        return data;
    }

    T& peek() const {
        if (isEmpty()) throw std::out_of_range("Linked List is empty");
        return top->data;
    }

    bool isEmpty() const {
        return top == NULL;
    }

    int size() const {
        int counter = 0;
        linkedNode<T>* temp = top;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
};
/**
 * @brief Linked List (Double) Node Sturct Containing Template data and Template Pointer next
 * 
 * @tparam T 
 */
template <typename T>
struct DoubleLinkedNode {
    T data;
    DoubleLinkedNode<T>* next;
    DoubleLinkedNode<T>* prev;
    DoubleLinkedNode(const T& val) : data(val), next(nullptr), prev(nullptr) {}
};

/**
 * @brief Linked List (Double) Data Structure Using Template Data Type
 * 
 * @tparam T 
 */
template <typename T>
class DoubleLinkedList {
private:
    DoubleLinkedNode<T>* head;
    DoubleLinkedNode<T>* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList() {
        while (head != nullptr) {
            DoubleLinkedNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& item) {
        DoubleLinkedNode<T>* newNode = new DoubleLinkedNode<T>(item);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    T shift() {
        if (isEmpty()) throw std::out_of_range("Double Linked List is empty");
        DoubleLinkedNode<T>* temp = head;
        T data = head->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return data;
    }

    T pop() {
        if (isEmpty()) throw std::out_of_range("Double Linked List is empty");
        DoubleLinkedNode<T>* temp = tail;
        T data = tail->data;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        return data;
    }

    T& peek() const {
        if (isEmpty()) throw std::out_of_range("Double Linked List is empty");
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        int counter = 0;
        DoubleLinkedNode<T>* temp = head;
        while (temp != nullptr) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
};
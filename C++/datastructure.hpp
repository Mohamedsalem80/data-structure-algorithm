/**
 * @brief Stack Data Structure Using Template Data Type
 * 
 * @tparam T Data type for the stack
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

    int getSize() const {
        return this->size;
    }

    void print() {
        for (int i = top; i >= 0; i--)
            std::cout << stack[i] << " ";
        std::cout << std::endl;
    }
};

/**
 * @brief Queue Data Structure Using Template Data Type
 * 
 * @tparam T Data type for the queue
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
        this->front = 0;
        this->rear = -1;
        this->size = size;
        this->queue = new T[size];
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

    int getSize() const {
        return this->size;
    }

    void print() {
        for (int i = front; i <= rear; i++)
            std::cout << queue[i] << " ";
        std::cout << std::endl;
    }
};

/**
 * @brief Circular Queue Data Structure Using Template Data Type
 * 
 * @tparam T Data type for the circular queue
 */
template <typename T>
class CircularQueue {
private:
    T* circularQueue;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int size = 10) {
        front = -1;
        rear = -1;
        this->size = size;
        this->circularQueue = new T[size];
    }

    ~CircularQueue(){
        delete[] circularQueue;
    }

    void enqueue(T item) {
        if (isFull()) throw std::out_of_range("Circular Queue is full");
        else if (isEmpty()) {
            front = rear = 0;
            circularQueue[rear] = item;
        } else {
            rear = (rear + 1) % size;
            circularQueue[rear] = item;
        }
    }

    T dequeue() {
        if (isEmpty()) throw std::out_of_range("Circular Queue is empty");
        else {
            T removedValue = circularQueue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return removedValue;
        }
    }

    T& peek() const {
        if (isEmpty()) throw std::out_of_range("Circular Queue is empty");
        return this->circularQueue[this->front];
    }

    bool isEmpty() const {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void print() {
        if (!isEmpty()) {
            int current = front;
            while (true) {
                std::cout << circularQueue[current] << " ";
                if (current == rear) break;
                current = (current + 1) % size;
            }
        }
        std::cout << std::endl;
    }
};

/**
 * @brief Linked List (Single) Node Structure Containing Template data and Template Pointer next
 * 
 * @tparam T Data type for linked list node
 */
template <typename T>
struct linkedListNode {
    T data;
    linkedListNode<T>* next;
};

/**
 * @brief Linked List (Single) Data Structure Using Template Data Type
 * 
 * @tparam T Data type for linked list
 */
template <typename T>
class LinkedList {
private:
    linkedListNode<T>* front;
    linkedListNode<T>* rear;
    int size;

public:
    LinkedList() {
        front = rear = nullptr;
        size = 0;
    }

    ~LinkedList(){
        clear();
    }

    void insert_in_order(T datum) {
        linkedListNode<T>* temp, ctemp, *dtemp;
        temp = new linkedListNode<T>;
        temp->data = datum;
        temp->next = nullptr;
        if (rear == nullptr) rear = front = temp;
        else {
            for (dtemp = front; (dtemp->next != nullptr && dtemp->next->data <= datum); dtemp = dtemp->next);
            ctemp = dtemp->next;
            dtemp->next = temp;
            temp->next = ctemp;
        }
        size++;
    }

    bool delete_item(T datum) {
        linkedListNode<T>* temp, *dtemp;
        for (temp = front; (temp->next != nullptr && temp->next->data != datum); temp = temp->next);
        dtemp = temp->next;
        if (dtemp->data == datum) {
            temp->next = dtemp->next;
            delete dtemp;
            size--;
            return true;
        }
        else return false;
    }

    int get_item_index(T datum) {
        linkedListNode<T>* temp;
        int i = 0;
        for (temp = front; temp != nullptr; temp = temp->next, i++)
            if (temp->data == datum) return i;
        return -1;
    }

    void delete_index(int index) {
        if (!front) std::out_of_range("Linked List is empty");
        linkedListNode<T>* temp, *dtemp;
        int i = 0;
        for (temp = front; (temp->next != nullptr && i != (index - 1)); temp = temp->next, i++);
        dtemp = temp->next;
        temp->next = dtemp->next;
        delete dtemp;
        size--;
    }

    void insert_index(T item, int index) {
        linkedListNode<T>* temp, *dtemp, *itemp;
        itemp = new linkedListNode<T>;
        itemp->data = item;
        itemp->next = nullptr;
        int i = 0;
        if (rear == nullptr) front = rear = itemp;
        else {
            for (temp = front; (temp->next != nullptr && i != (index - 1)); temp = temp->next, i++);
            dtemp = temp->next;
            temp->next = itemp;
            itemp->next = dtemp;
        }
        size++;
    }

    void insert_first(T datum) {
        linkedListNode<T>* temp;
        temp = new linkedListNode<T>;
        temp->data = datum;
        temp->next = nullptr;
        if (rear == nullptr) front = rear = temp;
        else {
            temp->next = this->front;
            this->front = temp;
        }
        size++;
    }

    void insert_last(T datum) {
        linkedListNode<T>* temp;
        temp = new linkedListNode<T>;
        temp->data = datum;
        temp->next = nullptr;
        if (rear == nullptr) front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    T delete_first() {
        if (!front) std::out_of_range("Linked List is empty");
        linkedListNode<T>* temp;
        T datum = front->data;
        temp = front;
        front = front->next;
        delete temp;
        if (!this->front) rear = nullptr;
        size--;
        return datum;
    }

    T delete_last() {
        if (!front) std::out_of_range("Linked List is empty");
        linkedListNode<T>* temp, *dtemp;
        T datum = this->rear->data;
        dtemp = this->rear;
        for (temp = front; temp->next != this->rear; temp = temp->next);
        this->rear = temp;
        this->rear->next = nullptr;
        delete dtemp;
        size--;
        return datum;
    }

    T peek_first() const {
        return this->front->data;
    }

    T peek_last() const {
        return this->rear->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void clear(){
        while (!!front) delete_first();
    }

    int getSize(){
        return size;
    }

    void print() {
        linkedListNode<T>* temp;
        for (temp = front; temp != nullptr; temp = temp->next)
            std::cout << temp->data << "\t";
        std::cout << "\n";
    }
};

/**
 * @brief Node structure for a double linked list containing a template data and template pointers to the next and previous nodes.
 * 
 * @tparam T Data type for the node.
 */
template <typename T>
struct DoubleLinkedListNode {
    T data;
    DoubleLinkedListNode<T>* next;
    DoubleLinkedListNode<T>* prev;
};

/**
 * @brief Double Linked List data structure using a template data type.
 * 
 * @tparam T Data type for the list.
 */
template <typename T>
class DoubleLinkedList {
private:
    doubleLinedListNode<T>* front;
    doubleLinedListNode<T>* rear;
    int size;

public:
    DoubleLinkedList() {
        front = rear = nullptr;
        size = 0;
    }

    ~DoubleLinkedList() {
        clear();
    }

    void insert_in_order(T datum) {
        doubleLinedListNode<T>* temp, *dtemp;
        temp = new doubleLinedListNode<T>;
        temp->data = datum;
        temp->next = temp->prev = nullptr;  // Initialize prev pointer
        if (rear == nullptr) {
            rear = front = temp;
        }
        else {
            for (dtemp = front; (dtemp->next != nullptr && dtemp->data <= datum); dtemp = dtemp->next);
            this->front = temp;
            temp->next = dtemp;
            if (dtemp->prev) {
                dtemp->prev->next = temp;
                temp->prev = dtemp->prev;
            }
            dtemp->prev = temp;
        }
        size++;
    }

    bool delete_item(T datum) {
        doubleLinedListNode<T>* temp, *dtemp;
        for (temp = front; (temp->next != nullptr && temp->next->data != datum); temp = temp->next);
        dtemp = temp->next;
        if (dtemp->data == datum) {
            temp->next = dtemp->next;
            if (dtemp->next) {
                dtemp->next->prev = temp;
            }
            delete dtemp;
            size--;
            return true;
        }
        else return false;
    }

    int get_item_index(T datum) {
        doubleLinedListNode<T>* temp;
        int i = 0;
        for (temp = front; temp != nullptr; temp = temp->next, i++)
            if (temp->data == datum) return i;
        return -1;
    }

    void delete_index(int index) {
        if (!front) std::out_of_range("Double Linked List is empty");
        doubleLinedListNode<T>* temp, *dtemp;
        int i = 0;
        for (temp = front; (temp->next != nullptr && i != (index - 1)); temp = temp->next, i++);
        dtemp = temp->next;
        temp->next = dtemp->next;
        if (dtemp->next) {
            dtemp->next->prev = temp;
        }
        delete dtemp;
        size--;
    }

    void insert_index(T item, int index) {
        doubleLinedListNode<T>* temp, *dtemp, *itemp;
        itemp = new doubleLinedListNode<T>;
        itemp->data = item;
        itemp->next = itemp->prev = nullptr;
        int i = 0;
        if (rear == nullptr) {
            front = rear = itemp;
        }
        else {
            for (temp = front; (temp->next != nullptr && i != (index - 1)); temp = temp->next, i++);
            dtemp = temp->next;
            temp->next = itemp;
            itemp->next = dtemp;
            if (dtemp) {
                dtemp->prev = itemp;
            }
            itemp->prev = temp;
        }
        size++;
    }

    void insert_first(T datum) {
        doubleLinedListNode<T>* temp;
        temp = new doubleLinedListNode<T>;
        temp->data = datum;
        temp->next = temp->prev = nullptr;
        if (rear == nullptr) {
            front = rear = temp;
        }
        else {
            temp->next = this->front;
            this->front->prev = temp;
            this->front = temp;
        }
        size++;
    }

    void insert_last(T datum) {
        doubleLinedListNode<T>* temp;
        temp = new doubleLinedListNode<T>;
        temp->data = datum;
        temp->next = temp->prev = nullptr;
        if (rear == nullptr) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        size++;
    }

    T delete_first() {
        if (!front) std::out_of_range("Double Linked List is empty");
        doubleLinedListNode<T>* temp;
        T datum = front->data;
        temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return datum;
    }

    T delete_last() {
        if (!front) std::out_of_range("Double Linked List is empty");
        doubleLinedListNode<T>* temp, *dtemp;
        T datum = this->rear->data;
        dtemp = this->rear;
        temp = dtemp->prev;
        if (temp) {
            temp->next = nullptr;
        }
        this->rear = temp;
        delete dtemp;
        size--;
        return datum;
    }

    T peek_first(){
        return this->front->data;
    }

    T peek_last(){
        return this->rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void clear() {
        while (!!front) delete_first();
    }

    int getSize() {
        return size;
    }

    void print() {
        doubleLinedListNode<T>* temp;
        for (temp = front; temp != nullptr; temp = temp->next)
            std::cout << temp->data << "\t";
        std::cout << "\n";
    }
};

/**
 * @brief Stack data structure using a linked list with a template data type.
 * 
 * @tparam T Data type for the stack.
 */
template <typename T>
class StackLL {
private:
    LinkedList<T> list;

public:
    void push(const T& item) {
        list.insert_last(item);
    }

    T pop() {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        return list.delete_last();
    }

    T peek() const {
        if (isEmpty()) throw std::out_of_range("Stack is empty");
        return list.peek_last();
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    int size() const {
        return list.getSize();
    }

    void print() {
        list.print();
    }
};

/**
 * @brief Queue data structure using a linked list with a template data type.
 * 
 * @tparam T Data type for the queue.
 */
template <typename T>
class QueueLL {
private:
    LinkedList<T> list;

public:
    void enqueue(const T& item) {
        list.insert_last(item);
    }

    T dequeue() {
        if (isEmpty()) throw std::out_of_range("Queue is empty");
        return list.delete_first();
    }

    T peek() const {
        if (isEmpty()) throw std::out_of_range("Queue is empty");
        return list.peek_first();
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    int size() const {
        return list.getSize();
    }

    void print() {
        list.print();
    }
};

/**
 * @brief Node structure for a binary tree containing template data and template pointers to the left and right branches.
 * 
 * @tparam T Data type for the tree node.
 */
template <typename T>
struct treeNode {
    T data;
    treeNode<T>* left;
    treeNode<T>* right;

    treeNode(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * @brief Binary Tree data structure using a template data type.
 * 
 * @tparam T Data type for the tree.
 */
template <typename T>
class BinaryTree {
private:
    treeNode<T>* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(T value) {
        if (root == nullptr) {
            root = new treeNode<T>(value);
            return;
        }
        insertRecursive(root, value);
    }
    
private:
    void insertRecursive(treeNode<T>* currenttreeNode, T value) {
        if (value < currenttreeNode->data) {
            if (currenttreeNode->left == nullptr) currenttreeNode->left = new treeNode<T>(value);
            else insertRecursive(currenttreeNode->left, value);
        } else {
            if (currenttreeNode->right == nullptr) currenttreeNode->right = new treeNode<T>(value);
            else insertRecursive(currenttreeNode->right, value);
        }
    }
};

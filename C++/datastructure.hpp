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
    linkedListNode<T>* start;
    int size;

public:
    LinkedList() {
        start = nullptr;
        size = 0;
    }

    ~LinkedList() {
        clear();
    }

    void insert_in_order(const T& data) {
        linkedListNode<T>* temp = new linkedListNode<T>;
        temp->data = data;
        temp->next = nullptr;

        if (start == nullptr || data < start->data) {
            temp->next = start;
            start = temp;
        } else {
            linkedListNode<T>* current = start;
            while (current->next != nullptr && data >= current->next->data)
                current = current->next;
            temp->next = current->next;
            current->next = temp;
        }
        size++;
    }

    bool delete_item(const T& data) {
        linkedListNode<T>* temp = start;
        linkedListNode<T>* dtemp = nullptr;

        if (temp != nullptr && temp->data == data) {
            start = temp->next;
            delete temp;
            size--;
            return true;
        }

        while (temp != nullptr && temp->next != nullptr && temp->next->data != data) temp = temp->next;

        if (temp != nullptr && temp->next != nullptr) {
            dtemp = temp->next;
            temp->next = dtemp->next;
            delete dtemp;
            size--;
            return true;
        }

        return false;
    }

    int get_item_index(const T& data) const {
        linkedListNode<T>* current;
        int index = 0;

        for (current = start; current != nullptr; current = current->next, index++)
            if (current->data == data)
                return index;
        return -1;
    }

    void delete_index(int index) {
        if (!start) throw std::out_of_range("Linked List is empty");

        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");

        linkedListNode<T>* temp = start;
        linkedListNode<T>* dtemp = nullptr;

        if (index == 0) {
            start = temp->next;
            delete temp;
            size--;
            return;
        }

        for (int i = 0; temp != nullptr && i != (index - 1); temp = temp->next, i++);

        dtemp = temp->next;
        temp->next = dtemp->next;
        delete dtemp;
        size--;
    }

    void insert_index(const T& item, int index) {
        if (index < 0 || index > size)
            throw std::out_of_range("Index out of bounds");

        linkedListNode<T>* itemp = new linkedListNode<T>;
        itemp->data = item;
        itemp->next = nullptr;

        if (index == 0) {
            itemp->next = start;
            start = itemp;
        } else {
            linkedListNode<T>* temp = start;

            for (int i = 0; temp != nullptr && i != (index - 1); temp = temp->next, i++);

            itemp->next = temp->next;
            temp->next = itemp;
        }

        size++;
    }

    void insert_first(const T& data) {
        linkedListNode<T>* temp = new linkedListNode<T>;
        temp->data = data;
        temp->next = start;

        start = temp;
        size++;
    }

    void insert_last(const T& data) {
        linkedListNode<T>* temp = new linkedListNode<T>;
        temp->data = data;
        temp->next = nullptr;

        if (start == nullptr) {
            start = temp;
        } else {
            linkedListNode<T>* lastNode = start;
            while (lastNode->next != nullptr) lastNode = lastNode->next;
            lastNode->next = temp;
        }

        size++;
    }

    T delete_first() {
        if (!start) throw std::out_of_range("Linked List is empty");

        linkedListNode<T>* temp = start;
        T data = temp->data;

        start = start->next;
        delete temp;

        size--;
        return data;
    }

    T delete_last() {
        if (!start) throw std::out_of_range("Linked List is empty");

        linkedListNode<T>* temp = start;
        linkedListNode<T>* dtemp = nullptr;
        T data;

        if (!start->next) {
            data = start->data;
            delete start;
            start = nullptr;
        } else {
            while (temp->next->next != nullptr) temp = temp->next;
            data = temp->next->data;
            dtemp = temp->next;
            temp->next = nullptr;
            delete dtemp;
        }
        size--;
        return data;
    }

    T peek() const {
        if (!start) throw std::out_of_range("Linked List is empty");
        return this->start->data;
    }

    T seek() const {
        if (!start) throw std::out_of_range("Linked List is empty");
        linkedListNode<T>* temp = start;
        while (temp->next != nullptr) temp = temp->next;
        return temp->data;
    }

    bool isEmpty() const {
        return start == nullptr;
    }

    void clear() {
        while (!!start) delete_first();
    }

    int getSize() const {
        return size;
    }

    void print() {
        linkedListNode<T>* temp;
        for (temp = start; temp != nullptr; temp = temp->next)
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
struct doubleLinkedListNode {
    T data;
    doubleLinkedListNode<T>* next;
    doubleLinkedListNode<T>* prev;
};

/**
 * @brief Double Linked List data structure using a template data type.
 * 
 * @tparam T Data type for the list.
 */
template <typename T>
class DoubleLinkedList {
private:
    doubleLinkedListNode<T>* start;
    int size;

public:
    DoubleLinkedList() {
        start = nullptr;
        size = 0;
    }

    ~DoubleLinkedList() {
        clear();
    }

    void insert_in_order(T data) {
        doubleLinkedListNode<T>* temp = new doubleLinkedListNode<T>;
        temp->data = data;
        temp->next = temp->prev = nullptr;

        if (start == nullptr) start = temp;
        else {
            doubleLinkedListNode<T>* dtemp = start;
            doubleLinkedListNode<T>* prev = nullptr;
            while (dtemp != nullptr && dtemp->data <= data) {
                prev = dtemp;
                dtemp = dtemp->next;
            }
            temp->next = dtemp;
            temp->prev = prev;

            if (prev) prev->next = temp;
            else start = temp;
            if (dtemp) dtemp->prev = temp;
        }
        size++;
    }


    bool delete_item(T data) {
        doubleLinkedListNode<T>* temp = start;
        doubleLinkedListNode<T>* prev = nullptr;
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr) {
            if (prev) prev->next = temp->next;
            else start = temp->next;
            if (temp->next) temp->next->prev = prev;

            delete temp;
            size--;
            return true;
        }
        return false;
    }

    int get_item_index(T data) {
        doubleLinkedListNode<T>* temp = start;
        int index = 0;

        while (temp != nullptr && temp->data != data) {
            temp = temp->next;
            index++;
        }

        return (temp != nullptr) ? index : -1;
    }

    void delete_index(int index) {
        if (!start) throw std::out_of_range("Double Linked List is empty");
        if (index < 0 || index >= size) throw std::out_of_range("Index out of bounds");
        
        doubleLinkedListNode<T>* temp = start;
        doubleLinkedListNode<T>* dtemp = nullptr;

        for (int i = 0; i < index - 1; ++i) temp = temp->next;

        dtemp = temp->next;
        temp->next = dtemp->next;

        if (dtemp->next) dtemp->next->prev = temp;

        delete dtemp;
        size--;
    }

    void insert_index(T item, int index) {
        if (index < 0 || index > size) throw std::out_of_range("Index out of bounds");

        doubleLinkedListNode<T>* temp = start;
        doubleLinkedListNode<T>* dtemp = nullptr;
        doubleLinkedListNode<T>* itemp = new doubleLinkedListNode<T>;
        itemp->data = item;
        itemp->next = itemp->prev = nullptr;

        if (index == 0) {
            itemp->next = start;
            if (start) start->prev = itemp;
            start = itemp;
        } else {
            for (int i = 0; i < index - 1; ++i) temp = temp->next;

            dtemp = temp->next;
            temp->next = itemp;
            itemp->next = dtemp;

            if (dtemp) dtemp->prev = itemp;

            itemp->prev = temp;
        }
        size++;
    }

    void insert_first(T data) {
        doubleLinkedListNode<T>* temp = new doubleLinkedListNode<T>;
        temp->data = data;
        temp->next = temp->prev = nullptr;

        if (start == nullptr) start = temp;
        else {
            temp->next = start;
            start->prev = temp;
            start = temp;
        }
        size++;
    }

    void insert_last(T data) {
        doubleLinkedListNode<T>* temp = new doubleLinkedListNode<T>;
        temp->data = data;
        temp->next = temp->prev = nullptr;

        if (start == nullptr) start = temp;
        else {
            doubleLinkedListNode<T>* last = start;

            while (last->next != nullptr) last = last->next;

            last->next = temp;
            temp->prev = last;
        }
        size++;
    }

    T delete_first() {
        if (!start) throw std::out_of_range("Double Linked List is empty");

        doubleLinkedListNode<T>* temp = start;
        T data = temp->data;
        start = start->next;
        if (start) start->prev = nullptr;

        delete temp;
        size--;

        return data;
    }

    T delete_last() {
        if (!start) throw std::out_of_range("Double Linked List is empty");

        doubleLinkedListNode<T>* temp = start;

        while (temp->next && temp->next->next) temp = temp->next;

        T data = temp->next ? temp->next->data : temp->data;

        if (temp->next) {
            delete temp->next;
            temp->next = nullptr;
        } else {
            delete start;
            start = nullptr;
        }

        size--;
        return data;
    }

    T peek() const {
        if (!start) throw std::out_of_range("Double Linked List is empty");
        return start->data;
    }

    T seek() const {
        if (!start) throw std::out_of_range("Double Linked List is empty");
        doubleLinkedListNode<T>* temp = start;
        while (temp->next != nullptr) temp = temp->next;
        return temp->data;
    }

    bool isEmpty() const {
        return start == nullptr;
    }

    void clear() {
        while (!!start) delete_first();
    }

    int getSize() const {
        return size;
    }

    void print() const {
        doubleLinkedListNode<T>* temp;
        for (temp = start; temp != nullptr; temp = temp->next)
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
        return list.seek();
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
        return list.peek();
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
    BinaryTree() : root(nullptr) {}

    void insert(T value) {
        if (root == nullptr) {
            root = new treeNode<T>(value);
            return;
        }
        insertRecursive(root, value);
    }

    void remove(T value) {
        root = removeRecursive(root, value);
    }

    void bfs() {
        bfsTraversal(root);
    }

    void dfs() {
        dfsTraversal(root);
    }

private:
    void insertRecursive(treeNode<T>* currentTreeNode, T value) {
        if (value < currentTreeNode->data) {
            if (currentTreeNode->left == nullptr)
                currentTreeNode->left = new treeNode<T>(value);
            else
                insertRecursive(currentTreeNode->left, value);
        } else {
            if (currentTreeNode->right == nullptr)
                currentTreeNode->right = new treeNode<T>(value);
            else
                insertRecursive(currentTreeNode->right, value);
        }
    }

    treeNode<T>* removeRecursive(treeNode<T>* currentTreeNode, T value) {
        if (currentTreeNode == nullptr) return currentTreeNode;
        if (value < currentTreeNode->data) {
            currentTreeNode->left = removeRecursive(currentTreeNode->left, value);
        } else if (value > currentTreeNode->data) {
            currentTreeNode->right = removeRecursive(currentTreeNode->right, value);
        } else {
            if (currentTreeNode->left == nullptr) {
                treeNode<T>* temp = currentTreeNode->right;
                delete currentTreeNode;
                return temp;
            } else if (currentTreeNode->right == nullptr) {
                treeNode<T>* temp = currentTreeNode->left;
                delete currentTreeNode;
                return temp;
            }
            treeNode<T>* temp = minValueNode(currentTreeNode->right);
            currentTreeNode->data = temp->data;
            currentTreeNode->right = removeRecursive(currentTreeNode->right, temp->data);
        }

        return currentTreeNode;
    }

    treeNode<T>* minValueNode(treeNode<T>* node) {
        treeNode<T>* current = node;

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    void bfsTraversal(treeNode<T>* startNode) {
        if (startNode == nullptr) return;

        Queue<treeNode<T>*> queue;
        queue.enqueue(startNode);

        while (!queue.isEmpty()) {
            treeNode<T>* current = queue.dequeue();
            std::cout << current->data << " ";

            if (current->left != nullptr) queue.enqueue(current->left);
            if (current->right != nullptr) queue.enqueue(current->right);
        }

        std::cout << std::endl;
    }

    void dfsTraversal(treeNode<T>* startNode) {
        if (startNode == nullptr) return;

        Stack<treeNode<T>*> stack;
        stack.push(startNode);

        while (!stack.isEmpty()) {
            treeNode<T>* current = stack.pop();
            std::cout << current->data << " ";

            if (current->right != nullptr) stack.push(current->right);
            if (current->left != nullptr) stack.push(current->left);
        }

        std::cout << std::endl;
    }
};

/**
 * @brief Graph data structure using a template data types.
 * 
 * @tparam T Data type for the tree.
 * @tparam MaxVertices 
 */
template <typename T, long long MaxVertices>
class Graph {
private:
    T adjacencyList[MaxVertices][MaxVertices];
    long long vertexCount;

public:
    Graph() : vertexCount(0) {}

    void addVertex(const T& vertex) {
        if (!containsVertex(vertex)) {
            adjacencyList[vertexCount][0] = vertex;
            ++vertexCount;
        }
    }

    void addEdge(const T& source, const T& destination) {
        addVertex(source);
        addVertex(destination);

        long long sourceIndex = findVertexIndex(source);
        adjacencyList[sourceIndex][vertexCount(sourceIndex)] = destination;
    }

    void print() const {
        for (long long i = 0; i < vertexCount; ++i) {
            std::cout << adjacencyList[i][0] << " -> ";
            for (long long j = 1; j <= vertexCount(i); ++j) {
                std::cout << adjacencyList[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(const T& start) const {
        bool visited[MaxVertices] = {false};
        T queue[MaxVertices];
        long long front = 0, rear = 0;

        long long startIdx = findVertexIndex(start);
        if (startIdx != vertexCount) {
            visited[startIdx] = true;
            queue[rear++] = start;

            while (front != rear) {
                T current = queue[front++];
                std::cout << current << " ";

                long long currentIdx = findVertexIndex(current);
                for (long long i = 1; i <= vertexCount(currentIdx); ++i) {
                    T neighbor = adjacencyList[currentIdx][i];
                    long long neighborIdx = findVertexIndex(neighbor);
                    if (!visited[neighborIdx]) {
                        visited[neighborIdx] = true;
                        queue[rear++] = neighbor;
                    }
                }
            }
        }

        std::cout << std::endl;
    }

    void dfs(const T& start) const {
        bool visited[MaxVertices] = {false};
        dfsRecursive(findVertexIndex(start), visited);
        std::cout << std::endl;
    }

    int shortestPath(const T& start, const T& destination) const {
        long long startIdx = findVertexIndex(start);
        long long destIdx = findVertexIndex(destination);

        if (startIdx == vertexCount || destIdx == vertexCount) {
            return -1;
        }

        int pathLength = findShortestPathLength(startIdx, destIdx);
        return pathLength;
    }

private:
    bool containsVertex(const T& vertex) const {
        for (long long i = 0; i < vertexCount; ++i) {
            if (adjacencyList[i][0] == vertex) {
                return true;
            }
        }
        return false;
    }

    long long findVertexIndex(const T& vertex) const {
        for (long long i = 0; i < vertexCount; ++i) {
            if (adjacencyList[i][0] == vertex) {
                return i;
            }
        }
        return vertexCount;
    }

    long long vertexCount(long long index) const {
        long long count = 0;
        while (adjacencyList[index][count + 1] != T()) {
            ++count;
        }
        return count;
    }

    void dfsRecursive(long long vertexIdx, bool visited[]) const {
        visited[vertexIdx] = true;
        std::cout << adjacencyList[vertexIdx][0] << " ";

        for (long long i = 1; i <= vertexCount(vertexIdx); ++i) {
            T neighbor = adjacencyList[vertexIdx][i];
            long long neighborIdx = findVertexIndex(neighbor);
            if (!visited[neighborIdx]) {
                dfsRecursive(neighborIdx, visited);
            }
        }
    }

    int findShortestPathLength(long long startIdx, long long destIdx) const {
        bool visited[MaxVertices] = {false};
        int distance[MaxVertices];

        for (long long i = 0; i < MaxVertices; ++i) {
            distance[i] = -1;
        }

        visited[startIdx] = true;
        distance[startIdx] = 0;

        T queue[MaxVertices];
        long long front = 0, rear = 0;
        queue[rear++] = adjacencyList[startIdx][0];

        while (front != rear) {
            T current = queue[front++];
            long long currentIdx = findVertexIndex(current);

            for (long long i = 1; i <= vertexCount(currentIdx); ++i) {
                T neighbor = adjacencyList[currentIdx][i];
                long long neighborIdx = findVertexIndex(neighbor);

                if (!visited[neighborIdx]) {
                    visited[neighborIdx] = true;
                    distance[neighborIdx] = distance[currentIdx] + 1;
                    queue[rear++] = neighbor;

                    if (neighbor == adjacencyList[destIdx][0]) {
                        return distance[neighborIdx];
                    }
                }
            }
        }

        return -1;
    }
};
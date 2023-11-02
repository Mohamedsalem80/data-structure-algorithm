class Stack:
    def __init__(self, size=1):
        self.size = size
        self.stack = [None] * size
        self.top = -1

    def push(self, item):
        if self.is_full():
            self.resize(self.size * 2)
        self.top += 1
        self.stack[self.top] = item

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is empty")
        item = self.stack[self.top]
        self.top -= 1
        if self.should_shrink():
            self.resize(self.size // 2)
        return item

    def peek(self):
        if self.is_empty():
            raise IndexError("Stack is empty")
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == self.size - 1

    def should_shrink(self):
        return self.top < self.size // 4 and self.size > 1

    def resize(self, new_size):
        new_stack = [None] * new_size
        for i in range(self.top + 1):
            new_stack[i] = self.stack[i]
        self.stack = new_stack
        self.size = new_size

    def get_size(self):
        return self.size

    def print(self):
        for i in range(self.top, -1, -1):
            print(self.stack[i], end=" ")
        print()


class Queue:
    def __init(self, size=1):
        self.size = size
        self.queue = [None] * size
        self.front = 0
        self.rear = -1

    def enqueue(self, item):
        if self.is_full():
            self.resize(self.size * 2)
        self.rear += 1
        self.queue[self.rear] = item

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        item = self.queue[self.front]
        self.front += 1
        if self.should_shrink():
            self.resize(self.size // 2)
        return item

    def peek(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        return self.queue[self.front]

    def is_empty(self):
        return self.front > self.rear

    def is_full(self):
        return (self.rear + 1) == self.size

    def should_shrink(self):
        return self.front > (self.size // 4) and self.size > 1

    def resize(self, new_size):
        new_queue = [None] * new_size
        for i in range(self.front, self.rear + 1):
            new_queue[i - self.front] = self.queue[i]
        self.queue = new_queue
        self.rear -= self.front
        self.front = 0
        self.size = new_size

    def get_size(self):
        return self.size

    def print(self):
        for i in range(self.front, self.rear + 1):
            print(self.queue[i], end=" ")
        print()

class CircularQueue:
    def __init__(self, size=10):
        self.size = size
        self.circularQueue = [None] * size
        self.front = self.rear = -1

    def enqueue(self, item):
        if self.is_full():
            raise IndexError("Circular Queue is full")
        elif self.is_empty():
            self.front = self.rear = 0
            self.circularQueue[self.rear] = item
        else:
            self.rear = (self.rear + 1) % self.size
            self.circularQueue[self.rear] = item

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Circular Queue is empty")
        removed_value = self.circularQueue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.size
        return removed_value

    def peek(self):
        if self.is_empty():
            raise IndexError("Circular Queue is empty")
        return self.circularQueue[self.front]

    def is_empty(self):
        return self.front == -1 and self.rear == -1

    def is_full(self):
        return (self.rear + 1) % self.size == self.front

    def print(self):
        if not self.is_empty():
            current = self.front
            while True:
                print(self.circularQueue[current], end=" ")
                if current == self.rear:
                    break
                current = (current + 1) % self.size
        print()

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.size = 0
        self.front = None
        self.rear = None

    def insert_in_order(self, data):
        new_node = Node(data)
        new_node.next = None
        if not self.front:
            self.rear = self.front = new_node
        else:
            current = self.front
            while current and data > current.data:
                current = current.next
            new_node.next = current
            if not current:
                self.rear = new_node
            self.front = new_node
        self.size += 1

    def delete_item(self, data):
        if not self.front:
            return False
        if self.front.data == data:
            if self.front == self.rear:
                self.rear = None
            self.front = self.front.next
            self.size -= 1
            return True
        current = self.front
        while current.next:
            if current.next.data == data:
                if current.next == self.rear:
                    self.rear = current
                current.next = current.next.next
                self.size -= 1
                return True
            current = current.next
        return False

    def get_item_index(self, data):
        current = self.front
        index = 0
        while current:
            if current.data == data:
                return index
            current = current.next
            index += 1
        return -1

    def delete_index(self, index):
        if not self.front:
            raise IndexError("Linked List is empty")
        if index == 0:
            self.front = self.front.next
            if not self.front:
                self.rear = None
            self.size -= 1
            return
        current = self.front
        for i in range(index - 1):
            if not current:
                raise IndexError("Index out of range")
            current = current.next
        if not current:
            raise IndexError("Index out of range")
        if not current.next:
            raise IndexError("Index out of range")
        current.next = current.next.next
        if not current.next:
            self.rear = current
        self.size -= 1

    def insert_index(self, item, index):
        new_node = Node(item)
        new_node.next = None
        if not self.front:
            self.front = self.rear = new_node
        else:
            current = self.front
            for i in range(index - 1):
                if not current:
                    raise IndexError("Index out of range")
                current = current.next
            if not current:
                raise IndexError("Index out of range")
            new_node.next = current.next
            current.next = new_node
            if not new_node.next:
                self.rear = new_node
        self.size += 1

    def insert_first(self, data):
        new_node = Node(data)
        new_node.next = self.front
        self.front = new_node
        if not self.rear:
            self.rear = new_node
        self.size += 1

    def insert_last(self, data):
        new_node = Node(data)
        new_node.next = None
        if not self.front:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self.size += 1

    def delete_first(self):
        if not self.front:
            raise IndexError("Linked List is empty")
        if self.front == self.rear:
            self.rear = None
        self.front = self.front.next
        self.size -= 1

    def delete_last(self):
        if not self.front:
            raise IndexError("Linked List is empty")
        if self.front == self.rear:
            self.front = None
            self.rear = None
        else:
            current = self.front
            while current.next != self.rear:
                current = current.next
            current.next = None
            self.rear = current
        self.size -= 1

    def print(self):
        current = self.front
        while current:
            print(current.data, end=" ")
            current = current.next
        print()

class DoubleListNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoubleLinkedList:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def insert_in_order(self, data):
        new_node = DoubleListNode(data)
        if not self.front:
            self.front = self.rear = new_node
        else:
            current = self.front
            while current and data > current.data:
                current = current.next
            if current:
                new_node.next = current
                new_node.prev = current.prev
                current.prev = new_node
                if new_node.prev:
                    new_node.prev.next = new_node
                if current == self.front:
                    self.front = new_node
            else:
                new_node.prev = self.rear
                self.rear.next = new_node
                self.rear = new_node
        self.size += 1

    def delete_item(self, data):
        if not self.front:
            return False
        current = self.front
        while current:
            if current.data == data:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.front = current.next
                if current.next:
                    current.next.prev = current.prev
                else:
                    self.rear = current.prev
                self.size -= 1
                return True
            current = current.next
        return False

    def insert_first(self, data):
        new_node = DoubleListNode(data)
        if not self.front:
            self.front = self.rear = new_node
        else:
            new_node.next = self.front
            self.front.prev = new_node
            self.front = new_node
        self.size += 1

    def insert_last(self, data):
        new_node = DoubleListNode(data)
        new_node.prev = self.rear
        self.rear.next = new_node
        self.rear = new_node
        self.size += 1

    def delete_first(self):
        if not self.front:
            raise IndexError("Double Linked List is empty")
        if self.front == self.rear:
            self.front = self.rear = None
        else:
            self.front = self.front.next
            self.front.prev = None
        self.size -= 1

    def delete_last(self):
        if not self.front:
            raise IndexError("Double Linked List is empty")
        if self.front == self.rear:
            self.front = self.rear = None
        else:
            self.rear = self.rear.prev
            self.rear.next = None
        self.size -= 1

    def print(self):
        current = self.front
        while current:
            print(current.data, end=" ")
            current = current.next
        print()

class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if not self.root:
            self.root = TreeNode(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, current, value):
        if value < current.value:
            if current.left is None:
                current.left = TreeNode(value)
            else:
                self._insert_recursive(current.left, value)
        else:
            if current.right is None:
                current.right = TreeNode(value)
            else:
                self._insert_recursive(current.right, value)

    def inorder_traversal(self):
        result = []
        self._inorder_recursive(self.root, result)
        return result

    def _inorder_recursive(self, node, result):
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.value)
            self._inorder_recursive(node.right, result)

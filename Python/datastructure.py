class Stack:
    def __init__(self, size=1):
        self.top = -1
        self.size = size
        self.stack = [None] * size

    def push(self, item):
        if self.top == self.size - 1:
            self.resize(self.size * 2)
        self.top += 1
        self.stack[self.top] = item

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is empty")
        item = self.stack[self.top]
        self.top -= 1
        if self.top < self.size // 4:
            self.resize(self.size // 2)
        return item

    def peek(self):
        if self.is_empty():
            raise IndexError("Stack is empty")
        return self.stack[self.top]

    def is_empty(self):
        return self.top == -1

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
    def __init__(self, size=1):
        self.front = 0
        self.rear = -1
        self.size = size
        self.queue = [None] * size

    def enqueue(self, item):
        if self.rear == self.size - 1:
            self.resize(self.size * 2)
        self.rear += 1
        self.queue[self.rear] = item

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        item = self.queue[self.front]
        self.front += 1
        if self.front > self.size // 4:
            self.resize(self.size // 2)
        return item

    def peek(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        return self.queue[self.front]

    def is_empty(self):
        return self.front > self.rear

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
        self.front = -1
        self.rear = -1
        self.size = size
        self.circularQueue = [None] * size

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


class LinkedListNode:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def insert_in_order(self, datum):
        temp = LinkedListNode(datum)
        temp.next = None
        if self.rear is None:
            self.rear = self.front = temp
        else:
            dtemp = self.front
            while dtemp.next and dtemp.data <= datum:
                dtemp = dtemp.next
            self.front = temp
            temp.next = dtemp
        self.size += 1

    def delete_item(self, datum):
        temp = self.front
        if temp is not None and temp.data == datum:
            self.front = temp.next
            del temp
            self.size -= 1
            return True
        while temp is not None:
            if temp.data == datum:
                break
            prev = temp
            temp = temp.next
        if temp is None:
            return False
        prev.next = temp.next
        del temp
        self.size -= 1
        return True

    def get_item_index(self, datum):
        temp = self.front
        i = 0
        while temp is not None:
            if temp.data == datum:
                return i
            temp = temp.next
            i += 1
        return -1

    def delete_index(self, index):
        if self.front is None:
            raise IndexError("Linked List is empty")
        temp = self.front
        if index == 0:
            self.front = temp.next
            del temp
            self.size -= 1
            return
        for i in range(index - 1):
            if temp is None:
                raise IndexError("Index out of range")
            temp = temp.next
        if temp is None:
            raise IndexError("Index out of range")
        if temp.next is None:
            raise IndexError("Index out of range")
        dtemp = temp.next
        temp.next = dtemp.next
        del dtemp
        self.size -= 1

    def insert_index(self, item, index):
        itemp = LinkedListNode(item)
        itemp.next = None
        if self.rear is None:
            self.front = self.rear = itemp
        else:
            temp = self.front
            for i in range(index - 1):
                if temp is None:
                    raise IndexError("Index out of range")
                temp = temp.next
            if temp is None:
                raise IndexError("Index out of range")
            dtemp = temp.next
            temp.next = itemp
            itemp.next = dtemp
        self.size += 1

    def insert_first(self, datum):
        temp = LinkedListNode(datum)
        temp.next = None

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

    # Other methods (get_item_index, delete_index, insert_index, insert_first, insert_last, delete_first, delete_last, etc.)

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
class TreeNode<T> {
    T data;
    TreeNode<T> left;
    TreeNode<T> right;

    public TreeNode(T value) {
        data = value;
        left = null;
        right = null;
    }
}

public class BinaryTree<T> {
    private TreeNode<T> root;

    public BinaryTree() {
        root = null;
    }

    public void insert(T value) {
        root = insertRecursive(root, value);
    }

    private TreeNode<T> insertRecursive(TreeNode<T> currentTreeNode, T value) {
        if (currentTreeNode == null) {
            return new TreeNode<T>(value);
        }

        if (compare(value, currentTreeNode.data) < 0) {
            currentTreeNode.left = insertRecursive(currentTreeNode.left, value);
        } else {
            currentTreeNode.right = insertRecursive(currentTreeNode.right, value);
        }

        return currentTreeNode;
    }

    private int compare(T a, T b) {
        if (a instanceof Comparable<?> && b instanceof Comparable<?>) {
            Comparable<T> comparableA = (Comparable<T>) a;
            return comparableA.compareTo(b);
        } else {
            throw new IllegalArgumentException("Elements are not comparable");
        }
    }
}

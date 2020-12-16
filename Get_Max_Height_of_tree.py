class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def isEmpty(self, root):
        if root == None:
            return True
        else:
            return False

    def isLeaf(self, root):
        if root.left == None and root.right == None:
            return True
        else:
            return False

    def getMaxHeight(self, root):
        if self.isEmpty(root):
            return 0
        elif self.isLeaf(root):
            return 1
        else:
            return (1 + max(self.getMaxHeight(root.left), self.getMaxHeight(root.right)))


if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.left.right.left = Node(6)

    print("The max height of the tree is :- ", root.getMaxHeight(root))
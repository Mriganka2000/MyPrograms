class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def invert(head):
    if head is not None:
        left = invert(head.left)
        right = invert(head.right)
        head.left = right
        head.right = left
    return head
    
def printf(head):
    if head:
        printf(head.left)
        print(head.data)
        printf(head.right)
    
if __name__ == '__main__':
    head = Node(1)
    head.left = Node(2)
    head.right = Node(3)
    head.left.left = Node(4)
    head.left.right = Node(5)
    head.right.left = Node(6)
    head.right.right = Node(7)
    
    print("Before Inevert")
    printf(head)
    invert(head)
    print("Before Inevert")
    printf(head)

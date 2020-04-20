class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next

    def print(self):
        ptr = self.head
        while ptr is not None:
            print(ptr.data)
            ptr = ptr.next
    def __reverse(self, head):
        prev = None
        current = head
        while(current is not None):
            next = current.next
            current.next = prev
            prev = current
            current = next
        head = prev
        return head

    def palindrome(self):
        count = 0
        ptr = self.head
        while(ptr != None):
            count = count+1
            ptr = ptr.next
        ptr = self.head
        for i in range(1, count//2+1):
            prev = ptr
            ptr = ptr.next
        ptr1 = self.head
        prev.next = None
        if(count % 2 == 0):
            ptr2 = ptr
        else:
            ptr2 = ptr.next
        ptr2 = self.__reverse(ptr2)
        # print(count)
        while ptr1 != None and ptr2 != None:
            if(ptr1.data == ptr2.data):
                ptr1 = ptr1.next
                ptr2 = ptr2.next
            else:
                break
        if(ptr1 == None and ptr2 == None):
            print("Palindrome ")
        else:
            print("Not palindrome")
if __name__ == "__main__":
    list = List()

    list.insert(1)
    list.insert(2)
    list.insert(2)
    list.insert(1)
    list.print()
    list.palindrome()

    list2 = List()
    list2.insert(1)
    list2.insert(2)
    list2.insert(3)
    list2.insert(4)
    list2.insert(3)
    list2.insert(2)
    list2.insert(1)
    list2.print()
    list2.palindrome()
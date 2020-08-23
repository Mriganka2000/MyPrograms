class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeTwoLists(l1, l2):
    result = ListNode()
    temp = result
    while l1 != None and l2 != None:
        if l1.val <= l2.val:
            result.next = l1
            l1 = l1.next
            result = result.next
        else:
            result.next = l2
            l2 = l2.next
            result = result.next
    while l1 != None:
        result.next = l1
        l1 = l1.next
        result = result.next
    while l2 != None:
        result.next = l2
        l2 = l2.next
        result = result.next

    return temp.next


def printList(head):
    temp = head

    while temp:
        print(temp.val, end="->")
        temp = temp.next


if __name__ == "__main__":
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)

    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)

    result = mergeTwoLists(l1, l2)
    printList(result)
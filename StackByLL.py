#Parth Dodiya:171CO215


class LinkedList:
    """Defines a Singly Linked List.
    attributes: head - a pointer to the first node object
    """

    def __init__(self):
        self.head = ListNode()
        """ This is the constructor. It tells you what are the attributes of all objects belonging to this class. You do not need to call the constructor. """
        """Creates a new list as soon as an object is created with a Sentinel( head with no value ) Node"""

    def insert(self, x, p):
        temp = ListNode(x, p.next)
        p.next = temp
        """This insert function creates and inserts a new node at a position after a node "p" that exists in the code already"""

    def delete(self, p):
        p.next = p.next.next
        """Delete the node following node p in the linked list, by removing any reference to that node itself. """

    def printlst(self):
        it = self.head.next
        while it is not None:
            print(it.value, end=' ')
            it = it.next
        print("")
        """ Print all the elements of a list in a row."""

    def insertAtIndex(self, x, i):
        it = self.head
        for m in range(0, i):
            it = it.next
        temp = ListNode(x, it.next)
        it.next = temp
        """Insert value x at list position i. (The position of the first element is taken to be 0.)"""

    def search(self, x):
        it = self.head.next
        ret = None
        while ret is None:
            if it.data == x:
                ret = it
            else:
                it = it.next
        """Search for value x in the list. Return a reference to the first node with value x; return None if no such node is found."""
        return (ret)


    def len(self):
        it = self.head
        ans = 0
        while it.next is not None:
            ans += 1
            it = it.next
        """Return the length (the number of elements) in the Linked List."""
        return ans


    def isEmpty(self):
        if self.head.next is None:
            return True
        else:
            return False
        """Return True if the Linked List has no elements, False otherwise."""
        
class ListNode:
    """Represents a node of a Singly Linked List.

    attributes: value, next - reference that points to the next node in the list.
    """

    def __init__(self, val=None, nxt=None):
        self.value = val
        self.next = nxt

class stack:
    def __init__(self):
        self.LL=LinkedList()
    def push(self,x):
        self.LL.insert(x,self.LL.head)
        print("Element Pushed:",x)
        return x
    def pop(self):
        if self.LL.isEmpty():
            print("Stack Underflow.")
        else:
            t=self.LL.head.next.value
            self.LL.delete(self.LL.head)
            print("Element Popped:",t)
            return t
    def display(self):
        self.LL.printlst()
    def peek(self):
        t=self.LL.head.next.value
        print("Peek Element:",t)
        return t
def main():
    S=stack()
    S.push(1)
    S.push(2)
    S.push(3)
    S.peek()
    S.push(4)
    S.push(5)
    S.display()
    S.peek()
    S.pop()
    S.pop()
    S.display()
    S.peek()

if __name__ == '__main__':
    main()

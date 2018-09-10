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

class Stack:
    def __init__(self):
        self.LL=LinkedList()
        self.size=0
    def push(self,x):
        self.LL.insert(x,self.LL.head)
        #print("Element Pushed:",x)
        self.size+=1
        return x
    def pop(self):
        if self.LL.isEmpty():
            print("Stack Underflow.")
        else:
            t=self.LL.head.next.value
            self.LL.delete(self.LL.head)
            #print("Element Popped:",t)
            self.size-=1
            return t
    def display(self):
        self.LL.printlst()
    def peek(self):
        t=self.LL.head.next.value
        #print("Peek Element:",t)
        return t
class Queue:
    def __init__(self):
        self.stack_1=Stack()
        self.stack_2=Stack()
    def enqueue(self,x):
        print("Enqueued:",x)
        self.stack_1.push(x)
    def dequeue(self):
        if self.stack_2.size>0:
            print("Dequeued:",self.stack_2.peek())
            self.stack_2.pop()
        elif self.stack_2.size==0 and self.stack_1.size==0:
            print("Queue is empty.")
        else:
            while self.stack_1.size>0:
                self.stack_2.push(self.stack_1.peek())
                self.stack_1.pop()
            print("Dequeued:",self.stack_2.peek())
            self.stack_2.pop()
            """If stack_2 is empty the we push all element of stack_1 into stack_2
            in the reverse manner and pop all elements fron stack_1 and then pop
            peek elemet fron stack_2."""
    def display(self):
         temp=self.stack_2
         k=Stack()
         while temp.size>0:
             k.push(temp.pop())
         m=Stack()
         while self.stack_1.size>0:
             m.push(self.stack_1.pop())
         temp=m
         while temp.size>0:
             k.push(temp.pop())
         k.display()
         while k.size>0:
             self.stack_2.push(k.pop())
    def isNotEmpty(self):
        if self.stack_1==0 and self.stack_2==0:
            return False
        else:
            return True
    def front(self):
        if self.stack_2.size==0:
            while self.stack_1.size>0:
                self.stack_2.push(self.stack_1.peek())
                self.stack_1.pop()
        print("Front:",self.stack_2.peek())
        return self.stack_2.peek()        
    def rear(self):
        if self.stack_1.size==0:
            while self.stack_2.size>0:
                self.stack_1.push(self.stack_2.peek())
                self.stack_2.pop()
        print("Rear:",self.stack_1.peek())
        return self.stack_1.peek()                
            
         
def main():
    Q=Queue()
    Q.enqueue(1)
    Q.enqueue(2)
    Q.enqueue(3)
    Q.enqueue(4)
    Q.enqueue(5)
    Q.display()
    Q.front()
    Q.rear()
    Q.enqueue(6)
    Q.enqueue(7)
    Q.dequeue()
    Q.display()
    Q.enqueue(8)
    Q.enqueue(9)
    Q.display()
    Q.dequeue()
    Q.display()
    Q.front()
    Q.rear()

if __name__ == '__main__':
    main()

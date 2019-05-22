class Node:
	def __init__(self,data):
		self.data = data
		self.next = None

class LL:
	def __init__(self):
		self.head = None
		self.length = 0
		self.dummy = None
		self.ans = True


	def addNode(self,data):
		if(self.head == None):
			self.head = Node(data)
			self.dummy = self.head
		else:
			node = Node(data)
			node.next=self.head
			self.head=node
			self.dummy = self.head


	def printLL(self):
		temp = self.head
		while(temp!=None):
			print(temp.data)
			temp=temp.next

	def rev(self):
		one = self.head
		two = one.next
		three = two.next

		one.next=None

		while two != None:
			self.head=two
			two.next=one
			one=two
			two=three
			if three != None:
				three=three.next

	def isPal(self,node):
		if node==None:
			return

		self.isPal(node.next)

		if node!=None and self.dummy != None:
			print(self.dummy.data , " - " ,node.data)
			if(node.data == self.dummy.data):
				self.dummy = self.dummy.next
			else:
				self.ans=False


		


ll = LL()
ll.addNode(1)
ll.addNode(2)
ll.addNode(3)
ll.addNode(4)
ll.addNode(5)
ll.addNode(4)
ll.addNode(3)
ll.addNode(2)
ll.addNode(1)
ll.printLL()
print("dummy : ",ll.dummy.data)
ll.isPal(ll.head)
if ll.ans:
	print("is  pal")
else:
	print("is not pal")

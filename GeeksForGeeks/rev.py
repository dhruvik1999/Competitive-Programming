class Node:
	def __init__(self,data):
		self.data = data
		self.next = None

class LL:
	def __init__(self):
		self.head = None
		self.length = 0

	def addNode(self,data):
		if(self.head == None):
			self.head = Node(data)
		else:
			node = Node(data)
			node.next=self.head
			self.head=node

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
		


ll = LL()
ll.addNode(1)
ll.addNode(2)
ll.addNode(3)
ll.addNode(4)
ll.addNode(5)
ll.printLL()
print("---------------")
ll.rev()
ll.printLL()

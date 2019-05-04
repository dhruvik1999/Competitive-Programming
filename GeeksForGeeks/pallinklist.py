class Node:
	def __init__(self,data):
		self.data = data
		self.next = None

class linklist:
	def __init__(self):
		self.head = None

	def addNode(self,data):
		if self.head == None:
			self.head = Node(data)
		else:
			

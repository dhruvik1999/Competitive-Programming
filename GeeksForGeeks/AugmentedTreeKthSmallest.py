class Node:
	def __init__(self,data):
		self.data = data
		self.right = None
		self.left = None

class BST:
	def __init__(self):
		self.root = None
		self.cnt = 0

	def addNode(self,data,node ,parent=None):
		

		if(node == None):
			if parent==None:
				self.root = Node(data)
				return

			if(parent.data > data):
				parent.left = Node(data)
			else:
				parent.right = Node(data)
		else:
			if(node.data > data):
				self.addNode(data,node.left,node)
			else:
				self.addNode(data,node.right,node)

	def inOrder(self,node,k):
		if(node!=None):
			self.inOrder(node.left,k)
			self.cnt+=1
			if(self.cnt==k):
				print(self.cnt , node.data)
			self.inOrder(node.right,k)

k = int(input())
bst = BST()
bst.addNode(100,bst.root)
bst.addNode(14,bst.root)
bst.addNode(222,bst.root)
bst.addNode(33,bst.root)
bst.addNode(40,bst.root)
bst.inOrder(bst.root,k)

		



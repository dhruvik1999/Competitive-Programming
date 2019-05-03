class Node:
	def __init__(self,data):
		self.data = data
		self.right = None
		self.left = None
		self.noLeft = 0

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
				node.noLeft += 1
			else:
				self.addNode(data,node.right,node)

	def inOrder(self,node):
		if(node!=None):
			self.inOrder(node.left)
			self.cnt+=1
			print(node.data,node.noLeft)
			self.inOrder(node.right)

	def find(self,node,k):
		if node.noLeft + 1 == k:
			return node.data
		elif node.noLeft + 1 < k:
			return self.find(node.right,k-(node.noLeft+1))
		else:
			return self.find(node.left,k)

k = int(input())
bst = BST()
bst.addNode(100,bst.root)
bst.addNode(14,bst.root)
bst.addNode(222,bst.root)
bst.addNode(33,bst.root)
bst.addNode(40,bst.root)
#bst.inOrder(bst.root)
print(bst.find(bst.root,k))

		



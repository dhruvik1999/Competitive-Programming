class Node:
	def __init__(self,value):
		self.value = value
		self.right = None
		self.left = None

class BST:
	def __init__(self):
		self.root = None
		print("bst cnst")
		self.sum = 0

	def insert(self,value):
		if self.root == None:
			self.root = Node(value)
			self.root.left=None
			self.root.right=None
		else:
			temp = self.root
			par = Node(-1)
			while(True):
				#print(par.value , value)
				if temp == None:
					#print("NONE")
					if par.value > value:
						par.left = Node(value)
					else:
						par.right = Node(value)
					break 
				elif temp.value > value:
					#print('#')
					par=temp
					temp = temp.left
					
				else:
					#print("*")
					par=temp
					temp=temp.right
					


	def inord(self,node):
		if node == None:
			return

		self.inord(node.right)
		node.value+=self.sum
		self.sum = node.value
		print(self.sum)
		self.inord(node.left)

def main():
	bst = BST()

	bst.insert(50)
	bst.insert(30)
	#print(bst.root.value)
	bst.insert(20)
	#print(bst.root.value)
	bst.insert(40)
	bst.insert(70)
	bst.insert(60)
	bst.insert(80)
	bst.inord(bst.root)


main()



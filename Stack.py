# -*- coding: utf-8 -*-

class Stack:
	
	def __init__(self):
		self.head = None
		self.length = 0

	def push(self, value):
		node = Node(value, self.head)
		self.head = node
		self.length = self.length + 1

	def pop(self):
		if self.is_empty():
			print("The stack is empty")
			return
		else:
			temp = self.head
			value = temp.value
			self.head = temp.next
			return value

	def is_empty(self):
		return (self.length == 0 and self.head is None)

	def size(self):
		return self.length

class Node:
	
	def __init__(self, value, next):
		self.value = value
		self.next = next



if __name__ == '__main__':
	stack = Stack()
	print(stack.is_empty())
	stack.pop()
	stack.push(10)
	print("The size is: {0}".format(stack.size()))
	print("Extract element: {0}".format(stack.pop()))
	stack.is_empty()
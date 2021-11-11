#include <iostream>


struct Node{
	Node(int value) : value(value) {}
	Node* left{NULL};
	Node* right{NULL};
	int value;
	int count{1};
};

Node* add_node(Node* node, int value){
	if(!node)
		return new Node(value);
	if(node->value == value){
		node->count += 1;
	}else if(node->value > value){
		node->left = add_node(node->left, value);
	}else if(node->value < value){
		node->right = add_node(node->right, value);
	}
	return node;
}

void print_inorder(Node* node){
	if(!node)
		return;
	print_inorder(node->left);
	std::cout << node->value << "|" << node->count << std::endl;
	print_inorder(node->right);
}

int main(){
	Node first(5);
	Node* head = &first;
	head = add_node(head, 3);
	head = add_node(head, 5);
	head = add_node(head, 10);
	head = add_node(head, 1);
	head = add_node(head, 2);
	head = add_node(head, 7);
	print_inorder(head);
}

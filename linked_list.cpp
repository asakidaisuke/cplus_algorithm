#include <iostream>


struct Node{
	Node(int value) : value(value) {}
	Node* next{NULL};
	int value;
};


void add(Node** head, int value){
	Node* new_node = new Node(value);
	new_node->next = (*head);
	(*head)=new_node;
}

void print(Node* node){
	while(node){
		std::cout << node->value << std::endl;
		node = node->next;
	}
}

int main(){
	Node first(5);
	Node* head = &first;
	add(&head, 3);
	add(&head, 4);
	add(&head, 1);
	add(&head, 10);
	print(head);
}

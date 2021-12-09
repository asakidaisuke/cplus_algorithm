#include <iostream>


struct Node{
	Node(int value) : value(value), next(NULL), prev(NULL) {}
	Node* next;
	Node* prev;
	int value;
};

void push(Node** head, int value){
	if(!*head){
		*head = new Node(value);
		return;
	}
	Node* temp = *head;
	*head = new Node(value);
	(*head)->next = temp;
	temp->prev = *head;
}

void insert_after(Node** head, int value, int new_value){
	Node* curr = *head;
	while(curr){
		if(curr->value == value){
			Node* new_node = new Node(new_value);
			Node* next = curr->next;
			curr->next = new_node;
			new_node->prev = curr;
			new_node->next = next;
			if(next){
				next->prev = new_node;
			}
			return;
		}
		curr = curr->next;
	}
	std::cout << "no matching node" << std::endl;
}

void pop(Node** head){
	Node* current = *head;
	Node* next = current->next;
	next->prev = NULL;
	*head = next;
	delete current;
}

void delete_node(Node** head, int value){
	Node* current = *head;
	if(current && current->value == value){
		Node* next = current->next;
		next->prev = NULL;
		*head = next;
		delete current;
		return;
	}
	current = current->next;
	while(current){
		if(current->value == value){
			Node* next = current->next;
			Node* prev = current->prev;
			prev->next = next;
			if(next){next->prev = prev;}
			return;
		}
		current = current->next;
	}
	std::cout << "no matched value" << std::endl;
}

void print(Node* head){
	while(head){
		std::cout << head->value << " ";
		if(!head->next) break;
		head = head->next;
	}
	std::cout << std::endl;
	std::cout << "reverse" << std::endl;
	while(head){
		std::cout << head->value << " ";
		head = head->prev;
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]){
	Node* head = NULL;
	push(&head, 10);
	push(&head, 1);
	push(&head, 4);
	push(&head, 6);
	print(head);
	std::cout << "insert 5 after 1" << std::endl;
	insert_after(&head, 1, 5);
	print(head);
	std::cout << "insert 7 after 6" << std::endl;
    insert_after(&head, 6, 7);
    print(head);	
	std::cout << "insert 11 after 10" << std::endl;
    insert_after(&head, 10, 11);
    print(head);
	std::cout << "pop" << std::endl;
	pop(&head);
	print(head);
	std::cout << "delete 7" << std::endl;
    delete_node(&head, 7);
    print(head);
	std::cout << "delete 5" << std::endl;
    delete_node(&head, 5);
    print(head);
	std::cout << "delete 11" << std::endl;
    delete_node(&head, 11);
    print(head);
}

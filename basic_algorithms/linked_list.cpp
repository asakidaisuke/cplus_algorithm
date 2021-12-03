#include <iostream>


struct Node{
	Node(int value) : value(value) {}
	Node* next{NULL};
	int value;
};


void add(Node** head, int value){
	Node* new_node = new Node(value);
	if(!*head){
		(*head)=new_node;
		return;
	}
	new_node->next = (*head);
	(*head)=new_node;
}

void delete_node(Node** head, int value){
	Node* prev = *head;
	
	if (prev && prev->value == value){
		*head = prev->next;
		delete prev;
		return;
	}
	while(prev){
		Node* curr = prev->next;
		if(curr && curr->value==value){
			prev->next = curr->next;
			delete curr;
			return;
		}
		prev = curr;
	}
	std::cout << "no matching" << std::endl;
}

void print(Node* node){
	while(node){
		std::cout << node->value << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

int main(){
	Node* head = NULL;
	add(&head, 3);
	add(&head, 4);
	add(&head, 1);
	add(&head, 10);
	print(head);
	std::cout << "after delete 4" << std::endl;
	delete_node(&head, 4);
	print(head);
    std::cout << "after delete 3" << std::endl;
	delete_node(&head, 3);
    print(head);
    std::cout << "after delete 10" << std::endl;
	delete_node(&head, 10);
    print(head);
    std::cout << "try to delete 100" << std::endl;
	delete_node(&head, 100);
    print(head);

}

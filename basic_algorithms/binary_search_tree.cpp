#include <iostream>
#include <queue>

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

void breadth_first_serach(std::queue<Node*>* to_visit){
	if(to_visit->size()==0){return;}
	Node* current_element = to_visit->front();
	to_visit->pop();
	if(current_element){
		std::cout << current_element->value << std::endl;
		to_visit->push(current_element->left);
		to_visit->push(current_element->right);
	}
	breadth_first_serach(to_visit);
}

void print_breadth_first(Node* node){
	std::queue<Node*> to_visit;
	to_visit.push(node);
	breadth_first_serach(&to_visit);
}


void depth_first_print(Node* node){
	if(!node){return;}
	std::cout << node->value << std::endl;
	depth_first_print(node->left);
	depth_first_print(node->right);

}

void delete_node(Node* node){
	

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
	head = add_node(head, 4);
	head = add_node(head, 10);
	head = add_node(head, 11);
	head = add_node(head, 15);
	head = add_node(head, 21);
	head = add_node(head, 4);
	head = add_node(head, 2);
	head = add_node(head, 9);
	head = add_node(head, 19);
	std::cout << "print inorder" << std::endl;
	print_inorder(head);
	std::cout << "print depth first" << std::endl;
	depth_first_print(head);
	std::cout << "print breadth first" << std::endl;
	print_breadth_first(head);
}


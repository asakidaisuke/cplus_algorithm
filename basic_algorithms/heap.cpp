#include <iostream>
#include <vector>


void swap(std::vector<int>* array, int i, int j){
	int temp = (*array)[i];
	(*array)[i] = (*array)[j];
	(*array)[j] = temp;
}

void heapify(std::vector<int>* array, int top, int tail){
	int left = top*2+1;
	int right = top*2+2;
	int largest = top;

	if(tail >= left && (*array)[largest] < (*array)[left]){
		largest = left;
	}
	if(tail >= right &&(*array)[largest] < (*array)[right]){
		largest = right;
	}
	if(largest != top){
		swap(array, top, largest);
		heapify(array, largest, tail);
	}
	
}

void build_heap(std::vector<int>* array){
	int start_index = array->size() / 2 - 1;
	int tail = array->size() -1;
	for(int i=start_index; i > -1; i--){
		heapify(array, i, tail);
	}
	
}

void heap_sort(std::vector<int>* array){
	build_heap(array);
	for(int i=array->size()-1; i<-1; i--){
		swap(array, 0, i);
		heapify(array, 0, i);
	}
}

void insert(std::vector<int>* array, int key){
	array->push_back(key);
	int current_position = array->size()-1;
	while(current_position!=0){
		if((*array)[current_position] > (*array)[current_position/2]){
			swap(array, current_position, current_position/2);
			current_position = current_position/2;
		}else{
			break;
		}
	}

}

void pop(std::vector<int>* array){
	swap(array, 0, array->size()-1);
	array->pop_back();
	heapify(array, 0, array->size()-1);	
}

void print(std::vector<int>* array){
	for(auto ele: *array){
		std::cout << ele << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[]){
	int N;
	std::cin >> N;
	std::vector<int> array(N);

	for(int i=0; i<N;i++){
		std::cin >> array[i];
	}

	build_heap(&array);
	std::cout << "heap built" << std::endl;
	print(&array);

	std::cout << "insert key" << std::endl;
	int key;
	std::cin >> key;
	insert(&array, key);
    std::cout << "key inserted" << std::endl;
    print(&array);

	pop(&array);
    std::cout << "pop top" << std::endl;
    print(&array);


}

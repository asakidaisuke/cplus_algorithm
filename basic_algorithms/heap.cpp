#include <iostream>
#include <vector>


void swap(std::vector<int>* array, int i, int j){
	int temp = (*array)[i];
	(*array)[i] = (*array)[j];
	(*array)[j] = temp;
}

void heapify(std::vector<int>* array, int top){
	int left = top*2+1;
	int right = top*2+2;
	int largest = top;

	if((*array)[largest] < (*array)[left]){
		largest = left;
	}
	if((*array)[largest] < (*array)[right]){
		largest = right;
	}
	if(largest != top){
		swap(array, top, largest);
		heapify(array, largest);
	}
	
}

void build_heap(std::vector<int>* array){
	int start_index = array->size() / 2 - 1;
	for(int i=start_index; i > -1; i--){
		heapify(array, i);
	}
	
}

void print(std::vector<int>* array){
	for(auto ele: *array){
		std::cout << ele;
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
	print(&array);
}

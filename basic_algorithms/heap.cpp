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

	heap_sort(&array);
	print(&array);
}

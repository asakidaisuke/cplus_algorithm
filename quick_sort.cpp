#include <vector>
#include <iostream>


void swap(std::vector<int>* array, int i, int j){
	int temp = (*array)[i];
	(*array)[i] = (*array)[j];
	(*array)[j] = temp;
}

int partition(std::vector<int>* array, int start_index, int end_index){
	int pivot = (*array)[end_index];
	int replace_index = start_index;
	for (int i=start_index; i < end_index; i++){
		if((*array)[i] < pivot){
			swap(array, i, replace_index);
			replace_index++;
		}
	}
	swap(array, end_index, replace_index);
	return replace_index;
}

void quick_sort(std::vector<int>* array, int start_index,int end_index){
	if (start_index > end_index)
		return;
	int middle_index = partition(array, start_index, end_index);
	quick_sort(array, start_index, middle_index-1);
	quick_sort(array, middle_index+1, end_index);
}


int main(){
	int N;
	std::cin >> N;
	
	std::vector<int> array(N);
	for(int i=0; i < N;i++){
		std::cin >> array[i];
	}
	quick_sort(&array, 0, N-1);
	for(auto element : array){
		std::cout << element << std::endl; 
	}
	

}

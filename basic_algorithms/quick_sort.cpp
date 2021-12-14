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


void quick_sort_iterative(std::vector<int>* array){
	std::vector<std::pair<int,int>> stack;
	stack.push_back(std::pair(0, array->size()-1));
	while(stack.size() != 0){
		std::pair<int,int> left_and_right = stack.back(); stack.pop_back();
		int middle = partition(array, left_and_right.first, left_and_right.second);
		if(left_and_right.first < middle-1){
			stack.push_back(std::pair(left_and_right.first, middle-1));
		}
		if(middle+1 < left_and_right.second){
            stack.push_back(std::pair(middle+1, left_and_right.second));
        }
		std::cout << stack.size() << std::endl;
	}
}

int main(){
	int N;
	std::cin >> N;
	std::vector<int> array(N);
	for(int i=0; i < N;i++){
		std::cin >> array[i];
	}
	std::vector<int> array_for_iter{array};

	quick_sort(&array, 0, N-1);
	for(auto element : array){
		std::cout << element << " "; 
	}
	std::cout << std::endl;

	quick_sort_iterative(&array_for_iter);
	for(auto element : array_for_iter){
        std::cout << element << " ";
    }
    std::cout << std::endl;

}

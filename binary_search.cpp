#include <vector>
#include <iostream>



int binary_search_iterative(std::vector<int>* array, int search_num){
	int left_index{0};
	int right_index = array->size()-1;
	while(left_index <= right_index){
		int middle_index = (left_index+right_index) / 2;
		if ((*array)[middle_index] == search_num){
			return middle_index;
		}else if((*array)[middle_index] < search_num){
			left_index = middle_index+1;
		}else{
			right_index = middle_index-1;
		}
	}
	return -1;
}


int binary_search_recursive(std::vector<int>* array, int search_num, int left_index, int right_index){
	if (right_index < left_index)
		return -1;
	int middle_index = (left_index + right_index) / 2;
	if ((*array)[middle_index] == search_num)
		return middle_index;
	else if ((*array)[middle_index] < search_num)
		return binary_search_recursive(array, search_num, middle_index+1, right_index);
	else
		return binary_search_recursive(array, search_num, left_index, right_index-1);
}

int main(){
	int N, search_number;
	std::cout << "input array size" << std::endl;
	std::cin >> N;
	std::cout << "input search number" << std::endl;
	std::cin >> search_number;
	
	std::vector<int> array(N);
	std::cout << "input array element" << std::endl;
	for(int i=0; i < N; i++){
		std::cin >> array[i];
	}
	
	int index_i = binary_search_iterative(&array, search_number);
    std::cout << "found index by iterative search is " << index_i <<  std::endl;	
	
	int index_r = binary_search_recursive(&array, search_number, 0, N-1);
	std::cout << "found index by recursive search is " << index_r <<  std::endl;
}

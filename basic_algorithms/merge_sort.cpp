# include <vector>
# include <iostream>


void merge_sort(std::vector<int>* array, int start_index, int end_index){
	if (end_index - start_index <= 1)
		return;
	int middle_index = (start_index + end_index) / 2;
	merge_sort(array, start_index, middle_index);
	merge_sort(array, middle_index, end_index);
	int f_i{start_index}, b_i{middle_index};
	bool to_be_continued = true;
	std::vector<int> temp_array;
	while(to_be_continued){
		if ((*array)[f_i] < (*array)[b_i]){
			temp_array.push_back((*array)[f_i]);
			f_i++;
		}else{
			temp_array.push_back((*array)[b_i]);
			b_i++;
		}
		if(f_i == middle_index || b_i == end_index)
			to_be_continued = false;
	}
	while(f_i < middle_index){
		temp_array.push_back((*array)[f_i]);
		f_i++;
	}
	while(b_i < end_index){
		temp_array.push_back((*array)[b_i]);
		b_i++;
	}

	for(int i=start_index; i < end_index; i++)
		(*array)[i] = temp_array[i - start_index];
}

int main(){
	int N;
    std::cin >> N;

	std::vector<int> array(N);
	for (int i=0; i < N; i++){
		std::cin >> array[i];
	}
	merge_sort(&array, 0, N);
	std::cout << "--------solution-----------" << std::endl;
	for(auto element : array){
		std::cout << element << std::endl;
	}

}

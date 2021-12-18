#include <string>
#include <iostream>

void reverse(std::string& target, int start_index, int end_index){
	for(int i=0; i < (end_index-start_index) / 2 + 1; i++){
		std::swap(target[start_index+i], target[end_index-i]);
	}
}

int main(int argc, char** argv){
	std::string target = "I reverse this sentense";
	reverse(target, 0, target.size()-1);
	int prev_stop{0};
	for(int i=0; i<target.size();i++){
		if(target[i] == ' '){
			reverse(target, prev_stop, i-1);
			prev_stop = i+1;
		}
	}
	reverse(target, prev_stop, target.size()-1);
	std::cout << target << std::endl;
}

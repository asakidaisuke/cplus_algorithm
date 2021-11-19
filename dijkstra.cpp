#include <vector>
#include <iostream>
#include <queue>

using DistanceMat = std::vector<std::vector<int>>;
using EdgeId = int;
using Pair = std::tuple<int, EdgeId, EdgeId>;

void dijkstra(DistanceMat* graph, EdgeId source){
	int num_node = graph->size();
	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> to_visit;
	std::vector<bool> is_reserved(num_node, false);
	std::vector<int> distance_from_source(num_node, 10000);
	
	is_reserved[source] = true;
	distance_from_source[source] = 0;
	for(EdgeId v = 0; v < num_node; v++){
		if((*graph)[0][v] == 0) continue;
		to_visit.push(Pair((*graph)[source][v], source, v));
	}
	while(!to_visit.empty()){
		Pair poped = to_visit.top(); to_visit.pop();
		EdgeId to = std::get<2>(poped), from = std::get<1>(poped); int dis = std::get<0>(poped);
		//std::cout << to << from << dis << std::endl;
		if (is_reserved[to]) continue;
		if (distance_from_source[from] + dis < distance_from_source[to]){
			is_reserved[to] = true;
			distance_from_source[to] = distance_from_source[from] + dis;
			std::cout << to << std::endl;
			for(EdgeId v = 0; v < num_node; v++){
        		if((*graph)[to][v] == 0) continue;
        		to_visit.push(Pair((*graph)[to][v], to, v));
   			 }
		}	
	}
}


int main(){
	DistanceMat graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                          { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                          { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                          { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                          { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                          { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                          { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                          { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                          { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(&graph, 0);
 
    return 0;
}

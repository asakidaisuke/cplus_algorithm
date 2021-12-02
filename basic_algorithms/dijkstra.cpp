#include <vector>
#include <iostream>
#include <queue>

#define Inf 100000
#define Unknown -1

using DistanceMat = std::vector<std::vector<int>>;
using EdgeId = int;
using Distance = int;
using DistanceFromSource = std::pair<Distance, EdgeId>;


void dijkstra(DistanceMat* graph, EdgeId source){
	int num_node = graph->size();
	std::priority_queue<DistanceFromSource, std::vector<DistanceFromSource>, std::greater<DistanceFromSource>> next_node_info;
	std::vector<bool> is_reserved(num_node, false);
	std::vector<Distance> distances(num_node, Inf);
	std::vector<EdgeId> froms(num_node, Unknown);
	
	is_reserved[source] = true;
	distances[source] = 0;
	froms[source] = 0;
	for(EdgeId v = 0; v < num_node; v++){
		Distance each_dist = (*graph)[source][v];
		if(each_dist == 0) continue;
		froms[v] = 0;
		distances[v] = each_dist;
		next_node_info.push(DistanceFromSource(each_dist, v));
	}
	while(!next_node_info.empty()){
		DistanceFromSource poped = next_node_info.top(); next_node_info.pop();
		is_reserved[poped.second] = true;
		for (EdgeId to=0; to < num_node; to++){
			if(is_reserved[to] || (*graph)[poped.second][to] == 0) continue;
			if(distances[poped.second] + (*graph)[poped.second][to] < distances[to]){
				distances[to] = distances[poped.second] + (*graph)[poped.second][to];
				froms[to] = poped.second;
				next_node_info.push(DistanceFromSource(distances[to], to));
			}
		}
	}
	for (int i=0; i< num_node; i++){
		std::cout << "node " << i << " from " << froms[i] << " distance from source " << distances[i] << std::endl;
	}
}


int main(){
	DistanceMat graph = { { 0, 3, 2, 0, 0, 0, 0},
                          { 3, 0, 2, 0, 2, 0, 1},
                          { 2, 0, 0, 3, 0, 0, 4},
                          { 0, 0, 3, 0, 4, 7, 1},
                          { 0, 0, 2, 4, 0, 3, 0},
                          { 0, 0, 0, 2, 3, 0, 0},
                          { 0, 1, 4, 1, 0, 0, 0}};
    dijkstra(&graph, 0);
 
    return 0;
}

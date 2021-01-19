#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Edge
{
    int start;
    int end;
};

class Graph
{
    vector<vector<int> > route;
    int num_of_nodes;
    public:
        Graph(vector<Edge> &edges, int N);
        bool isConnected(int start, int end);
        void visualize();
};

Graph::Graph(vector<Edge> &edges, int N)
{
    int start, end;
    route.resize(N);
    for(int i=0; i < edges.size(); i++)
    {
        start = edges[i].start;
        end = edges[i].end;
        route[start].push_back(end);
    }
    num_of_nodes = N;
}

void Graph::visualize()
{
    string text = "->";
    string message;
    for(int i=0; i < num_of_nodes; i++)
    {
        for(int j=0; j < route[i].size(); j++)
        {
            message = to_string(i) + text + to_string(route[i][j]);
            cout << message << endl;
        }
    }
}

bool Graph::isConnected(int start, int end)
{
    vector<bool> visited(num_of_nodes,false);
    queue<int> q;
    int visiting;

    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        visiting = q.front();
        q.pop();
        cout << visiting << endl;
        if(visiting == end)
            return true;
        for(int node :route[visiting])
        {
            if(!visited[node])
            {
                visited[node] = true;
                q.push(node);
            }
        }
    }
    return false;
}

int main()
{
    vector<Edge> route = {{1,2},{3,5},{5,3},{6,7},{3,4},{2,1},{4,3},{1,3}};
    int number_of_graph = 8;
    Graph graph(route, number_of_graph);
    graph.visualize();
    cout << graph.isConnected(1,6);
}

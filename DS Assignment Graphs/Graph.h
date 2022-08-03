#ifndef GRAPH__H
#define GRAPH__H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <set>
#include <algorithm>
#include <queue>
// You may include more libraries.

using namespace std;
class node;

class edge
{
	// You may add more variables and functions in this class
	public:
		node* Origin;
		node* Dest;
		float weight;
		friend bool operator < (edge a, edge b);
		friend bool operator > (edge a, edge b);	
};
class node
{
	// You may add more variables and functions in this class
	public:
		int visit; // flag to check if the node has been already visited
		string name;
		int distance;
		node* previous_node;
		vector<edge> edges; // edges connected to node
		friend bool operator < (node a, node b);
		friend bool operator > (node a, node b);
};


class Graph
{
	public:
		vector<node*> Mst; // minimum spanning tree
		vector<node*> people;
		vector<edge> arcs;
		Graph(char* filename, bool isUnitLenght);
		void display(node* temp);// displays the graph
		int name_to_index(string name);
		priority_queue<edge> sort_edges();
		void Reachable_helper(string start, int start_index,string dest, bool visited[]);
		bool Reachable(string start, string dest);
		vector<node*> Kruskal(); //runs kruskal algorithm and returns the Minimum spanning tree
		vector<string> Dijkstra(string start, string dest);
		int vector_contains(vector<vector<node*>> v, node *find);

};

#endif


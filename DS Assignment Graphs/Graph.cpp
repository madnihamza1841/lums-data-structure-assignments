#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>
#include <limits.h>
// #include <pqueue>

using namespace std;

bool operator < (edge a, edge b)
{
	return a.weight >b.weight;
}
bool operator > (edge a, edge b)
{
	return a.weight < b.weight;
}

bool operator < (node a, node b)
{
	return a.distance > b.distance;
}
bool operator > (node a, node b)
{
	return a.distance <b.distance;
}

Graph::Graph(char* file, bool isUnitLength=false)
{
	string line;
	ifstream friend_file (file);
	// vector<node*> nodes;
	// vector<edge> edges;
	while (getline (friend_file,line))
	{
		if(line == "CONNECTIONS")
			break;
		if(line != "PEOPLE")
		{
			node *temp = new node;
			temp->name = line;
			temp->visit =0;
			people.push_back(temp);
		}
	}	
	bool check =true;
	// cout<< endl;
	// cout << endl;
	while(getline (friend_file,line))
	{
		vector<string> v;
		boost:: split(v, line, boost::is_any_of(" "));
		// cout << v[0]<<"    "<< v[1]<< "    "<< v[2]<< endl;
		int index1=-1;
		int index2=-1;
		for(int i=0; i<people.size(); i++) //check if every word has a space added in txt file incase does not work.
		{
			if (people[i]->name == v[0]) index1 = i;
			if (people[i]->name == v[1]) index2 =i;
		}

		edge temp1;
		temp1.Origin = people[index1];
		temp1.Dest = people[index2];
		if(isUnitLength == false) temp1.weight = stoi(v[2]);
		else temp1.weight = 1; 
		

		edge temp2; 
		temp2.Origin = people[index2];
		temp2.Dest = people[index1];
		if(isUnitLength == false) temp2.weight = stoi(v[2]);
		else temp2.weight = 1;

		people[index1]->edges.push_back(temp1);
		people[index2]->edges.push_back(temp2);

		arcs.push_back(temp1);
	}

	friend_file.close();

	// display(people[2]);
}

void Graph::display(node* temp)
{
	if(temp->visit)
		return;
	
	cout << "Person: " << temp->name;
	temp->visit = 1;
	for(int i=0; i< temp->edges.size(); i++)
	{
		if(!temp->edges[i].Origin->visit || !temp->edges[i].Dest->visit)
		cout << "->" << temp->edges[i].weight << endl;
		display(temp->edges[i].Origin);
		display(temp->edges[i].Dest);
	}
}

int Graph::name_to_index(string Name)
{
	for (int i=0; i<people.size(); i++) if(people[i]->name == Name) return i;

	return -1;
} 

void Graph::Reachable_helper(string start,int start_index,string dest,bool visited[])
{
	visited[start_index] = true;
	// cout << people[start_index]->name << " "<< start_index<< endl;

	for(int i=0; i<people[start_index]->edges.size(); i++)
	{
		if (visited[name_to_index(people[start_index]->edges[i].Dest->name)] == false)
		{
			Reachable_helper(people[start_index]->edges[i].Dest->name, name_to_index(people[start_index]->edges[i].Dest->name), dest,visited);
		}
	}
}

bool Graph::Reachable(string start, string dest)
{
	int start_index =name_to_index(start);
	// cout << start << " with index " << start_index << endl;
	// for(int i=0; i<people.size(); i++) if(people[i]->name == start) start_index = i;

	bool *visited = new bool[people.size()];
	for(int i=0; i<people.size(); i++) visited[i] = false;

	Reachable_helper(start,start_index,dest,visited);
	
	if (visited[name_to_index(dest)] == 1) return 1;
	else return 0;

}
                                                                                                                                                                                                  

priority_queue<edge> Graph::sort_edges()
{
	priority_queue<edge> sorted_edges;

	for(int i=0; i<arcs.size(); i++)
	{
		sorted_edges.push(arcs[i]);
	}

	// cout<< sorted_edges.top().weight<< endl;

	return sorted_edges;
}

int Graph::vector_contains(vector<vector<node*>> v, node *find)
{
	for (int i=0; i<v.size(); i++)
		for(int j=0; j<v[i].size(); j++)  
			if(v[i][j] == find) return i;

	return -1;
}

vector<node*> Graph::Kruskal()
{
	priority_queue<edge> EDGES = sort_edges();

	vector<edge> mst_edges;

	vector<vector<node*>> sets;
	for (int i=0; i<people.size(); i++)
	{
		vector<node*> v;
		v.push_back(people[i]);

		sets.push_back(v);
	}

	for(int i=0; i<arcs.size(); i++)
	{
		edge temp = EDGES.top();
		EDGES.pop();

		for(int j=0; j<sets.size(); j++)
		{
			if(sets[j].empty()) continue;

			int index_origin = vector_contains(sets, temp.Origin);
			int index_dest = vector_contains(sets, temp.Dest);

			if (index_origin != index_dest)
			{
				for (int k=0; k<sets[index_dest].size(); k++)
				{
					sets[index_origin].push_back(sets[index_dest][k]);
				}

				sets[index_dest].clear();
				mst_edges.push_back(temp);

			}
		}
	}
	cout<< endl;
	cout<< "Printing MST Edges: "<< endl;
	cout << endl;
	for (int i = 0; i < mst_edges.size();i++)
	{	
		cout << mst_edges[i].Origin->name<< " "<< mst_edges[i].Dest->name << " " << mst_edges[i].weight<< endl;
	}

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i=0; i<people.size(); i++)
	{
		node *temp = new node;
		temp->name = people[i]->name;
		temp->visit = 0;

		Mst.push_back(temp);
	}

	for (int i=0; i<mst_edges.size(); i++)
	{
		Mst[name_to_index(mst_edges[i].Origin->name)]->edges.push_back(mst_edges[i]);
	}

	return Mst;

}

vector<string> Graph::Dijkstra(string start, string dest)
{
	vector<node> path;

	for (int i=0; i<people.size(); i++) //initializing all nodes to maximum distance from source and previous NULL
	{
		people[i]->previous_node = NULL;
		people[i]->distance = 100000;		
	}

	node* temp_start = people[name_to_index(start)];  //pointer to start and setting distance 0
	temp_start -> distance =0;

	node * traversal_node = temp_start;

	while(traversal_node != people[name_to_index(dest)])   //same as traversal_node != dest
	{
		path.push_back(*traversal_node);

		priority_queue<node> pq;
		for(int i=0; i<people.size(); i++) pq.push(*people[i]);

		for (int i=0; i<traversal_node->edges.size(); i++)
		{
			node* temp = traversal_node->edges[i].Dest;
			if(temp->distance > traversal_node->distance + traversal_node->edges[i].weight)
			{
				temp->distance = traversal_node->distance + traversal_node->edges[i].weight;
				temp->previous_node = traversal_node;
			}
		}

		
		node *node_ptr;
		for(int i=0; i<people.size(); i++)
		{
			node pq_top = pq.top();
			pq.pop();
			node_ptr = &pq_top;

			int count;

			for(count=0;count<path.size();count++) if(node_ptr->name==path[count].name) break;

			if(count==path.size()) break;
		}

		traversal_node=node_ptr;


		traversal_node= people[name_to_index(traversal_node->name)];

	}

	vector<string> result;
	while(traversal_node)
	{
		result.push_back(traversal_node->name);
		cout<< traversal_node->name<< endl;

		traversal_node= traversal_node->previous_node;
	}

	return result;
}

int main()
{
	char* filename = "friends.txt"; 
	Graph temp(filename,false);
	cout << "Question 1"<< endl;
	cout << endl;
	cout<< "Testing Reachability for Mannan and Ali: "; 
	cout << temp.Reachable("Mannan", "Ali")<< endl;
	cout << endl;
	cout<< "Testing Reachability for Mannan and Trump: "; 
	cout << temp.Reachable("Mannan", "Trump")<< endl;
	cout << endl;
	cout<< "Testing Reachability for Ali and Trump: "; 
	cout << temp.Reachable("Ali", "Trump")<< endl;
	cout << endl;
	cout << endl;


	Graph temp2(filename, true);
	cout << "Question 2 and 3"<< endl;
	cout << endl;
	cout << "Path for Ali and Trump with Unit length true; "<< endl;
	temp2.Dijkstra("Ali", "Trump");
	cout << endl;
	cout << "Path for Mannan and Trump with Unit length true; "<< endl;
	temp2.Dijkstra("Mannan", "Trump");
	cout << endl;
	cout << endl;


	Graph temp4(filename, false);
	cout << "Question 4"<< endl;
	cout << endl;
	cout << "Path for Ali and Trump with Unit length true; "<< endl;
	temp4.Dijkstra("Ali", "Trump");
	cout << "Total Friendship index = 11"<< endl;
	cout << endl;
	cout << "Path for Mannan and Trump with Unit length true; "<< endl;
	temp4.Dijkstra("Mannan", "Trump");
	cout << "Total Friendship index = 8"<< endl;
	cout << endl;
	cout << "Mannan is closer to Trump since lower friendship inddex"<< endl;
	cout << endl;
	cout << endl;


	cout << "Question 4"<< endl;
	cout << endl;
	cout<<"MST for UNit length graph: "<< endl;
	temp2.Kruskal();
	cout<< endl;
	cout<< endl;
	cout<<"MST for weighted graph: "<< endl;
	temp4.Kruskal();
	cout<< endl;
	cout<< endl;
	cout << "In case of unit length, there can be more than one MST but the algorithm is set in a way that it will print the same always as it works sequentially."<< endl;
	cout << endl;
	cout << "Weights on a graph effect the nodes and corresponding edges in MST. "<< endl;
	cout << endl;
	cout<< "The MST can be used to represent a social network, where the nodes are like minded people and the connections which are the edges can represent the interaction number between the people. By means of MST, the graph can be represented as such to show all vertices connected to each other to maximize the interactions. Therefore this can be used as recommendations/suggestions for new people to connect to each other"<< endl;









	return 0;
}

#endif

#ifndef __TREE_H
#define __TREE_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include "queue.cpp"

using namespace std;

struct TreeItem
{
	string name;
	int generation;
	vector<TreeItem*> children; 

	TreeItem()
	{
		name = "";
	}

	TreeItem(string name)
	{
		this->name = name;
	}
};


class Tree
{
	TreeItem *root;

public:
	// Constructor
	Tree(string name); 

	// Destructor
	~Tree();


	//helper functions
	int height_of_tree(TreeItem* p);
	void print_by_level(TreeItem* p, int level); 
	void destructor_recursion(TreeItem* p); 
	int GenerationCount_helper(TreeItem* p, int gen);
	TreeItem* AddChild_helper(TreeItem *p, string parent_name, string child_name);   // helper for addchild for recursion
	TreeItem* GetPerson_helper(TreeItem* p, string person_name);
	TreeItem* GetParent_helper(TreeItem* p, string person_name);
	bool contains(string person,vector<TreeItem*> v);


	// Member Functions
	void AddChild(string parent_name, string child_name);
	TreeItem* GetPerson(string person_name);
	void GetParent(string child_name);
	void GetChildren(string parent_name);
	int GetGeneration(string person_name);
	int GenerationCount(int generation);
	int GenerationGap(string person_name1, string person_name2);
	void level_traversal();

	/*You can add additional functions if necessary*/
};
#endif

#ifndef __TREE_CPP
#define __TREE_CPP
#include "tree.h"
#include "iostream"
#include <cstdlib>
using namespace std;



Tree::Tree(string name)
{
	TreeItem *temp = new TreeItem(name);
	temp -> generation =1;
	root = temp;	
}

void Tree:: destructor_recursion(TreeItem* p)
{
	if(p!=NULL)
	{
		for (int i=0; i<p->children.size(); i++)
		{
			destructor_recursion(p->children[i]);
		}
		delete p;
	}
}

Tree::~Tree()
{
	destructor_recursion(root);
}



void Tree::AddChild(string parent_name, string child_name)
{
	AddChild_helper(root, parent_name, child_name);	
}
TreeItem* Tree:: AddChild_helper(TreeItem *p, string parent_name, string child_name)
{
	if (p->name == parent_name)
	{
		TreeItem *temp = new TreeItem(child_name);
		temp -> generation = p ->generation +1;

		p -> children.push_back(temp); 
	}

	else if (p->name != parent_name && p->children.empty() ==true) {}

	else if (p->name != parent_name && p->children.empty() ==false) 
	{
		for (int i=0; i<p->children.size(); i++)
		{
			AddChild_helper(p->children[i], parent_name, child_name);
		}

	}
	return p;
}








TreeItem* Tree::GetPerson(string person_name)
{
	// TreeItem *temp = root;
	return GetPerson_helper( root, person_name); 
}
TreeItem* Tree:: GetPerson_helper(TreeItem* p, string person_name)
{
	if (p-> name == person_name) return p;
	else if (p->name != person_name && p->children.empty()==false)
	{
		TreeItem *temp = p;
		for (int i=0; i<p->children.size(); i++)
		{
			temp= GetPerson_helper(p->children[i], person_name);
			if(temp!=NULL) return temp;
			
		}
	}
	else return NULL;
}





bool Tree:: contains(string person, vector<TreeItem*> v)
{
	for (int i=0; i< v.size(); i++)
	{
		if (v[i]->name == person)return true; 
	}
	return false;
}

TreeItem* Tree:: GetParent_helper(TreeItem* p, string child_name)
{
	if (p->children.empty()==false)if (contains(child_name, p->children) == true)return p;
	else if (contains(child_name, p->children) ==false && p->children.empty()==false)
	{
		TreeItem *temp = p;
		for (int i=0; i<p->children.size(); i++)
		{
			temp= GetParent_helper(p->children[i], child_name);
			if(temp!=NULL) return temp;
			
		}
	}
	else return NULL;

}
void Tree::GetParent(string child_name)
{
	TreeItem* parent = GetParent_helper( root, child_name);
	cout << parent -> name;
}






void Tree::GetChildren(string parent_name)
{
	TreeItem* temp = GetPerson(parent_name);

	if (temp->children.empty()== false)
	{
		for (int i=0; i<temp->children.size(); i++) cout << temp->children[i]->name<< " ";
	}

	else 
	{
		cout << parent_name << " has no children";
	}
}

int Tree::GetGeneration(string person_name)
{
	TreeItem* temp = GetPerson(person_name);

	if (temp == NULL) return 0;

	return temp -> generation;
}


int Tree:: GenerationCount_helper(TreeItem* p, int gen)  
{  
	int count =0;
	if (p==NULL) return 0;
	else if (p!=NULL && p->generation> gen) return 0;
	else if (p!=NULL && p->generation == gen) {return 1;}

	else if (p!=NULL && p->generation<gen && p->children.empty()==false) 
	{
		for (int i=0; i<p->children.size(); i++)
    	{
    		count += GenerationCount_helper(p->children[i], gen);
    	}

	}
	return count;
}


int Tree::GenerationCount(int generation)
{
	return GenerationCount_helper(root, generation);

}

int Tree::GenerationGap(string person_name1, string person_name2)
{
	TreeItem* temp1 = GetPerson(person_name1);
	TreeItem* temp2 = GetPerson(person_name2);

	int gen1 = temp1 -> generation;
	int gen2 = temp2 -> generation;

	if (gen1-gen2>=0) return gen1-gen2;
	else return gen2-gen1;
}

int Tree:: height_of_tree(TreeItem* p)  
{  
    if (p == NULL)  
        return 1;  
    else
    {  
        vector<int> ht;
        for (int i=0; i< p->children.size(); i++)
        {
        	ht.push_back(height_of_tree(p->children[i]));
        }

        if (ht.empty() == true) return 1;
        int largest = ht[0];

        for (int i=0; i<ht.size(); i++)
        {
        	if (ht[i]> largest) largest = ht[i];
        }  
        
        return(largest + 1);  
    }  
}

void Tree:: print_by_level(TreeItem* p, int level)  
{  
    if (p == NULL)  
        return;  
    if (level == 1)  
        cout << p->name << " ";  
    else if (level > 1)  
    {  
        for (int i=0; i<p->children.size(); i++)
    	{
    		print_by_level(p->children[i], level-1);
    	}  
    }  
}


void Tree::level_traversal() 
{ 
	int tree_height = height_of_tree(root);

	for (int i=1; i<=tree_height; i++)
	{
		cout << "Level "<< i << ": ";
		print_by_level(root, i);
		cout << endl;
	}

} 


#endif

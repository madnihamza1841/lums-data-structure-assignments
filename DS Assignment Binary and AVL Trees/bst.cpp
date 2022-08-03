#ifndef __BST_CPP
#define __BST_CPP
#include "bst.h"
#include <iostream>
#include <queue>
// HELPER FUNCTIONS HERE...
template <class T>
BST<T>::BST(){
	root = NULL;
}

template <class T>
void BST<T>:: destroy_recursion(node<T> *ptr)
{
    if(ptr!=NULL)
    {
        destroy_recursion(ptr->left);
        destroy_recursion(ptr->right);
        delete ptr;
    }
} 

template <class T>
BST<T>:: ~BST(){

    destroy_recursion(root);
}

template <class T>
int BST<T> :: height (node<T>* p){
    if(p!=NULL) return p->height;
    else return 0;
}

// template <class T>
// int BST<T> :: balanceFactor(node<T>* p){
//     // you can use this to find balance factor.
// }

// template <class T>
// void BST<T> :: fixHeight(node<T>* p){
//     // use this function to fix height of a node after insertion or deletion.
//     return;
// }

// ROTATING HELPERS 
// template <class T>
// node<T>* BST<T> :: rotateleft(node<T>* p){
//     // Rotate left code goes here.
//     return p;
// }

// template <class T>
// node<T>* BST<T> :: rotateright(node<T>* p){
//     // Rotate right code goes here
//     return p;
// }

// template <class T>
// node<T>* BST<T> :: balance(node<T>* p){    
//     fixHeight(p);
//     return p;
//     // Balancing code goes here. You might need to find balance factor and call appropriate rotations.
// }
// CLASS FUNCTIONS HERE
template <class T>
void BST<T> :: insert(string value,T k){
    root = insertHelper(value,k,root);
}
// insertion helpe  r
template <class T>
node<T>* BST<T> :: insertHelper(string value,T k, node<T> *p) 
{
  
    if (p==NULL)
    {
        p = new node<T>(k,value);
    }
    else 
    {
        if (k<p->key)
        {
            p->left = insertHelper(value,k,p->left);
        } 
        else if (k>= p->key)
        {
            p->right = insertHelper(value,k,p->right);
        }
    }
///////////////////////////////////// updating height 
    if (p==NULL) p->height =0;
    else if(p->right==NULL && p->left==NULL)p->height =0;
    else p->height = 1 + max(height(p->left),height(p->right));
/////////////////////////////////////
    return p;
}
template<class T>
node<T>* BST<T> :: search(T key)
{
    node<T>* p = root;
    while(p!=NULL)
    {
        if (p->key == key) return p;
        else if(key<p->key) p=p->left;
        else if (key>p->key) p=p->right;
    }
    return NULL;
}
// DELETE HELPER FUNCTIONS
template<class T>
node<T>* BST<T> :: findmin(node<T> *p){
    while (p!=NULL && p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}

template<class T>
node<T>* BST<T>::removemin(node<T>* p) {
    if (p == NULL || (p->left==NULL && p->right==NULL)) return NULL;
    else 
    {
        if (p->left!=NULL)p->left= removemin(p->left);
        else if (p->right!=NULL)  return p->right;
    }

///////////////////////////////////// updating height 
    if (p==NULL) p->height =0;
    else if(p->right==NULL && p->left==NULL)p->height =0;
    else p->height = 1 + max(height(p->left),height(p->right));
/////////////////////////////////////
        return p;
}

template<class T>
void BST<T>::delete_node(T k){
    root = remove(root, k);
}

template<class T>
node<T>*  BST<T>::remove(node<T>* p, T k) // k key deletion from p tree
{
   
    if (p==NULL) {return NULL;}

    if (p->key==k)
    {
        if (p->left==NULL && p->right==NULL) return NULL;

        else if (p->right==NULL && p->left!=NULL)return p->left;

        else if (p->left==NULL && p->right!=NULL) return p->right;
 
        else if (p->right!=NULL && p->left !=NULL) 
        {
            node<T>*Temp=findmin(p->right);
            Temp->right=removemin(p->right);
            Temp->left= p->left;
            return Temp;
        }
    }
    
    else 
    {
        if (k<p->key && p->left!=NULL)p->left=remove(p->left,k);

        else if (k>=p->key && p->right!=NULL)p->right=remove(p->right,k);
    }

    
    return p;
    // This function uses findmin and deletemin to delete arbitrary node in the tree.
}
template<class T>
node<T>* BST<T>::getRoot(){
    return root;
}
#endif

#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
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
   if (p==NULL) return 1;
   else return (1 + max(height(p->left),height(p->right)));
}

template <class T>
int BST<T> :: balanceFactor(node<T>* p){
    if(p == NULL) return 0;
    else return (height(p -> left) - height(p -> right));
}

template <class T>
void BST<T> :: fixHeight(node<T>* p){
   p->height = height(p);
}

// ROTATING HELPERS 
template <class T>
node<T>* BST<T> :: rotateleft(node<T>* p){

    node<T>* temp = p->right; 
    p->right = temp->left;
    temp->left = p;

    fixHeight(p);
    fixHeight(temp);

    return temp;
}

template <class T>
node<T>* BST<T> :: rotateright(node<T>* p){

    node<T>* temp = p->left;
    p->left = temp->right;
    temp->right = p;

    fixHeight(p);
    fixHeight(temp);

    return temp;
}

template <class T>
node<T>* BST<T> :: balance(node<T>* p){    
    // fixHeight(p);

    if(balanceFactor(p) <= -2)
    {
        if(balanceFactor(p->right) >= 1 ) p->right = rotateright(p->right); 

        return rotateleft(p);
    }

    else if(balanceFactor(p) >= 2)
    {
        if( balanceFactor(p->left) <= -1 ) p->left = rotateleft(p->left);

        return rotateright(p);
    }

    else if (balanceFactor(p)<=1 && balanceFactor(p)>=-1)
    {
        return p;        
    } 

}
// CLASS FUNCTIONS HERE
template <class T>
void BST<T> :: insert(string value,T k){
    root = insertHelper(value,k,root);
}
// insertion helpe  r
template <class T>
node<T>* BST<T> :: insertHelper(string value,T k, node<T> *p) { // note we need a helper because we need recursive calls
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

    return balance(p);
}
template<class T>
node<T>* BST<T> :: search(T key){

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
    return balance(p);
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

    return balance(p);
    // This function uses findmin and deletemin to delete arbitrary node in the tree.
}
template<class T>
node<T>* BST<T>::getRoot(){
    return root;
}
#endif

#ifndef __DICTIONARY_CPP
#define __DICTIONARY_CPP
#include "dictionary.h"
#include <time.h>
#include <stdio.h>
#include <fstream>

Dictionary::Dictionary() {
	wordsTree = new BST<string>(); 
}

Dictionary::~Dictionary(){
    
}

void Dictionary::initialize(string wordsFile) {

	ifstream myfile(wordsFile);
	// cout<< "fkajaf"<< endl;
	int count =0;
	string word="";
	if (myfile.is_open())
	{
		while (getline(myfile,word))
		{
			//uncomment this if prints not found.  (text file made in windows)-->> due to different line endings 
			// word.pop_back();

			wordsTree->insert(word,word);
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file"<< endl;		
	} 

	// cout<< "jksv"<< endl;
	// cout << wordsTree->root->key<< endl;

	// cout << wordsTree->root->right->key<< endl;
	// cout << wordsTree->root->right->right->key<< endl;
	// cout << wordsTree->root->right->left->key<< endl;

	// cout << wordsTree->root->left->key<< endl;
	// cout << wordsTree->root->left->right->key<< endl;
	// cout << wordsTree->root->left->left->key<< endl;
}

bool Dictionary::deleteWord(string word) {
	wordsTree->delete_node(word);
	return true;
}
bool Dictionary::editWord(string oldWord, string newWord) {
	wordsTree->delete_node(oldWord);
	wordsTree->insert(newWord,newWord);
	return true;
}
bool Dictionary::insertWord(string word) {
	wordsTree->insert(word,word);
	return true;
}
node<string>* Dictionary::findWord(string word) {
	clock_t t; 
    t = clock();
    ///////////////////////////////////////////////////////////
    // TODO your code here
    node<string>* p= wordsTree->search(word);
    // cout<<p->key<< endl;
    if (p!=NULL) if(p->key == word) cout << "found "<< p->key<< endl;

    if (p==NULL) cout <<"Not found"<< endl;
    ///////////////////////////////////////////////////////////
    t = clock() - t; 
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 
    cout << "findWord() took " << time_taken << "sec to search for " << word << endl;  
    return NULL; // TODO
}

#endif

int main() {

	// string l="hamza";
	// cout << l.length()<<endl;

	Dictionary hamza;
	hamza.initialize("words2.txt");
	
	hamza.findWord("alvarado");
	hamza.findWord("bostic");
	hamza.findWord("cuittikin");
	hamza.findWord("de-americanize");
	hamza.findWord("exampless");
	hamza.findWord("foster-father");
	hamza.findWord("gabionage");
	hamza.findWord("hickman");
	hamza.findWord("intercupola");	
	hamza.findWord("jointy");
	hamza.findWord("kinks");
	hamza.findWord("lecithic");
	hamza.findWord("mammillary");
	hamza.findWord("nonmateriality");
	hamza.findWord("out-of-the-world");
	hamza.findWord("pervaded");
	hamza.findWord("quasi-actively");
	hamza.findWord("residencer");
	hamza.findWord("slivovic");
	hamza.findWord("twice-dared");
	hamza.findWord("unilingualism");
	hamza.findWord("vice-director");
	hamza.findWord("watchmanship");
	hamza.findWord("xanthippe");
	hamza.findWord("yamani");
	hamza.findWord("zellamae");

	// hamza.insertWord("qweghywki");
	// // hamza.findWord("gopherberries");
	// hamza.findWord("qweghywki");

	// hamza.editWord("qweghywki","qweghywking");
	// hamza.findWord("qweghywki");
	// hamza.findWord("qweghywking");



	return 0;
}

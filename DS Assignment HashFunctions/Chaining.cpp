#ifndef CHAINING_CPP
#define CHAINING_CPP
#include "Chaining.h"
#include "hashfunctions.cpp"

HashC::HashC(int size){
	tableSize = size;
	hashTable = new LinkedList<string>[size];
}
HashC::~HashC(){

}

unsigned long HashC :: hash(string input){

	long hash = bitHash(input); //used bithash because timed out at polyHash.
	int index = divCompression(hash, tableSize); //could have used madcompression here too.
	return index; 
}

void HashC::insert(string word){
	int index = hash(word);
	hashTable[index].insertAtHead(word);
} 

ListItem<string>* HashC :: lookup(string word){
	int index = hash(word);
	return hashTable[index].searchFor(word);
}

void HashC :: deleteWord(string word){
	int index = hash(word);
	return hashTable[index].deleteElement(word);
}


#endif
#ifndef DOUBLEHASH_CPP
#define DOUBLEHASH_CPP
#include "doubleHash.h"
#include "hashfunctions.cpp"
HashD::HashD(){
    tableSize = 10000; // you cant change this
    count =0;

    //initializing the hashtable and setting all values to NULL
    hashTable = new block*[tableSize];
    for(int i=0; i<tableSize; i++) hashTable[i]=NULL;
}

HashD::~HashD(){
}

unsigned long HashD:: hash1(string value){
	long hash = polyHash(value);
	return hash;
}

unsigned long HashD:: hash2(string value){
	long hash = bitHash(value);
	return hash;
}

void HashD::resizeTable(){
	int current_tableSize = tableSize;
	int new_tableSize = 8*tableSize;  //new table size is 6 times the previous one.

	//Creating new hashtable and setting all indexes to NULL
	block** new_hashTable;
	new_hashTable = new block*[new_tableSize];
	for(int i=0; i<new_tableSize; i++) new_hashTable[i] = NULL;

	tableSize = new_tableSize; //updating tableSize to new_tableSize
	
	for(int i=0; i<current_tableSize; i++)
	{
		if (hashTable[i]!=NULL)
		{
			int index = madCompression(hash1(hashTable[i]->value),tableSize);
			int collision=0;

			while(new_hashTable[index]!=NULL)
			{
				collision++;
				index = madCompression(collision*hash2(hashTable[i]->value)+ hash1(hashTable[i]->value),tableSize);
			}
			new_hashTable[index] = new block(index,hashTable[i]->value);
		}
	}
	delete[] hashTable;
	hashTable = new_hashTable;

}

void HashD::insert(string value){

	if (count >= 0.4*tableSize) 
	{
		// cout << "here"<< endl; 
	    resizeTable();
    }
	int index = madCompression(hash1(value),tableSize);

	int collision  =0;
	while(hashTable[index]!=NULL)
	{
		index = madCompression(collision*hash2(value)+ hash1(value),tableSize);
		collision++;
	}
	hashTable[index] = new block(index, value);
	count++;  
}

void HashD::deleteWord(string value){

	block *del_block = lookup(value);

	if(del_block !=NULL)
	{
		del_block->key =-1000;
		del_block->value = "";
	}
}

block* HashD::lookup(string value){

	int index = madCompression(hash1(value),tableSize);
	int collision=0;
	while(hashTable[index]->value != value && hashTable[index]->key!=-1000)
	{
		collision++;
		index = madCompression(collision*hash2(value)+hash1(value), tableSize);
	}
	if (hashTable[index]->value == value) return hashTable[index];

	return NULL;

}

#endif
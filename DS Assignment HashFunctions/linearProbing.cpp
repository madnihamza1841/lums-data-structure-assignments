#ifndef LINEARPROBING_CPP
#define LINEARPROBING_CPP

#include "linearProbing.h"
#include "hashfunctions.cpp"


HashL::HashL(){
    tableSize = 1000; // you cant change this
    count =0;
    hashTable = new block*[tableSize];

    for(int i=0; i<tableSize; i++)
    {
    	hashTable[i] = NULL;
    }

}

HashL::~HashL(){
}

unsigned long HashL :: hash(string value){
	long hash = bitHash(value);
	int index = divCompression(hash, tableSize);
	return index;
}

void HashL::resizeTable(){
	int current_tableSize = tableSize;
	int new_tableSize = 4*tableSize;  //new table size is 4 times the previous one.

	//Creating new hashtable and setting all indexes to NULL
	block** new_hashTable;
	new_hashTable = new block*[new_tableSize];
	for(int i=0; i<new_tableSize; i++) new_hashTable[i] = NULL;

	tableSize = new_tableSize; //updating tableSize to new_tableSize
	
	for(int i=0; i<current_tableSize; i++)
	{
		if (hashTable[i]!=NULL)
		{
			int index = hash(hashTable[i]->value);

			while(new_hashTable[index]!=NULL)
			{
				index++;
				index = index % tableSize;
			}
			new_hashTable[index] = new block(index,hashTable[i]->value);
		}
	}
	delete[] hashTable;
	hashTable = new_hashTable;

}

void HashL::insert(string value){
	if (count > 0.8*tableSize) resizeTable();
	int index = hash(value);

	if(hashTable[index] != NULL)
	{
		while (hashTable[index]!=NULL)
		{
			index++;
			index = index % tableSize;
		}
	} 
	hashTable[index] = new block(index,value);
	count++;
}

void HashL::deleteWord(string value){
	int index = hash(value);
	while(hashTable[index]->value!=value)
	{
		index++;
		index = index%tableSize;
	}
	hashTable[index]-> value = "";
	hashTable[index]->key = -1000;    //setting a flag of any negative index as it doesnt exist.
	
	count--;
}

block* HashL::lookup(string value){
	int index = hash(value);
	while(hashTable[index]->value!=value && hashTable[index]->key!=-1000)
	{
		index++;
		index = index % tableSize;
	}
	if(hashTable[index]->value == value)
	{
		return hashTable[index];
	}
	return NULL;
}
#endif

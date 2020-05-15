#include <iostream>
#include <string>
#include "HashTable.h"
#include <algorithm> 
#define MaxTableSize 10000



using namespace std;

void HashTable::addItem(string key , string gender , int height , int weight)
{
	int index = hash(key);
	
	if(hashtable[index] == NULL)
	{
		hashtable[index] = new patient;
		hashtable[index] -> height = height;
		hashtable[index] -> weight = weight;
		hashtable[index] -> key = key;
		
		if(gender == "female")
			hashtable[index] -> gender = 0; 
		else	
			gender = 1;
	}
	else
	{
		patient* temp = hashtable[index];
		hashtable[index] = new patient;
		hashtable[index] -> key = key;
		hashtable[index] -> next = temp;
		hashtable[index] -> height = height;
		hashtable[index] -> weight = weight;
		if(gender == "female")
			hashtable[index] -> gender = 0;
		else 
			hashtable[index] -> gender = 1;
	}
}

string HashTable::getGender()
{
	patient* temp = hashtable[current_index];
	while(temp->key != current_key)
		temp = temp -> next;
	
	if(temp->gender == 0)
		return "female";
	else 
		return "male";
}

int HashTable::getHeight()
{
	patient* temp = hashtable[current_index];
	while(temp->key != current_key)
		temp = temp -> next;

	return temp -> height;
}

int HashTable::getWeight()
{
	patient* temp = hashtable[current_index];
	
	while(temp->key != current_key)
		temp = temp -> next;

	return temp -> weight;
	
}

HashTable&	HashTable::operator[](const string key)
{
	current_key = key;
	current_index = hash(key);
	return *this;
}

int HashTable::hash(const string key)
{
	return ((atoi(key.c_str())+7) % MaxTableSize);
    	
    	
}



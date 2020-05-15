#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#define MaxTableSize 10000

using namespace std;

struct patient
{
    string key;
    int gender,weight,height;
    patient* next;
};

class HashTable
{
	public:
			HashTable(){};
			void addItem(string , string , int , int);
			string getGender();
			int getHeight();
			int getWeight();
			HashTable	&operator[] (const string);
    
	private:
			patient* hashtable[MaxTableSize];
			int hash(const string);
            int current_index;
            string current_key;
};

#endif

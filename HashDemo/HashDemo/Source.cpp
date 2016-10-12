#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <list>

using namespace std;

const int TABLE_SIZE = 256;

// very naively implemented hash function
// takes a string and returns the length of the string 
// to eventually be used as the index into the hash table
unsigned int DoHash(string str)
{
	// Convert the string into an integer
	// in the range 0 -> TABLE_SIZE-1

	unsigned int val = str.length();



	return (val % TABLE_SIZE);  // why modulus TABLE_SIZE?
}


int main()
{
	string buffer;  // place to hold each dictionary word
	list<string> *HashTable[TABLE_SIZE] = { NULL };  // a hash table intialized to all 0s

										// various variables to help in doing statistics on the hashing
	int val;
	unsigned long num_values = 0;
	unsigned long mean = 0;
	double variance = 0;

	// reading in a whole dictionary
	ifstream fin("C:\\Users\\nicholson\\Downloads\\words.txt");

	if (!fin) {
		cerr << "Unable to open dictionary file!" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Reading dictionary..." << endl;

	fin >> buffer;

	// DoHash uses the dictionary word to generate an index into the array 
	// each time a word "hits" that array index the element (value) in the array is 
	// incremented by one to keep a tally of the hash hits
	while (fin) {

		if (HashTable[DoHash(buffer)] == NULL) {
			HashTable[DoHash(buffer)] = new list<string>();
		}

		HashTable[DoHash(buffer)]->push_back(buffer);
		
		
		fin >> buffer;
	}


		for (list<string>::iterator it = HashTable[1]->begin(); it != HashTable[1]->end(); it++) {
			cout << *it << endl;
		}
	

	return 0;
}







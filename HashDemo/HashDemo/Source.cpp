#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

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
	int HashTable[TABLE_SIZE] = { 0 };  // a hash table intialized to all 0s

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

		HashTable[DoHash(buffer)]++;
		num_values++;
		fin >> buffer;
	}

	// statistics are computed
	mean = ceil((double)num_values / TABLE_SIZE);

	cout << "Hash Function Distribution:" << endl;
	for (int i = 0; i < TABLE_SIZE; i++) {
		val = HashTable[i];
		variance += ((val - mean) * (val - mean));
		cout << "HashTable [" << i << "] = " << val << endl;
	}

	variance /= TABLE_SIZE;

	cout << endl << endl;
	cout << "Mean: " << mean << endl;
	cout << "Standard Deviation: " << sqrt(variance) << endl;

	return 0;
}







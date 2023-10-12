//Shyam Patel
//sjp0059
//project3_Patel_sjp0059.cpp
//To compile my code type "g++ project3_Patel_sjp0059.cpp" and hit enter
//run using ./a.out
//make sure test files are in same directory before testing
//I used Dr. Li's 02/21/2022 lecture video for help
//I used the hints on the project files and lab file

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//Check if file exists
bool check_file(string);

//Adds values to vector
vector<int> read_file(string);

//Puts the values of the vector into a file
void write_file(string, vector<int>);

/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/
vector<int> merge(vector<int>, vector<int>);

/*
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/
void to_string(string, vector<int>);

/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int
*/
int main() {
	string file1;
	string file2;
	string file3;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	cout << "*** Welcome to Shyam's sorting program ***\n";

	//Get name of file one.
	do {
		cout << "Enter the first input file name: ";
		cin >> file1;
	} while (cin.fail() || !check_file(file1));

	// Get and display numbers from file one 
	v1 = read_file(file1);
	to_string(file1, v1);

	// Get name of file two
	do {
		cout << "Enter the second input file name: ";
		cin >> file2;
	} while (cin.fail() || !check_file(file2));

	// Get and display numbers from file two
	v2 = read_file(file2);
	to_string(file2, v2);

	// Combine vectors and display the sorted result
	v3 = merge(v1, v2);
	cout << "The sorted list of " << v3.size()
		 << " numbers is: ";

	for (int i = 0; i < v3.size() - 1; i++) {
		cout << v3.at(i) << " ";
	}
	cout << v3.at(v3.size() - 1) << "\n";

	// Get name of output file
	do {
		cout << "Enter the output file name: ";
		cin >> file3;
	} while (cin.fail());

	// Write combined vector to output file
	write_file(file3, v3);
	cout << "*** Please check the new file - " << file3 << " ***\n";
	cout << "*** Goodbye. ***\n";

	return 1;
}

bool check_file(string file) {
	// Input file stream. (ifstream
	ifstream stream;

	// Check whether file exists
	stream.open(file.c_str());
	if (stream.fail()) {
		cout << "File not found.\n";
		return false;
	}
	stream.close();

	return true;
}

vector<int> read_file(string file) {
	// Input file stream. (ifstream
	ifstream stream;

	// Vector containing numbers from file. (vector<int>
	vector<int> v;

	// Integer read from file. (int
	int i;

	// Add each number in the file to a vector
	stream.open(file.c_str());
	while (stream.good()) {
		stream >> i;
		v.push_back(i);
	}
	v.pop_back();
	stream.close();

	return v;
}

void write_file(string file, vector<int> v) {
	// Output file stream. (ofstream
	ofstream stream;

	// Vector iterator number. (unsigned short
	unsigned short i;

	// Write each number in the vector to the file
	stream.open(file.c_str());
	for (i = 0; i < v.size() - 1; i++) {
		stream << v.at(i) << "\n";
	}
	stream << v.at(v.size() - 1);
	stream.close();
}

vector<int> merge(vector<int> v1, vector<int> v2) {
	// Combined and sorted vector. (vector<int>
	vector<int> v3;

	// Vector interator number. (unsigned short
	unsigned short i;

	// Vector iterator size. (unsigned short
	unsigned short s;

	// Compare both vectors
	while (v1.size() > 0 && v2.size() > 0) {
		if (v1.at(0) < v2.at(0)) {
			v3.push_back(v1.at(0));
			v1.erase(v1.begin());
		} else {
			v3.push_back(v2.at(0));
			v2.erase(v2.begin());
		}
	}

	// Add any remaining numbers from vector one
	if (v1.size() > 0) {
		s = v1.size();
		for (i = 0; i < s; i++) {
			v3.push_back(v1.at(0));
			v1.erase(v1.begin());
		}
	}

	// Add any remaining numbers from vector two
	if (v2.size() > 0) {
		s = v2.size();
		for (i = 0; i < s; i++) {
			v3.push_back(v2.at(0));
			v2.erase(v2.begin());
		}
	}
			
	return v3;
}

void to_string(string file, vector<int> v) {
	// Vector interator number. (unsigned short
	unsigned short i;

	// Display the numbers contained in a vector
	cout << "The list of " << v.size() << " numbers "
		 << "in file " << file << " is:\n";

	for (i = 0; i < v.size(); i++) {
		cout << v.at(i) << "\n";
	}

	cout << "\n";
}
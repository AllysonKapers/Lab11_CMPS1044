// Allyson Moore
// CMPS1044-102
// Lab 11: Structs
// November 22, 2019
// This program creates a struct ot hold Student information.
// An array of structs is then created to hold a "roster" of students.
// A for loop runs through the array and prints out all students with above
// a 3.0 GPA, calculates the average GPA of all students, and finally edits a
// int array holding the classification counts. The AverageGPA and
// calssification counts are all printed to a file.

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream infile;
	ofstream outfile;
	outfile.open("output.txt");
	infile.open("input.txt");

	int num; // number of records on file
	double sumGPA = 0.0;
	double avgGPA = 0.0;
	int classCount[4] = {0};

	struct Student {
		string lastname;
		string firstname;
		int classification;
		float GPA;
	};

	Student list[100];
	// checks for error opening file
	if (!infile) {
		cerr << "Error: File could not be opened" << endl;
		exit(1);
	}

	infile >> num;

	// fills the array with type Student
	for (int i = 0; i < num; i++) {
		infile >> list[i].lastname;
		infile >> list[i].firstname;
		infile >> list[i].classification;
		infile >> list[i].GPA;
	}

	outfile << "Students with GPA above a 3.0: \n\n";
	for (int i = 0; i < num; i++) {
		if (list[i].GPA > 3.0) {
			outfile << list[i].lastname << " " << list[i].firstname << " ";
			outfile << list[i].GPA << endl;
		}
		// calculates the average GPAfor all Students
		sumGPA += list[i].GPA;
		avgGPA = sumGPA / num;

		// count the number of student in each classCount
		switch (list[i].classification) {
		case 0:
			classCount[0]++;
			break;
		case 1:
			classCount[1]++;
			break;
		case 2:
			classCount[2]++;
			break;
		case 3:
			classCount[0]++;
			break;
		}
	}

	// output the average GPA
	outfile << "\n\n" << fixed << setprecision(1);
	outfile << "Average GPA of all students: " << avgGPA << "\n\n";

	// output the class counts
	outfile << "Freshmen: " << classCount[0] << " ";
	outfile << "Sophomores: " << classCount[1] << " ";
	outfile << "Juniors: " << classCount[2] << " ";
	outfile << "Seniors: " << classCount[3] << " ";
	outfile << "Total: " << num << endl;

	infile.close();
	outfile.close();
	return 0;
}
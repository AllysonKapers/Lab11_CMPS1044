////////////////////////////////////////////////////////////////////////////
//Allyson Moore
//March 11, 2020
//CMPS 2433: Discrete Structures and Analysis
//Program 2 SeqSums S20
//
//This program reads in a user specified file full of data to calculate
//arithmetic and geometric sequences and summations. It primarily uses 6
//different variables: a char to hold the sequence type, and 5 int's(a and d/r
//for the equations, N to store the number of terms and L and U to hold the 
//lower and upper limits of the summation.
////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//Function headers
int summation(int lower, int upper, int* array);
void printSum(int lower, int upper, int* array, ofstream& out);
void print(int* array, int size, ofstream& out, char T);
int* arithmetic(int a, int d, int N, int* seqArray);
int* geometric(int a, int r, int N, int* seqArray);


int main()
{   ifstream infile;
    ofstream outfile;
    //Declares variables to hold user inputed file names
    string infileName, outfileName;
    

    //prompts user for file names and reads into proper variables
    cout << "What is the exact name of the input file\n";
    getline(cin, infileName);
    
    cout << "What is the exact name of the output file?\n";
    getline(cin, outfileName);


    //opens files
    infile.open(infileName);
    outfile.open(outfileName);
    
    //Outfile Header
    outfile << "Allyson Moore\n\n";

    //declares variable names to read file data into
    char type;
    int a, d, N, L, U, sum;

    //cycles though the file until it reaches the end of file
    while(infile >> type >> a >> d >> N >> L >> U)
    {   //creates a pointer to a new array specific to the problem from the file
        int* seq = new int[N+1];

        //checks the character type to see if the input is a arithmetic problem
        if(type == 'A')
        {   seq = arithmetic(a, d, N, seq);
            print(seq, N, outfile, type);
            //printSum(L, U, seq, outfile);
        }

        //checks the character type to see if the input is a geometric problem
        //only if it's not an arithmetic problem
        else if(type == 'G')
        {   seq = geometric(a, d, N, seq);
            print(seq, N, outfile, type);
            //printSum(L, U, seq, outfile);   
        }

        //default else statement to handle incorrect sequence type character
        else
        {
            cout << "Invalid type, please correct input file.\n";
        }

        //deletes array pointer to free memory
        delete[] seq;

    }
    infile.close();
    outfile.close();
    return 0;
}













int* arithmetic(int a, int d, int N, int* seqArray)
{
    //for loop used to fill array with each character of the sequence
    //until it reaches the Nth term. Starts at one to make it easier to 
    //calculate the summation correctly

    //arithmetic equation = a + (n-1)d
    for(int i = 1; i < N+1; i++)
    {
        seqArray[i] = a + ((i - 1)*d);
    }

    return seqArray;
}

int* geometric(int a, int r, int N, int* SeqArray)
{   //for loop used to fill array with each character of the sequence
    //until it reaches the Nth term. Starts at one to make it easier to 
    //calculate the summation correctly

    //geometric equation = ar^(n-1)
    for(int i = 1; i < N+1; i++)
    {
        SeqArray[i] = a * (pow(r, i-1));
    }

    return SeqArray;
}


//function takes the summation limits and the array and
//uses a for loop to sum the values within the limits
int summation(int lower, int upper, int* array)
{   int sum = 0;
    for(int i = lower; i <= upper; i++)
    {
        sum += array[i];
    }
    return sum;
}

//takes in the size, outfile, array, and seq. type
//then prints out the right seq. type  header then uses 
//a for loop to print out each value in the array
void print(int* array, int size, ofstream& out, char T)
{   if(T == 'A')
    {
        out << "Arithmetic Sequence: ";
    }
    else
    {
        out << "Geometric Sequence: ";
    }
    
    for(int i = 1; i < size+1; i++)
    {
        out << array[i] << "  ";
    }
    out << endl;   
}

//takes in the array, limits and outfile, then prints
//out the correct phrase, calling the summation function
void printSum(int* SumArray, int Upper, int Lower, ofstream& out)
{
    out << "Sum of sequence from terms " << Lower << " to "; 
    out << Upper << " is: ";
    out << summation(Lower, Upper, SumArray);
}

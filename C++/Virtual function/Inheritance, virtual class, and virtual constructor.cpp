
// This program assumes the current index value for n, i.e. n=i;
// Counts the sum of the terms of an arithmetic and geometric sequence using f virtuals (separately for each sequence)

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Sequence
{
public:
	virtual double Sum_of_terms(int n) = 0;
	virtual Sequence *Create_new() = 0;
	~Sequence()
	{
		cout << "The destructor of sequences works.\n";
	}
};

class arithmetic_sequence : public Sequence
{
	Sequence *Create_new()
	{
		cout << "The virtual constructor of arithmetic sequences works.\n"
			 << endl;
		return new arithmetic_sequence;
	}

public:
	double Sum_of_terms(int n)
	{
		// wzor an=2n+1, r=2, a1=0
		double sum;
		sum = ((6 + (n - 1) * 2) / 2) * n;
		cout << "The sum of terms of an arithmetic sequence:" << sum << endl;
		return sum;
	}
	~arithmetic_sequence()
	{
		cout << "The destructor of an arithmetic sequence works. ";
	}
};

class geometric_sequence : public Sequence
{
	Sequence *Create_new()
	{
		cout << "The virtual constructor for the geometric sequence works.\n"
			 << endl;
		return new geometric_sequence;
	}

public:
	double Sum_of_terms(int n)
	{
		// an=2^n q=2
		double sum;
		sum = 2 * (1 - pow(2, n)) / (-1);
		//	cout<<"2^n to:"<<2^n;
		cout << "The sum of terms of the geometric sequence:" << sum << endl;
		return sum;
	}
	~geometric_sequence()
	{
		cout << "The destructor of the geometric sequence works. ";
	}
};

int main()
{
	const int sequence_size = 10;
	Sequence *sequence_array[sequence_size];
	Sequence *sequence_ptr;
	arithmetic_sequence A_default;
	geometric_sequence G_default;

	for (int i = 1; i < sequence_size + 1; i++)
	{
		int Choice;
		cout << "What sequence to create (selection to create 10 sequences)? 1: arithmetic / 2: geometric ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			sequence_ptr = &A_default;
			sequence_array[i] = sequence_ptr->Create_new();
			cout << "I'm creating an arithmetic sequence. 2n+1 \n";
			break;
		case 2:
			sequence_ptr = &G_default;
			sequence_array[i] = sequence_ptr->Create_new();
			cout << "I'm creating an geometric sequence. 2^n \n";
			break;
		default:
			cout << "Wrong choice." << endl;
			exit(1);
		}
	}
	cout << "\nSequences:\n";
	for (int i = 1; i < sequence_size + 1; i++)
	{
		cout << "i=" << i << " ";
		sequence_array[i]->Sum_of_terms(i);
	}
	for (int i = 1; i < sequence_size + 1; i++)
	{
		delete sequence_array[i];
	}
}

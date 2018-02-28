//Author: Yafu Deng
//CPSC 121 Lab 4
//2/27/2018

#include<iostream>
using namespace std;

/*  1.  Displays a menu of functions that the user is able to pick from. 
If information is returned from a function (ie NOT a void function), then that information should be displayed outside of the function. 
Any information passed as an argument (in the parenthesis) should be obtained outside of the function and passed in when called.
    a) void hello()
      Will simply display the text ¡°Hello, world!¡±
    b) void printBetween(int a, int b)
      Will print all numbers between a and b, including a and b, counting up
      E.G. a = 3, b = 6, ouput = ¡°3 4 5 6¡± (or can use newlines)
      Order is unassumed, but data is displayed counting up
    c) bool isPrime(int n)
      Returns true to indicate n is prime, or false to indicate it¡¯s not
      A number  n is prime if it is greater than 1 and not divisible by any of the numbers x in the range 1 < x < n
    d) int leastCommonDenominator(int a, int b)
      Returns the smallest number that is divisible by both a and b
      Which means (answer % a) and (answer % b) are both 0
      The least common denominator of 3 and 4 is 12
    e) void squaredOpposite(double &n)
      Sets the contents of the argument to be the squared value of n, with the opposite sign compared to n
      E.G. input of 3 would result in output of -9
      n is being passed as a reference variable, meaning changes made to it in the function will be reflected in the argument that was passed into the function call
  2. Asks the user if they would like to return to step 1, or exit.*/

void hello();
void printBetween(int, int);
bool isPrime(int);
int leastCommonDenominator(int, int);
void squareOpposite(double&);

int main()
{
	//set variables
	char choice = 'z';
	int min = 0;
	int max = 0;
	bool Prime = 0;
	int n = 0;
	int common1 = 0;
	int common2 = 0;
	int answer = 0;
	double squared = 0.0;
	bool loop = 1;

	//Build a loop that allows user to do the process repeadly
	while (loop)
	{
		//Displays a menu of functions that the user is able to pick from.
		system("cls");
		cout << "Please pick one funtion that you want to run from the following:" << endl;
		cout << "Enter the letter in front of the function name to pick." << endl;
		cout << "a) void hello()" << endl;
		cout << "b) void printBetween(int a, int b)" << endl;
		cout << "c) bool isPrime(int n)" << endl;
		cout << "d) int leastCommonDenominator(int a, int b)" << endl;
		cout << "e) void squaredOpposite(double &n)" << endl;

		//User's choice input
		cin >> choice;

		//Operation based on user's chioce
		switch (choice)
		{
		case 'a':
			hello();
			break;
		case 'b':
		{
			//ask user to enter the print range
			cout << "Please enter the minimum integer and the maximun integer that you want to print in between:" << endl;
			cout << "Minimum number first then maximum number" << endl;
			//get input from user
			cin >> min >> max;

			//check if the max is greater than max
			if (min > max)
				cout << "The maximum number you entered is smaller than your minimum. The funtion won't run." << endl;
			else
				printBetween(min, max);
			break;
		}
		case 'c':
		{
			//Ask for user's pick of the interger
			cout << "Please enter the interger you want to test:" << endl;
			//Get input from user
			cin >> n;
			Prime = isPrime(n);
			if (Prime)
				cout << "The number you entered is prime." << endl;
			else
				cout << "The number you entered is not prime." << endl;
			break;
		}
		case 'd':
		{
			//Ask user to enter the two integers
			cout << "Please enter the two integers you want to send to the function:" << endl;
			cin >> common1 >> common2;
			//send the two integers to the function
			answer = leastCommonDenominator(common1, common2);
			cout << "The least common denominator of the two integers you entered will be: " << answer << endl;
			break;
		}
		case 'e':
		{
			//Ask for user's input and accept it
			cout << "Please enter the number you want to send to the function:" << endl;
			cin >> squared;
			squareOpposite(squared);
			cout << "The squared opposite number of your input will be " << squared << endl;
			break;
		}
		default:
			cout << "This is not a valid choice. Please follow the instruction." << endl;
			break;
		}

		//Ask if user wants to repeat
		cout << "Do you want to do it again?" << endl;
		cout << "Enter '1' to repeat or enter '0' to exit" << endl;
		cin >> loop;
	}


	system("pause");
	return 0;
}

//funciton hello
void hello()
{
	cout << "Hello, world!" << endl;
}

//function print Between
void printBetween(int min, int max)
{
	for (int i = min; i <= max; i++)
		cout << i << " ";
}

//function isPrime
bool isPrime(int n)
{
	if (n == 1)
		return 1;
	else if (n > 1)
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
				return 0;
			else
				cout << "";
		}
		return 1;
	}
	return 0;
}

//function least common denominator
int leastCommonDenominator(int common1, int common2)
{
	int i;
	for (i = 1; i <= common1 * common2; i++)
	{
		if ((i % common1 == 0) && (i % common2 == 0))
			return i;
	}
	return 0;
}

//function squaredOpposite
void squareOpposite(double& squared)
{
	if (squared >= 0)
	{
		squared = - pow(squared, 2);
	}
	else
	{
		squared = pow(squared, 2);
	}
}

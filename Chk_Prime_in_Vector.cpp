/* The Code checks to see if there is a prime number in vector.
If there is prime number in vector, calculates average of even elements, otherwise returns maximum element of vector.
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h> 
#include <cmath>
using namespace std;
vector<int> FillVector(const int x, vector<int> &vec); /*The Fill_V function fills the vector by random elements.
											 First argument is vector size, second argument is vector.*/
void PrintVector(vector<int> &vec);		  // The Print() function printing Vector.
bool CheckPrime(vector<int> &vec);		 //The Prime () function checks to see if there is a prime number in the vector.
bool IsPrime(int x);				// The IsPrime() function checks to see if number is prime 
double AverageOfEven(vector<int> &vec); // The Aver_Sum calculates average of Even elements .
int  MaxElement(vector<int> &vec);  // The Max_elem function returns maximum element of vector.

int main()
{
	vector<int> vec1;
	FillVector(10, vec1);
	PrintVector(vec1);
	if (CheckPrime(vec1) == true) cout << "The Average of Even Values is :" << AverageOfEven(vec1) << endl;
	else cout << "There is no prime number in vector." << endl << "The MAX value of Vector is :" << MaxElement(vec1) << endl;
	vec1.clear();
	system("pause");
	return 0;
}

vector<int> FillVector(const int x, vector<int> &vec) {
	int rez;
	for (int i = 0; i < x; i++) { rez = rand() % 10 + time(NULL) % 100; vec.push_back(rez); }
	return vec;
}
void PrintVector(vector<int> &vec) {
	cout << "Vector is : [ ";
	for (int i = 0; i != vec.size(); ++i) { cout << vec[i] << " "; }
	cout << "] " << endl;
}
bool CheckPrime(vector<int> &vec) {
	for (int i = 0; i != vec.size(); ++i) { if (IsPrime(vec[i])) { cout << "Get a Prime number : " << vec[i] << endl; return true; break; } }
	return false;
}
bool IsPrime(int x)
{
	if (x <= 1) return false; if (x == 2) return true; if ((x % 2) == 0) return false;
	for (int i = 3; i <= sqrt(x); i += 2) { if (!(x % i)) return false; }
	return true;
}
double AverageOfEven(vector<int> &vec) {
	double sum(0); double count(0); double result(0);
	for (int i = 0; i != vec.size(); ++i) { if (vec[i] % 2 == 0) { sum += vec[i]; count++; } }
	result = sum / count;
	return result;
}
int  MaxElement(vector<int> &vec) {
	int max = 0;
	for (int i = 0; i != vec.size(); ++i) { if (vec[i] >= max) max = vec[i]; }
	return max;
}
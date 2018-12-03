#include<iostream>
using namespace std;
struct element {
	int val;
	int index;
	element(int v, int i) {
		val = v;
		index = i;
	}
};
void printarray(element A[], int n) {
	for (int k = 0; k < n; k++) {
		cout << "\t(" << A[k].val <<","<<A[k].index<<") ";
	}
	cout << endl;
}
void insertionSort(element A[], int n) {
	printarray(A, n);
	int value = 0; int index = 0;
	int hole = 0;
	for (int i = 1; i <= n - 1; i++) {
		value = A[i].val; index = A[i].index;
		hole = i;
		cout << " I = " << i << " Value = " << value <<endl;
		while (hole > 0 && A[hole - 1].val > value) {
			cout << "A[" << hole - 1 << "] > " << value << endl;
			A[hole].val = A[hole - 1].val; A[hole].index = A[hole - 1].index;
			hole--;
			cout << " shift Hole to " << hole << endl;
		}
		A[hole].val = value; A[hole].index = index;
		printarray(A, n);
	}
	cout << " FINISHED \n";
	printarray(A, n);
}
int main() {
	cout << " *******\t\t Insertion Sort worst case: O(n^2) , stable \t\t*******\n";
	struct element A[] = { element(7,0),element(2,1),element(5,2),element(4,3),element(5,4),element(3,5)};
	// Find the Length of the array 
	int length; length = sizeof(A) / sizeof(element);
    cout << "length " << length << endl;
	for (int k = 0; k <length; k++) {
		cout << "\t " << k << "  ";
	}
	cout << endl<<endl;

	insertionSort(A,length);

	system("pause");
	return 0;
}
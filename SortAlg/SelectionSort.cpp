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
void selectionsort(element A[], int n) {
	int indexMin = 0;
	printarray(A, n);
	for (int i = 0; i < n - 1; i++) { // if we sorted n-2 out of n then we dont need to check n-1
		indexMin = i;
		cout << "Index Min " << indexMin << endl;
		for (int j = i + 1; j < n; j++) {
			if (A[j].val < A[indexMin].val) {
				indexMin = j;
				cout << " Found Min at " << j <<" index Min "<<indexMin<<" A[j] "<<A[j].val<<" A[j].index "<<A[j].index<< endl;
			}
		}
		int temp = A[i].val;
		int temp2 = A[i].index;
		A[i].val = A[indexMin].val;		A[i].index = A[indexMin].index;
		A[indexMin].val = temp;         A[indexMin].index = temp2;
		printarray(A,n);
	}
	printarray(A,n);
}
int main() {
	cout << " *******\t\t Selection Sort O(n^2) , Unstable \t\t*******\n";
		struct element A[] = { element(7,0),element(2,1),element(5,2),element(4,3),element(5,4),element(3,5)};
	// Find the Length of the array 
	int length; length = sizeof(A) / sizeof(element);
    cout << "length " << length << endl;
	for (int k = 0; k <length; k++) {
		cout << "\t " << k << "  ";
	}
	cout << endl<<endl;

	selectionsort(A,length);

	system("pause");
	return 0;
}
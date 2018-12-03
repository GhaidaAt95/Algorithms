#include<iostream>
using namespace std;
struct element {
	int val;
	int index;
	element(int v, int i) {
		val = v;
		index = i;
	}
	element() {}
};
void printarray(element A[], int n) {
	for (int k = 0; k < n; k++) {
		cout << "\t(" << A[k].val << "," << A[k].index << ") ";
	}
	cout << endl;
}
void Merge(element Left[], element Right[], element A[],int nL, int nR) {
	int i = 0, j = 0, k = 0;
	while (i < nL && j < nR) {
		if (Left[i].val <= Right[j].val) {
			A[k].val = Left[i].val; A[k].index = Left[i].index;
			i++; k++;
		}
		else {
			A[k].val = Right[j].val; A[k].index = Right[j].index;
			k++; j++;
		}
	}
	while (i < nL) {
		A[k].val = Left[i].val; A[k].index = Left[i].index; i++; k++;
	}
	while (j < nR) {
		A[k].val = Right[j].val; A[k].index = Right[j].index;  j++; k++;
	}

}
void MergeSort(element A[], int n) {
	if (n < 2)return;
	int mid = n / 2; cout <<"*****************************************\n"<< "Mid " << mid << endl;
	struct element *left = new element[mid];
	struct element *right = new element[n - mid];
	int i = 0;
	for (i = 0; i < mid; i++) {
		left[i].val = A[i].val; left[i].index = A[i].index;
	}
	cout << "Left -> ";
	printarray(left, mid);
	for (i = mid; i < n; i++) {
	right[i-mid].val = A[i].val;  right[i-mid].index = A[i].index; 
	}
	cout << "Right -> ";
	printarray(right, n-mid);
	MergeSort(left,mid);
	MergeSort(right,n-mid);
	cout << "Call MERGE \n";
	Merge(left, right, A,mid,n-mid);
	cout << "After Merge ->  "; printarray(A, n);
	delete[] left;
	delete[]right;
}
int main() {
	cout << " *******\t\t Merge Sort O(nlogn), stable \t\t*******\n";
	struct element A[] = { element(7,0),element(2,1),element(5,2),element(4,3),element(5,4),element(3,5) };
	// Find the Length of the array 
	int length; length = sizeof(A) / sizeof(element);
	cout << "Unsorted\n";
	for (int k = 0; k <length; k++) {
		cout << "\t " << k << "  ";
	}
	cout << endl;
	printarray(A, length);
	cout << endl;
	cout << "length " << length << endl;
	MergeSort(A, length);
	cout <<"*****************************************\n"<<"Sorted\n";
	printarray(A, length);

	system("pause");
	return 0;
}
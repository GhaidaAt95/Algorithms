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
void bubbleSort(element A[], int n) {
	printarray(A, n);
	int flag = 0;
	for (int k = 1; k < n - 1; k++) { // worst case loop from 0 element till n-1 (0 to 5)
		flag = 0;
		cout << " K = " << k << endl;
		for (int i = 0; i <= n - k -1; i++) { // 1st time from 0 to 6-1-1=4 and at 4 compares it to 5
			                                  // 2nd time from 0 to 6-1-2=3 and at 3 compares it to 4 ( cause at this point 5>4)
											  // 3rd time from 0 to 6-1-3=2 and at 2 compares it to 3 ( cause at this point 5>4>3)
											  // 4th time from 0 to 6-1-4=1 and at 1 compares it to 2 ( cause at this point 5>4>3>2)
											  // 5th time from 0 to 6-1-5=1 and at 0 compares it to 1 ( cause at this point 5>4>3>2>1)
											  // No 6th time or no Nth time 
			if (A[i].val > A[i + 1].val) {
				cout << "A[" << i << "]" << " > A[" <<i + 1 << "] " << endl;
				int temp = A[i].val;
				int temp2 = A[i].index;
				A[i].val = A[i+1].val;		A[i].index = A[i+1].index;
				A[i+1].val = temp;         A[i+1].index = temp2;
				flag = 1;
				printarray(A, n);
			}

		}
		if (flag == 0) {
			cout << "Break on " << k << endl;
			break; 
		}
	}
	printarray(A, n);
}
int main() {
	cout << " *******\t\t Bubble Sort worst case: O(n^2) , stable \t\t*******\n";
	struct element A[] = { element(7,0),element(2,1),element(5,2),element(4,3),element(5,4),element(3,5)};
	// Find the Length of the array 
	int length; length = sizeof(A) / sizeof(element);
    cout << "length " << length << endl;
	for (int k = 0; k <length; k++) {
		cout << "\t " << k << "  ";
	}
	cout << endl<<endl;

	bubbleSort(A,length);

	system("pause");
	return 0;
}
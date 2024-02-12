#include <iostream>
#include <vector>
#include "myFile.h"
using namespace std;

//fucntion prototypes 
void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(std::vector<int>& arr, int left, int right);

int main() {	
	
	// Create a vector of unsorted integers
	vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };

	// Print the unsorted vector
	cout << "Unsorted array: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	// Call mergeSort on the entire array
	mergeSort(arr, 0, arr.size() - 1);

	// Print the sorted vector
	cout << "Sorted array: ";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout<<'\n';

	system("pause");

	print_id("Lab 2 Merge sort/Comsc 210");
	
}
/*********************************************************************
* Function: merge
* Description: Merges two sorted subarrays of a vector into a single
*              sorted subarray. The first subarray is from left to mid,
*              and the second subarray is from mid+1 to right.
* Parameters:
*   arr - reference to the vector of integers being sorted.
*   left - the starting index of the first subarray.
*   mid - the ending index of the first subarray and the midpoint for the merge.
*   right - the ending index of the second subarray.
* Return: void
*********************************************************************/
void merge(vector<int>& arr, int left, int mid, int right) {

	int left_size = mid - left + 1;//length of the left side 
	int right_size = right - mid;//length of the right side 

	//temp array
	vector<int> L(left_size), R(right_size);

	//copy data to temp arrays
	for (int i = 0; i < left_size; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < right_size; j++)
		R[j] = arr[mid + 1 + j];
	//merge the temp arrays back into arr[left and right]
	int i = 0;
	int j = 0;
	int k = left;
	while (i < left_size && j < right_size) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}// copy temaining elements of L[]
	while (i < left_size) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < right_size) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
/*********************************************************************
* Function: mergeSort
* Description: Recursively divides the vector into two halves, sorts
*              each half, and then merges the sorted halves back together.
* Parameters:
*   arr - reference to the vector of integers to be sorted.
*   left - the starting index of the subarray of the vector to be sorted.
*   right - the ending index of the subarray of the vector to be sorted.
* Return: void
***********************************************************/
void mergeSort(std::vector<int>& arr, int left, int right) {
	if (left >= right) {
		return; // Returns recursively
	}
	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}


/*********************************************************************
	Summary of the time complexity of the merge sort algorithm.
	-----------------------------------------------------------
	PROS:
	-Uses divide and conquer and merges them back together.
	-Time complexity arcoss all cases is O(nlogn).
	-Merge sort is highly efficent for large datasets. 
	-Merge sort is stable and has a predictable time complexity.
	CONS:
	-Requires additonal space proportional to the size of the input array for the merging process,
	 which is a considertation in a memory constrained environment. 
***********************************************************/
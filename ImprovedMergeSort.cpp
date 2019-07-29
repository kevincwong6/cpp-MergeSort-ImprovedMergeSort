#include <iostream>
#include "ImprovedMergeSort.h"

using namespace std;
ImprovedMergeSort::ImprovedMergeSort()
{
}
// ------------------------------------- printArray ----------------------------
void ImprovedMergeSort::printArray(int Arr[], int array_size)
{
	for (int i = 0; i < array_size; i++)
		cout << Arr[i] << " ";
	cout << endl;
}

// ----------------------------- swapValues ------------------------------------
// The benchmark showed that using a temp variable is the fastest compared to
// the other methods. Such as xor or swap two values without a temp.
// See Testing.cpp for detail.
void ImprovedMergeSort::swapValues(
	int &val1,
	int &val2)
{
	int temp = val2;
	val2 = val1;
	val1 = temp;
}
// ------------------------------- updateArray ---------------------------------
// It is mainly to update the right side array after swapping values.
void ImprovedMergeSort::updateArray(
	int Arr[],
	int idx,  
	int high)
{
	for (int i = idx; i < high; i++)
	{
		if (Arr[i] < Arr[i + 1])
			break;

		swapValues(Arr[i], Arr[i + 1]);
	}
}

// ------------------------------- ProcessNextValue ----------------------------
bool ImprovedMergeSort::ProcessNextValue(
	int Arr[], 
	int mid,   // the first slot of right side
	int high,  // the last slot
	int &idx1, // points to the left side slot
	int &idx2) // points to the right side slot
{
	bool rc = false;
	if (Arr[idx1] > Arr[idx2]) // right side is smaller
	{
		swapValues(Arr[idx1], Arr[idx2]);
		updateArray(Arr, idx2, high); // moves it to the right spot if needed
	}
	idx1++;

	if (idx1 == mid) // depleted left side already ?
	{
		rc = true;
	}
	return rc;
}
// ----------------------------------- ImprovedMerge ---------------------------
// This ImprovedMerge method does not need an extra array to hold the
// merged output.
// This helps to improve performance more than 4 times or more in most cases.
void ImprovedMergeSort::ImprovedMerge(
	int Arr[],
	int low,  // the starting index
	int mid,  // the cutoff index where left & right side already sorted (the last slot of left side)
	int high) // the ending index
{
	//printArray(Arr, high + 1);
	if (low == high) // return if it is a single slot array
		return;

	int idx1 = low;
	int idx2 = mid + 1;

	for (int i = low; i <= high; i++)
	{
		bool done = ProcessNextValue(Arr, mid + 1, high, idx1, idx2);
		if (done)  // early exit, mostly like left side was depleted
		{          // Also, the right side is already in ascending order
			break; // So, the whole array is in correct sorting order.
		}          // Then it can exit.
	}
}

// ------------------------------- ImprovedMergeSort ---------------------------
// This part is same as the MergeSort::mergeSort.
// The improvement is mainly in ImprovedMerge() method by avoid using extra
// buffer and cut down the variables copy time.
void ImprovedMergeSort::improvedMergeSort(
	int Arr[],
	int low,   // the starting array index
	int high)  // the ending array index
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		improvedMergeSort(Arr, low, mid);
		improvedMergeSort(Arr, mid + 1, high);
		ImprovedMerge(Arr, low, mid, high);
	}
}



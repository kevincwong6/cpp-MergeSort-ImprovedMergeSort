#include <iostream>
#include "MergeSort.h"

using namespace std;
MergeSort::MergeSort()
{
}

// ------------------------------------- printArray ----------------------------
void MergeSort::printArray(int Arr[], int array_size)
{
	for (int i = 0; i < array_size; i++)
		cout << Arr[i] << " ";
	cout << endl;
}

// ---------------------------------- getNextValue -----------------------------
// get the next smaller from an array
// I think this approach is simpler & cleaner. In other words, it will have
// less bugs, and easier to understand & maintain.
int MergeSort::getNextValue(int Arr[], int q, int r, int &idx1, int &idx2)
{
	int rc = 0;
	if (idx1 == q) // left side already depleted
	{
		rc = Arr[idx2];
		idx2++;
	}
	else if (idx2 == (r+1)) // right side alredy depleted
	{
		rc = Arr[idx1];
		idx1++;
	}
	else // still have values on both side
	{
		if (Arr[idx1] > Arr[idx2]) // right side is smaller
		{ 
			rc = Arr[idx2];
			idx2++;
		}
		else // left side is smaller
		{
			rc = Arr[idx1];
			idx1++;
		}
	}
	return rc;
}

// --------------------------------------- Merge -------------------------------
void MergeSort::Merge(
	int Arr[], 
	int low,  // the starting index
	int mid,  // the cutoff index where left & right side already sorted
	int high) // the ending index
{
	// There are other approaches to create a temp array.
	// 1) int temp[r - p + 1]
	//    However, not all compiler supports non-constant array declaraction
	// and
	// 2) int *temp = new int[r - p + 1];
	//    delete [] array
	//    It works but it needs to copy the element by element from temp back to Arr
	//
	// To use malloc instead because it can use memcpy that can greatly improve
	// the performance. Otherwise, it needs copy from temp back to Arr element
	// by element.
	if (low == high) // return if it is a single element array
		return;

	int array_cnt = high - low + 1;
	int buff_size = sizeof(int)*(array_cnt);
	int *temp = (int *) malloc(buff_size);
	int idx1 = low;
	int idx2 = mid+1;

	for (int i = low; i <= high; i++)
	{
		temp[i-low] = getNextValue(Arr, mid + 1, high, idx1, idx2);
	}
	memcpy(&Arr[low], temp, buff_size);
	free(temp);
}

// ------------------------------------- mergeSort -----------------------------
void MergeSort::mergeSort(
	int Arr[], 
	int low,   // the starting array index
	int high)  // the ending array index
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(Arr, low, mid);
		mergeSort(Arr, mid + 1, high);
		Merge(Arr, low, mid, high);
	}
}
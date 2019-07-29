#ifndef GET_MERGE_SORT_H
#define GET_MERGE_SORT_H

class MergeSort
{
	public:
	    MergeSort();

		int getNextValue(int Arr[], int q, int r, int &idx1, int &idx2);

		void printArray(int Arr[], int array_size);

		void mergeSort(
			int Arr[],
			int low,   // the starting array index
			int high);  // the ending array index

		void Merge(
			int Arr[],
			int low,  // the starting index
			int mid,  // the cutoff index where left & right side already sorted
			int high); // the ending index
};
#endif
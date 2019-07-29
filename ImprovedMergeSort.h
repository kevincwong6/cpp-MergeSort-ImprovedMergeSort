#ifndef GET_IMPROVED_MERGE_SORT_H
#define GET_IMPROVED_MERGE_SORT_H

class ImprovedMergeSort
{
	public:
		ImprovedMergeSort();

		void printArray(int Arr[], int array_size);

		void swapValues(
			int &val1,
			int &val2);

		bool ProcessNextValue(
			int Arr[],
			int mid,   // the first slot of right side
			int high,  // the last slot
			int &idx1, // points to the left side slot
			int &idx2); // points to the right side slot

		void ImprovedMerge(
			int Arr[],
			int low,  // the starting index
			int mid,  // the cutoff index where left & right side already sorted
			int high); // the ending index

		void improvedMergeSort(
			int Arr[],
			int low,   // the starting array index
			int high); // the ending array index

		void updateArray(
			int Arr[],
			int idx,
			int high);
};
#endif
#include <iostream>
#include <windows.h>
#include "Testing.h"
#include "MergeSort.h"
#include "ImprovedMergeSort.h"

using namespace std;

#define _TEST_ITERATION   (1000000)
void test_Merge1()
{
	int Arr[] = { 1,3, 7, 5, 6, 9 }; // three & three
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1; 
	int mid = idx2;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr, mid, array_size, idx1, idx2);
		temp[i] = j;
		// cout << temp[i] << endl;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge2()
{
	int Arr[] = { 1,3, 7, 8, 5, 6, 9 }; // four & three
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1;
	int mid = idx2;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr, mid, array_size, idx1, idx2);
		temp[i] = j;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge3()
{
	int Arr[] = { 2,2, 2, 2, 1, 1, 1 }; // four & three
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1;
	int mid = idx2;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr,mid, array_size - 1, idx1, idx2);
		temp[i] = j;
	    // cout << temp[i] << endl;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge4()
{
	//int Arr[]={ 5,7,100,10,11,77,8,9,121,22,33};
	int Arr[] = { 1,1,1,1,2, 2, 2}; // four & three
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1;
	int mid = idx2;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr, mid, array_size - 1, idx1, idx2);
		temp[i] = j;
		// cout << temp[i] << endl;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge5()
{
	int Arr[] = { 7,5 }; // one & one
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1;
	int mid = idx2; // 1
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr, mid, array_size - 1, idx1, idx2);
		temp[i] = j;
		// cout << temp[i] << endl;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge6()
{
	int Arr[] = { 7 }; 
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1;
	int mid = idx2;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr, mid, array_size - 1, idx1, idx2);
		temp[i] = j;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge7()
{
	int Arr[] = { 11, 12, 8 }; // two & one
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int *temp = (int *)malloc(sizeof(int)*(array_size));
	int high = array_size - 1;
	int idx1 = 0;
	int idx2 = (high / 2) + 1;
	int mid = idx2;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	for (int i = 0; i < array_size; i++)
	{
		int j = ms.getNextValue(Arr, mid, array_size - 1, idx1, idx2);
		temp[i] = j;
	}
	ms.printArray(temp, array_size);
	cout << endl;
	free(temp);
}

void test_Merge()
{
	cout << endl << "===== Test Merge =====" << endl;
	test_Merge1();
	test_Merge2();
	test_Merge3();
	test_Merge4();
	test_Merge5();
	test_Merge6();
	test_Merge7();
}

// --------------------------- swapPerformanceTest -----------------------------
void swapPerformanceTest()
{
	int x = 5, y = 10;
	DWORD dw1, dw2;

	dw1 = GetTickCount();
	for (int i = 0; i < 10000000; i++) // 62 milliseconds
	{
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
	}
	dw2 = GetTickCount();
	cout << "Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;

	dw1 = GetTickCount();
	for (int i = 0; i < 10000000; i++) // 47 milliseconds
	{
		x ^= y ^= x ^= y;
	//	x = x + y - (y=x);
	//	cout << x << endl;
	//	cout << y << endl;
	}
	dw2 = GetTickCount();
	cout << "Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;

	dw1 = GetTickCount();
	for (int i = 0; i < 10000000; i++) // 31 milliseconds
	{
		x = x + y;
		y = x - y;
		x = x - y;
	}
	dw2 = GetTickCount();
	cout << "Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;

	dw1 = GetTickCount();
	int temp;
	for (int i = 0; i < 10000000; i++) // 16 milliseconds
	{
		temp=y;
		y = x;
		x = temp;
	}
	dw2 = GetTickCount();
	cout << "Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
}

void test_MergeSort1()
{
	int Arr[] = { 3,1 };
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	MergeSort ms = MergeSort();

	DWORD dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ms.mergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_MergeSort2 Merge Sorted List is:\n";

	ms.printArray(Arr, array_size);
	cout << endl;
}

void test_MergeSort2()
{
	int Arr[] = { 3,1, 2 };
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	MergeSort ms = MergeSort();

	DWORD dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ms.mergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_MergeSort2 Merge Sorted List is:\n";

	ms.printArray(Arr, array_size);
	cout << endl;
}

void test_MergeSort3()
{
    //int Arr[] = { 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33, 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33 };
	int Arr[] = { 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33, 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33,5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33, 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33 };
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	MergeSort ms = MergeSort();

	ms.printArray(Arr, array_size);
	DWORD dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ms.mergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_MergeSort3 Merge Sorted List is:\n";

	ms.printArray(Arr, array_size);
	cout << endl;
}

void test_MergeSort4()
{
	//int Arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	//int Arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int Arr[] = {1,3,5,7,9,2,4,6,8,10};

	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	MergeSort ms = MergeSort();

	DWORD	dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ms.mergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_MergeSort4 Merge Sorted List is:\n";

	ms.printArray(Arr, array_size);
	cout << endl;
}

// ----------------------------------- test_ImprovedMergeSort1 -----------------
void test_ImprovedMergeSort1()
{
	int Arr[] = { 3,1 };
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	ImprovedMergeSort ims = ImprovedMergeSort();

	ims.printArray(Arr, array_size);
	DWORD	dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ims.improvedMergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_ImprovedMergeSort1 Merge Sorted List is:\n";
	ims.printArray(Arr, array_size);
	cout << endl;
}

void test_ImprovedMergeSort2()
{
	int Arr[] = { 3,1, 2 };
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	ImprovedMergeSort ims = ImprovedMergeSort();

	ims.printArray(Arr, array_size);
	DWORD	dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ims.improvedMergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_ImprovedMergeSort2 Merge Sorted List is:\n";
	ims.printArray(Arr, array_size);
	cout << endl;
}

void test_ImprovedMergeSort3()
{
	//int Arr[] = { 5,7,100,10,11,77,8,9,121,22,33 };
	int Arr[] = { 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33, 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33,5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33, 5, 7, 100, 10, 11, 77, 8, 9, 121, 22, 33 };
	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	ImprovedMergeSort ims = ImprovedMergeSort();

	ims.printArray(Arr, array_size);
	DWORD	dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ims.improvedMergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_ImprovedMergeSort3 Merge Sorted List is:\n";
	ims.printArray(Arr, array_size);
	cout << endl;
}

void test_ImprovedMergeSort4()
{
	//int Arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	//int Arr[] = {1,2,3,4,5,6,7,8,9,10 };
	int Arr[] = { 1,3,5,7,9,2,4,6,8,10 };

	int array_size = sizeof(Arr) / sizeof(Arr[0]);
	int low = 0;
	int high = array_size - 1;
	ImprovedMergeSort ims = ImprovedMergeSort();

	ims.printArray(Arr, array_size);
	DWORD	dw1 = GetTickCount();
	for (int i = 0; i < _TEST_ITERATION; i++)
	{
		ims.improvedMergeSort(Arr, low, high);
	}
	DWORD dw2 = GetTickCount();
	cout << _TEST_ITERATION << " Iterations, Time difference is " << (dw2 - dw1) << " milliSeconds" << endl;
	cout << "The test_ImprovedMergeSort4 Merge Sorted List is:\n";
	ims.printArray(Arr, array_size);
	cout << endl;
}

// ----------------------------------- main test -------------------------------
void test_MergeSort()
{
	cout << endl << "===== Test MergeSort =====" << endl;
	test_MergeSort1();
	test_MergeSort2();
	test_MergeSort3();
	test_MergeSort4();
}

void test_improvedMergeSort()
{
	cout << endl << "===== Test ImprovedMergeSort =====" << endl;
	test_ImprovedMergeSort1();
	test_ImprovedMergeSort2();
    test_ImprovedMergeSort3();
	test_ImprovedMergeSort4();
}
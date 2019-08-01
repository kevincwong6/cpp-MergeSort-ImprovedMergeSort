1) The MergeSort is very basic merge sort algorithm but the merge method was implemented with a 
simpler, and easier to understand getNextValue() method. 
It uses memcpy to copy between arrays. 
The benchmark shows similar performance with element copying.

2) The ImprovedMergeSort is big improvement to the MergeSort by avoid using extra buffer.
The performance improvement is more than 4 times in a lot cases.


===== Test MergeSort =====

1000000 Iterations, Time difference is 375 milliSeconds

The test_MergeSort2 Merge Sorted List is:

1 3

1000000 Iterations, Time difference is 734 milliSeconds

The test_MergeSort2 Merge Sorted List is:

1 2 3

5 7 100 10 11 77 8 9 121 22 33 5 7 100 10 11 77 8 9 121 22 33 5 7 100 10 11 77 8 9 121 22 33 5 7 100 10 11 77 8 9 121 22 33

1000000 Iterations, Time difference is 18969 milliSeconds

The test_MergeSort3 Merge Sorted List is:

5 5 5 5 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 22 22 22 22 33 33 33 33 77 77 77 77 100 100 100 100 121 121 121 121


1000000 Iterations, Time difference is 3484 milliSeconds

The test_MergeSort4 Merge Sorted List is:

1 2 3 4 5 6 7 8 9 10

===== Test ImprovedMergeSort =====

3 1

1000000 Iterations, Time difference is 94 milliSeconds

The test_ImprovedMergeSort1 Merge Sorted List is:

1 3

3 1 2

1000000 Iterations, Time difference is 188 milliSeconds

The test_ImprovedMergeSort2 Merge Sorted List is:

1 2 3

5 7 100 10 11 77 8 9 121 22 33 5 7 100 10 11 77 8 9 121 22 33 5 7 100 10 11 77 8 9 121 22 33 5 7 100 10 11 77 8 9 121 22 33

1000000 Iterations, Time difference is 5172 milliSeconds

The test_ImprovedMergeSort3 Merge Sorted List is:
5 5 5 5 7 7 7 7 8 8 8 8 9 9 9 9 10 10 10 10 11 11 11 11 22 22 22 22 33 33 33 33 77 77 77 77 100 100 100 100 121 121 121 121

1 3 5 7 9 2 4 6 8 10

1000000 Iterations, Time difference is 859 milliSeconds

The test_ImprovedMergeSort4 Merge Sorted List is:

1 2 3 4 5 6 7 8 9 10

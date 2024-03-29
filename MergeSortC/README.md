# Merge Sort Algorithm

Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list.

Idea:

* Divide the unsorted list into N sublists, each containing 1 element.
* Take adjacent pairs of two singleton lists and merge them to form a list of 2 elements. N will now convert into N/2 lists of size 2.
* Repeat the process till a single sorted list of obtained.
* 
While comparing two sublists for merging, the first element of both lists is taken into consideration. 
While sorting in ascending order, the element that is of a lesser value becomes a new element of the sorted list. 
This procedure is repeated until both the smaller sublists are empty and the new combined sublist comprises all the elements of both the sublists.

Source: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/

EXAMPLE OUTPUT
------------------------------------------------------------------------
```diff
The given array is:
14 15 78 48 95 10 96 21


The sorted array is:
10 14 15 21 48 78 95 96



Process returned 0 (0x0)   execution time : 0.034 s
Press any key to continue.

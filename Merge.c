#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  

  
int main()
{
    int sizes[] = {1000, 10000, 25000,50000,75000,100000}; // Sizes of arrays to tes
	
    for (int i = 0; i < 6; i++)
    {
		int size = sizes[i];	 //The size of the input file
		char nameOfTheFile[100]; //The name of the input file
		char inputType ='R'; 	 //The type of the input array
		
		if(inputType == 's'){
			printf("SortedArray\n");
			if(size == 1000){
				strcpy(nameOfTheFile, "Sorted1000.txt");
			} else if(size == 10000){
				strcpy(nameOfTheFile, "Sorted10000.txt");
			} else if(size == 25000){
				strcpy(nameOfTheFile, "Sorted25000.txt");
			} else if(size == 50000){	
				strcpy(nameOfTheFile, "Sorted50000.txt");
			} else if(size == 75000){
				strcpy(nameOfTheFile, "Sorted75000.txt");
			} else if(size == 100000){
				strcpy(nameOfTheFile, "Sorted100000.txt");
			}
			
		}else if(inputType == 'r'){
			printf("RandomArray\n");
			if(size == 1000){
				strcpy(nameOfTheFile, "Random1000.txt");
			} else if(size == 10000){
				strcpy(nameOfTheFile, "Random10000.txt");
			} else if(size == 25000){
				strcpy(nameOfTheFile, "Random25000.txt");
			} else if(size == 50000){
				strcpy(nameOfTheFile, "Random50000.txt");
			} else if(size == 75000){
				strcpy(nameOfTheFile, "Random75000.txt");
			} else if(size == 100000){
				strcpy(nameOfTheFile, "Random100000.txt");
			}	

		}else if(inputType == 'R'){
			printf("ReverseSortedArray\n");
			if(size == 1000){
				strcpy(nameOfTheFile, "ReverseSorted1000.txt");
			} else if(size == 10000){
				strcpy(nameOfTheFile, "ReverseSorted10000.txt");
			} else if(size == 25000){
				strcpy(nameOfTheFile, "ReverseSorted25000.txt");
			} else if(size == 50000){
				strcpy(nameOfTheFile, "ReverseSorted50000.txt");
			} else if(size == 75000){
				strcpy(nameOfTheFile, "ReverseSorted75000.txt");
			} else if(size == 100000){
				strcpy(nameOfTheFile, "ReverseSorted100000.txt");
			}
		}
		
		
        FILE *file = fopen(nameOfTheFile, "r");
		
		int arr_size = size;
		int index = 0;
		int arr[arr_size];
		int num;
		while (fscanf(file, "%d", &num) == 1) {
			arr[index] = num;
			index++;
		}
		fclose(file); 
        struct timespec start, end;

        clock_gettime(CLOCK_MONOTONIC, &start);
        mergeSort(arr, 0, arr_size - 1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

        printf("Array after sorting (size %d):\n", size);
        printf("Time taken for sorting (size %d): %.7f seconds\n\n", size, cpu_time_used);
 
        
    }
    return 0;
}
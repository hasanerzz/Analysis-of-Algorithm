#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include <string.h>

// Swap two elements in an array
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Partition the array using the first element as pivot
int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int i = left + 1;
	int j = right;

	while (i <= j)
	{
		while (i <= j && arr[i] <= pivot)
		{
			i++;
		}
		while (i <= j && arr[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[left], &arr[j]);

	return j;
}

// Quickselect algorithm
int quickSelect(int arr[], int left, int right, int k)
{
	if (left == right)
	{
		return arr[left];
	}

	int pivotIndex = partition(arr, left, right);

	if (k == pivotIndex)
	{
		return arr[k];
	}
	else if (k < pivotIndex)
	{
		return quickSelect(arr, left, pivotIndex - 1, k);
	}
	else
	{
		return quickSelect(arr, pivotIndex + 1, right, k);
	}
}

int main()
{
    int sizes[] = {1000, 10000, 25000,50000,75000,100000}; // Sizes of arrays to test
	
    int i, j;
	
	
    for (i = 0; i < 6; i++)
    {
       int size = sizes[i];	 //The size of the input file
		char nameOfTheFile[100]; //The name of the input file
		char inputType ='r'; 	 //The type of the input array
		
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
        int median = quickSelect(arr, 0, arr_size - 1, size/2);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
		
		printf("Median: %d\n", median);
        printf("Array after sorting (size %d):\n", size);
        printf("Time taken for sorting (size %d): %.7f seconds\n\n", size, cpu_time_used);
  
    }
    return 0;
}
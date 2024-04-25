#include <stdio.h>
#include <stdlib.h>  
#include <time.h>   
#include <string.h>

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
		count++;
        if(count == N/2)
            break;
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
        heapSort(arr, arr_size);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
		
		printf("Median: %d\n", arr[size/2]);
        printf("Array after sorting (size %d):\n", size);
        printf("Time taken for sorting (size %d): %.7f seconds\n\n", size, cpu_time_used);
  
    }
    return 0;
}
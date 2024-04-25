#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* array, int i, int index) {
    if (array[i] == array[index]) {
        return;
    }
    int temp = array[i];
    array[i] = array[index];
    array[index] = temp;
}

int getMedian(int* array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                swap(array, i, j);
            }
        }
    }
    return array[n / 2];
}

int partition(int* array, int low, int high, int pivot) {
    for (int i = low; i <= high; i++) {
        if (array[i] == pivot) {
            swap(array, i, high);
            break;
        }
    }
    int index = low - 1;
    for (int i = low; i < high; i++) {
        if (array[i] < pivot) {
            index++;
            swap(array, i, index);
        }
    }
    index++;
    swap(array, index, high);
    return index;
}

int getKthSmallestQuickSelectWorstCaseLinearTime(int* array, int low, int high, int k) {

    if (k > 0 && k <= high - low + 1) {
        int n = high - low + 1;
        int i;
        int median[(n + 4) / 5];

        for (i = 0; i < (n + 4) / 5 - 1; i++) {
            int sublist[5];
            for (int j = 0; j < 5; j++) {
                sublist[j] = array[5 * i + low + j];
            }
            median[i] = getMedian(sublist, 5);
        }

        if (n % 5 == 0) {
            int sublist[5];
            for (int j = 0; j < 5; j++) {
                sublist[j] = array[5 * i + low + j];
            }
            median[i] = getMedian(sublist, 5);
            i++;
        } else {
            int sublist[n % 5];
            for (int j = 0; j < n % 5; j++) {
                sublist[j] = array[5 * i + low + j];
            }
            median[i] = getMedian(sublist, n % 5);
            i++;
        }

        int medOfMed = i == 1 ? median[0] : getKthSmallestQuickSelectWorstCaseLinearTime(median, 0, i - 1, i / 2);

        int partitionIndex = partition(array, low, high, medOfMed);

        if (partitionIndex - low == k - 1) {
            return array[partitionIndex];
        }

        if (partitionIndex - low > k - 1) {
            return getKthSmallestQuickSelectWorstCaseLinearTime(array, low, partitionIndex - 1, k);
        }

        return getKthSmallestQuickSelectWorstCaseLinearTime(array, partitionIndex + 1, high, k - partitionIndex + low - 1);
    }

    return -1;
}


int main()
{
    int sizes[] = {1000, 10000, 25000,50000,75000,100000}; // Sizes of arrays to test
	
    for (int i = 0; i < 6; i++)
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
        int median = getKthSmallestQuickSelectWorstCaseLinearTime(arr, 0, arr_size - 1, size/2 + 1);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double cpu_time_used = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
		
		printf("Median: %d\n", median);
        printf("Array after sorting (size %d):\n", size);
        printf("Time taken for sorting (size %d): %.7f seconds\n\n", size, cpu_time_used);
  


        
    }
    return 0;
}
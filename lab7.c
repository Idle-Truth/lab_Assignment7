#include <stdio.h>

// helper swap function
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n, int swappedArr[])
{
	int i, j, min_index, temp;

	int count = 0;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n; i++)
	{
		min_index = i;

		// find the minimum element in unsorted array
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}

		// swap the found minimum element with the first element
		if (i != min_index)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;

			swappedArr[min_index]++;
			swappedArr[i]++;

			swap(&swappedArr[min_index], &swappedArr[i]);
			count++;
		}
	}

	

	for (i = 0; i < n; i++)
	{
		printf("%d: %d\n", arr[i], swappedArr[i]);
	}

	printf("%d\n", count);


	for (i = 0; i < n; i++)
	{
		swappedArr[i] += swappedArr[i];
	}

	// printf("")

	printf("\n");
}

// bubble sort with swap helper function
void bubbleSort(int arr[], int n, int swappedArr[])
{
	int i, j, p;

	int count = 0;

	for (i = 0; i < n - 1; i++)
	{
		// last i element are already in place, so stop j before n-i
		// as we will compare j with j+1 we will stop j before n-i-1
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				// use the value of the number being swapped to count how many times it's been swapped
				swappedArr[j]++;
				swappedArr[j + 1]++;
				swap(&swappedArr[j], &swappedArr[j + 1]);
				count++;
			}
		}
	}


	for (i = 0; i < n; i++)
	{
		printf("%d: %d\n", arr[i], swappedArr[i]);
	}
	printf("%d\n", count);
	
	
	
	printf("\n");
}

int main()
{

	int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
	int arrayCopy1[9];
	int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	int arrayCopy2[9];

	for (int i = 0; i < 9; i++)
	{
		arrayCopy1[i] = array1[i];
		arrayCopy2[i] = array2[i];
	}
	

	int swappedArr[9] = {0};
	int swappedArr2[9] = {0};
	int n = 9;





	bubbleSort(arrayCopy1, n, swappedArr);
	bubbleSort(arrayCopy2, n, swappedArr2);

	for (int i = 0; i < n; i++)
	{
		swappedArr[i] = 0;
		swappedArr2[i] = 0;
	}

	for (int i = 0; i < 9; i++)
	{
		arrayCopy1[i] = array1[i];
		arrayCopy2[i] = array2[i];
	}
	
	
	selectionSort(arrayCopy1, n, swappedArr);
	selectionSort(arrayCopy2, n, swappedArr2);
}
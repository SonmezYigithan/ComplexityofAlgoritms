#include <iostream>
#include <cstdlib>
#include <chrono> 

using namespace std;
using namespace std::chrono; 

void bublesort(int *A, int n)
{
	int swapped,temp;
	for (int k=n;k>0;k--)
	{
		swapped = 0;
		for (int j=0;j<k-1;j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
				swapped=1;
			}

		}
	/*	if(swapped==0)
			break;*/
	}
}




void insertionsort(int *A, int n)
{
	int key;
	int i;

	for(int j=1;j<n;j++)
	{
		key = A[j];
		i = j-1;
		while(i>=0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}

void selectionSort(int *A, int n) 
{ 
    int i, j, min_idx,temp; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (A[j] < A[min_idx]) 
            min_idx = j; 

		temp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = temp;
    } 
} 


int main()
{


	int size= 1000;
	int A[size];
 
 	srand((unsigned)time(0)); 
     
    for(int i=0; i<size; i++){ 
        A[i] = (rand()%100)+1; 
         
 } 
	

	
	auto start = std::chrono::high_resolution_clock::now();
	insertionsort(A, size);
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "Insertionsort took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;

	start = std::chrono::high_resolution_clock::now();
	bublesort(A, size);
	finish = std::chrono::high_resolution_clock::now();
	cout << "Bubblesort took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
	start = std::chrono::high_resolution_clock::now();
	selectionSort(A,size);
	finish = std::chrono::high_resolution_clock::now();
	cout << "Selectionsort took " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " nanoseconds" << endl;
	
	

	system("PAUSE");
	return 1;

}

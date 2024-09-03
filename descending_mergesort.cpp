#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &array, int left, int mid, int right){
	int i, j, k; 

    int n1 = mid - left + 1; 

    int n2 =  right - mid; 

  

    /* create temp arrays */

    int Left[n1], Right[n2]; 

  

    /* Copy data to temp arrays L[] and R[] */

    for (i = 0; i < n1; i++) 

        Left[i] = array[left + i]; 

    for (j = 0; j < n2; j++) 

        Right[j] = array[mid + 1+ j]; 

  

    /* Merge the temp arrays back into arr[l..r]*/

    i = 0; // Initial index of first subarray 

    j = 0; // Initial index of second subarray 

    k = left; // Initial index of merged subarray 

    while (i < n1 && j < n2) 

    { 

        if (Left[i] >= Right[j]) 

        { 

            array[k] = Left[i]; 

            i++; 

        } 

        else

        { 

            array[k] = Right[j]; 

            j++; 

        } 

        k++; 

    } 

  

    /* Copy the remaining elements of L[], if there 

       are any */

    while (i < n1) 

    { 

        array[k] = Left[i]; 

        i++; 

        k++; 

    } 

  

    /* Copy the remaining elements of R[], if there 

       are any */

    while (j < n2) 

    { 

        array[k] = Right[j]; 

        j++; 

        k++; 

    } 
	
	
}

void merge_sort(vector<int> &array, int left, int right ){
	
	if(left < right){
		
		int middle = left + (right- left)/2;
		
		merge_sort(array, left, middle);
		merge_sort(array, middle+1, right);
		
		merge(array, left, middle, right);
	}
	
}


int main(int argc, char *argv[])
{

	vector<int> nums {5,9,17,2,6,1};
	
	merge_sort(nums, 0, nums.size()-1);
	
	for(auto &i: nums){
		cout<<i<<" ";
	}
		
	cout<<endl;
	
	return 0;
}
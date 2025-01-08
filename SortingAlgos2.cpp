// Author: Jose Lara

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// RandomSizeGen
//
// This function is meant to generate a random size for an array.
// The minimum size being 10 and the maximum being 100. 
//
void RandomSizeGen(int &s){
    srand(time(0));
    s = (rand() % 91) + 10;
}

// RandomNumGen
//
// This function generates random numbers for our arrays.
// The qunatity of numbers generated is dependant on the random size that was generated. 
//
void RandomNumGen(int arr[], int size){
    int number = 0;
    for(int i = 0; i < size; i++){
        number = (rand() % 100);
        arr[i] = number;
    }
}

// CopyArray
//
// This function is here mostly to copy the original array back to the unsorted one.   
// This will give us the functionality of seeing multiple sorting methods without having to re-run the program each time.
// because I can just copy over the orginal array into the sorted one. 
//
void CopyArray(int original_arr[], int unsorted_arr[], int size){
    for(int i = 0 ; i < size; i++){
        unsorted_arr[i] = original_arr[i];
    }
}

// PrintArr
//
// Standard printing function dedicated on printing all the elements in the specified array. 
//
void PrintArr(int Arr[], int size){
    for(int i = 0; i < size; i++){
        cout << Arr[i] << " ";
    }
}

// SelectionSort 
//
// This function will run selection sort on the specified array. 
// This is done by repeateadly selecting the smallest or largest element in the array and swapping it
// with the first unsorted element. This will continue until the entire array is sorted in order.
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)
//
// Additional notes: Not suited for big data sets. 
//

void SelectionSort(int unsorted_arr[], int size){
    for(int i = 0; i < size; i++){
        int min_index = i;
        for(int j = i + 1; j < size; j++){
            if(unsorted_arr[min_index] > unsorted_arr[j]){
                min_index = j;
            }
        }
        int tmp_val = unsorted_arr[i];
        unsorted_arr[i] = unsorted_arr[min_index];
        unsorted_arr[min_index] = tmp_val;
    }

    cout << "This is the sorted Array: ";
    PrintArr(unsorted_arr, size);
    cout << endl;
}

// BubbleSort
//
// This function will run bubble sort on the specififed array. 
// This is accomplished by repeatedly swapping adjacent elements if they are found to be in the wrong order. 
// This goes on until no more elements need to be swapped. 
// 
// Time Complexity: O(N)
// Space Complexity: O(1)
//
// Additional notes: Not suited for big data sets. 
// 
void BubbleSort(int unsorted_arr[], int size){
    for(int i = 0; i < size - 1 ; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(unsorted_arr[j] > unsorted_arr[j + 1]){
                int tmp_val = unsorted_arr[j];
                unsorted_arr[j] = unsorted_arr[j + 1];
                unsorted_arr[j + 1] = tmp_val;
            }
        }
    }
    cout << "This is the sorted Array: ";
    PrintArr(unsorted_arr, size);
    cout << endl;
}

// Insertion Sort
//
// This function will run Insertion Sort on the array/
//
// This is accomplished by iteratively inserting each element of an unsorted list into the correct position in the list.
// Starting from the 2nd element you check the firt element to make sure its correct. If not swap if yes go to the next element and check the previous two.  
// This will keep going until you do the entire list which by then the elements should be sorted. 
//
// Time Complexity: O(N) 
// Space Complexity: O(1)
//
void InsertionSort(int unsorted_arr[], int size){
    for(int i = 1; i < size; i++){
        int j = i - 1;
        int tmp_val = unsorted_arr[i];

        while(j >= 0 && unsorted_arr[j] > tmp_val){
            unsorted_arr[j + 1] = unsorted_arr[j];
            j--;
        }

        unsorted_arr[j + 1] = tmp_val;
    }

    cout << "This is the sorted Array: ";
    PrintArr(unsorted_arr, size);
    cout << endl;
}

// merge
//
// A helper function to Merge Sort.
//
// This helper function will check the left and right arrays and begin to put the right order of elements
// into the main array. This function essentially combines the split up arrays until both the left and right sides
// are done being put back together as one. 
void merge(int LeftArr[], int leftSize, int RightArr[], int RightSize, int unsorted_arr[]){
    int i = 0, l = 0, r = 0; // indices

    while(l < leftSize && r < RightSize){
        if(LeftArr[l] < RightArr[r]){
            unsorted_arr[i] = LeftArr[l];
            i++;
            l++;
        } else {
            unsorted_arr[i] = RightArr[r];
            i++;
            r++;
        }
    }
    while(l < leftSize){
        unsorted_arr[i] = LeftArr[l];
        i++;
        l++;
    }
    while(r < RightSize){
        unsorted_arr[i] = RightArr[r];
        i++;
        r++;
    }
}

// MergeSort
//
// This function runs Merge Sort on the specified array
//
// It accomplishes this by following a divide and conquer approach in where it 
// works recursively by dividing the array into smaller subarrays which it then sorts those 
// smaller subarrays and then finally merging them all back together into one. 
void MergeSort(int unsorted_arr[], int size){
    int length = size;
    if (length <= 1) return; 

    int middle = length / 2;

    int leftArray[middle];
    int rightArray[length - middle];

    int i = 0; // left array
    int j = 0; // right array

    for(; i < length; i++){
        if(i < middle){
            leftArray[i] = unsorted_arr[i];
        } else {
            rightArray[j] = unsorted_arr[i];
            j++;
        }
    }
    MergeSort(leftArray,middle);
    MergeSort(rightArray, size - middle);
    merge(leftArray, middle, rightArray, size - middle ,unsorted_arr);
}

int main(){
    int user_input;
    int size = 0;
    RandomSizeGen(size);

    int original_arr[size];
    RandomNumGen(original_arr, size);

    int unsorted_arr[size];
    CopyArray(original_arr, unsorted_arr, size);

    cout << "This is the unsorted Array: ";
    PrintArr(original_arr, size);
    cout << endl;

    // SelectionSort(unsorted_arr, size);
    // BubbleSort(unsorted_arr, size);
    // InsertionSort(unsorted_arr,size);
    // MergeSort(unsorted_arr,size);
    
    cout << "Ending Program";
    return 0;
};
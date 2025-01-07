#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void RandomSizeGen(int &s){
    srand(time(0));
    s = (rand() % 91) + 10;
}

void RandomNumGen(int arr[], int size){
    int number = 0;
    for(int i = 0; i < size; i++){
        number = (rand() % 100);
        arr[i] = number;
    }
}

void CopyArray(int original_arr[], int unsorted_arr[], int size){
    for(int i = 0 ; i < size; i++){
        unsorted_arr[i] = original_arr[i];
    }
}

void PrintArr(int Arr[], int size){
    for(int i = 0; i < size; i++){
        cout << Arr[i] << " ";
    }
}

void SelectionSort(int original_arr[], int unsorted_arr[], int size){
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
    CopyArray(original_arr,unsorted_arr,size);
}

void bubbleSort(int original_arr[], int unsorted_arr[], int size){
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
    CopyArray(original_arr,unsorted_arr,size);
}

void insertionSort(int original_arr[], int unsorted_arr[], int size){
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
    CopyArray(original_arr,unsorted_arr,size);
}

// void merge(int LeftArr, int RightArr, int unsorted_arr){
//     int leftSize = unsorted_arr
// }

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

    // SelectionSort(original_arr, unsorted_arr, size);
    // bubbleSort(original_arr, unsorted_arr, size);
    insertionSort(original_arr,unsorted_arr,size);
    
    cout << "Ending Program";
    return 0;
};
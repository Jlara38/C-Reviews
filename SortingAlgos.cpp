// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// // Function meant to print the vector array this will be used to make sure that 
// // the vector array is still the same unsorted numbers that are meant to be there.
// void printVectorArray(vector<int> unsorted){
//     for(int val = 0; val < unsorted.size(); val++){
//         cout << unsorted.at(val) << " ";
//     }
// }

// // This function will run selectionSort through the unsorted vector array. It will not
// // influemce the actual vector array since I want to use it for other sorts.
// // The sorting algo works by repeateadly swapping the smallest (or largest *depending on implementation*)
// // element with the first unsorted element until the entire array is sorted. 
// void selectionSort(vector<int> unsorted){
//     for(int i = 0; i < unsorted.size() - 1; i++){
//         int min_index = i;
//         for(int j = i + 1; j < unsorted.size(); j++){
//             if(unsorted.at(min_index) > unsorted.at(j)){
//                 min_index = j;
//             }
//         }

//         int tmp_val = unsorted.at(i);
//         unsorted.at(i) = unsorted.at(min_index);
//         unsorted.at(min_index) = tmp_val;
//     }

//     printVectorArray(unsorted);
// }

// // This function will run bubbleSort through the unsorted vector array.
// // This algo will work by repeatedly checking the current element with the element next to it and swapping if the 2nd element is smaller
// // Should it not be smaller then it will check the next element and so forth until it finds an shorter element of until it determines its the shortest already.
// // Will be a decent sorting algo for small datasets but will be bad for larger ones due to how long it takes. 
// void bubbleSort(vector<int> unsorted){
//     for(int i = 0; i < unsorted.size() - 1; i++){
//         for(int j = 0; j < unsorted.size() - i - 1; j++){
//             if(unsorted[j] > unsorted[j + 1]){
//                 int tmp_val = unsorted[j];
//                 unsorted[j] = unsorted[j + 1];
//                 unsorted[j + 1] = tmp_val;
//             }
//         }
//     }
//     printVectorArray(unsorted);
// }

// // Great for smaller data steps considered better than bubble and selection sort. 
// void insertionSort(vector<int> unsorted){
//     for(int i = 1; i < unsorted.size(); i++){
//         int j = i - 1;
//         int tmp_val = unsorted[i];

//         while(j >= 0 && unsorted[j] > tmp_val){
//             unsorted[j + 1] = unsorted[j];
//             j--;
//         }

//         unsorted[j + 1] = tmp_val;
//     }
//     printVectorArray(unsorted);
// }

// void merge(vector<int> leftArr, vector<int> RightArr, vector<int> unsorted){
//     int leftSize = unsorted.size() / 2;
//     int rightSize = unsorted.size() - leftSize;
//     int i = 0, l = 0, r = 0;

//     while(l < leftSize && r < rightSize){
//         if(leftArr[l] < RightArr[r]){
//             unsorted[i] = leftArr[l];
//             i++;
//             l++;
//         } else{
//             unsorted[i] = RightArr[r];
//             i++;
//             r++;
//         }
//     }

//     while(l < leftSize){
//         unsorted[i] = leftArr[l];
//         i++;
//         l++;
//     }

//     while(r < rightSize){
//         unsorted[i] = RightArr[r];
//         i++;
//         r++;
//     }
// }

// void mergeSort(vector<int> unsorted){
//     int size = unsorted.size();
//     if(size <= 1) return;

//     int middle = size / 2;
//     vector<int> leftArr;
//     vector<int> rightArr;

//     int l = 0;
//     int r = 0;

//     for(; l < size; l++){
//         if(l < middle){
//             leftArr.push_back(unsorted.at(l));
//         } else{
//             rightArr.push_back(unsorted.at(l));
//         }
//     }

//     mergeSort(leftArr);
//     mergeSort(rightArr);
//     merge(leftArr,rightArr,unsorted);
// }



// int main() {
//     vector<int> unsorted_numbers = {27, 14, 7, 20, 9, 19, 57, 3, 2, 5, 13, 93, 12};
//     cout << "Current unsorted numbers: ";
//     printVectorArray(unsorted_numbers);
//     cout << "\nThis is the selection sort results: ";
//     selectionSort(unsorted_numbers);

//     cout << "\n\nCurrent unsorted numbers: ";
//     printVectorArray(unsorted_numbers);
//     cout << "\nThis is the bubble sort results: ";
//     bubbleSort(unsorted_numbers);

//     cout << "\n\nCurrent unsorted numbers: ";
//     printVectorArray(unsorted_numbers);
//     cout << "\nThis is the insertion sort results: ";
//     insertionSort(unsorted_numbers);

//     cout << "\n\nCurrent unsorted numbers: ";
//     printVectorArray(unsorted_numbers);
//     cout << "\nThis is the merge sort results: ";
//     mergeSort(unsorted_numbers);


//     return 0;
// }
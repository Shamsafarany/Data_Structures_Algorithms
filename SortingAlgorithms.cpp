#include <iostream>
using namespace std;
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);

int main(){
    int arr[] = {10, 9, 8, 7, 6 ,5, 4, 3, 2 ,1};
    //selectionSort(arr, 10);
    bubbleSort(arr, 10);
}

void selectionSort(int arr[], int n){
    cout<<"Selection Sort: " << endl;
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j]< arr[min]) {
                min = j;
            }
        } 
         int temp = arr[i];
         arr[i] = arr[min];
         arr[min] = temp;
    }
    printArray(arr, n);
}

void bubbleSort(int arr[], int n) {
    cout<<"Bubble Sort: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
    printArray(arr, n);  
}

void printArray(int arr[], int n) {
    for (int i =0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
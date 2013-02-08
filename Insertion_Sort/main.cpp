/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 7, 2013, 6:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

void insertion_sort(vector<int> & array) {
    
    int key;
    
    for(int i=1; i < array.size(); i++) {
        key = array[i];
        
        int j = i;
        while ((j > 0) && (array[j-1] > key)) {
            
            array[j] = array[j-1];
            j--;
        }
        array[j] = key;
    }
    
}

int main(int argc, char** argv) {

    vector<int> arr;
    int number, size;
    
    cout << "Enter the size of the array:\n";
    cin >> size;
    
    cout << "Enter the numbers in the array to be sorted:\n";
    
    while(size){
        cin >> number;
        arr.push_back(number);
        size--;
    }
    
    cout << "UnSorted array is: " << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    insertion_sort(arr);
    
    cout << "Sorted array is: " << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
}


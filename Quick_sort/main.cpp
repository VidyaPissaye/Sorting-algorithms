/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 20, 2013, 10:18 PM
 * 
 * Quick Sort
 * O(nlgn)
 * 
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */

int partition(vector<int> & array, int p, int r) {
    int x = array[r];
    
    int i = p-1;
    
    for(int j=p; j<r; j++) {
        if (array[j] < x) {
            i++;
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    array[r] = array[i+1];
    array[i+1] = x;
    return (i+1);
}

void quicksort(vector<int> & array, int p, int r) {
    
    if (p<r) {
        int q = partition(array, p, r);
        quicksort(array, p, q-1);
        quicksort(array, q+1, r);
    }
}

int main(int argc, char** argv) {

    vector<int> input_array;
    int element = 0, number = 0;
    
    cout << "Enter the number of elements in the array" << endl;
    cin >> number;
    
    cout << "Enter the numbers" << endl;
    for(int i=0; i<number; i++){
        cin >> element;
        input_array.push_back(element);
    }
    
    quicksort(input_array, 0, number-1);
    
    cout << "The sorted array is " << endl;
    for (int j=0; j< number; j++) {
        cout << input_array[j] << endl;
    }
    
}


/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 21, 2013, 11:13 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */


int* countsort(vector<int> & inarr, int n, int k) {
    
    int* temparr = new int[k];
    int* outputarr = new int[n];
    
    for(int i=0; i<k; i++) {
        temparr[i] = 0;
    }
    
    for(int j=0; j<n; j++) {
        temparr[inarr[j]]++;
    }
    
    for(int i=1; i<k; i++) {
        temparr[i] = temparr[i] + temparr[i-1];
    }
    
    for(int j=(n-1); j>=0; j--) {
        outputarr[temparr[inarr[j]]-1] = inarr[j];
        temparr[inarr[j]]--;
    }
    
    return outputarr;
}

int main(int argc, char** argv) {

    vector<int> input_array;
    
    int k=0, number = 0, element = 0;
    
    cout << "Enter the number of elements in the array" << endl;
    cin >> number;
    
    cout << "Enter the numbers" << endl;
    for(int i=0; i<number; i++){
        cin >> element;
        input_array.push_back(element);
    }
    
    for(int j=0; j<number; j++) {
        if(input_array[j] > k) {
            k = input_array[j];
        }
    }
    k = k+1; // Considering 0
    
    cout << "k is " << k << endl;
    
    int *output_array = countsort(input_array, number, k);
    
    cout << "The sorted array is " << endl;
    for (int j=0; j< number; j++) {
        cout << output_array[j] << endl;
    }
}


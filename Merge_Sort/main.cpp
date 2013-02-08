/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 7, 2013, 8:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */



void merge(vector<int> & array, int p, int m, int q) {
    
    int n1 = (m-p)+1;
    int n2 = (q-m);
    
    vector<int> a(n1), b(n2);

    for(int i=0; i < n1; i++){
        a[i] = array[p+i];
    }
    
    for(int j=0; j < n2; j++){
        b[j] = array[m+j+1];
    }
    
    int i=0;
    int j=0;
    
    for(int x=p; x <= q; x++) {
        
        if(i<n1 && j<n2){
            if(a[i] <= b[j]){
                array[x] = a[i++];
            }
            else{
                array[x] = b[j++];
            }
        }
        else if(i==n1){
            array[x] = b[j++];
        }
        else{
            array[x] = a[i++];
        }
    }

}

void mergesort(vector<int> & array, int p, int q){
    
    if(p < q){
        int mid = (p + q)/2;
        
        mergesort(array, p, mid);
        mergesort(array, mid+1, q);
        merge(array, p, mid, q);
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
    
    mergesort(arr, 0, (arr.size()-1));
    
    cout << "Sorted array is: " << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
}


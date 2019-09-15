/**
 * Alex Chheng
 * CECS 282 Lab 3
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

//http://www.cplusplus.com/doc/tutorial/pointers/
using namespace std;

int readData(int *arr){
    for (int i = 0; 10 > i; i++){
        cout << arr[i] << endl;
    }
    return *arr;
}

void bsort(int *arr, int last){
    bool change = true;
    int numChange = 0;
    int i = 0;
    int temp1 = 0;
    int temp2 = 0;
    while (last > i || change){
        if (i < last - 1){
            temp1 = arr[i];
            temp2 = arr[i + 1];
            //cout << temp1 << endl << temp2 << endl << endl;
            if (temp1 > temp2){
                arr[i + 1] = temp1;
                arr[i] = temp2;
                numChange++;
            }
        }
        i++;
        if (numChange > 0 && last <= i){
            i = 0;
            numChange = 0;
        }
        else if (numChange <= 0 && last <= i) {
            change = false;
        }
    }
}

void writeToConsole(int * arr, int last){
    readData(arr);
}

void bubble_sort(){

}

int main() {
    ifstream inFile; //read file
    inFile.open("data.txt"); //open file
    if(inFile.fail()){
        cerr << "Error opening file" << endl; //notify failure to open file
        exit(1); //exit to avoid crash
    }
    int x;
    int textLength = 0;
    int arrayP[10];
    while (!inFile.eof()){
        inFile >> x;
        arrayP[textLength] = x;
        textLength++;
    }

    //readData(arrayP);
    bsort(arrayP, 10);
    writeToConsole(arrayP, 10);

    inFile.close(); //close file
    return 0;
}
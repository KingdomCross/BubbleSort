/**
 * Alex Chheng
 * CECS 282 Lab 3
 */
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>

//http://www.cplusplus.com/doc/tutorial/pointers/
//https://www.tutorialspoint.com/cplusplus/cpp_pointer_to_an_array.htm
using namespace std;

int readData(int *arr){
    ifstream infile("data.txt");
    infile >> *arr;
    /*for (int i = 0; size > i; i++){
        infile >> x;
        arr[i] = x;
        cout << x << " x " << i << " i " << size << " size " << &arr[i] << " arr" << "\n";
    }*/
    infile.close();
    return *arr;
}

void bsort(int *arr, int last){
    cout << "Bubble sort " << endl;
    bool change = true;
    int numChange = 0;
    int i = 0;
    int temp1 = 0;
    int temp2 = 0;
    int select = 0;

    cout << "Select 1 for ascend or -1 for descend\n";
    cin >> select;
    if (select == -1){
        while (last > i || change){
            if (i < last - 1){
                temp1 = *(arr + i);
                temp2 = *(arr + i + 1);
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

    else if (select == 1){
        while (last > i || change){
            if (i < last - 1){
                temp1 = *(arr + i);
                temp2 = *(arr + i + 1);
                //cout << temp1 << endl << temp2 << endl << endl;
                if (temp1 < temp2){
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

    else{
        cout << "Wrong input, try again\n";
    }
}

void bubble_sort(int* arr, int size, int(*operation)(int x, int y) ){
    bool sorted = false;
    int *ptr = arr;
    while(!sorted){
        sorted = true;
        for (int i = 0; i < size; i++) // Repeat until N - 1 (i.e. 8 in this case)
        {
            if (*(ptr + i ) > *(ptr + i + 1)) // make sure you don't access out of bounds
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + i + 1);
                *(ptr + i + 1) = temp;
                sorted = false; // we swapped, so keep sorting
            }
        }
    }
}

bool desend (int temp1, int temp2){
    return temp1 < temp2;
}
bool ascend (int temp1, int temp2){
    return temp1 > temp2;
}

void writeToConsole(int * arr, int last){
    for (int i = 0; 10 > i; i++){
        cout << arr[i] << endl;
    }
}

int main() {

    int number = 0;

    int * arr;
    arr = &number;

    ifstream inFile; //read file
    inFile.open("data.txt"); //open file
    if(inFile.fail()){
        cerr << "Error opening file" << endl; //notify failure to open file
        exit(1); //exit to avoid crash
    }

    cout << readData(arr) << "\n";
    //cout << *arr << "\n";
    int last = *arr;

    for (int i = 0; last > i; i++){
        inFile >> *arr;
        cout << *arr << " arr " << i << " i " << "\n";
        arr++;
    }

    for (int i = 0; last > i; i++){
        cout << *arr << " arr " << "\n";
        arr--;
    }

    cout << *arr;

    /*int x;
    int textLength = 0;
    while (!inFile.eof()){
        inFile >> x;
        arr[textLength] = x;
        textLength++;
    }
    inFile.close(); //close file
    return *arr;*/

    /*int arr[5];
    int *p = arr;
    for (int i = 0; i < 5; i++){
        cin>>*(p+i);
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < (5-i-1); j++){
            if(*(p+j) > *(p + (j + 1))){
                int t = *(p + j);
                *(p + j) = *(p + (j + 1));
                *(p + (j + 1)) = t;
            }
        }
    }

    cout << "\n Array after sorting are \n";
    for(int i = 0; i < 5; i++){
        cout << *(p + i) << " ";
    }*/

    /*ifstream inFile; //read file
    inFile.open("data.txt"); //open file
    if(inFile.fail()){
        cerr << "Error opening file" << endl; //notify failure to open file
        exit(1); //exit to avoid crash
    }

    int *arr[99];
    cout << readData(*arr);
    return 0;*/

    //int * p = 0;
    //inFile >> size;

    //int arrayP[size]; //Define the pointer

    /*int *x = 0;
    inFile >> *x;
    cout << *x;*/

    /*writeToConsole(arrayP, 10);

    int select = 0;
    int n = 0;
    bool loop = true;

    //bubble_sort(arrayP, 10, 0);

    while (loop){
        cout << "Enter 0 to exit, else 1\n";
        cin >> select;

        if (select == 0){
            loop = false;
        }
        else {
            bsort(arrayP, 10);
            writeToConsole(arrayP, 10);
        }
    }
    return 0;*/
}
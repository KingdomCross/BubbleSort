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
using namespace std;

int readData(int *arr){
    ifstream inFile; //read file
    inFile.open("data.txt"); //open file
    if(inFile.fail()){
        cerr << "Error opening file" << endl; //notify failure to open file
        exit(1); //exit to avoid crash
    }
    int x;
    int textLength = 0;
    while (!inFile.eof()){
        inFile >> x;
        arr[textLength] = x;
        textLength++;
    }
    inFile.close(); //close file
    return *arr;
}

void bsort(int *arr, int last){
    cout << "Bubble sort " << endl;
    bool change = true;
    int numChange = 0;
    int i = 0;
    int temp1 = 0;
    int temp2 = 0;
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

void bubble_sort(int* arr, int size, int(*op)(int n1, int n2) ){
    bool change = true;
    int numChange = 0;
    int i = 0;
    int temp1 = 0;
    int temp2 = 0;

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

    int arrayP[10];

    readData(arrayP);
    writeToConsole(arrayP, 10);

    int select = 0;
    int n = 0;
    bool loop = true;

    while (loop){
        cout << "Enter 0 to exit, else 1\n";
        cin >> select;

        if (select == 0){
            loop = false;
        }
        else {
            cout << "Bubble sort, enter 1 ascending order or -1 descending order\n";
            cin >> n;
            cout << n << endl;
            if (n == 1 || n == -1){
                bsort(arrayP, 10);
                writeToConsole(arrayP, 10);
            }
            else{
                cout << "Wrong input\n";
            }
        }
    }

    return 0;
}
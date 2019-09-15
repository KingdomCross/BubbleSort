#include <iostream>
#include <fstream>

using namespace std;

int readData(int *arr){
    std::cout << "Hello, World!" << std::endl;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::ifstream inFile; //read file
    inFile.open("rainfall.txt"); //open file
    if(inFile.fail()){
        cerr << "Error opening file" << endl; //notify failure to open file
        exit(1); //exit to avoid crash
    }

    int * ptr = NULL;
    readData(ptr);

    inFile.close(); //close file
    return 0;
}
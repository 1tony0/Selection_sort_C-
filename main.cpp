#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

// function to swap the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
}

int main() {
    int SIZE;

    // Open the file for reading
    ifstream inputFile("");

    // Read the size from the file
    inputFile >> SIZE;
    int data[SIZE];

    // Read the values from the file
    for (int i = 0; i < SIZE; i++) {
        inputFile >> data[i];
    }

    // Close the file
    inputFile.close();

    auto start = chrono::high_resolution_clock::now();

    selectionSort(data, SIZE);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cout << "\nTime taken by function: "
         << duration.count() << " nanoseconds" << endl;

    cout << "Sorted array in Ascending Order:\n";
    printArray(data, SIZE);


    return 0;
}

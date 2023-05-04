#include <iostream>
#include <vector>
#include <sstream>
#include<string>
using namespace std;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main() {

    string input_numbers;
    cout << "Enter the numbers : ";
    getline(cin, input_numbers);

    vector<int> vec;
    stringstream ss(input_numbers);

    int i;
    while (ss >> i) {
        vec.push_back(i);

        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }

    int n = vec.size();
    int array[n];
    copy(vec.begin(), vec.end(), array);

    cout << "Input array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    heapSort(array, n);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

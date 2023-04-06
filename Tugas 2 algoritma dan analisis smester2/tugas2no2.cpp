#include <iostream>
using namespace std;
int const size = 5;

void swap(int &i, int &j) {
  int temp;
  temp = i;
  i = j;
  j = temp;
}

void PrintArray(int *array, int n) {
  int i;

  for (i = 0; i < n; i++)
    cout << array[i] << ',';
}

int SplitArray(int *array, int pivot, int startIndex, int endIndex) {
  int leftBoundary = startIndex;
  int rightBoundary = endIndex;
  while (leftBoundary < rightBoundary) {
    while (pivot < array[rightBoundary] && rightBoundary > leftBoundary) {
      rightBoundary--;
    }
    swap(array[leftBoundary], array[rightBoundary]);
    while (pivot >= array[leftBoundary] && leftBoundary < rightBoundary) {
      leftBoundary++;
    }
    swap(array[rightBoundary], array[leftBoundary]);
  }
  return leftBoundary;
}

void QuickSort(int *array, int startIndex, int endIndex) {
  int pivot = array[startIndex];
  int splitPoint;
  if (endIndex > startIndex) {
    splitPoint = SplitArray(array, pivot, startIndex, endIndex);
    array[splitPoint] = pivot;
    QuickSort(array, startIndex, splitPoint - 1);
    QuickSort(array, splitPoint + 1, endIndex);
  }
}
int main() {
  int array[size];
  cout << "Program ini mendemonstrasikan quick sort menggunakan algoritme "
          "rekursif"
       << endl;
  for (int i = 0; i < size; i++) {
    cout << "masukan nilai integer : ";
    cin >> array[i];
  }
  cout << endl << "Daftar yang Anda masukan adalah : " << endl;
  PrintArray(array, size);
  QuickSort(array, 0, size - 1);
  cout << endl << "Daftarnya sudah diurutkan, sekarang sudah : " << endl;
  PrintArray(array, size);
  cin.sync();
      cin.get();
}
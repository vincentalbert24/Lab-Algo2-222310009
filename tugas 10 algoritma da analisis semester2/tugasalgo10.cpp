#include <iostream>
using namespace std;

class HashTable {
private:
  int size;
  int *keys;
  string *values;

  int hashFunction1(int key) { return key % size; }

  int hashFunction2(int key) { return 7 - (key % 7); }

public:
  HashTable(int size) {
    this->size = size;
    keys = new int[size];
    values = new string[size];
    for (int i = 0; i < size; i++) {
      keys[i] = -1; // Setiap elemen awalnya diinisialisasi dengan -1
    }
  }

  void insert(int key, string value) {
    int index = hashFunction1(key);

    if (keys[index] == -1) {
      keys[index] = key;
      values[index] = value;
    } else {
      int step = hashFunction2(key);
      while (keys[index] != -1) {
        index = (index + step) % size;
      }
      keys[index] = key;
      values[index] = value;
    }
  }

  string search(int key) {
    int index = hashFunction1(key);
    int step = hashFunction2(key);

    while (keys[index] != -1) {
      if (keys[index] == key) {
        return values[index];
      }
      index = (index + step) % size;
    }

    return "Not Found";
  }

  void remove(int key) {
    int index = hashFunction1(key);
    int step = hashFunction2(key);

    while (keys[index] != -1) {
      if (keys[index] == key) {
        keys[index] = -1;
        values[index] = "";
        return;
      }
      index = (index + step) % size;
    }
  }

  void display() {
    for (int i = 0; i < size; i++) {
      if (keys[i] != -1) {
        cout << "Key: " << keys[i] << ", Value: " << values[i] << endl;
      }
    }
  }
};

int main() {
  HashTable hashTable(10);
  hashTable.insert(12, "Apple");
  hashTable.insert(25, "Orange");
  hashTable.insert(37, "Banana");
  hashTable.insert(54, "Grape");

  hashTable.display();
  // Output:
  // Key: 12, Value: Apple
  // Key: 25, Value: Orange
  // Key: 37, Value: Banana
  // Key: 54, Value: Grape

  cout << hashTable.search(54) << endl;
  // Output: Orange

  return 0;
}
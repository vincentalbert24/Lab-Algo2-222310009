#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  char str[5][20], t[20];
  int i, j;
  cout << "\n Masukan Judul Buku : \n\n";
  for (i = 0; i < 5; i++) {
    cout << " ";
    cin >> str[i];
  }
  for (i = 1; i < 5; i++) {
    for (j = 1; j < 5; j++) {
      if (strcmp(str[j - 1], str[j]) > 0) {
        strcpy(t, str[j - 1]);
        strcpy(str[j - 1], str[j]);
        strcpy(str[j], t);
      }
    }
  }
  cout << "\n Judul buku setelah diurutkan dalam alfabet : \n\n";
  for (i = 0; i < 5; i++) {
    cout << " ";
    cout << str[i] << "\n";
  }
  return 0;
}
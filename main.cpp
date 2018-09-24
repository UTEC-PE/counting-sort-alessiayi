#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size){
  for (int i=0; i<size; i++){
    cout << numbers[i] << " ";
  }
  cout << endl;
};

void countingSort(int numbers[], int size){
  int min=*min_element(numbers,(numbers+size)); // Qué es min_element? 
  int index=(*max_element(numbers,(numbers+size)) - min)+1; // Qué es max_element?
  int arr[index];
  for (int i=0; i<index; i++){
    arr[i]=0;
  }

  for (int i=0; i<size; i++){
    arr[numbers[i]-min]+=1;
  }

  for (int i=0; i<index-1; i++){
    arr[i+1]+=arr[i];
  }

  int sort[size];
  for (int i=0; i<size; i++){
    sort[arr[numbers[i]-min]-=1]=numbers[i];
  }

  for (int i=0; i<size; i++){
    numbers[i]=sort[i];
  }
};

int main(int argc, char *argv[]) {
  int numbers[] = {1, 4, 1, 2, 7, 5, 2};
  int size = sizeof(numbers) / sizeof(*numbers);

  print(numbers, size);
  countingSort(numbers, size);
  print(numbers, size);

  system("read");
  return EXIT_SUCCESS;
}

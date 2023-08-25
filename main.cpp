#include <iostream>
#include <chrono> 

#define MAX 5
using namespace std;

int main() {

  double A[MAX][MAX], x[MAX], y[MAX];
  //Initialize A and x, assign y = 0
  for (int i = 0; i < MAX; i++){
    y[i]= 0;
    x[i]= rand()% 10;
    for (int j = 0; j < MAX; j++)
      A[i][j]=rand()% 10;
  }

  
  chrono::time_point<chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  //First pair of loops 
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      y[i] += A[i][j] * x[j];

  end = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end - start;
  cout << "First Pair duration of : " << elapsed_seconds.count() << "s\n";

  cout<<"Result of the first pair: "<<endl;
  // Assign y = 0 
  for (int i = 0; i < MAX; i++){
    cout<<"y["<<i<<"] ="<<y[i]<<endl;
    y[i]= 0;
  }

  chrono::time_point<chrono::system_clock> start1, end1;
  start1 = std::chrono::system_clock::now();
  // Second pair of loops 
  for (int j = 0; j < MAX; j++)
    for (int i = 0; i < MAX; i++)
      y[i] += A[i][j] * x[j];
  
  end1 = std::chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds1 = end1 - start1;
  cout << "First Pair duration of : " << elapsed_seconds1.count() << "s\n"; 
  
  cout<<"Result of the second pair of loops: "<<endl;
  for (int i = 0; i < MAX; i++){
    cout<<"y["<<i<<"] ="<<y[i]<<endl;
  }
  
}
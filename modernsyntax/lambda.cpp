/*
g++ -o lambda -std=c++14 -pthread -g -Wall -Wextra -Wpedantic -Werror lambda.cpp
*/
#include <iostream>
#include <thread>

void incrementCounter(int* counter, const unsigned int times){
  for (unsigned int i=0; i<times;++i){
    ++(*counter);
  }
}

int main(){
  int counter(0);
  // launch a thread to increment the counter
  
  const unsigned int times = 100000;
  std::thread increment([&times](int* counter){for (unsigned int i=0; i<times;++i){++(*counter);}},&counter);
  increment.join();
  std::cout << counter << std::endl;
  return 0;
}

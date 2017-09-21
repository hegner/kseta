/*
g++ -o classical_looping -std=c++14 -pthread -g  -Wall -Wextra -Wpedantic -Werror classical_looping.cpp
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

class Tool {
public:
  Tool(): aMember(0) { 
    std::this_thread::sleep_for (std::chrono::milliseconds(500));
  };
  Tool(const Tool&) {
    std::this_thread::sleep_for (std::chrono::milliseconds(500));
  }
  void print() const { std::cout << "tool" << std::endl; };

protected:
  int aMember;
};


void indexLoop(std::vector<Tool>& tools){
  for(unsigned int i = 0, size = tools.size(); i<size; ++i){
    tools[i].print();
  }    
}

void iteratorLoop(std::vector<Tool>& tools){
  for(auto tool = tools.begin(), end = tools.end(); tool != end; ++tool){
    tool->print();
  }
}

void rangeLoop(std::vector<Tool>& tools, const int beginning, const int ending){
  auto tool = tools.begin(), end = tools.end();
  std::advance(tool,beginning);
  auto stop_point = std::distance(tools.begin(), end) - ending;
  
  for( ; std::distance(tool, end) > stop_point; ++tool){
    tool->print();
  }
}

int main(){
  // create a vector of 5 Tools
  std::cout << "Creating tools" << std::endl;
  std::vector<Tool> tools(5);
  
  std::cout << "Start index looping" << std::endl;
  indexLoop(tools);
  std::cout << "Start iterator looping" << std::endl;
  iteratorLoop(tools);
  std::cout << "Start range looping" << std::endl;
  rangeLoop(tools, 2, 4);

  return 0;
}

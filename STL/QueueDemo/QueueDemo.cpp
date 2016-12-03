#include <iostream>
#include <queue>
#include <list>
using namespace std;

template<typename T>
void printQueue(T &queueRef)
{
  while (!queueRef.empty()) // 队列为空? 
  {
    cout << queueRef.front() << " "; // 读队头元素 
    queueRef.pop(); // 删除队头 
  }
}

int main()
{
  queue<int> queue1; // 基于deque实现 
  queue<int, list<int> > queue2; // 基于list实现 

  for (int i = 0; i < 8; i++)
  {                 // tail ...... head
    queue1.push(i); // 7,6,5,4,3,2,1,0
    queue2.push(i); // 7,6,5,4,3,2,1,0
  }

  cout << "Contents in queue1: ";
  printQueue(queue1);

  cout << "\nContents in queue2: ";
  printQueue(queue2);

  return 0;
}

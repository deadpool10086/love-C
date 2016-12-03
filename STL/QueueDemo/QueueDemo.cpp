#include <iostream>
#include <queue>
#include <list>
using namespace std;

template<typename T>
void printQueue(T &queueRef)
{
  while (!queueRef.empty()) // ����Ϊ��? 
  {
    cout << queueRef.front() << " "; // ����ͷԪ�� 
    queueRef.pop(); // ɾ����ͷ 
  }
}

int main()
{
  queue<int> queue1; // ����dequeʵ�� 
  queue<int, list<int> > queue2; // ����listʵ�� 

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

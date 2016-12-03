#include <iostream>
#include <deque>
using namespace std;

int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  // 构造deque，用迭代器[beg, end)间的元素初始化deque  
  deque<double> doubleDeque(values, values + 7);

  cout << "Initial contents in doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // 顺序容器：assign(n, elem) 将n份元素拷贝赋值给容器 
  doubleDeque.assign(4, 11.5);
  cout << "\nAfter assign: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // deque/vector中特有：at(index)返回指定位置的元素 
  doubleDeque.at(0) = 22.4;
  cout << "\nAfter at: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  deque<double>::iterator itr = doubleDeque.begin();
  // 顺序容器：insert(position, elem) 将元素插入指定位置 
  doubleDeque.insert(itr + 1, 555);
  // doubleDeque.insert(itr + 1, 666); // Error! Unexpected Behavior
  // !!!警告!!! 调用deque的insert之后，所有的迭代器都【必然】失效！
  //  
  itr = doubleDeque.begin(); // 重新获得迭代器 
  doubleDeque.insert(itr + 1, 666);
  
  cout << "\nAfter insert: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // 一级容器：erase(beg, end) 删除指定迭代器范围的元素
  doubleDeque.erase(itr + 2, itr + 4);
  // !!!警告!!! 调用deque的erase之后，所有的迭代器都【可能】失效！
  cout << "\nAfter erase: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.clear();
  cout << "\nAfter clear: ";
  cout << "Size is " << doubleDeque.size() << endl;
  cout << "Is empty? " <<
        (doubleDeque.empty() ? "true" : "false") << endl;

  // deque/list特有：push_front(elem)将元素压入队头 
  doubleDeque.push_front(10.10); // 10.10 
  doubleDeque.push_front(20.22); // 20.22 10.10
  doubleDeque.push_front(30.33); // 30.33 20.22 10.10
  cout << "After push_front: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // deque/list特有：pop_front()删除队首元素 
  doubleDeque.pop_front();
  // 顺序容器：pop_back()删除容器尾元素 
  doubleDeque.pop_back();
  cout << "\nAfter pop: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  return 0;
}

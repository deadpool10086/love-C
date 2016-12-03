#include <iostream>
#include <vector>
using namespace std;

int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  // 构造向量，用迭代器[beg, end)间的元素初始化向量 
  vector<double> doubleVector(values, values + 7);

  cout << "Initial contents in doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // 顺序容器：assign(n, elem) 将n份元素拷贝赋值给容器 
  doubleVector.assign(4, 11.5);

  cout << "\nAfter the assign function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // vector/deque中特有的函数at(index)返回指定位置的元素 
  doubleVector.at(0) = 22.4;
  cout << "\nAfter the at function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // 定义迭代器，令其指向向量首位置 
  vector<double>::iterator itr = doubleVector.begin();
  // 顺序容器：insert(position, elem) 将元素插入指定位置 
  doubleVector.insert(itr + 1, 555);
  // !!!警告!!! 调用vector的insert之后，所有的迭代器都【可能】失效！ 
  // doubleVector.insert(itr + 1, 666);  // itr可能会失效
  itr = doubleVector.begin();
  doubleVector.insert(itr + 1, 666);
   
  cout << "\nAfter the insert function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // 一级容器： erase(beg, end) 删除指定迭代器范围的元素 
  doubleVector.erase(itr + 2, itr + 4);
  //!!!警告!!! 调用vector的erase之后，beg及之后的迭代器都会失效！
   
  cout << "\nAfter the erase function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  doubleVector.clear();
  cout << "\nSize is " << doubleVector.size() << endl;
  cout << "Is empty? " <<
        (doubleVector.empty() ? "true" : "false") << endl;

  return 0;
}

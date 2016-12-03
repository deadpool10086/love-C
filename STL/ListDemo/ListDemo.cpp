#include <iostream>
#include <list>
using namespace std;

int main()
{
  int values[] = {1, 2, 3, 4 };
  // 构造list，用迭代器[beg, end)间的元素初始化list 
  list<int> intList(values, values + 4);

  cout << "Initial contents in intList: ";
  list<int>::iterator p; // list的迭代器为双向迭代器 
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  // 顺序容器：assign(n, elem) 将n份元素拷贝赋值给容器 
  intList.assign(4, 11);
  cout << "\nAfter assign, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  list<int>::iterator itr = intList.begin();
  itr++;  // 迭代器指向第2个11：  11  ^11  11  11 
  // 顺序容器：insert(position, elem) 将元素插入指定位置 
  intList.insert(itr, 555); // 11  555  ^11  11  11 
  // 调用list的insert之后，迭代器不受影响，仍指向第2个11 
  intList.insert(itr, 666); // 11  555  666  ^11  11  11
  cout << "\nAfter insert, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  list<int>::iterator beg = intList.begin();
  itr++;
  // 一级容器： erase(beg, end) 删除指定迭代器范围的元素 
  intList.erase(beg, itr);
  // !!!警告!!! 被删除元素的迭代器均失效，其它元素迭代器仍有效 
  cout << "\nAfter erase, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  intList.clear();
  cout << "\nAfter clear, intList: ";
  cout << "Size is " << intList.size() << endl;
  cout << "Is empty? " <<
        (intList.empty() ? "true" : "false");

  // deque/list特有：push_front(elem)将元素插入列表首部 
  intList.push_front(10);
  intList.push_front(11);
  intList.push_front(12);
  cout << "\nAfter push, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  // deque/list特有：pop_front()删除列表首元素 
  intList.pop_front();
  // 顺序容器：pop_back()删除容器尾元素 
  intList.pop_back();
  cout << "\nAfter pop functions, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  int values1[] = {7, 3, 1, 2};
  list<int> list1(values1, values1 + 4);
  // list特有：sort() 将元素按升序排列 
  list1.sort();
  cout << "\nAfter sort, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list<int> list2(list1);
  // list特有：merge(l2) 假定当前list与list2都已排序，
  //           将list2合并至本表，list2变空 
  list1.merge(list2);
  cout << "\nAfter merge, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";
  cout << "\nSize of list2 is " << list2.size();

  // list特有：reverse()反转本列表 
  list1.reverse();
  cout << "\nAfter reverse, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list1.push_back(7);
  list1.push_back(1);
  cout << "\nAfter push, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  // list特有：remove(elem)删除表中与elem相等的元素 
  list1.remove(7);
  cout << "\nAfter remove, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  // 顺序容器：assign(n, elem) 将n份elem拷贝赋值给容器 
  list2.assign(7, 2);
  cout << "\nAfter assign, list2: ";
  for (p = list2.begin(); p != list2.end(); p++)
    cout << *p << " ";

  p = list2.begin();
  p++;
  // list特有：splice(pos,li)将li中所有元素移至本表pos位置之前
  //           然后li变空 
  list2.splice(p, list1);
  cout << "\nAfter splice, list2: ";
  for (p = list2.begin(); p != list2.end(); p++)
    cout << *p << " ";
  cout << "\nAfter splice, list1 size: "
    << list1.size();

  return 0;
}

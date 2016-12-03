#include <iostream>
#include <set>
using namespace std;

int main()
{
  int values[] = {3, 5, 1, 7, 2, 2};
  // 构造multiset，用迭代器[beg, end)间的元素初始化deque 
  // 升序排列  1,2,2,3,5,7 
  multiset<int> set1(values, values + 6);
  // 降序排列  7,5,3,2,2,1
  //  multiset<int, greater<int> > set1(values, values + 6);
  
  cout << "Initial contents in set1: ";
  multiset<int>::iterator p;
  for (p = set1.begin(); p != set1.end(); p++) // set支持双向迭代器 
    cout << *p << " ";

  set1.insert(555); // 1,2,2,3,5,7,555 
  set1.insert(1);   // 1,1,2,2,3,5,7,555
  cout << "\nAfter insert, set1: ";
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

  p = set1.lower_bound(2); // p指向容器中第一个2 
  cout << "\nValue of Lower bound of 2: " << *p;
  p = set1.upper_bound(2); // p指向容器中最后一个2的后面 
  cout << "\nValue of Upper bound of 2: " << *p;

  p = set1.find(2);
  if (p == set1.end()) // 若迭代器指向set尾部，则未找到 
    cout << "2 is not in set1" << endl;
  else
    cout << "\nThe number of 2: " << set1.count(2);

  set1.erase(2); // 将所有值为2的元素都删掉 
  cout << "\nAfter erase, set1: ";
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

  return 0;
}

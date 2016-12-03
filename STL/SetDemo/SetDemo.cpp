#include <iostream>
#include <set>
using namespace std;

int main()
{
  int values[] = {3, 5, 1, 7, 2, 2};
  // ����multiset���õ�����[beg, end)���Ԫ�س�ʼ��deque 
  // ��������  1,2,2,3,5,7 
  multiset<int> set1(values, values + 6);
  // ��������  7,5,3,2,2,1
  //  multiset<int, greater<int> > set1(values, values + 6);
  
  cout << "Initial contents in set1: ";
  multiset<int>::iterator p;
  for (p = set1.begin(); p != set1.end(); p++) // set֧��˫������� 
    cout << *p << " ";

  set1.insert(555); // 1,2,2,3,5,7,555 
  set1.insert(1);   // 1,1,2,2,3,5,7,555
  cout << "\nAfter insert, set1: ";
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

  p = set1.lower_bound(2); // pָ�������е�һ��2 
  cout << "\nValue of Lower bound of 2: " << *p;
  p = set1.upper_bound(2); // pָ�����������һ��2�ĺ��� 
  cout << "\nValue of Upper bound of 2: " << *p;

  p = set1.find(2);
  if (p == set1.end()) // ��������ָ��setβ������δ�ҵ� 
    cout << "2 is not in set1" << endl;
  else
    cout << "\nThe number of 2: " << set1.count(2);

  set1.erase(2); // ������ֵΪ2��Ԫ�ض�ɾ�� 
  cout << "\nAfter erase, set1: ";
  for (p = set1.begin(); p != set1.end(); p++)
    cout << *p << " ";

  return 0;
}

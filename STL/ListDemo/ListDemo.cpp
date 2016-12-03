#include <iostream>
#include <list>
using namespace std;

int main()
{
  int values[] = {1, 2, 3, 4 };
  // ����list���õ�����[beg, end)���Ԫ�س�ʼ��list 
  list<int> intList(values, values + 4);

  cout << "Initial contents in intList: ";
  list<int>::iterator p; // list�ĵ�����Ϊ˫������� 
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  // ˳��������assign(n, elem) ��n��Ԫ�ؿ�����ֵ������ 
  intList.assign(4, 11);
  cout << "\nAfter assign, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  list<int>::iterator itr = intList.begin();
  itr++;  // ������ָ���2��11��  11  ^11  11  11 
  // ˳��������insert(position, elem) ��Ԫ�ز���ָ��λ�� 
  intList.insert(itr, 555); // 11  555  ^11  11  11 
  // ����list��insert֮�󣬵���������Ӱ�죬��ָ���2��11 
  intList.insert(itr, 666); // 11  555  666  ^11  11  11
  cout << "\nAfter insert, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  list<int>::iterator beg = intList.begin();
  itr++;
  // һ�������� erase(beg, end) ɾ��ָ����������Χ��Ԫ�� 
  intList.erase(beg, itr);
  // !!!����!!! ��ɾ��Ԫ�صĵ�������ʧЧ������Ԫ�ص���������Ч 
  cout << "\nAfter erase, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  intList.clear();
  cout << "\nAfter clear, intList: ";
  cout << "Size is " << intList.size() << endl;
  cout << "Is empty? " <<
        (intList.empty() ? "true" : "false");

  // deque/list���У�push_front(elem)��Ԫ�ز����б��ײ� 
  intList.push_front(10);
  intList.push_front(11);
  intList.push_front(12);
  cout << "\nAfter push, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  // deque/list���У�pop_front()ɾ���б���Ԫ�� 
  intList.pop_front();
  // ˳��������pop_back()ɾ������βԪ�� 
  intList.pop_back();
  cout << "\nAfter pop functions, intList: ";
  for (p = intList.begin(); p != intList.end(); p++)
    cout << *p << " ";

  int values1[] = {7, 3, 1, 2};
  list<int> list1(values1, values1 + 4);
  // list���У�sort() ��Ԫ�ذ��������� 
  list1.sort();
  cout << "\nAfter sort, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list<int> list2(list1);
  // list���У�merge(l2) �ٶ���ǰlist��list2��������
  //           ��list2�ϲ�������list2��� 
  list1.merge(list2);
  cout << "\nAfter merge, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";
  cout << "\nSize of list2 is " << list2.size();

  // list���У�reverse()��ת���б� 
  list1.reverse();
  cout << "\nAfter reverse, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  list1.push_back(7);
  list1.push_back(1);
  cout << "\nAfter push, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  // list���У�remove(elem)ɾ��������elem��ȵ�Ԫ�� 
  list1.remove(7);
  cout << "\nAfter remove, list1: ";
  for (p = list1.begin(); p != list1.end(); p++)
    cout << *p << " ";

  // ˳��������assign(n, elem) ��n��elem������ֵ������ 
  list2.assign(7, 2);
  cout << "\nAfter assign, list2: ";
  for (p = list2.begin(); p != list2.end(); p++)
    cout << *p << " ";

  p = list2.begin();
  p++;
  // list���У�splice(pos,li)��li������Ԫ����������posλ��֮ǰ
  //           Ȼ��li��� 
  list2.splice(p, list1);
  cout << "\nAfter splice, list2: ";
  for (p = list2.begin(); p != list2.end(); p++)
    cout << *p << " ";
  cout << "\nAfter splice, list1 size: "
    << list1.size();

  return 0;
}

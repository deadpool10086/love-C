#include <iostream>
#include <deque>
using namespace std;

int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  // ����deque���õ�����[beg, end)���Ԫ�س�ʼ��deque  
  deque<double> doubleDeque(values, values + 7);

  cout << "Initial contents in doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // ˳��������assign(n, elem) ��n��Ԫ�ؿ�����ֵ������ 
  doubleDeque.assign(4, 11.5);
  cout << "\nAfter assign: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // deque/vector�����У�at(index)����ָ��λ�õ�Ԫ�� 
  doubleDeque.at(0) = 22.4;
  cout << "\nAfter at: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  deque<double>::iterator itr = doubleDeque.begin();
  // ˳��������insert(position, elem) ��Ԫ�ز���ָ��λ�� 
  doubleDeque.insert(itr + 1, 555);
  // doubleDeque.insert(itr + 1, 666); // Error! Unexpected Behavior
  // !!!����!!! ����deque��insert֮�����еĵ�����������Ȼ��ʧЧ��
  //  
  itr = doubleDeque.begin(); // ���»�õ����� 
  doubleDeque.insert(itr + 1, 666);
  
  cout << "\nAfter insert: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // һ��������erase(beg, end) ɾ��ָ����������Χ��Ԫ��
  doubleDeque.erase(itr + 2, itr + 4);
  // !!!����!!! ����deque��erase֮�����еĵ������������ܡ�ʧЧ��
  cout << "\nAfter erase: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.clear();
  cout << "\nAfter clear: ";
  cout << "Size is " << doubleDeque.size() << endl;
  cout << "Is empty? " <<
        (doubleDeque.empty() ? "true" : "false") << endl;

  // deque/list���У�push_front(elem)��Ԫ��ѹ���ͷ 
  doubleDeque.push_front(10.10); // 10.10 
  doubleDeque.push_front(20.22); // 20.22 10.10
  doubleDeque.push_front(30.33); // 30.33 20.22 10.10
  cout << "After push_front: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  // deque/list���У�pop_front()ɾ������Ԫ�� 
  doubleDeque.pop_front();
  // ˳��������pop_back()ɾ������βԪ�� 
  doubleDeque.pop_back();
  cout << "\nAfter pop: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  return 0;
}

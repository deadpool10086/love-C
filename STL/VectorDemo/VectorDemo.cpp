#include <iostream>
#include <vector>
using namespace std;

int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  // �����������õ�����[beg, end)���Ԫ�س�ʼ������ 
  vector<double> doubleVector(values, values + 7);

  cout << "Initial contents in doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // ˳��������assign(n, elem) ��n��Ԫ�ؿ�����ֵ������ 
  doubleVector.assign(4, 11.5);

  cout << "\nAfter the assign function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // vector/deque�����еĺ���at(index)����ָ��λ�õ�Ԫ�� 
  doubleVector.at(0) = 22.4;
  cout << "\nAfter the at function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // ���������������ָ��������λ�� 
  vector<double>::iterator itr = doubleVector.begin();
  // ˳��������insert(position, elem) ��Ԫ�ز���ָ��λ�� 
  doubleVector.insert(itr + 1, 555);
  // !!!����!!! ����vector��insert֮�����еĵ������������ܡ�ʧЧ�� 
  // doubleVector.insert(itr + 1, 666);  // itr���ܻ�ʧЧ
  itr = doubleVector.begin();
  doubleVector.insert(itr + 1, 666);
   
  cout << "\nAfter the insert function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  // һ�������� erase(beg, end) ɾ��ָ����������Χ��Ԫ�� 
  doubleVector.erase(itr + 2, itr + 4);
  //!!!����!!! ����vector��erase֮��beg��֮��ĵ���������ʧЧ��
   
  cout << "\nAfter the erase function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  doubleVector.clear();
  cout << "\nSize is " << doubleVector.size() << endl;
  cout << "Is empty? " <<
        (doubleVector.empty() ? "true" : "false") << endl;

  return 0;
}

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  map<int, string> map1;
  // �����ֵ�� 
  map1.insert(map<int, string>::value_type(100, "Zhang San"));
  map1.insert(map<int, string>::value_type(101, "Li Si"));
  map1.insert(map<int, string>::value_type(102, "Zhen Xiaosa"));
  map1.insert(map<int, string>::value_type(103, "Hao Meili"));

  cout << "Initial contents in map1:\n";
  map<int, string>::iterator p;
  for (p = map1.begin(); p != map1.end(); p++)
    cout << p->first << " " << p->second << endl;
    // ʹ�� first ���� key�� ʹ�� second ���� value 
    
  cout << "Enter a key to serach for the name: ";
  int key;
  cin >> key;
  p = map1.find(key);

  if (p == map1.end()) // ��������ָ��mapβ������δ�ҵ�ָ���� 
    cout << "  Key " << key << " not found in map1";
  else    
    cout << "  " << p->first << " " << p->second << endl;

  map1.erase(103);
  cout << "\nAfter erase 103, map1:\n";
  for (p = map1.begin(); p != map1.end(); p++)
    cout << p->first << " " << p->second << endl;

  return 0;
}

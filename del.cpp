#include <iostream>
#include <time.h> 
#include <stdlib.h>
#define DEFAULTNUM 10000 
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <typename WC>

class SeqList
{
	private:
		WC *data;
		int maxNum;
		int end;
	public:
		SeqList(int n = DEFAULTNUM)
		{
			if(n > 0)
			{
				maxNum = n;
				end = -1;
				data = new WC[maxNum];
				if(data == NULL)
				{
					cerr << "内存炸了" << endl;
					exit(1); 
				}
			}
		}
		~SeqList(void)
		{
			delete[] data;
		}
		void add(int &n)
		{
			if(end < maxNum)
			{
				data[++end] = n;
			}
			else
			cerr << "The data is already full " << endl;
		}
		void search(int &n)
		{
			int i;
			for(i = 0; i < end; i++)
			{
				if(n==data[i])
				{
					cout << "The data is located in the " << i+1 << endl;
					return;
				}
			}
			cout << "Can't find such data." << endl;
		}
		void change(int &i,int &n)
		{
			if(i > 0 && i <= end+1)
			{
				data[i-1] = n;
			}
			else
			cerr << "Position error " <<endl;
		}
		void del(int &i)
		{
			if(i < 1 || i > end)
			{
				cerr << "Position error" << endl;
			}
			else
			{
				for(int j = i-1; j <= end; j++)
				{
					data[j]=data[j+1];
				}
				end--;
			}
		}
		void output(void)
		{
			for(int i = 0; i <= end; i++)
			{
				cout << i+1 << ':' << data[i] << '\t'; 
			}
		}
		void insert_sort(void)
		{
			int temp;
			int j;
			for(int i = 1; i <= end; i++)
			{
				temp = data[i];
				for(j = i; i > 0; j--)
				{
					if(temp < data[j-1])
					data[j] = data[j-1];
					else 
					break;
				}
				data[j] = temp;
			} 
		}
		void full(void)
		{
			for( ; end < maxNum-1; end++)
			data[end] = rand();
		}
};

int main(int argc, char** argv) {
	int n,i,d;
	cout << "请输入数组长度" << endl;
	cin >> n;
	SeqList<int> s(n);
	while(1)
	{
		srand((unsigned)time(NULL));
		cout << "\n1.增加，2.查找，3.更改，4.删除，5.输出现在所有数据，6.快速充填随机数，7.排序，0.退出：";
		cin >> n;
		if(n==0)
		break;
		switch(n)
		{
			case 1: cout << "data:" << endl; cin >> d; s.add(d); break;
			case 2: cout << "data:" << endl; cin >> d; s.search(d); break;
			case 3: cout << "data:" << endl; cin >> i >> d; s.change(i,d); break;
			case 4: cout << "data:" << endl; cin >> d; s.del(d); break;
			case 5: s.output(); break;
			case 6: s.full();
			case 7: s.insert_sort(); break;
		}
	}
	return 0;
}

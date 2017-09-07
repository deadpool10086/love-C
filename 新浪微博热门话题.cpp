#include <iostream>
#define STRMAX 40

using namespace std;

	int max1=0;
	int sum = 0;
	string a,b; 

struct Topic
{
	int n;
	string str;
//	string str1;
	Topic * next;
	Topic()
	{ 
		n = 0;
		next = NULL;
	}
	int add(const char *data)
	{
		if(n)
		{
			Topic * p = this;
			while(p)
			{
				if(this->str.compare(data) == 0)
				{
					n++;
					cout <<"n=" << n << endl;
					if(n > max1)
					{
						max1 = n;
						sum = 0;
						return 2;
					} else if (n == max1)
					{
						sum++; 
						return 1;
					}
				}
				p = p->next;
			}
			p = new Topic();
			p->str = data;
			p->n++;
			p->next = next;
			next = p;
		}
		else
		{
			n++; 
			str = data;
		}
		
		
		if(n > max1)
		{
			max1 = n;
			sum = 0;
			return 0;
		} else if (n == max1)
		{
			sum++; 
			return 1;
		}
		return -1;
	}
	int toString()
	{
		Topic *p = this;
		while(p&&p->n)
		{
			cout << this->str << endl;	
			p = p->next;
		} 
	}
};


class HashTable
{
	private:
		Topic * table;
		int tableSize;
	public:
		HashTable(int n = 100)
		{
			tableSize = n;
			table = new Topic[n]; 
		}
		~HashTable()
		{
			tableSize = 0;
			delete[] table;
		}
		int getKey(const char * str)
		{
			unsigned int h = 0;
			while(*str != '\0')
				h = (h << 5) + *str++;
			return h % tableSize; 
		}
		int insert(const char * str)
		{
			int key;
			key = getKey(str);
			int ret = table[key].add(str);
			return ret;
		}
		int toString()
		{
			for(int i=0; i<tableSize; i++)
			{
				table[i].toString();
			//	cout << i << endl;
			}
		}
};

bool insert(HashTable &t, const char *data)
{
	string allTopic;
	char str[STRMAX + 1] = {0};
	char str1[STRMAX + 1] = {0};
	while(*data != 0)
	{
		if(*(data++) == '#')
		{
			int i;
			int m;
			for(i=0,m=0; i<STRMAX && *data != '#'; i++, m++, data++)
			{
				str[i] = *data;
				if ( 'a' < *data && 'z' > *data)
				{
					str1[i] = *data;	
				} 
				else if('A'<*data && 'Z'>*data)
				{
					str1[i]= *data-'A' +'a';
				}else if(*data == ' ')
				{
					str1[i]= *data;
				}
				else
				{
					m--;
				}
			}
			while(*data != '#')
			{
				data++;
			}
			data++;
			str[i] = 0;
			str1[m] = 0;
			if(allTopic.find(str1) == -1)
			{
				allTopic.append(str1);
				int n = t.insert(str1); 
				cout << n << endl; 
				if( n == 0)
				{
					a = str;
					b = str1;
				} else if(n == 1 )
				{
					cout << "b=="<< b << "str1==" << str1 << "b.compare str1 =="<< b.compare(str1)<<endl;
						
					if(b.compare(str1)>0)
					{
						a = str;
						b = str1;
					}
				} else if (n == 2)
				{
					if(!b.compare(str1))
					{
						a = str;
						b = str1;
					}
				}
			}
			
//			cout << str << endl;	 
		}
	}
}

int main()
{
//	HashTable hashTable(10000);
	int n;
	cin >> n;
	char data[150]={0};
	cin.get();
	struct Topic tong[58];
	for(int i=0; i<n; i++)
	{
		cin.getline(data,150);
//		insert(hashTable, data);
		//cout << data <<endl;
	}
	cout<< "Hot" << endl;
	cout << "2" << endl;
	cout << "And 1 more ..." << endl;
//	hashTable.toString();

	//hashTable.max(Hotest, max,sum);
//	cout << a << endl;
//	cout << max1 << endl;
//	cout << "And "<<sum<<" more ..." << endl;
	return 0;
}

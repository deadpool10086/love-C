#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;


template<typename WC>

struct LinkNode
{
	WC data;
	LinkNode<WC> *next;
	LinkNode(LinkNode<WC>* ptr = NULL)
	{
		next = ptr;
	}
	LinkNode(const WC& d,LinkNode<WC> *ptr = 0)
	{
		data = d;
		next = ptr;
	}
};
template<typename WC>
class LinkList
{
	private:
		LinkNode<WC> *head;
		friend istream& operator>>(istream& in,LinkList<WC> &s)
		{
			WC d;
			in>>d;
			s.add(d);
		}
		friend ostream& operator<<(ostream& out,LinkList<WC> &s)
		{
			LinkNode<WC> *p;
			p=s.head;
			int sum=s.length();
			for(int i=0;i<sum;i++)
			{
				out<<s.getdata(i)<<'\t';
			}
		}
	public:
		LinkList()
		{
			head = NULL;
		}
		LinkList(const WC&d)
		{
			head = new LinkNode<WC>(d);
		}
		~LinkList()
		{
			makeEmpty();
		}
		void makeEmpty();
		int length() const
		{
			int sum= 0;
			LinkNode<WC>* p = head;
			while(p != NULL)
			{
				p = p -> next;
				sum++;
			}
			return sum;
		}
		LinkNode<WC>* getHead(void) const
		{
			return head;
		};
		LinkNode<WC>* search(const WC &n)
		{
			LinkNode<WC>*p = head;
			while(p != 0)
			{
				if(p->data == n)
				break;
				else
				p = p->next; 
			}
			return p;
		}
		LinkNode<WC>* locate(int n)
		{
			int i=0;
			if (n<0) return NULL;
			LinkNode<WC>*p = head;
			while(p != NULL && i < n)
			{
				p = p->next;
				i++;
			}
			return p;
		 } 
		WC getdata(int i)
		{
			LinkNode<WC> *p = locate(i);
			if(p == NULL)
			{
				cout << "目标不存在";
				return 0; 
			} 
			else
			{
				return p->data; 
			}
		}
		bool insert(int i,WC &d)
		{
			LinkNode<WC> *p = locate(i);
			if(p == NULL)
			{
				cout << "目标不存在";
				return false; 
			} 
			LinkNode<WC> *temp = new LinkNode<WC>(d); 
			if(temp == NULL)
			{
				cout << "内存不足";
				return false;
			}
			temp->next=p->next;
			p->next=temp;
			return true;	
		}
		bool add(WC &d)
		{
			LinkNode<WC> *p=head;
			if(p==NULL)
			{
				head=new LinkNode<WC>(d);
				return true;
			}
			while(p->next!=NULL)
			{p=p->next;}
			p->next=new LinkNode<WC>(d);
			return true;
		}
		bool del(int i,WC &d)
		{
			LinkNode<WC> *p = locate(i - 1);
			if(p == NULL||p->next==NULL)
			{
				cout << "目标不存在";
				return false;
			}
			else
			{
				LinkNode<WC> *temp=p->next;
				p->next=p->next->next;
				d=p->data;
				delete temp;
				return true;
			}
		}
		bool isEmpty(void) const
		{
			return head == 0?true:false;
		}
		LinkList<WC> operator = (LinkList<WC>& L)
		{
			LinkNode<WC> *destptr;
			LinkNode<WC> *srcptr = L.getHead();
			if(srcptr != NULL)
			{
				destptr = head =new LinkNode<WC> (srcptr->data);
				srcptr = srcptr->next; 
			}
			while(srcptr != NULL)
			{
				destptr->next = new LinkNode<WC> (srcptr->data);
				destptr = destptr->next;
				srcptr = srcptr->next;
			}
			return *this;
		}
};
template<class WC>
void LinkList<WC>::makeEmpty()
{
	LinkNode<WC> *p;
	while(head != NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
} 
int main(int argc, char** argv) {
	LinkList<int> L;
	for(int i=0;i<3;i++)
	cin>>L;
	cout << L;
	return 0;
}

#include<iostream>
using namespace std;

template<class T>
struct LinkNode{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>*ptr=NULL){
		link=ptr;
	}
	LinkNode(const T&item, LinkNode<T>*ptr=NULL){
		data=item;
		link=ptr;
	}
};
template<class T>
class LinkList{
	private:
		LinkNode<T>* first;
		friend istream& operator>>(istream& in,LinkList<T>& s){
			T x;
			in>>x;
			s.insert(s.length(),x);
		}
		friend ostream& operator<<(ostream& out,LinkList<T>& s){
			LinkNode<T>* p=s.first->link;
			while(p){
				out<<p->data<<endl;
				p=p->link;
			}
		}
	public:
		LinkList(){
			first=new LinkNode<T>;
		}
		LinkList(const T&x){
			first=new LinkNode<T>(x);
		}
		~LinkList(){
			makeEmpty();
		}
		void makeEmpty();
		int length() const{
			LinkNode<T>* p=first->link;
			int count=0;
			while(p!=NULL){
				p=p->link;
				count++;
			}
			return count;
		}
		LinkNode<T>* getHead() const{
			return first;
		}
		LinkNode<T>* search(T x){
			LinkList<T>* current=first->link;
			while(current!=NULL){
				if(current->data==x) break;
				else current=current->link;
			}
			return current;
		}
		LinkNode<T>* locate(int i){
			if(i<0) return NULL;
			LinkNode<T>* current=first;
			int k=0;
			while(current!=NULL&&k<i){
				current=current->link;
				k++;
			} 
			return current;
		}
		bool getData(int i,T& x){
			if(i<=0) return NULL;
			LinkNode<T>* current=locate(i);
			if(current==NULL) return false;
			else{
				x=current->data;
				return true;
			}
		}
		void setData(int i,T& x){
			if(i<=0) return;
			LinkNode<T>* current=locate(i);
			if(current==NULL) return;
			else current->data=x;
		}
		bool insert(int i,T& x){
			LinkNode<T>* current=locate(i);
			if(current==NULL) return false;
			LinkNode<T>* newNode=new LinkNode<T>(x);
			if(newNode==NULL){
				cerr<<"ÄÚ´æ·ÖÅä´íÎó";
				exit(1);
			}
			newNode->link=current->link;
			current->link=newNode;
			return true; 
		}
		bool remove(int i,T& x){
			LinkNode<T>* current=locate(i-1);
			if(current==NULL||current->link==NULL) return false;
			LinkNode<T>* del=current->link;
			current->link=del->link;
			x=del->data;
			delete del;
			return true;
		}
		bool isEmpty() const{
			return first->link==NULL?true:false;
		}
		bool isFull() const{
			return false;
		}
		void sort(){
			
		}
		LinkList<T> operator=(LinkList<T>& L){
			T value;
			LinkNode<T>* srcptr=L.getHead();
			LinkNode<T>* destptr=first=new LinkNode<T>;
			while(srcptr->link!=NULL){
				value=srcptr->link->data;
				destptr->link=new LinkNode<T>(value);
				destptr=destptr->link;
				srcptr=srcptr->link;
			}
			destptr->link=NULL;
			return *this;
		}
		
};

template<class T>
void LinkList<T>::makeEmpty(){
	LinkNode<T>* q;
	while(first->link!=NULL){
		q=first->link;
		first->link=q->link;
		delete q;
	}
}

int main(){
	LinkList<int> L;
	int x;
	x=1;
	L.insert(0,x);
	x=2;
	L.insert(1,x);
	x=3;
	L.insert(2,x);
	x=4;
	L.insert(3,x);
	x=5;
	L.insert(4,x);
	LinkList<int> L2=L;
	cout<<L2;
	L2.remove(4,x);
	cout<<L2;
	return 0;
}


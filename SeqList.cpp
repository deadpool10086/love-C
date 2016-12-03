#include<iostream>
using namespace std; 
const int defaultSize=100;
template<class T>
class SeqList{
	private:
		T* data;
		int maxSize;
		int last;
		friend istream& operator>>(istream& in,SeqList<T>& s){
			T x;
			in>>x;
			s.insert(s.length(),x);
		}
		friend ostream& operator<<(ostream& out,SeqList<T>& s){
			for(int i=0;i<=s.last;i++){
				out<<s.data[i]<<" ";
			}
			out<<endl;
		}
		void reSize(int newSize){
			if(newSize<=0){
				cerr<<"²ÎÊý´íÎó"<<endl;return;
			}
			if(newSize!=maxSize){
				T* newarray=new T[newSize];
				if(newarray==NULL){
					cerr<<"·ÖÅä´íÎó"<<endl;exit(1);
				}
			int n=last+1;
			T* srcptr=data;
			T* destptr=newarray;
			while(n--) *destptr++=*srcptr++;
			delete[] data;
			data=newarray;
			maxSize=newSize; 
			}
		}
	public:
		SeqList(int sz=defaultSize){
			if(sz>0){
				maxSize=sz;
				last=-1;
				data=new T[99999999];
				if(data==NULL){
					cerr<<"´æ´¢·ÖÅä´íÎó"<<endl;exit(1);
				}
			}
		}
		SeqList(SeqList<T>& L){
			maxSize=L.size();
			last=L.length()-1;
			T value;
			data=new T[maxSize];
			for(int i=1;i<=last+1;i++){
				L.getData(i,value);
				data[i-1]=value;
			}
		}
		~SeqList(){
			delete[] data;
		}
		int size() const {
			return maxSize;
		}
		int length() const{
			return last+1;
		}
		int search(T& x) const{
			for(int i=0;i<=last;i++){
				if(data[i]==x) return i+1;
			}
			return 0;
		}
		bool getData(int i,T& x)  const{
			if(i>0&&i<=last+1) {
				x=data[i-1];
				return true;
			}
			else{
				return false;
			}
		}
		void setData(int i,T& x){
			if(i>0&&i<=last+1) {
				data[i-1]=x;
			}
		}
		bool insert(int i,T& x){
			if(last==maxSize-1) return false;
			if(i<0||i>last+1) return false;
			for(int j=last;j>=i;j--){
				data[j+1]=data[j]; 
			}
			data[i]=x;
			last++;
			return true;
		}
		bool remove(int i,T& x){
			if(last==-1) return false;
			if(i<1||i>last+1) return false;
			x=data[i-1];
			for(int j=i;j<=last;j++){
				data[j-1]=data[j];
			}
			last--;
			return true;
		}
		bool isEmpty(){
			return(last==-1)?true:false;
		}
		bool isFull(){
			return(last==maxSize-1)?true:false;
		}
		SeqList<T> operator=(SeqList<T>& L){
			
		}
		
};

int main(){
	SeqList<int> s;
	int i;
	for(i=0;i<5;i++){
		cin>>s;
	}
	int key=20;
	s.remove(4,key);
	cout<<s;
	return 0;
}


template<class T>

class Heap {
	private:	
		T* dataArray_;
		int size_;         //�ѵĴ�С 
		int endPosi_;     //ָ�����һ�����ݵ�λ�� 
		
	public:
		Heap () 
		{
			size_ = 1024;       
			dataArray_ = new T[size_];
			endPosi_ = 0;      
		}
		
		Heap (int size)
		{
			int i;
			for (i=1; i<size; i*=2)
				;
			size_ = i;
			dataArray_ = new T[size_];
			endPosi_ = 0;
		}
		Heap (T* dataArray, int dataSize)
		{
			int i=dataSize;
//			for (i=1; i<dataSize; i*=2)
//				;
			size_ = i+1;
//			dataArray_ = (T*)realloc(dataArray,size_*sizeof(T));
			dataArray_ = dataArray;
			dataArray_[dataSize] = dataArray_[0];
			endPosi_ = dataSize;
			initdata();
		}
		~Heap()
		{
			delete[] dataArray_;
		}
		void initdata ()
		{
			for (int i=endPosi_/2; i>0; i--)
			{
 				adjust(i);
			}
		}
		
		void adjust(int i) //������ ǰ����i�²�ȫ��������� 
		{            
				T temp = dataArray_[i];  //������i��λ�ã� �ȴ�����I 
				int j = i*2;          //j��i������� 
				while (1)
				{
					if (j > endPosi_)  //���������Ѿ������˷�Χ��������Ӳ����ڣ��Լ���Ҷ�ڵ�
						break;             //������ɿ����˳� 
					if (j+1 <= endPosi_ && dataArray_[j] > dataArray_[j+1]) //������������Ӷ����Ҷ��ӱ������С 
						j += 1;       //j=�Ҷ��� 
					if (temp > dataArray_[j])       	//�����ǰֵ���ڶ����н�С�� 
							dataArray_[j/2] = dataArray_[j];   	//����λ�� 
					else			//����ȽϽ��� 
							break;
					j *= 2;  //	û�����Ļ�������һ��ıȽ� 
				}
				
				dataArray_[j/2] = temp;
		}
		int  push (T &n)
		{
			T * temp;
			if (endPosi_+1 >= size_)
			{
				if (temp = (T*)realloc(dataArray_,size_*2*sizeof(T)))
					dataArray_ = temp;
				else
				{
					cout << "mermory error " << endl;
					return 1;	
				}
			}
			temp = new T;
			*temp = n;
			endPosi_++;
			int i; 
			for (i=endPosi_; i>0; i/=2)
			{
				if (*temp < dataArray_[i/2])
					dataArray_[i] = dataArray_[i/2];
				else
					break;
			}
			if (i)
				dataArray_[i] = *temp;
			else
				dataArray_[1] = *temp;
			delete temp;
			return 0;
		}
		T pop ()
		{
			T n = dataArray_[1];
			dataArray_[1] = dataArray_[endPosi_--];
			adjust(1);
			return n;
		}
		T operator[](const int & index)
		{
			if (index<1 || index>endPosi_)
			{
				cout << "Didn't find the data" << endl;
				return -1;
			}
			else
			{
				return dataArray_[index];
			}
		} 
		friend ostream &operator<<(ostream &ostream,Heap<T> &heap)
		{
			ostream << heap.pop();
			return ostream;
		}
		friend istream &operator<<(istream &istream,Heap<T> &heap)
		{
				T data;
				istream >> data;
				heap.push(data);
				return istream;
		}
};

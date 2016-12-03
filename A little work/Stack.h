template <class T>

class Stack
{
	private:
		T* stack_;
		int top_;
		int size_;
	public:
		Stack(int size = 100)
		{
			stack_ = new T[size];
			size_ = size;	
			top_ = 0;
		}
		void push(T &e)
		{
			if(isFull())
			{
				cout << "error stack is full"<< endl;
				exit(0); 
			}
			else
			{
				stack_[top_++] = e;
			}
		}
		
		T pop()
		{
			T rec = 0;
			if(!isEmpty())
			{
				rec = stack_[--top_];
			}
			return rec;
		}
		
		bool isFull()
		{
			return top_==size_;
		}
		bool isEmpty()
		{
			return top_ == 0;
		}
};


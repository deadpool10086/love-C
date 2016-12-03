template <class T>
class Queue
{
	private:
		T *queue_;
		int front_;
		int rear_;
		int size_;
	public:
		Queue(int size = 100)
		{
			queue_ = new T[size];
			size_ =size;
			front_ = rear_ = 0;
		}
		~Queue()
		{
			delete[] queue_;
		}
		bool isEmpty()
		{
			return front_ == rear_;
		}
		bool isFull()
		{
			return 	(front_+1)%size_ == front_;
		} 
		void enQueue(T &e)
		{
			if(!isFull())
			{
				queue_[rear_] = e;
				rear_ = (rear_+1)%size_; 
			}
			else
			{
				cout << "queue is full";
				exit(0);
			}
		}
		T deQueue()
		{
			T rec = 0;
			if(!isEmpty())
			{
				rec = queue_[front_];
				front_ = (front_+1)%size_;
			}
			return rec;
		} 
};

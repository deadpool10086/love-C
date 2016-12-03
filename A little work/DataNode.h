class DataNode{
	private:
		int weight_;
		char data_; 
		
	public:
		DataNode * leftchild_;
		DataNode * rightchild_;
		DataNode()
		{
			weight_ = 0;
			leftchild_ =  rightchild_ = 0; 
		}
		DataNode(char data)
		{
			weight_ = 0;
			data_ = data;
			leftchild_ =  rightchild_ = 0; 
		}
		DataNode(int weight, DataNode * leftchild, DataNode * rightchild)
		{
			weight_ = weight;
			data_ = 0;
			leftchild_ =  leftchild;
			rightchild_ = rightchild; 
		}
		void setWeight(int weight)
		{
			weight_ = weight;
		}
		void setData(int data)
		{
			data_ = data;
		}
		
		int getWeight()
		{
			return weight_;
		} 
		unsigned char getData()
		{
			return data_;
		}
		bool operator>(DataNode & n1)
		{
			 if (weight_ > n1.getWeight())
			 return true;
			 else
			 return false;
		}
		bool operator<(DataNode & n1)
		{
			 if (weight_ < n1.getWeight()) 
			 return true;
			 else
			 return false;
		}
		bool operator=(int weight)
		{
			setWeight(weight);
		}
		
		DataNode operator++(int)
		{
			weight_++;
			return *this;
		}
}; 

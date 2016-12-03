class HuffCodeBuilder
{
	private:
		unsigned int data_[5];
		int size_;  //ÓÐÐ§Î»”µ 
		
	public:
		HuffCodeBulder()
		{
			size_ = 0;
			for(int i=0 ; i<5; i++)
				data_[i] = 0;
		}
		void add(bool b)
		{
			data_[size_/32] = data_[size_/32]<<1;
			if(b)
				data_[size_/32] = data_[size_/32]| 1;	
			size_++;
		}
		void del()
		{
			size_ --;
			data_[size_/32] = data_[size_/32]>>1;
		}
		void buildCode(HuffCodeNode &e)
		{
			HuffCodeNode *temp = new HuffCodeNode(data_, size_) ;
			e = *temp;
			delete temp;
		}
};

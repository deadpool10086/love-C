class HuffCodeNode
{
	private:
		unsigned int *data_;
		int size_;
	public:
		HuffCodeNode()
		{
			data_ = 0;
			size_ = 0;
		}
		HuffCodeNode(unsigned int *data, int size)
		{
			size_ = size;
			data_ = new unsigned int[size / 32 + 1];
			for(int i=0; i<size/32+1; i++)
			{
				data_[i] = data[i];
			}
			
		}
		void writ(fstream & writ,int & forWrit, int &bitSize)
		{
			while(bitSize + size_ >= 32)
			{
				if(bitSize + size_ >32)
				{
					forWrit = forWrit|(data_[0]>>(bitSize));
					size_ = size_ + bitSize - 32; 
					for(int i=0;i<size_/32;i++)
					{
						data_[i] = data_[i]<<(32-bitSize)|data_[i+1]>>(bitSize);
					}
					bitSize = 32;
				}
				if(bitSize == 32)
				{
					writ.write(reinterpret_cast<char *>(&forWrote), 4);
					bitSize=0;
				}
			}
		}
};

#include <iostream>
#include <ctime>
#include <cstdlib> 
#define MAXNUM 10000000


using namespace std;

class MaxSum
{
	private:
		int * data;   //������ݵ�����
		int max;   //���������Ӷκ�
		int num;  //Ԫ�صĸ���
		void divide(int left, int center, int right)
		{
			if(right - left > 0)
			{
				int sum = 0;
				divide(left, (left + center)/2, center);
				divide(center+1, (center + right)/2, right);
				
				int s1 = 0;
				for(int i = center+1; i<=right; i++)
				{
					sum+=data[i];
					if(sum > s1)
					{
						s1 = sum;
					}
				}

				int s2 = 0;
				sum = 0;
				for(i = center; i>=left; i--)
				{
					sum+=data[i];
					if(sum > s2)
					{
						s2 = sum;
					}
				}
				if(s1 + s2 > max)
					max = s1 + s2;
			}
			else
			{
				if(data[left] > max)
				{
					max = data[left];
				}
			}

		}
	public:
		MaxSum(int n = MAXNUM)
		{
			data = new int[n];
			num = n;
			srand((unsigned)time(NULL));
			for(int i=0; i<n; i++)
			{
				data[i] = rand() - RAND_MAX / 2;
			}
		}
		void violence()   //������
		{
			max = 0;
			int sum;
			for(int i=1; i<= num; i++)
			{
				for(int j=i; j<=num; j++)
				{	
					sum = 0;
					for(int k=0,index = j; k<i; k++)
					{
						sum += data[--index];
					}
					if(sum > max)
					{
						max = sum;
					}
				} 
			}
		}
		
		void dynamic() //��̬�滮
		{
			int sum = 0;
			for(int i=0; i<num; i++)
			{
				sum += data[i];
				if(sum > max)
					max = sum;
				else if(sum < 0)
					sum = 0;
			}
		}

		void divideAndConquer() //���β���
		{
			max = 0;
			divide(0, num/2, num-1);
			if(max < 0)
				max = 0;
		}

		int getMax()
		{
			return max;
		}
};

int main(int argc, char ** argv)
{
	
	MaxSum test;
	clock_t start, stop;
	
	start = clock();
//	test.violence();
	stop = clock();
	cout << (double)(stop - start)/CLK_TCK << " " <<test.getMax() <<endl;

	start = clock();
	test.divideAndConquer();
	stop = clock();
	cout << (double)(stop - start)/CLK_TCK << " " <<test.getMax() <<endl;


	start = clock();
	test.dynamic();
	stop = clock();
	cout << (double)(stop - start)/CLK_TCK << " " <<test.getMax() <<endl;

	
	return 0;
} 

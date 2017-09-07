#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#define ROWNUM 20   //����������� 
#define DATANUM 10   //���������� 
#define TEMPSIZE 10  //��ʱ�洢�����Ϣ 
#define MINSPACE 3   //��СѰ�ҿռ� 

using namespace std;

int temp[TEMPSIZE][2];

class Field{
	private:
		int ** dataField;    //������ͼ�洢 
		int sideNum;     //����Ľ� 
		int min; 
		void findMin(int left, int right)  //Ѱ�� left < x < right 0 < Y < left�е���С��Ծ��� Ĭ�� ��֪��СΪmin  999��ʾ������ 
		{
			int count = 0;
			for(int i = left; i <= right; i++)
			{
				for(int j=0; j<sideNum; j++)
				{
					if(dataField[i][j])
					{
						temp[count][0] = i;
						temp[count][1] = j;
						count++;
						if(count >= TEMPSIZE)
						{
							cout << "count error1" << endl;
							exit(0);
						}
					}
				}
			}
			for(int i=0; i<count - 1; i++)
			{
				for(int j=i+1; j<count; j++)
				{
					int distancePow = (int)pow(temp[i][0]-temp[j][0],2)+pow(temp[i][1]-temp[j][1],2);
					if(distancePow < min)
						min = distancePow;
				}
			}
			return;
		}
		void divideMin(int left, int right)   //������������� 
		{
			
			if(right - left < MINSPACE)
			{
				findMin(left, right);
			}
			else
			{
				int center = (right + left) / 2;
				divideMin(left, center);
				divideMin(center + 1, right);
				if(center - min < left || center + min > right)
					findMin(left ,right);
				else
					findMin(center - min,center + min);
			}
			return;
		}
	public:
		Field(int sum = 0)
		{
			min = 999;
			sideNum = sum;
			dataField = new int*[sum];
			srand((unsigned)time(NULL));
			for(int i=0; i<sum; i++)
			{
				dataField[i] = new int[sum];
				for(int j=0; j<sum; j++)
				 	dataField[i][j] = 0;     //��ʼ��ͼ 
			}
			for(int i=0; i<DATANUM; i++)
			{
				dataField[rand()%sum][rand()%sum] = 1;  //������ɵ� 
			}
		}
		int minDistance()   //Ѱ����̾���Ľӿ� 
		{
			divideMin(0, sideNum - 1);
			return min;
		}
		void show()  //��ӡ��������Ϣ 
		{
			for(int i=0; i<sideNum; i++)
			{
				for(int j=0; j<sideNum; j++)
				 	cout << dataField[i][j] << " ";
				cout << endl;
			}
			return;
		}
		~Field()
		{
			for(int i =0; i<sideNum; i++)
				delete dataField[i];
			delete dataField;
		}
};


int main(int argv, char ** argc)
{
	srand((unsigned)time(NULL));
	Field data = Field(ROWNUM);
	data.show();
	cout << data.minDistance() << endl;
	return 0;
}

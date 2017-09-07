#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#define ROWNUM 20   //方阵的行列数 
#define DATANUM 10   //随机点的数量 
#define TEMPSIZE 10  //临时存储点的信息 
#define MINSPACE 3   //最小寻找空间 

using namespace std;

int temp[TEMPSIZE][2];

class Field{
	private:
		int ** dataField;    //数据用图存储 
		int sideNum;     //方阵的阶 
		int min; 
		void findMin(int left, int right)  //寻找 left < x < right 0 < Y < left中的最小点对距离 默认 已知最小为min  999表示不存在 
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
		void divideMin(int left, int right)   //分治来求解问题 
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
				 	dataField[i][j] = 0;     //初始化图 
			}
			for(int i=0; i<DATANUM; i++)
			{
				dataField[rand()%sum][rand()%sum] = 1;  //随机生成点 
			}
		}
		int minDistance()   //寻找最短距离的接口 
		{
			divideMin(0, sideNum - 1);
			return min;
		}
		void show()  //打印出矩阵信息 
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

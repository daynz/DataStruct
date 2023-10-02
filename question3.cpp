/*****************************************************************//**
 * \brief  7-3 银行业务队列简单模拟
 * 
 * \version 1.0
 * \author 戴延喆
 * \date   October 2,2023
 * \time 
 *********************************************************************/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef int Status;


int main()
{
	//输入
	int n;
	cin >> n;
	vector<int> v1;
	vector<int> v2;
	
	int m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		v1.push_back(m);
	}

#if 0
	time_t start_time = 0, end_time = 0;
	start_time = clock();
#endif // 0

#if 0

	double run_time;
	_LARGE_INTEGER time_start;	//开始时间
	_LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//计时开始
#endif // 1

	//主体及输出
	queue<int> queA;
	queue<int> queB;

	for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		if (*it % 2 == 0)
		{
			queB.push(*it);
		}
		else
		{
			queA.push(*it);
		}
	}

	int i = 0;
	while(i < n)
	{
		if (queA.size() != 0)
		{
			v2.push_back(queA.front());
			queA.pop();
			i++;
			if (queA.size() != 0)
			{
				v2.push_back(queA.front());
				queA.pop();
				i++;
			}
		}
		if (queB.size() != 0)
		{
			v2.push_back(queB.front());
			queB.pop();
			i++;
		}
	}

	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		if (flag) flag = 0;
		else cout << " ";
		cout << v2[i];
	}
	cout << endl;

#if 0
	end_time = clock();
	cout << endl;
	cout << ((double)(end_time - start_time)/CLOCKS_PER_SEC) << endl;
#endif

#if 0
	QueryPerformanceCounter(&time_over);	//计时结束
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << endl;
	cout << run_time << endl;
#endif

	return 0;
}

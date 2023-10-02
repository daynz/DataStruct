/*****************************************************************//**
 * \brief  7-2 一元多项式求导
 * 
 * \version 1.0
 * \author 戴延喆
 * \date   October 2,2023
 * \time 
 *********************************************************************/
#include<iostream>

using namespace std;
typedef int Status;

typedef struct PNode
{
	int coefficient;//系数
	int index;		//指数
	struct PNode* next;
}PNode, * PLinkList;

//输出
Status printPoly(PNode* p)
{
	cout << p->coefficient << " " << p->index;
	return 1;
}

//多项式类
class Polynome
{
public:
	PLinkList PL;
	int length;


	//构造函数
	Polynome()
	{
		this->PL = new PNode;
		if (!this->PL)
			exit(-2);
		this->PL->next = NULL;
		this->length = 0;
	}


	Status InputPoly()
	{
		int m, n;
		PNode* p = new PNode;
		if (!p)exit(-2);
		p = this->PL;

		while (scanf_s("%d %d", &m, &n) != EOF)
		{
			PNode* newNode = new PNode;
			if (!newNode)
				exit(-2);

			newNode->coefficient = m;
			newNode->index = n;

			p->next = newNode;
			newNode->next = NULL;
			p = p->next;

			this->length++;
		}

		

		return 1;
	}

	Status TraversePoly(Status(*visit)(PNode*))
	{
		if (!this->length)
		{
			cout << "0 0" << endl;
			return 0;
		}

		PNode* p = new PNode;
		if (!p)
			exit(-2);
		p = this->PL->next;
		int flag = 1;
		for (int i = 0; i < this->length; i++)
		{
			if (flag)flag = 0;
			else cout << " ";
			visit(p);
			p = p->next;
		}
		return 1;
	}

	Status DerivationPoly()
	{
		PNode* p = new PNode;
		PNode* q = new PNode;
		if (!p||!q)exit(-2);
		p = this->PL;
		q = this->PL->next;

		while (q)
		{
			q->coefficient = q->coefficient * q->index;
			if (q->coefficient == 0)
			{
				p->next = q->next;
				this->length--;
			}
			else
			{
				p = p->next;
				q->index--;
			}
			q = q->next;
		}
		
		return 1;
	}
};

int main()
{
	//输入
	Polynome P;
	P.InputPoly();
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
	
	P.DerivationPoly();
	P.TraversePoly(printPoly);


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
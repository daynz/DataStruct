/*****************************************************************//**
 * \brief  7-1 һԪ����ʽ�ĳ˷���ӷ�����
 * 
 * \version 1.1
 * \author ���ӆ�
 * \date   October 1,2023
 * \time 
 *********************************************************************/
#include<iostream>
#include<Windows.h>

using namespace std;
typedef int Status;

typedef struct PNode
{
	int coefficient;//ϵ��
	int index;		//ָ��
	struct PNode* next;
}PNode, * PLinkList;

//���
Status printPoly(PNode* p)
{
	if (p->coefficient == 0)
		return 0;
	cout << p->coefficient << " " << p->index;
	return 1;
}

//����ʽ��
class Polynome
{
public:
	int length;		//����ʽ��
	PLinkList PL;	//�ڲ�ά��������

	//���캯��
	//����һ��ͷ���
	//length = 0
	explicit Polynome()
	{
		this->PL = (PNode*)malloc(sizeof(PNode));
		if (!PL)		//ȱ�ٻᵼ��C6011��ȡ����NULLָ�������
			exit(-2);

		PL->next = NULL;
		this->length = 0;
	}

	/**
	 * �������ʽ����.
	 * 
	 * \param len ����ʽ��
	 * \return Status
	 */
	Status inputPolynome(int len)
	{
		this->length = len;

		PNode* p = new PNode;
		
		p = this->PL;
		if (len == 0)
		{
			PNode* newNode = new PNode;
			if (!newNode)
				exit(-2);

			newNode->coefficient = 0;
			newNode->index = 0;
			this->PL->next = newNode;
			newNode->next = NULL;
			this->length = 1;
			return 1;
		}

		for (int i = 0; i < len; i++)
		{
			PNode* newNode = new PNode;
			if (!newNode)
				exit(-2);

			cin >> newNode->coefficient;
			cin >> newNode->index;

			p->next = newNode;
			newNode->next = NULL;
			p = p->next;
		}
		return 1;
	}

	/**
	 * ��������.
	 * ���ʱʹ��
	 * 
	 * \param visit
	 * \return 
	 */
	Status PolynomeTraverse(Status(*visit)(PNode*))
	{
		if (!this->PL->next)
		{
			cout << 0 << " " << 0;
			return 1;
		}
		PNode* p = new PNode;
		if (!p)
			exit(-2);
		if (!this->PL->next)
			return 1;

		p =	this->PL->next;
		int flag = 1;

		for (int i = 0; i < this->length; i++)
		{
			if (flag)flag = 0;
			else if (p->coefficient != 0)cout << " ";
			visit(p);
			p = p->next;
		}
		return 1;
	}

	/**
	 * ����ʽ�˷�.
	 * 
	 * \param P
	 * \return 
	 */
	Polynome PolynomeMul(Polynome P)
	{
		PNode* p1 = new PNode;
		PNode* p2 = new PNode;
		PNode* p3 = new PNode;
		
		Polynome newPoly;
		p3 = newPoly.PL;
		for (p1 = this->PL->next; p1 != NULL; p1 = p1->next)
		{
			for (p2 = P.PL->next; p2 != NULL; p2 = p2->next)
			{
				PNode* newNode = new PNode;
				
				newNode->coefficient = p1->coefficient * p2->coefficient;
				newNode->index = p1->index + p2->index;

				p3->next = newNode;
				newNode->next = NULL;
				p3 = p3->next;
			}
		}
		newPoly.length = this->length * P.length;
		return newPoly;
	}

	/**
	 * ����ʽ�ӷ�.
	 * 
	 * \param P
	 * \return 
	 */
	Polynome PolynomeAdd(Polynome P)
	{
		PNode* p1 = new PNode;
		PNode* p2 = new PNode;
		PNode* p3 = new PNode;

		Polynome newPoly;
		newPoly.length = this->length + P.length;

		newPoly.PL->next = this->PL->next;
		for (p1 = this->PL->next; p1->next != NULL; p1 = p1->next);

		p1->next = P.PL->next;

		if (!newPoly.PL->next->next)
		{
			return newPoly;
		}

		for (p2 = newPoly.PL->next; p2 != NULL; p2 = p2->next)
		{
			if (p2->coefficient == 0)
			{
				continue;
			}
			for (p3 = p2->next; p3 != NULL; p3 = p3->next)
			{
				if (p3->coefficient == 0)
				{
					continue;
				}
				if (p2->index == p3->index)		//����ָ����� ��ϵ����� ������p2�Ľ���� p3��ϵ����ֵΪ0
				{
					p2->coefficient += p3->coefficient;
					p3->coefficient = 0;
				}
			}
		}
		return newPoly;
	}

	/**
	 * ������ʽ��Ϊָ���ݽ���ʽ���.
	 * 
	 * \return 
	 */
	void integration()
	{
		PNode* p1 = new PNode;
		PNode* p2 = new PNode;
		PNode* p3 = new PNode;
		PNode* p4 = new PNode;

		if (!this->PL)
			exit(-2);
		p3 = this->PL;
		p4 = this->PL->next;


		for (;p3 && p4; p4 = p4->next)
		{
			if (p4->coefficient == 0)
			{
				p3->next = p4->next;
				this->length--;
			}
			else
			{
				p3 = p3->next;
			}
		}

		//��������
		for (p1 = this->PL->next; p1 != NULL; p1 = p1->next)
		{
			
			for (p2 = p1->next; p2 != NULL; p2 = p2->next)
			{
				
				if (p1->index < p2->index)
				{
					int temp1 = p1->index;
					p1->index = p2->index;
					p2->index = temp1;
					int temp2 = p1->coefficient;
					p1->coefficient = p2->coefficient;
					p2->coefficient = temp2;
				}
				if (p1->index == p2->index)
				{
					p1->coefficient += p2->coefficient;
					p2->coefficient = 0;
				}
			}
		}
	}

};

int main()
{

	Polynome p1;
	Polynome p2;
	Polynome p3;
	Polynome p4;

	int m, n;
	cin >> m;
	p1.inputPolynome(m);
	cin >> n;
	p2.inputPolynome(n);

#if 0
	time_t start_time = 0, end_time = 0;
	start_time = clock();
#endif // 0

#if 1

	double run_time;
	_LARGE_INTEGER time_start;	//��ʼʱ��
	_LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//��ʱ��ʼ
#endif // 1

	p3 = p1.PolynomeMul(p2);
	p3.integration();

	p3.PolynomeTraverse(printPoly);
	cout << endl;
	p4 = p1.PolynomeAdd(p2);
	p4.integration();

	p4.PolynomeTraverse(printPoly);

#if 0
	end_time = clock();
	cout << endl;
	cout << ((double)(end_time - start_time)/CLOCKS_PER_SEC) << endl;
#endif

#if 1
	QueryPerformanceCounter(&time_over);	//��ʱ����
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	cout << endl;
	cout << run_time << endl;
#endif


	return 0;
}
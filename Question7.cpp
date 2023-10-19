//该版本使用的是普通的队列,超时
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//消息类
class Wmsg
{
public:
	//命令
	string cmd;
	//消息内容
	string msgString;
	//优先级
	int pri;

	//构造函数
	Wmsg():pri(0)
	{}

	//输入函数
	void inputMsg()
	{
		cin >> this->cmd;
		if (this->cmd == "PUT")
		{		
			cin >> this->msgString;
			cin >> this->pri;
		}
	}
};

//重写仿函数
struct compareF
{
	bool operator()(Wmsg w1, Wmsg w2)
	{
		return w1.pri > w2.pri;
	}
};

class WindowsQueue
{
public:
	//内部维护的队列
	queue<Wmsg>winQueue;
	//优先队列
	priority_queue<Wmsg,vector<Wmsg>,compareF> winPriQueue;

	//队列的最小优先级数
	int minPri;

	WindowsQueue():minPri(99999)
	{}

	//出队并把结果放入qf
	void deWinQueue(Wmsg& qf)
	{
		//qf = this->winQueue.front();
		//this->winQueue.pop();
		qf = this->winPriQueue.top();
		this->winPriQueue.pop();
	}
};

int main()
{
	ios::sync_with_stdio(false);
	WindowsQueue wq;
	int n;
	cin >> n;
	//主循环
	while (n--)
	{
		//封装消息
		Wmsg wm;
		wm.inputMsg();

		//判断消息类型
		//若消息类型为PUT,将消息入队,并且更新队列最小优先级数
		if (wm.cmd == "PUT")
		{
			//wq.winQueue.push(wm);
			wq.winPriQueue.push(wm);
			if (wm.pri < wq.minPri)
			{
				wq.minPri = wm.pri;
			}
		}
		else
		{
			//若消息类型为GET,取出优先级最小的消息
			//int length = wq.winQueue.size();
			int length = wq.winPriQueue.size();
			
			if (!length)
			{
				cout << "EMPTY QUEUE!" << endl;
			}
			else
			{
				//轮询,找到优先级最小的消息
				Wmsg wmsg;
				while (length--)
				{
					wq.deWinQueue(wmsg);

					if (wmsg.pri == wq.minPri)
					{
						cout << wmsg.msgString << endl;
						wq.minPri = 9999;

						//轮询,找到队列中优先级最小的消息,将消息保存到最小优先级数中
						//length = wq.winQueue.size();
						length = wq.winPriQueue.size();
						while (length--)
						{
							wq.deWinQueue(wmsg);

							if (wmsg.pri < wq.minPri)
							{
								wq.minPri = wmsg.pri;
							}
							//wq.winQueue.push(wmsg);
							wq.winPriQueue.push(wmsg);

						}
						break;
					}
					else
					{
						//wq.winQueue.push(wmsg);
						wq.winPriQueue.push(wmsg);
					}
				}
			}
		}

	}

	return 0;
}

//所有以head作为形参的函数，中心思想都是遍历的算法
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>

using namespace std;

typedef struct  worker
{
	char id[12];
	char name[10];
	char sex[6];
	int age;
	char edu[16];
	int salary;
	char phone[14];
	char address[32];
	struct worker *next;
}LNode, *LinkList;

void mainMenu()
{
    cout<<"\n---------------------------------------------------------------------"<<endl;
	cout << "\n\n\t欢迎使用公司员工管理系统Beta.\t" << endl;
	cout << "\n\t请按对应的数字选择功能\t" << endl;
	cout << "\n\t0.立刻存档\t" << endl;
	cout << "\n\t1.输入职员信息.\t" << endl;
	cout << "\n\t2.删除职员信息\t" << endl;
	cout << "\n\t3.显示所有职员\t" << endl;
	cout << "\n\t4.按工资范围查询职员\t" << endl;
	cout << "\n\t5.按工号精确查询职员\t" << endl;
	cout << "\n\t6.修改职员信息\t" << endl;
	cout << "\n\t7.按工资升序排列所有职员\t" << endl;
	cout << "\n\t提示：请在操作之后使用存档功能，以免数据丢失！\t" << endl;
	cout << "\n\t河南工业大学 计科F1701班 高云飞" << endl;
	cout<<"\n---------------------------------------------------------------------"<<endl;

}

void Wrong()
{
	exit(0);
	cout << "\n出现了一个错误。" << endl;
}

void Done()
{
	cout << "\n完成！" << endl;
}

void Add(LinkList head)
{
	int i, n;
	LNode *p, *p0;//定义指向结构体的指针
	p0 = head;
	cout << "\n请输入需要添加的员工数目：";
	cin >> n;

	while (p0->next != NULL)
		p0 = p0->next;//走向最后一个节点，准备加人

	for (i = 1; i <= n; i++)
	{
		if ((p = new LNode) == NULL)//为地址是LinkList的类型为LNode链表准备内存
		{
			void Wrong();
			exit(-1);
		}

		cout << "\n该员工的工号是(决定后不可修改)：";
		cin >> p->id;

		cout << "\n该员工的姓名是：";
		cin >> p->name;

		cout << "\n该员工的性别是(男/女):";
		cin >> p->sex;

		cout << "\n该员工的年龄是：";
		cin >> p->age;

		if((p->age)>65)
        {
            cout<<"\n不正确的年龄！\n";
            cout << "\n该员工的年龄是：";
            cin >> p->age;
        }

		cout << "\n该员工的学历是(中专/大专/本科/硕士/博士/其他)：";
		cin >> p->edu;

		cout << "\n该员工的月薪是：";
		cin >> p->salary;

		cout << "\n该员工的电话号码是：";
		cin >> p->phone;

		cout << "\n该员工的住址是：";
		cin >> p->address;

		cout << endl;
		p->next = NULL;//表明这是链表的尾部结点
		p0->next = p;//将新建的结点加入链表尾部中
		p0 = p;
		Done();
	}
}

void showAll(LinkList head)
{
	LNode *p;
	p = head->next;
	if (!p)//报错报错
	{
		Wrong();
		cout << "没有员工信息，请先录入！";
	}
	cout << "\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 " << endl;
	while (p)
	{
		cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
		p = p->next;
	}
	Done();
}

void sortBySalary(LinkList head)
{
	LNode *p0, *p1;//这两个指针是从左到右的关系，随着指针的运动，p1是最先指向最后一个节点的
	p0 = head->next;
	p1 = p0->next;
	if (!p0)//如果p是0就走这个分支报错了
	{
		Wrong();
		cout << "没有员工信息，请先录入!";
		exit(0);
	}

	int count = 0;//计数装置，activated！
	int i, j;

	char id[12];//临时数据保存点，activated！
	char name[10];
	char sex[6];
	int age;
	char edu[16];
	int salary;
	char phone[14];
	char address[32];

	cout << "即将按工资升序排列";
	//冒泡排序准备中...
	while (p0)//记录节点总数
	{
		count++;
		p0 = p0->next;
	}

	for (i = 1; i <= count - 1; i++)//冒泡排序的运算量是项目总数-1
	{
		for (j = 1; j <= count - 1 - i; j++)//每从头到尾过一遍，大数就沉到最底部，比较次数就减少1次
		{
			p0 = head->next;//回到表头
			p1 = p0->next;

			while (p1)//p1与p0比大小
			{
				if (p0->salary > p1->salary)//p0比p1大，不行，升序排序要求小数在前
				{
					strcpy(id, p0->id);//保存所有p0的数据
					strcpy(name, p0->name);
					strcpy(sex, p0->sex);
					age = p0->age;
					strcpy(edu, p0->edu);
					salary = p0->salary;
					strcpy(phone, p0->phone);
					strcpy(address, p0->address);

					strcpy(p0->id, p1->id);//p1的数据给p0
					strcpy(p0->name, p1->name);
					strcpy(p0->sex, p1->sex);
					p0->age = p1->age;
					strcpy(p0->edu, p1->edu);
					p0->salary = p1->salary;
					strcpy(p0->phone, p1->phone);
					strcpy(p0->address, p1->address);

					strcpy(p1->id, id);//p0的数据给p1
					strcpy(p1->name, name);
					strcpy(p1->sex, sex);
					p1->age = age;
					strcpy(p1->edu, edu);
					p1->salary = salary;
					strcpy(p1->phone, phone);
					strcpy(p1->address, address);
				}
				p0 = p0->next;
				p1 = p1->next;
			}
		}
	}
	cout << "\n排序完了：";
	showAll(head);
	Done();
}

void findBySalary(LinkList head)
{
	int maxsalary, minsalary;
	cout << "请输入查找工资的范围：" << endl;
	cout << "查找工资的最小值：";
	cin >> minsalary;
	cout << "查找工资的最大值：";
	cin >> maxsalary;

	int count = 0;
	cout << "\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 \n";

	LNode *p;
	p = head->next;

	while (p)
	{
		if ((p->salary <= maxsalary) && (p->salary >= minsalary))
		{
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
			count++;
		}
		p = p->next;
	}

	if (count == 0)
		cout << "没有符合条件的员工" << endl;
	Done();
}

void findById(LinkList head)
{
	char id[12];
	cout << "请输入查找职员的工号：" << endl;
	cin >> id;

	int count = 0;
	cout << "\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 \n";

	LNode *p;
	p = head->next;

	while (p)
	{
		if (strcmp(id, p->id) == 0)
		{
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
			count++;
		}
		p = p->next;
	}

	if (count == 0)
		cout << "没有符合条件的员工" << endl;
	Done();
}

void Rewrite(LinkList head)
{
	cout << "\n请输入你想修改的员工的编号：";
	char id[12];
	cin >> id;

	LNode *p;
	p = head->next;

	int count = 0;

	while (p)
	{
		if (strcmp(p->id, id) == 0)
		{
			count++;
			cout << "\n已经查找到:" << endl;
			cout << "\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 " << endl;
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
			cout << "\n请在下面输入修改后的新数据：" << endl;

			cout << "\n修改后该职工的姓名是：";
			cin >> p->name;

			cout << "\n修改后该职工的性别是(男/女):";
			cin >> p->sex;

			cout << "\n修改后该职工的年龄是：";
			cin >> p->age;
            if((p->age)>65)
            {
            cout<<"\n不正确的年龄！\n";
            cout << "\n该员工的年龄是：";
            cin >> p->age;
            }

			cout << "\n修改后该职工的学历是(中专/大专/本科/硕士/博士/其他)：";
			cin >> p->edu;

			cout << "\n修改后该职工的月工资是：";
			cin >> p->salary;

			cout << "\n修改后该职工的电话号码是：";
			cin >> p->phone;

			cout << "\n修改后该职工的住址是：";
			cin >> p->address;
		}
		p = p->next;
	}
	if (count == 0)
	{
		Wrong();
		cout << "查无此人，请检查后再试。";
	}
	Done();
}

void Del(LinkList head)
{
	cout << "\n请输入你想删除的职工的编号：";
	char id[12];
	cin >> id;

	LNode *p, *p0;//p0在p前一位
	p = head->next;
	p0 = head;

	int count = 0;
	char choose;
	while (p)
	{
		if (strcmp(p->id, id) == 0)
		{
			count++;
			cout << "\n已经查找到:" << endl;
			cout << "\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 " << endl;
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
			cout << "\n要删除吗?（Y/N）";
			cin >> choose;

			if (choose == 'y' || choose == 'Y')
			{
				p0->next = p->next;
				delete p;
				break;
			}
			else
			{
				cout << "\n正在退出..." << endl;
				exit(0);
			}
		}
		p = p->next;
		p0 = p0->next;
	}


	if (count == 0)
	{
		Wrong();
		cout << "查无此人，请检查后再试。";
	}
	Done();
}

void Save(LinkList L)
{
	FILE *fp;
	fp = fopen("worklist.txt", "wb");//写文件

	LNode *p;//准备一个指针指向原结构体，准备靠它的移动来写数据
	p = L->next;//这个指针已经指向了第一个节点的数据域

	if (fp == NULL)//找不着打不开，报错
	{
		Wrong();
		exit(-1);
	}

	while (p)
	{
		if (fwrite(p, sizeof(LNode), 1, fp) == 1)//将第一个记录结点值写入文件
		{
			p = p->next; //指向下一个数据域，接着写
		}
		else//报错报错
		{
			Wrong();
			exit(-1);
		}
	}
	fclose(fp);
	cout << "\n正在存档...";
	Done();
}

int main(void)
{
	FILE *fp;
	LNode *p, *p0;//p0在p靠前一个节点
	LinkList L;//这是一个链表
	L = new LNode;

	if (!L)//检查报错
	{
		void Wrong();
		exit(-1);
	}
	p0 = L;//p0是指向倒数第二节点的指针
	L->next = NULL;//就像这样
	char choose;
	fp = fopen("worklist.txt", "rb");//读文件

	if (fp == NULL)
	{
		cout << "\n请注意：存储员工信息的本地文件不存在，是否创建？(Y/N)" << endl;
		cin >> choose;
		if (choose == 'y' || choose == 'Y')
		{
			fp = fopen("worklist.txt", "ab+");
			cout << "本地文件已创建！" << endl;
		}
		else
		{
			cout << "本地文件不存在，无法读写员工信息!" << endl;
			exit(0);
		}

	}
	cout << "本地文件已找到，读取完毕";

	while (!feof(fp)) //循环读取文件
	{
		p = new LNode;
		if (!p)//检查报错
		{
			void Wrong();
			exit(0);
		}

		if (fread(p, sizeof(LNode), 1, fp)) //读文件的已有内容
		{
			p->next = NULL;//目前最后一个节点，往后没有数据
			p0->next = p;
			p0 = p; //将该结点挂入链表中,
		}
	}
	fclose(fp);
	void Done();

	while (1)
	{
		mainMenu();
		cout << "\n选择的编号是：";
		int select;
		cin >> select;
		switch (select)
		{
		case 0:Save(L);
			break;
		case 1:Add(L);
			break;
		case 2:Del(L);
			break;
		case 3:showAll(L);
			break;
		case 4:findBySalary(L);
			break;
		case 5:findById(L);
			break;
		case 6:Rewrite(L);
			break;
		case 7:sortBySalary(L);
			break;
		default:
			Wrong();
			break;
		}
	}
}

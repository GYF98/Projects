//所有以head作为形参的函数，中心思想都是遍历的算法
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	struct Node *next;
}LNode, *LinkList;

void mainmenu()
{
	printf("\n\n\t欢迎使用职工信息管理系统Beta.\t\n");
	printf("\n\t请按对应的数字选择功能\t\n");
	printf("\t0.立刻存档\t\n");
	printf("\t1.输入职工信息.\t\n");
	printf("\t2.浏览全部职工信息\t\n");
	printf("\t3.按工资升序排列所有职工\t\n");
	printf("\t4.按工资查询职工\t\n");
	printf("\t5.修改职工信息\t\n");
	printf("\t6.删除职工信息\t\n");
	printf("\t温馨提示：请在操作之后使用存档功能，以免数据丢失！\t\n");
	printf("\n\t河南工业大学 计科1707班 高云飞\n");

}

void wrong()
{
	system("cls");
	printf("\n出现了一个错误。\n");
}

void done()
{
	printf("\n完成！\n");
}

void add(LinkList head)
{
	int i, n;
	LNode *p, *p0;//定义指向结构体的指针
	p0 = head;
	printf("\n您想添加多少职工呢：");
	scanf("%d", &n);

	while (p0->next != NULL)
		p0 = p0->next;//走向最后一个节点，准备加人

	for (i = 1; i <= n; i++)
	{
		if ((p = (LinkList)malloc(sizeof(LNode))) == NULL)//为地址是LinkList的类型为LNode链表准备内存
		{
			void wrong();
			exit(-1);
		}
		printf("\n");
		printf("该职工的工号是(决定后不可修改)：");
		scanf("%s", p->id);

		printf("\n");
		printf("该职工的姓名是：");
		scanf("%s", p->name);

		printf("\n");
		printf("该职工的性别是(男/女):");
		scanf("%s", p->sex);

		printf("\n");
		printf("该职工的年龄是：");
		scanf("%d", &p->age);

		printf("\n");
		printf("该职工的学历是(中专/大专/本科/硕士/博士/其他)：");
		scanf("%s", p->edu);

		printf("\n");
		printf("该职工的月工资是：");
		scanf("%d", &p->salary);

		printf("\n");
		printf("该职工的电话号码是：");
		scanf("%s", p->phone);

		printf("\n");
		printf("该职工的住址是：");
		scanf("%s", p->address);

		printf("\n");
		p->next = NULL;//表明这是链表的尾部结点
		p0->next = p;//将新建的结点加入链表尾部中
		p0 = p;
		done();
	}
}

void showall(LinkList head)
{
	LNode *p;
	p = head->next;
	if (!p)//报错报错
	{
		wrong();
		printf("没有职工信息，请先录入！");
	}
	printf("\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 \n");
	while (p)
	{
		printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
		p = p->next;
	}
	done();
}

void sortbysalary(LinkList head)
{
	LNode *p0, *p1;//这两个指针是从左到右的关系，随着指针的运动，p1是最先指向最后一个节点的
	p0 = head->next;
	p1 = p0->next;
	if (!p0)//如果p是0就走这个分支报错了
	{
		wrong();
		printf("没有员工信息，请先录入QAQ");
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

	printf("即将按工资升序排列");
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
	printf("\n排序完了：");
	showall(head);
	done();
}

void findbysalary(LinkList head)
{
	int salary;
	printf("您想查找工资为多少的员工：");
	scanf("%d", &salary);

	int count = 0;
	printf("\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 \n");

	LNode *p;
	p = head->next;

	while (p)
	{
		if (p->salary == salary)
		{
			printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
			count++;
		}
		p = p->next;
	}

	if (count == 0)
		printf("没有符合条件的员工\n");
	done();
}

void rewrite(LinkList head)
{
	printf("\n请输入你想修改的职工的编号：");
	char id[12];
	scanf("%s", id);

	LNode *p;
	p = head->next;

	int count = 0;

	while (p)
	{
		if (strcmp(p->id, id) == 0)
		{
			count++;
			printf("\n已经查找到:\n");
			printf("\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 \n");
			printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
			printf("\n请在下面输入修改后的新数据：\n");

			printf("修改后该职工的姓名是：");
			scanf("%s", p->name);

			printf("\n");
			printf("修改后该职工的性别是(男/女):");
			scanf("%s", p->sex);

			printf("\n");
			printf("修改后该职工的年龄是：");
			scanf("%d", &p->age);

			printf("\n");
			printf("修改后该职工的学历是(中专/大专/本科/硕士/博士/其他)：");
			scanf("%s", p->edu);

			printf("\n");
			printf("修改后该职工的月工资是：");
			scanf("%d", &p->salary);

			printf("\n");
			printf("修改后该职工的电话号码是：");
			scanf("%s", p->phone);

			printf("\n");
			printf("修改后该职工的住址是：");
			scanf("%s", p->address);
		}
		p = p->next;
	}
	if (count == 0)
	{
		wrong();
		printf("查无此人，请检查后再试。");
	}
	done();
}

void del(LinkList head)
{
	printf("\n请输入你想删除的职工的编号：");
	char id[12];
	scanf("%s", id);

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
			printf("\n已经查找到:\n");
			printf("\n工号\t姓名\t性别\t年龄\t学历\t工资\t电话\t\t住址 \n");
			printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
			printf("\n要删除吗?（Y/N）");
			scanf("%s", &choose);

			if (choose == 'y' || choose == 'Y')
			{
				p0->next = p->next;
				free(p);
				break;
			}
			else
			{
				printf("\n正在退出...\n");
				exit(0);
			}
		}
		p = p->next;
		p0 = p0->next;
	}


	if (count == 0)
	{
		wrong();
		printf("查无此人，请检查后再试。");
	}
	done();
}

void save(LinkList L)
{
	FILE *fp;
	fp = fopen("worklist.txt", "wb");//写文件

	LNode *p;//准备一个倒霉蛋指针指向原结构体，准备靠它的移动来写数据
	p = L->next;//很显然，这个倒霉蛋指针已经指向了第一个节点的数据域

	if (fp == NULL)//找不着打不开，报错
	{
		wrong();
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
			wrong();
			exit(-1);
		}
	}
	fclose(fp);
	printf("\n正在存档...");
	done();
}

int main(void)
{
	FILE *fp;
	LNode *p, *p0;//p0在p靠前一个节点
	LinkList L;//这是一个链表
	L = (LinkList)malloc(sizeof(LNode));

	if (!L)//检查报错
	{
		void wrong();
		exit(-1);
	}
	p0 = L;//p0是指向倒数第二节点的指针
	L->next = NULL;//就像这样
	char choose;
	fp = fopen("worklist.txt", "rb");//读文件

	if (fp == NULL)
	{
		printf("\n请注意：存储职工信息的本地文件不存在，是否创建？(Y/N)\n");
		scanf("%c", &choose);
		if (choose == 'y' || choose == 'Y')
		{
			fp = fopen("worklist.txt", "ab+");
			printf("本地文件已创建！\n");
		}
		else
		{
			printf("本地文件不存在，无法读写职工信息!\n");
			exit(0);
		}

	}
	printf("本地文件已找到，读取完毕");

	while (!feof(fp)) //循环读取文件
	{
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)//检查报错
		{
			void wrong();
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
	void done();

	while (1)
	{
		mainmenu();
		printf("\n选择的编号是：");
		int select;
		scanf("%d", &select);
		switch (select)
		{
		case 0:save(L);
			break;
		case 1:add(L);
			break;
		case 2:showall(L);
			break;
		case 3:sortbysalary(L);
			break;
		case 4:findbysalary(L);
			break;
		case 5:rewrite(L);
			break;
		case 6:del(L);
			break;
		default:
			wrong();
			break;
		}
	}
}

//������head��Ϊ�βεĺ���������˼�붼�Ǳ������㷨
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
	cout << "\n\n\t��ӭʹ�ù�˾Ա������ϵͳBeta.\t" << endl;
	cout << "\n\t�밴��Ӧ������ѡ����\t" << endl;
	cout << "\n\t0.���̴浵\t" << endl;
	cout << "\n\t1.����ְԱ��Ϣ.\t" << endl;
	cout << "\n\t2.ɾ��ְԱ��Ϣ\t" << endl;
	cout << "\n\t3.��ʾ����ְԱ\t" << endl;
	cout << "\n\t4.�����ʷ�Χ��ѯְԱ\t" << endl;
	cout << "\n\t5.�����ž�ȷ��ѯְԱ\t" << endl;
	cout << "\n\t6.�޸�ְԱ��Ϣ\t" << endl;
	cout << "\n\t7.������������������ְԱ\t" << endl;
	cout << "\n\t��ʾ�����ڲ���֮��ʹ�ô浵���ܣ��������ݶ�ʧ��\t" << endl;
	cout << "\n\t���Ϲ�ҵ��ѧ �ƿ�F1701�� ���Ʒ�" << endl;
	cout<<"\n---------------------------------------------------------------------"<<endl;

}

void Wrong()
{
	exit(0);
	cout << "\n������һ������" << endl;
}

void Done()
{
	cout << "\n��ɣ�" << endl;
}

void Add(LinkList head)
{
	int i, n;
	LNode *p, *p0;//����ָ��ṹ���ָ��
	p0 = head;
	cout << "\n��������Ҫ��ӵ�Ա����Ŀ��";
	cin >> n;

	while (p0->next != NULL)
		p0 = p0->next;//�������һ���ڵ㣬׼������

	for (i = 1; i <= n; i++)
	{
		if ((p = new LNode) == NULL)//Ϊ��ַ��LinkList������ΪLNode����׼���ڴ�
		{
			void Wrong();
			exit(-1);
		}

		cout << "\n��Ա���Ĺ�����(�����󲻿��޸�)��";
		cin >> p->id;

		cout << "\n��Ա���������ǣ�";
		cin >> p->name;

		cout << "\n��Ա�����Ա���(��/Ů):";
		cin >> p->sex;

		cout << "\n��Ա���������ǣ�";
		cin >> p->age;

		if((p->age)>65)
        {
            cout<<"\n����ȷ�����䣡\n";
            cout << "\n��Ա���������ǣ�";
            cin >> p->age;
        }

		cout << "\n��Ա����ѧ����(��ר/��ר/����/˶ʿ/��ʿ/����)��";
		cin >> p->edu;

		cout << "\n��Ա������н�ǣ�";
		cin >> p->salary;

		cout << "\n��Ա���ĵ绰�����ǣ�";
		cin >> p->phone;

		cout << "\n��Ա����סַ�ǣ�";
		cin >> p->address;

		cout << endl;
		p->next = NULL;//�������������β�����
		p0->next = p;//���½��Ľ���������β����
		p0 = p;
		Done();
	}
}

void showAll(LinkList head)
{
	LNode *p;
	p = head->next;
	if (!p)//������
	{
		Wrong();
		cout << "û��Ա����Ϣ������¼�룡";
	}
	cout << "\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ " << endl;
	while (p)
	{
		cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
		p = p->next;
	}
	Done();
}

void sortBySalary(LinkList head)
{
	LNode *p0, *p1;//������ָ���Ǵ����ҵĹ�ϵ������ָ����˶���p1������ָ�����һ���ڵ��
	p0 = head->next;
	p1 = p0->next;
	if (!p0)//���p��0���������֧������
	{
		Wrong();
		cout << "û��Ա����Ϣ������¼��!";
		exit(0);
	}

	int count = 0;//����װ�ã�activated��
	int i, j;

	char id[12];//��ʱ���ݱ���㣬activated��
	char name[10];
	char sex[6];
	int age;
	char edu[16];
	int salary;
	char phone[14];
	char address[32];

	cout << "������������������";
	//ð������׼����...
	while (p0)//��¼�ڵ�����
	{
		count++;
		p0 = p0->next;
	}

	for (i = 1; i <= count - 1; i++)//ð�����������������Ŀ����-1
	{
		for (j = 1; j <= count - 1 - i; j++)//ÿ��ͷ��β��һ�飬�����ͳ�����ײ����Ƚϴ����ͼ���1��
		{
			p0 = head->next;//�ص���ͷ
			p1 = p0->next;

			while (p1)//p1��p0�ȴ�С
			{
				if (p0->salary > p1->salary)//p0��p1�󣬲��У���������Ҫ��С����ǰ
				{
					strcpy(id, p0->id);//��������p0������
					strcpy(name, p0->name);
					strcpy(sex, p0->sex);
					age = p0->age;
					strcpy(edu, p0->edu);
					salary = p0->salary;
					strcpy(phone, p0->phone);
					strcpy(address, p0->address);

					strcpy(p0->id, p1->id);//p1�����ݸ�p0
					strcpy(p0->name, p1->name);
					strcpy(p0->sex, p1->sex);
					p0->age = p1->age;
					strcpy(p0->edu, p1->edu);
					p0->salary = p1->salary;
					strcpy(p0->phone, p1->phone);
					strcpy(p0->address, p1->address);

					strcpy(p1->id, id);//p0�����ݸ�p1
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
	cout << "\n�������ˣ�";
	showAll(head);
	Done();
}

void findBySalary(LinkList head)
{
	int maxsalary, minsalary;
	cout << "��������ҹ��ʵķ�Χ��" << endl;
	cout << "���ҹ��ʵ���Сֵ��";
	cin >> minsalary;
	cout << "���ҹ��ʵ����ֵ��";
	cin >> maxsalary;

	int count = 0;
	cout << "\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ \n";

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
		cout << "û�з���������Ա��" << endl;
	Done();
}

void findById(LinkList head)
{
	char id[12];
	cout << "���������ְԱ�Ĺ��ţ�" << endl;
	cin >> id;

	int count = 0;
	cout << "\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ \n";

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
		cout << "û�з���������Ա��" << endl;
	Done();
}

void Rewrite(LinkList head)
{
	cout << "\n�����������޸ĵ�Ա���ı�ţ�";
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
			cout << "\n�Ѿ����ҵ�:" << endl;
			cout << "\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ " << endl;
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
			cout << "\n�������������޸ĺ�������ݣ�" << endl;

			cout << "\n�޸ĺ��ְ���������ǣ�";
			cin >> p->name;

			cout << "\n�޸ĺ��ְ�����Ա���(��/Ů):";
			cin >> p->sex;

			cout << "\n�޸ĺ��ְ���������ǣ�";
			cin >> p->age;
            if((p->age)>65)
            {
            cout<<"\n����ȷ�����䣡\n";
            cout << "\n��Ա���������ǣ�";
            cin >> p->age;
            }

			cout << "\n�޸ĺ��ְ����ѧ����(��ר/��ר/����/˶ʿ/��ʿ/����)��";
			cin >> p->edu;

			cout << "\n�޸ĺ��ְ�����¹����ǣ�";
			cin >> p->salary;

			cout << "\n�޸ĺ��ְ���ĵ绰�����ǣ�";
			cin >> p->phone;

			cout << "\n�޸ĺ��ְ����סַ�ǣ�";
			cin >> p->address;
		}
		p = p->next;
	}
	if (count == 0)
	{
		Wrong();
		cout << "���޴��ˣ���������ԡ�";
	}
	Done();
}

void Del(LinkList head)
{
	cout << "\n����������ɾ����ְ���ı�ţ�";
	char id[12];
	cin >> id;

	LNode *p, *p0;//p0��pǰһλ
	p = head->next;
	p0 = head;

	int count = 0;
	char choose;
	while (p)
	{
		if (strcmp(p->id, id) == 0)
		{
			count++;
			cout << "\n�Ѿ����ҵ�:" << endl;
			cout << "\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ " << endl;
			cout << p->id << "\t" << p->name << "\t" << p->sex << "\t" << p->age << "\t" << p->edu << "\t" << p->salary << "\t" << p->phone << "\t" << p->address << endl;
			cout << "\nҪɾ����?��Y/N��";
			cin >> choose;

			if (choose == 'y' || choose == 'Y')
			{
				p0->next = p->next;
				delete p;
				break;
			}
			else
			{
				cout << "\n�����˳�..." << endl;
				exit(0);
			}
		}
		p = p->next;
		p0 = p0->next;
	}


	if (count == 0)
	{
		Wrong();
		cout << "���޴��ˣ���������ԡ�";
	}
	Done();
}

void Save(LinkList L)
{
	FILE *fp;
	fp = fopen("worklist.txt", "wb");//д�ļ�

	LNode *p;//׼��һ��ָ��ָ��ԭ�ṹ�壬׼���������ƶ���д����
	p = L->next;//���ָ���Ѿ�ָ���˵�һ���ڵ��������

	if (fp == NULL)//�Ҳ��Ŵ򲻿�������
	{
		Wrong();
		exit(-1);
	}

	while (p)
	{
		if (fwrite(p, sizeof(LNode), 1, fp) == 1)//����һ����¼���ֵд���ļ�
		{
			p = p->next; //ָ����һ�������򣬽���д
		}
		else//������
		{
			Wrong();
			exit(-1);
		}
	}
	fclose(fp);
	cout << "\n���ڴ浵...";
	Done();
}

int main(void)
{
	FILE *fp;
	LNode *p, *p0;//p0��p��ǰһ���ڵ�
	LinkList L;//����һ������
	L = new LNode;

	if (!L)//��鱨��
	{
		void Wrong();
		exit(-1);
	}
	p0 = L;//p0��ָ�����ڶ��ڵ��ָ��
	L->next = NULL;//��������
	char choose;
	fp = fopen("worklist.txt", "rb");//���ļ�

	if (fp == NULL)
	{
		cout << "\n��ע�⣺�洢Ա����Ϣ�ı����ļ������ڣ��Ƿ񴴽���(Y/N)" << endl;
		cin >> choose;
		if (choose == 'y' || choose == 'Y')
		{
			fp = fopen("worklist.txt", "ab+");
			cout << "�����ļ��Ѵ�����" << endl;
		}
		else
		{
			cout << "�����ļ������ڣ��޷���дԱ����Ϣ!" << endl;
			exit(0);
		}

	}
	cout << "�����ļ����ҵ�����ȡ���";

	while (!feof(fp)) //ѭ����ȡ�ļ�
	{
		p = new LNode;
		if (!p)//��鱨��
		{
			void Wrong();
			exit(0);
		}

		if (fread(p, sizeof(LNode), 1, fp)) //���ļ�����������
		{
			p->next = NULL;//Ŀǰ���һ���ڵ㣬����û������
			p0->next = p;
			p0 = p; //���ý�����������,
		}
	}
	fclose(fp);
	void Done();

	while (1)
	{
		mainMenu();
		cout << "\nѡ��ı���ǣ�";
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

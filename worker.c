//������head��Ϊ�βεĺ���������˼�붼�Ǳ������㷨
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
	printf("\n\n\t��ӭʹ��ְ����Ϣ����ϵͳBeta.\t\n");
	printf("\n\t�밴��Ӧ������ѡ����\t\n");
	printf("\t0.���̴浵\t\n");
	printf("\t1.����ְ����Ϣ.\t\n");
	printf("\t2.���ȫ��ְ����Ϣ\t\n");
	printf("\t3.������������������ְ��\t\n");
	printf("\t4.�����ʲ�ѯְ��\t\n");
	printf("\t5.�޸�ְ����Ϣ\t\n");
	printf("\t6.ɾ��ְ����Ϣ\t\n");
	printf("\t��ܰ��ʾ�����ڲ���֮��ʹ�ô浵���ܣ��������ݶ�ʧ��\t\n");
	printf("\n\t���Ϲ�ҵ��ѧ �ƿ�1707�� ���Ʒ�\n");

}

void wrong()
{
	system("cls");
	printf("\n������һ������\n");
}

void done()
{
	printf("\n��ɣ�\n");
}

void add(LinkList head)
{
	int i, n;
	LNode *p, *p0;//����ָ��ṹ���ָ��
	p0 = head;
	printf("\n������Ӷ���ְ���أ�");
	scanf("%d", &n);

	while (p0->next != NULL)
		p0 = p0->next;//�������һ���ڵ㣬׼������

	for (i = 1; i <= n; i++)
	{
		if ((p = (LinkList)malloc(sizeof(LNode))) == NULL)//Ϊ��ַ��LinkList������ΪLNode����׼���ڴ�
		{
			void wrong();
			exit(-1);
		}
		printf("\n");
		printf("��ְ���Ĺ�����(�����󲻿��޸�)��");
		scanf("%s", p->id);

		printf("\n");
		printf("��ְ���������ǣ�");
		scanf("%s", p->name);

		printf("\n");
		printf("��ְ�����Ա���(��/Ů):");
		scanf("%s", p->sex);

		printf("\n");
		printf("��ְ���������ǣ�");
		scanf("%d", &p->age);

		printf("\n");
		printf("��ְ����ѧ����(��ר/��ר/����/˶ʿ/��ʿ/����)��");
		scanf("%s", p->edu);

		printf("\n");
		printf("��ְ�����¹����ǣ�");
		scanf("%d", &p->salary);

		printf("\n");
		printf("��ְ���ĵ绰�����ǣ�");
		scanf("%s", p->phone);

		printf("\n");
		printf("��ְ����סַ�ǣ�");
		scanf("%s", p->address);

		printf("\n");
		p->next = NULL;//�������������β�����
		p0->next = p;//���½��Ľ���������β����
		p0 = p;
		done();
	}
}

void showall(LinkList head)
{
	LNode *p;
	p = head->next;
	if (!p)//������
	{
		wrong();
		printf("û��ְ����Ϣ������¼�룡");
	}
	printf("\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ \n");
	while (p)
	{
		printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
		p = p->next;
	}
	done();
}

void sortbysalary(LinkList head)
{
	LNode *p0, *p1;//������ָ���Ǵ����ҵĹ�ϵ������ָ����˶���p1������ָ�����һ���ڵ��
	p0 = head->next;
	p1 = p0->next;
	if (!p0)//���p��0���������֧������
	{
		wrong();
		printf("û��Ա����Ϣ������¼��QAQ");
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

	printf("������������������");
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
	printf("\n�������ˣ�");
	showall(head);
	done();
}

void findbysalary(LinkList head)
{
	int salary;
	printf("������ҹ���Ϊ���ٵ�Ա����");
	scanf("%d", &salary);

	int count = 0;
	printf("\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ \n");

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
		printf("û�з���������Ա��\n");
	done();
}

void rewrite(LinkList head)
{
	printf("\n�����������޸ĵ�ְ���ı�ţ�");
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
			printf("\n�Ѿ����ҵ�:\n");
			printf("\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ \n");
			printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
			printf("\n�������������޸ĺ�������ݣ�\n");

			printf("�޸ĺ��ְ���������ǣ�");
			scanf("%s", p->name);

			printf("\n");
			printf("�޸ĺ��ְ�����Ա���(��/Ů):");
			scanf("%s", p->sex);

			printf("\n");
			printf("�޸ĺ��ְ���������ǣ�");
			scanf("%d", &p->age);

			printf("\n");
			printf("�޸ĺ��ְ����ѧ����(��ר/��ר/����/˶ʿ/��ʿ/����)��");
			scanf("%s", p->edu);

			printf("\n");
			printf("�޸ĺ��ְ�����¹����ǣ�");
			scanf("%d", &p->salary);

			printf("\n");
			printf("�޸ĺ��ְ���ĵ绰�����ǣ�");
			scanf("%s", p->phone);

			printf("\n");
			printf("�޸ĺ��ְ����סַ�ǣ�");
			scanf("%s", p->address);
		}
		p = p->next;
	}
	if (count == 0)
	{
		wrong();
		printf("���޴��ˣ���������ԡ�");
	}
	done();
}

void del(LinkList head)
{
	printf("\n����������ɾ����ְ���ı�ţ�");
	char id[12];
	scanf("%s", id);

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
			printf("\n�Ѿ����ҵ�:\n");
			printf("\n����\t����\t�Ա�\t����\tѧ��\t����\t�绰\t\tסַ \n");
			printf("%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s\n", p->id, p->name, p->sex, p->age, p->edu, p->salary, p->phone, p->address);
			printf("\nҪɾ����?��Y/N��");
			scanf("%s", &choose);

			if (choose == 'y' || choose == 'Y')
			{
				p0->next = p->next;
				free(p);
				break;
			}
			else
			{
				printf("\n�����˳�...\n");
				exit(0);
			}
		}
		p = p->next;
		p0 = p0->next;
	}


	if (count == 0)
	{
		wrong();
		printf("���޴��ˣ���������ԡ�");
	}
	done();
}

void save(LinkList L)
{
	FILE *fp;
	fp = fopen("worklist.txt", "wb");//д�ļ�

	LNode *p;//׼��һ����ù��ָ��ָ��ԭ�ṹ�壬׼���������ƶ���д����
	p = L->next;//����Ȼ�������ù��ָ���Ѿ�ָ���˵�һ���ڵ��������

	if (fp == NULL)//�Ҳ��Ŵ򲻿�������
	{
		wrong();
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
			wrong();
			exit(-1);
		}
	}
	fclose(fp);
	printf("\n���ڴ浵...");
	done();
}

int main(void)
{
	FILE *fp;
	LNode *p, *p0;//p0��p��ǰһ���ڵ�
	LinkList L;//����һ������
	L = (LinkList)malloc(sizeof(LNode));

	if (!L)//��鱨��
	{
		void wrong();
		exit(-1);
	}
	p0 = L;//p0��ָ�����ڶ��ڵ��ָ��
	L->next = NULL;//��������
	char choose;
	fp = fopen("worklist.txt", "rb");//���ļ�

	if (fp == NULL)
	{
		printf("\n��ע�⣺�洢ְ����Ϣ�ı����ļ������ڣ��Ƿ񴴽���(Y/N)\n");
		scanf("%c", &choose);
		if (choose == 'y' || choose == 'Y')
		{
			fp = fopen("worklist.txt", "ab+");
			printf("�����ļ��Ѵ�����\n");
		}
		else
		{
			printf("�����ļ������ڣ��޷���дְ����Ϣ!\n");
			exit(0);
		}

	}
	printf("�����ļ����ҵ�����ȡ���");

	while (!feof(fp)) //ѭ����ȡ�ļ�
	{
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)//��鱨��
		{
			void wrong();
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
	void done();

	while (1)
	{
		mainmenu();
		printf("\nѡ��ı���ǣ�");
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

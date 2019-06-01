#include"pch.h"
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
int deleteStudent(struct Student * list, char * m, int t);
void printStudntInfo(struct Student * list, int t, struct Student * q);
void saveStudentInfo(struct Student * list, int m);
void readStudentInfo(struct Student * list);
void inputStudentInfo(struct Student * list);
void insertList(struct Student * list, struct Student * student);
int changStudentInfo(struct Student * list, char * m, int t);
void classSearch(struct Student * list, char * Class);
void personSearch(struct Student * list, char * person, int t);
void courseSearch(struct Student * list, char * course, int year);
void add(struct Student * list, char * course, struct Student * q, int year, int t, int n);
void closeMC(struct Student * list);
void stuGradeSortSin(struct Student *, int, int, char *, char *);
void GradeSort(struct Student * list, struct Student * q, int year);
void totalGradeSort(struct Student * list, int t, int year, char * Class);

void changeInfo(struct Student * list, char * person, int t2);
void changeCourse(struct Student * list, char * person, int t, char * course);
//������Ϣ
/*
*���� 1  ��ʾҪ�ӵ�����ͷ
*/
void inputStudentInfo(struct Student * list)
{
	int t = 1, i, j;
	struct Student * p, *tail;
	//ѧ����Ϣ��¼��
	p = list->next;
	//����ѧ������Ϣ���ҽ��в���
	//��ʼ����ѧ������Ϣ
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		tail = p;

	}
	else
	{
		tail = list;
	}

	while (t)
	{
		system("cls");
		printf("\nѧ����Ϣ����ҳ��:\n");
		//������Ϣ��¼��
		p = (struct Student *)malloc(sizeof(struct Student));
		p->TotalGrade[0] = 0.0;
		p->TotalGrade[1] = 0.0;
		printf("������ѧ���İ༶��");
		scanf("%s", p->Class);
		printf("��������ѧ����ѧ��:");
		scanf("%s", p->id);
		printf("��������ѧ��������:");
		scanf("%s", p->name);
		printf("�������� 2018 ��������ѧ�ڵĳɼ���\n");
		for (i = 0; i < 2; i++)
		{
			printf("\n2018#0%d\n", i + 1);
			for (j = 0; j < 3; j++)
			{
				p->Acourse[i][j].year = i + 1;
				printf("������γ�����");
				scanf("%s", p->Acourse[i][j].A_course);
				printf("������ƽʱ�ɼ�:");
				scanf("%lf", &(p->Acourse[i][j].dayGrade));
				printf("�����뿼�Գɼ�:");
				scanf("%lf", &(p->Acourse[i][j].examGrade));

				p->Acourse[i][j].totalGrade = (p->Acourse[i][j].dayGrade * 0.2) + (p->Acourse[i][j].examGrade * 0.8);
				printf("\n");
				p->TotalGrade[i] += p->Acourse[i][j].totalGrade;
			}
		}

		//����ѧ������Ϣ�������β��
		tail->next = p;
		tail = p;


		//���浽�ϴε�β��
		saveStudentInfo(p, 1);
		tail->next = NULL;


		//��Ϣ����� ȷ���û�ȷ��

		system("cls");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��Ϣ����ɹ�(^_^)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("��¼�������Ϊ��\n");
		printStudntInfo(list, 3, p);

		printf("\n���Ƿ�������룿����(0/1)����");
		scanf("%d", &t);

	}
	printf("ѧ����Ϣ����ҳ���˳��ɹ�...\n");
	system("pause");
}

//����ѧ������Ϣ��������
/*
*���� 1  ��ʾҪ����������
*���� 2 ��ʾҪ�����������Ϣ
*/
void insertList(struct Student * list, struct Student * student)
{
	struct Student * p = list->next;
	if (list->next == NULL)
	{
		list->next = student;
		return;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = student;
		student->next = NULL;
	}
	//����ѧ������Ϣ
	saveStudentInfo(list, 0);

}

//ɾ��ѧ����Ϣ
/*
*����1 ��ʾҪ����������
*����2 ��ʾ ѧ����ID��������
*����3 ��ʾ�������͵�ɾ��
*/
int deleteStudent(struct Student * list, char * m, int t)
{
	struct Student * p = list->next, *q = list;
	int k = 1;

	if (list->next == NULL) return 0;
	switch (t)
	{
		//��idɾ��
	case 1:
		while (p)
		{
			if (strcmp(p->id, m) == 0)
			{
				printf("����ѧ������ϢΪ:\n");
				printf("�༶\t\tѧ��\t\t����\t\t2018���ܳɼ�\t\t2018���ܳɼ�\t\t\n");
				printf("%s\t%s\t%s\t\t%.2lf\t\t%.2lf\n", p->Class, p->id, p->name, p->TotalGrade[0], p->TotalGrade[1]);
				printf("�Ƿ�ȷ��?(��0ȡ�������������ּ���...)��");
				scanf("%d", &k);
				if (k == 0) return -2;


				q->next = p->next;
				free(p);
				break;

			}
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			return -1;
		}
		break;
	case 2:
		//������ɾ��
		while (p)
		{
			if (strcmp(p->name, m) == 0)
			{
				printf("����ѧ������ϢΪ:\n");
				printf("�༶\tѧ��\t����\t2018���ܳɼ�\t2018���ܳɼ�\t\n");
				printf("%s\t%s\t%s\t%.2lf\t%.2lf\n", p->Class, p->id, p->name, p->TotalGrade[0], p->TotalGrade[1]);
				printf("�Ƿ�ȷ��?(��0ȡ�������������ּ���...)��");
				scanf("%d", &k);
				if (k == 0) return -2;
				q->next = p->next;
				free(p);
				break;

			}
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			return -1;
		}

		break;
	}
	return 1;
}

//����ѧ����Ϣ
/*
*����1  ��ʾҪ����������
*����2 ��ʾѧ����ID��������
*����3  ��ʾ��������
*/
int changStudentInfo(struct Student * list, char * m, int t)
{
	int i, j, d;
	struct Student * p = list->next;
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		if (t == 1)
		{
			while (p)
			{
				if (strcmp(p->id, m) == 0)
				{
					printStudntInfo(list, 3, p);
					printf("�Ƿ������Ϣ���˸��Ľ�����������ȫ���������ݣ�����������0ȡ�����������ּ�������");
					scanf("%d", &d);
					//��ʾȡ��
					if (d == 0) return -1;


					p->TotalGrade[0] = 0.0;
					p->TotalGrade[1] = 0.0;
					printf("������ѧ���İ༶��");
					scanf("%s", p->Class);
					printf("��������ѧ����ѧ��:");
					scanf("%s", p->id);
					printf("��������ѧ��������:");
					scanf("%s", p->name);
					printf("�������� 2018 ��������ѧ�ڵĳɼ���\n");
					for (i = 0; i < 2; i++)
					{
						printf("\n2018#0%d\n", i + 1);
						for (j = 0; j < 3; j++)
						{
							p->Acourse[i][j].year = i + 1;
							printf("������γ�����");
							scanf("%s", p->Acourse[i][j].A_course);
							printf("������ƽʱ�ɼ�:");
							scanf("%lf", &(p->Acourse[i][j].dayGrade));
							printf("�����뿼�Գɼ�:");
							scanf("%lf", &(p->Acourse[i][j].examGrade));

							p->Acourse[i][j].totalGrade = (p->Acourse[i][j].dayGrade * 0.2) + (p->Acourse[i][j].examGrade * 0.8);
							printf("\n");
							p->TotalGrade[i] += p->Acourse[i][j].totalGrade;
						}
					}
					printf("���ĺ��ѧ����ϢΪ:\n");
					printStudntInfo(list, 3, p);
					saveStudentInfo(list, 0);

					break;

				}
				p = p->next;
			}
			if (p == NULL) return -2;
		}
		else if (t == 2)
		{
			while (p)
			{
				if (strcmp(p->name, m) == 0)
				{
					printStudntInfo(list, 3, p);
					printf("�Ƿ������Ϣ���˸��Ľ�����������ȫ���������ݣ�����������0ȡ�����������ּ�������");
					scanf("%d", &d);
					//��ʾȡ��
					if (d == 0) return -1;


					p->TotalGrade[0] = 0.0;
					p->TotalGrade[1] = 0.0;
					printf("������ѧ���İ༶��");
					scanf("%s", p->Class);
					printf("��������ѧ����ѧ��:");
					scanf("%s", p->id);
					printf("��������ѧ��������:");
					scanf("%s", p->name);
					printf("�������� 2018 ��������ѧ�ڵĳɼ���\n");
					for (i = 0; i < 2; i++)
					{
						printf("\n2018#0%d\n", i + 1);
						for (j = 0; j < 3; j++)
						{
							p->Acourse[i][j].year = i + 1;
							printf("������γ�����");
							scanf("%s", p->Acourse[i][j].A_course);
							printf("������ƽʱ�ɼ�:");
							scanf("%lf", &(p->Acourse[i][j].dayGrade));
							printf("�����뿼�Գɼ�:");
							scanf("%lf", &(p->Acourse[i][j].examGrade));

							p->Acourse[i][j].totalGrade = (p->Acourse[i][j].dayGrade * 0.2) + (p->Acourse[i][j].examGrade * 0.8);
							printf("\n");
							p->TotalGrade[i] += p->Acourse[i][j].totalGrade;
						}
					}
					printf("���ĺ��ѧ����ϢΪ:\n");
					printStudntInfo(list, 3, p);
					saveStudentInfo(list, 0);
					break;

				}
				p = p->next;
			}
			if (p == NULL) return -2;

		}


	}


	return 1;




}

//����ѧ����Ϣ ¼�뵽ϵͳ�е�
/*
*����1  ��ʾҪ����������
*����2  ��ʾ�����ݵ�ģʽ
*/
void saveStudentInfo(struct Student * list, int m)
{
	FILE * fp = NULL;

	if (m == 0)
	{
		struct Student * p = list->next;

		if ((fp = fopen("StudentInfomation.txt", "wb+")) == NULL)
		{
			printf("Error: Can not open the file !");
			exit(0);
		}
		while (p != NULL)
		{
			fwrite(p, sizeof(struct Student), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else
	{
		struct Student * p = list;
		if ((fp = fopen("StudentInfomation.txt", "ab")) == NULL)
		{
			printf("Error: Can not open the file !");
			exit(0);
		}
		if (p != NULL)
		{
			fwrite(p, sizeof(struct Student), 1, fp);
		}
		fclose(fp);
	}

}

//��ȡѧ������Ϣ
/*
����1 ��ʾ��ȡ���������
*/
void readStudentInfo(struct Student * list)
{
	struct Student * p = list, *q = NULL;
	FILE * fp;
	if ((fp = fopen("StudentInfomation.txt", "r")) == NULL)
	{
		return;
	}
	q = (struct Student *) malloc(sizeof(struct Student));
	while ((fread(q, sizeof(struct Student), 1, fp)) != 0)
	{
		p->next = q;
		p = q;
		q = (struct Student *) malloc(sizeof(struct Student));
	}

	p->next = NULL;

	fclose(fp);



}

//��չ�����������ӡѧ����Ϣ
/*
*����1 ��ʾҪ����������
*����2 ��ʾҪ������ݵ�����
*����3����ѡ�� ��ʾ����������qָ�������
*/
void printStudntInfo(struct Student * list, int t, struct Student * q)
{
	int i, j;
	struct Student * p = list->next;
	if (p != NULL)
	{
		if (t == 1)
		{

			printf("\n�༶\tѧ��\t����\t2018���ܳɼ�\t2018���ܳɼ�\t\n");
			while (p)
			{

				printf("%s\t%s\t%s\t%.2lf\t\t%.2lf\n", p->Class, p->id, p->name, p->TotalGrade[0], p->TotalGrade[1]);
				p = p->next;

			}
		}
		else if (t == 2)
		{
			while (p)
			{
				printf("\n.......................................................................................\n");
				printf("\n�༶\t\tѧ��ѧ��\t\tѧ������\n");
				printf("%s\t%s\t%s\n", p->Class, p->id, p->name);
				printf("ѧ��\t�γ���\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�");
				printf("\n........................................................................................\n");
				for (i = 0; i < 2; i++)
				{

					for (j = 0; j < 3; j++)
					{
						printf("2018#0%d\t", i + 1);
						printf("%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[i][j].A_course, p->Acourse[i][j].dayGrade, p->Acourse[i][j].examGrade, p->Acourse[i][j].totalGrade);
					}


				}
				printf("2018������ܳɼ�Ϊ:%.2lf\t2018������ܳɼ�Ϊ:%.2lf\n", p->TotalGrade[0], p->TotalGrade[1]);
				printf(".....................................................................................\n");
				p = p->next;
			}


		}
		else if (t == 3)
		{

			printf("\n�༶\t\tѧ��ѧ��\t\tѧ������\n");
			printf("%s\t%s\t%s\n", q->Class, q->id, q->name);
			printf("ѧ��\t�γ���\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�");
			printf("\n.....................................................................................\n");
			for (i = 0; i < 2; i++)
			{

				for (j = 0; j < 3; j++)
				{
					printf("2018#0%d\t", i + 1);
					printf("%s\t%.2lf\t%.2lf\t%.2lf\n", q->Acourse[i][j].A_course, q->Acourse[i][j].dayGrade, q->Acourse[i][j].examGrade, q->Acourse[i][j].totalGrade);
				}

			}
			printf("2018������ܳɼ�Ϊ:%.2lf\t2018������ܳɼ�Ϊ:%.2lf\n", q->TotalGrade[0], q->TotalGrade[1]);

		}
	}
}

//�༶ѧ����Ϣ��ѯ
/*
*����1  ��ʾ����������
*����2  ��ʾƥ��İ༶�����ѯ�İ༶��
*/
void classSearch(struct Student * list, char * Class)
{
	struct Student * p = list->next;
	int k = 0;
	int i;
	int numbers = 0, T_num1 = 0, T_num2 = 0, T_num3 = 0, T_num4 = 0;
	if (p == NULL)
	{
		printf("ѧ����Ϣ������ѧ����Ϣ�ɲ�ѯ����ȷ��ѧ����Ϣ�Ƿ����?\n");
		return;
	}
	//����ȫ��
	while (p)
	{

		if (strcmp(p->Class, Class) == 0)
		{
			printStudntInfo(list, 3, p);
			if (p->TotalGrade[0] >= 250) T_num1++;
			if (p->TotalGrade[1] >= 250) T_num2++;
			for (i = 0; i < 3; i++)
			{
				if (p->Acourse[0][i].totalGrade < 60)
				{
					T_num3++;
					break;
				}
			}
			for (i = 0; i < 3; i++)
			{
				if (p->Acourse[1][i].totalGrade < 60)
				{
					T_num4++;
					break;
				}
			}
			numbers++;
			k = 1;

		}
		p = p->next;
	}
	//����༶�Ƿ����
	if (k == 0)
	{
		printf("������İ༶�����ڣ���ȷ�����������Ƿ���ȷ��\n");
		return;

	}
	printf("\n...................................................................\n");
	printf("�༶������Ϊ��%d\n", numbers);
	printf("2018�����ѧ���������㣨>=250��������: %d\n", T_num1);
	printf("2018�����ѧ���������㣨>=250��������: %d\n", T_num2);
	printf("2018�����ѧ�ڹҿ�(��������<60)������: %d\n", T_num3);
	printf("2018�����ѧ�ڹҿ�(��������<60)������: %d\n", T_num4);

}
//������Ϣ��ѯ
/*
*����1 ��ʾ����������
*����2 ��ʾѧ����������ѧ����ID
*����3 ��ʾ��ѯ����
*/
void personSearch(struct Student * list, char * person, int t)
{
	struct Student * p = list->next;
	int k = 0;
	if (p == NULL)
	{
		printf("ѧ����Ϣ������ѧ����Ϣ�ɲ�ѯ����ȷ��ѧ����Ϣ�Ƿ����?\n");
		return;
	}
	if (t == 1)
	{

		while (p)
		{
			//ѧ����Ψһ��
			if (strcmp(p->id, person) == 0)
			{
				printStudntInfo(list, 3, p);
				k = 1;
				break;

			}
			p = p->next;
		}
	}
	else
	{
		while (p)
		{
			//��������Ψһ��
			if (strcmp(p->name, person) == 0)
			{
				printf("%s����ϸ��ϢΪ:\n", person);
				printStudntInfo(list, 3, p);
				k = 1;

			}
			p = p->next;
		}
	}
	if (k == 0)
	{
		printf("�������ѧ�������ڣ������²鿴һ�����������Ƿ���ȷ��\n");
	}
}

//�γ���Ϣ��ѯ
/*
*����1  ��ʾҪ����������
*����2  ��ʾ��ѯ�Ŀγ�
*����3  ��ʾ��ѯ��ѧ��
*/
void courseSearch(struct Student * list, char * course, int year)
{
	struct Student * p = list->next;
	//���ڷ�����λ�� 0-100��

	double max = -1, min = 120.0, sum = 0, len = 0, gK = 0;
	int k = 0;
	int i, j;

	if (p == NULL)
	{
		printf("ѧ����Ϣ������ѧ����Ϣ�ɲ�ѯ����ȷ��ѧ����Ϣ�Ƿ����?\n");
		return;
	}
	//����course�Ƿ����

	if (year == 1)
	{
		printf("2018�����ѧ�ڣ�\n");
		printf("�༶\tѧ��ѧ��\tѧ������\t�γ�����\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(course, p->Acourse[0][j].A_course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Class, p->id, p->name, p->Acourse[0][j].A_course, p->Acourse[0][j].dayGrade, p->Acourse[0][j].examGrade, p->Acourse[0][j].totalGrade);
					if (p->Acourse[0][j].totalGrade > max) max = p->Acourse[0][j].totalGrade;
					if (p->Acourse[0][j].totalGrade < min) min = p->Acourse[0][j].totalGrade;
					if (p->Acourse[0][j].totalGrade < 60) gK++;
					sum += p->Acourse[0][j].totalGrade;
					len++;
					k = 1;
					break;

				}
			}
			p = p->next;

		}
		if (k == 0)
		{
			printf("����,�޸ÿγ̵���Ϣ��\n");
			return;
		}
		printf(".......................................................................\n");
		printf("��߷�Ϊ:%.2lf\t��ͷ�Ϊ:%.2lf\n", max, min);
		printf("����Ϊ:%.0lf\tƽ����Ϊ:%.2lf\n", len, sum / len);
		printf("�ҿ�(�ɼ�< 60 )����Ϊ:%.0lf\n", gK);
	}
	else if (year == 2)
	{
		printf("2018�����ѧ�ڣ�\n");
		printf("�༶\tѧ��ѧ��\tѧ������\t�γ�����\t\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(course, p->Acourse[1][j].A_course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Class, p->id, p->name, p->Acourse[1][j].A_course, p->Acourse[1][j].dayGrade, p->Acourse[1][j].examGrade, p->Acourse[1][j].totalGrade);
					if (p->Acourse[1][j].totalGrade > max) max = p->Acourse[1][j].totalGrade;
					if (p->Acourse[1][j].totalGrade < min) min = p->Acourse[1][j].totalGrade;
					if (p->Acourse[1][j].totalGrade < 60) gK++;
					sum += p->Acourse[1][j].totalGrade;
					len++;
					k = 1;
					break;


				}


			}
			p = p->next;
		}
		if (k == 0)
		{
			printf("����,�޸ÿγ̵���Ϣ��\n");
			return;
		}
		printf(".......................................................................\n");
		printf("��߷�Ϊ:%.2lf\t��ͷ�Ϊ:%.2lf\n", max, min);
		printf("����Ϊ:%.0lf\tƽ����Ϊ:%.2lf\n", len, sum / len);
		printf("�ҿ�(�ɼ�< 60 )����Ϊ:%.0lf\n", gK);

	}
	else
	{
		printf("��Ǹ��������ݵ�ѡ���ѯ��δ���ţ�\n");
	}

}

//���Ƴɼ�����
/*
����1  ��ʾ����������
����2 ��ʾѧ��
����3 ��ʾ���������
����4 ��ʾ����Ŀγ�
����5  ��ʾ����İ༶
*/
void stuGradeSortSin(struct Student * list, int year, int t, char * course, char * Class)
{
	struct Student * p = list->next;
	struct Student * r = NULL;
	struct Student * q = NULL, head1;
	int i, j, k = 0;
	head1.next = NULL;
	if (!p)
	{
		printf("ѧ����Ϣ������ѧ����Ϣ�ɲ�����");
		return;
	}
	if (year > 2 || year < 1)
	{
		printf("��Ǹ��������ݵĲ�����δ���ţ������ڴ���\n");
		return;
	}
	//�༶������
	if (t == 1)
	{
		q = (struct Student *)malloc(sizeof(struct Student));

		while (p)
		{
			//������ͬһ�༶��ѧ����Ϣ
			if (strcmp(Class, p->Class) == 0)
			{
				strcpy(q->Class, p->Class);
				strcpy(q->id, p->id);
				strcpy(q->name, p->name);
				q->TotalGrade[0] = p->TotalGrade[0];
				q->TotalGrade[1] = p->TotalGrade[1];
				for (i = 0; i < 2; i++)
				{
					for (j = 0; j < 3; j++)
					{
						strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
						q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
						q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
						q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
					}
				}
				q->next = NULL;
				add(&head1, course, q, 0, 1, 0);
				q = (struct Student *)malloc(sizeof(struct Student));
			}
			p = p->next;
		}
		p = head1.next;
		if (head1.next == NULL)
		{
			printf("��Ǹ���޸ð༶��������Ϣ!\n");
			system("pause");
			return;

		}
		i = 1;
		if (year == 1)
		{
			printf("2018����ѧ��:\n");
		}
		else
		{
			printf("2018����ѧ��:\n");
		}
		printf("�༶\tѧ��ѧ��\tѧ������\t�γ�����\t\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\t���\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{

				if (strcmp(p->Acourse[year - 1][j].A_course, course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%d\n", p->Class, p->id, p->name, p->Acourse[year - 1][j].A_course, p->Acourse[year - 1][j].dayGrade, p->Acourse[year - 1][j].examGrade, p->Acourse[year - 1][j].totalGrade, i++);
					break;
				}
			}
			p = p->next;
		}
		system("pause");
		closeMC(&head1);
	}
	else
	{


		int n;
		q = (struct Student *)malloc(sizeof(struct Student));
		while (p)
		{
			for (i = 0; i < 3; i++)
			{
				//���γ���Ϣ��ͬ��ͬѧת�Ƶ���һ���������ź�xu

				if (strcmp(course, p->Acourse[year - 1][i].A_course) == 0)
				{
					n = i;
					strcpy(q->Class, p->Class);
					strcpy(q->id, p->id);
					strcpy(q->name, p->name);
					q->TotalGrade[0] = p->TotalGrade[0];
					q->TotalGrade[1] = p->TotalGrade[1];
					for (i = 0; i < 2; i++)
					{
						for (j = 0; j < 3; j++)
						{
							strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
							q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
							q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
							q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
						}
					}
					q->next = NULL;
					add(&head1, course, q, year - 1, 2, n);
					q = (struct Student *)malloc(sizeof(struct Student));
					break;
				}
			}
			p = p->next;
		}
		p = head1.next;
		if (head1.next == NULL)
		{
			printf("��Ǹ����������Ϣ!\n");
			system("pause");
			return;

		}
		i = 1;
		if (year == 1)
		{

			printf("2018����ѧ��:\n");
		}
		else
		{
			printf("2018����ѧ��:\n");
		}
		printf("�༶\tѧ��ѧ��\tѧ������\t�γ�����\t\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\t���\n");
		printf(".............................................................................\n");
		while (p)
		{
			for (j = 0; j < 3; j++)
			{

				if (strcmp(p->Acourse[year - 1][j].A_course, course) == 0)
				{
					printf("%s\t%s\t%s\t%s\t%.2lf\t%.2lf\t%.2lf\t%d\n", p->Class, p->id, p->name, p->Acourse[year - 1][j].A_course, p->Acourse[year - 1][j].dayGrade, p->Acourse[year - 1][j].examGrade, p->Acourse[year - 1][j].totalGrade, i++);
					break;
				}
			}
			p = p->next;
		}
		system("pause");
		closeMC(&head1);
	}
}

//�ؽ�����  �����Ӵ�С����
/*
����1 ��ʾ����������
����2 ��ʾ����Ŀγ�
����3 ��ʾ��ӵ�ѧ��
����4  ��ʾѧ��
����5  ��ʾ����
����6  ��ʾ�γ̵�λ��

*/
void add(struct Student * list, char * course, struct Student * q, int year, int t, int n)
{
	struct Student * p = list->next, *r = list;
	int  j, i, k = 0;
	if (t == 1)
	{
		if (!p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(q->Acourse[year][j].A_course, course) == 0)
				{
					list->next = q;
					break;
				}
			}
			if (j == 3) return;
		}
		while (p)
		{

			//��������Ͼ���  �Ƚ������γ���ͬ�ĳɼ���С
			for (j = 0; j < 3; j++)
			{
				if (strcmp(p->Acourse[year][j].A_course, course) == 0)
				{
					for (i = 0; i < 3; i++)
					{
						if (strcmp(q->Acourse[year][i].A_course, course) == 0)
						{
							//��ǩ ������־ p��q�Ŀγ�һ��  ���� �ɼ�����p��
							k = 1;
							if (q->Acourse[year][i].totalGrade > p->Acourse[year][j].totalGrade)
							{
								k = 0;
								goto lable1;
							}
							break;

						}
					}
					//�ܽ��뵽�������  ��˵�� p�Ѿ��ҵ�Ҫ��Ŀγ���  ���ߵ���һ��  ��˵���ɼ��Ѿ��Ƚ��꣨��γ̲���ͬ��  �����˳�
					break;
				}

			}

			r = p;
			p = p->next;


		}
	lable1:
		r->next = q;
		q->next = p;

		if (k == 1)
		{
			r->next = q;

		}
	}
	else                                    //����ǰ��꼶�ĵ�������
	{
		if (!p)
		{
			list->next = q;
		}
		while (p)
		{
			for (j = 0; j < 3; j++)
			{
				if (strcmp(p->Acourse[year][j].A_course, course) == 0)
				{
					k = 1;
					if (q->Acourse[year][n].totalGrade > p->Acourse[year][j].totalGrade)
					{
						r->next = q;
						q->next = p;
						k = 0;
						break;

					}

				}

			}
			if (k == 0) return;

			r = p;
			p = p->next;

		}
		if (k == 1) r->next = q;
	}

}
//�ͷŽڵ�ռ�
void closeMC(struct Student * list)
{
	struct Student * p = list->next, *r = NULL;
	while (p)
	{
		r = p->next;
		free(p);
		p = r;


	}
}

//��ʾ�ܳɼ�����
/*
����1  ��ʾҪ����������
����2  ��ʾ����
����3  ��ʾѧ��
����4����ѡ�� ��ʾ �༶

*/
void totalGradeSort(struct Student * list, int t, int year, char * Class)
{
	struct Student * p = list->next, *q = NULL;
	struct Student head1;
	int i, j;

	head1.next = NULL;
	if (list->next == 0)
	{
		printf("ѧ����Ϣ��������ѧ����Ϣ�ɲ�����\n");
		return;
	}
	if (year > 2 || year < 1)
	{
		printf("��Ǹ������ѧ�ڵĲ������޿��ţ������ڴ���\n");
		return;
	}

	if (t == 2)
	{
		q = (struct Student *)malloc(sizeof(struct Student));
		while (p)
		{
			strcpy(q->Class, p->Class);
			strcpy(q->id, p->id);
			strcpy(q->name, p->name);
			q->TotalGrade[0] = p->TotalGrade[0];
			q->TotalGrade[1] = p->TotalGrade[1];
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 3; j++)
				{
					strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
					q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
					q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
					q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
				}
			}
			q->next = NULL;
			GradeSort(&head1, q, year);
			q = (struct Student *)malloc(sizeof(struct Student));

			p = p->next;
		}

	}
	else if (t == 1)
	{
		q = (struct Student *)malloc(sizeof(struct Student));
		while (p)
		{
			//�༶�ܳɼ�����
			if (strcmp(Class, p->Class) == 0)
			{
				strcpy(q->Class, p->Class);
				strcpy(q->id, p->id);
				strcpy(q->name, p->name);
				q->TotalGrade[0] = p->TotalGrade[0];
				q->TotalGrade[1] = p->TotalGrade[1];
				for (i = 0; i < 2; i++)
				{
					for (j = 0; j < 3; j++)
					{
						strcpy(q->Acourse[i][j].A_course, p->Acourse[i][j].A_course);
						q->Acourse[i][j].dayGrade = p->Acourse[i][j].dayGrade;
						q->Acourse[i][j].examGrade = p->Acourse[i][j].examGrade;
						q->Acourse[i][j].totalGrade = p->Acourse[i][j].totalGrade;
					}
				}
				q->next = NULL;
				GradeSort(&head1, q, year);
				q = (struct Student *)malloc(sizeof(struct Student));
			}

			p = p->next;
		}



	}
	p = head1.next;
	i = 1;
	if (p == NULL)
	{
		printf("����������Ϣ!\n");
		return;
	}
	if (year == 1)
	{
		printf("2018����ѧ���ܳɼ�����:\n");
	}
	else
	{
		printf("2018����ѧ���ܳɼ�����:\n");
	}
	printf("�༶\tѧ��ѧ��\tѧ������\t�ܳɼ�\t���\n");
	while (p)
	{
		printf("%s\t%s\t%s\t%.2lf\t%d\n", p->Class, p->id, p->name, p->TotalGrade[year - 1], i++);
		p = p->next;
	}
	closeMC(&head1);
}

//�ܳɼ����򣨺�������
/*
����1 ����������
����2  ��Ҫ��ӽ������ѧ����Ϣ
����3  ��ʾѧ��
*/
void GradeSort(struct Student * list, struct Student * q, int year)
{
	struct Student * p = list->next, *r = list;
	if (!p)
	{
		list->next = q;
		return;
	}
	while (p)
	{
		if (p->TotalGrade[year - 1] < q->TotalGrade[year - 1])
		{
			r->next = q;
			q->next = p;
			return;
		}
		r = p;
		p = p->next;
	}
	r->next = q;
}

//����ѧ���ĸ�����Ϣ
/*
����1  ��ʾ����������
����2  ��ʾѧ������������ID
����3  ��ʾ����
*/
void changeInfo(struct Student * list, char * person, int t2)
{
	int t;
	int i, j;
	struct Student * p = list->next;
	if (!p)
	{
		printf("ѧ����Ϣ������ѧ����Ϣ�ɲ���!\n");
		return;
	}
	while (p)
	{
		//�ж��ǰ�ID���ǰ�����
		if (t2 == 1)
		{

			if (strcmp(p->id, person) == 0)
			{
				printf("��Ҫ�޸ĵ���ϢΪ:\n");
				printf("�༶\tѧ������\tѧ��ID\n");
				printf("%s\t%s\t%s\n", p->Class, p->name, p->id);
				printf("����0ȡ���޸�,�������ּ���:\n");
				scanf("%d", &t);
				if (t == 0)
				{
					printf("����ȡ��...");
					return;
				}
				printf("����������ID��");
				scanf("%s", p->id);
				printf("���������İ༶:");
				scanf("%s", p->Class);
				printf("��������������:");
				scanf("%s", p->name);
				break;
			}
		}
		else
		{
			if (strcmp(p->name, person) == 0)
			{
				printf("��Ҫ�޸ĵ���ϢΪ:\n");
				printf("�༶\tѧ������\tѧ��ID\n");
				printf("%s\t%s\t%s\n", p->Class, p->name, p->id);
				printf("����0ȡ���޸�,�������ּ���:\n");
				scanf("%d", &t);
				if (t == 0)
				{
					printf("����ȡ��...");
					return;
				}
				printf("����������ID��");
				scanf("%s", p->id);
				printf("���������İ༶:");
				scanf("%s", p->Class);
				printf("��������������:");
				scanf("%s", p->name);
				break;
			}
		}
		p = p->next;
	}

	if (p == NULL)
	{
		printf("�������ѧ�������ڣ�������������...");
		return;
	}
	saveStudentInfo(list, 0);
	printf("(^^)��Ϣ����ɹ���\n");
	printf("���޸ĵ���ϢΪ:\n");
	printf("�༶\tѧ������\tѧ��ID\n");
	printf("%s\t%s\t%s\n", p->Class, p->name, p->id);
}
//����ѧ���Ŀγ���Ϣ
/*
����1  ��ʾ����������
����2 ��ʾѧ����������id
����3 ��ʾ���ĸ�ʽ
����4 ��ʾ���ĵĿγ�

*/
void changeCourse(struct Student * list, char * person, int t, char * course)
{
	int i, k;
	int year;
	struct Student * p = list->next;
	if (!p)
	{
		printf("ѧ����Ϣ������ѧ����Ϣ�ɲ���!\n");
		return;
	}
	printf("��������ѧ��(1Ϊ��ѧ��,2Ϊ��ѧ��):");
	scanf("%d", &year);

	while (p)
	{
		if (t == 1)
		{
			if (strcmp(p->id, person) == 0)
			{
				for (i = 0; i < 3; i++)
				{
					if (strcmp(p->Acourse[year - 1][i].A_course, course) == 0)
					{
						printf("��Ҫ�޸ĵ���ϢΪ:\n");
						printf("ѧ��\t�γ���\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\n");
						printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[year - 1][i].year, p->Acourse[year - 1][i].A_course, p->Acourse[year - 1][i].dayGrade, p->Acourse[year - 1][i].examGrade, p->Acourse[year - 1][i].totalGrade);
						printf("����0ȡ���޸�,�������ּ���:\n");
						scanf("%d", &k);
						if (k == 0)
						{
							printf("ȡ���޸ĳɹ�...");
							return;
						}
						printf("���������Ŀγ���:");
						scanf("%s", p->Acourse[year - 1][i].A_course);
						printf("����������ƽʱ�ɼ�:");
						scanf("%lf", &p->Acourse[year - 1][i].dayGrade);
						printf("���������Ŀ��Գɼ�:");
						scanf("%lf", &p->Acourse[year - 1][i].examGrade);
						p->TotalGrade[year - 1] -= p->Acourse[year - 1][i].totalGrade;
						p->Acourse[year - 1][i].totalGrade = (p->Acourse[year - 1][i].dayGrade * 0.2) + (p->Acourse[year - 1][i].examGrade * 0.8);
						p->TotalGrade[year - 1] += p->Acourse[year - 1][i].totalGrade;

						goto lable1;
					}
				}
			}
		}
		else
		{
			if (strcmp(p->name, person) == 0)
			{
				for (i = 0; i < 3; i++)
				{
					if (strcmp(p->Acourse[year - 1][i].A_course, course) == 0)
					{
						printf("��Ҫ�޸ĵ���ϢΪ:\n");
						printf("ѧ��\t�γ���\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\n");
						printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[year - 1][i].year, p->Acourse[year - 1][i].A_course, p->Acourse[year - 1][i].dayGrade, p->Acourse[year - 1][i].examGrade, p->Acourse[year - 1][i].totalGrade);
						printf("����0ȡ���޸�,�������ּ���:\n");
						scanf("%d", &k);
						if (k == 0)
						{
							printf("ȡ���޸ĳɹ�...");
							return;
						}
						printf("���������Ŀγ���:");
						scanf("%s", p->Acourse[year - 1][i].A_course);
						printf("����������ƽʱ�ɼ�:");
						scanf("%lf", &p->Acourse[year - 1][i].dayGrade);
						printf("���������Ŀ��Գɼ�:");
						scanf("%lf", &p->Acourse[year - 1][i].examGrade);
						p->TotalGrade[year - 1] -= p->Acourse[year - 1][i].totalGrade;
						p->Acourse[year - 1][i].totalGrade = (p->Acourse[year - 1][i].dayGrade * 0.2) + (p->Acourse[year - 1][i].examGrade * 0.8);
						p->TotalGrade[year - 1] += p->Acourse[year - 1][i].totalGrade;


						goto lable1;
					}
				}
			}

		}
		p = p->next;
	}
lable1:
	if (p == NULL)
	{
		printf("�������ѧ�������ڣ�������������...\n");
		return;
	}
	saveStudentInfo(list, 0);
	printf("(^^)��Ϣ����ɹ���\n");
	printf("���޸ĵ���ϢΪ:\n");
	printf("ѧ��\t�γ���\tƽʱ�ɼ�\t���Գɼ�\t�����ɼ�\n");
	printf("%d\t%s\t%.2lf\t%.2lf\t%.2lf\n", p->Acourse[year - 1][i].year, p->Acourse[year - 1][i].A_course, p->Acourse[year - 1][i].dayGrade, p->Acourse[year - 1][i].examGrade, p->Acourse[year - 1][i].totalGrade);
}



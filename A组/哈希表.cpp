//#define _CRT_SECURE_NO_WARNINGS
//#include<bits/stdc++.h>
//#define MAX_SIZE 25
//typedef struct data {
//	char name[50];
//	char home[120];
//}Data;
//typedef struct node {
//	char key[15];
//	Data data;
//	struct node * next;
//}Node;
//void Hash(Node*& base, Node* a)//������
//{
//	int index = 0;
//	bool flag = false;
//	int num = ((a->key[0]-'0'+(a->key[1]-'0')*10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //���������ͻ
//	{
//		//����̽�ⷨ
//		//index = 1;
//		//while(strcmp(base[(index + num) % MAX_SIZE].key,"\0")!=0)
//		//{
//		//	index++;
//		//}
//
//		//ƽ��̽�ⷨ
//		//index = 1;
//		//while (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		//{
//		//	if (index > 0)
//		//		index = -index;
//		//	else if (index < 0)
//		//		index=(index-1)*(index-1);
//		//}
//
//		//������
//			flag = true;
//			a->next = base[num + index].next;
//			base[num + index].next = a;
//			
//	}
//
//	//��������̽�ⷨ��ƽ��̽�ⷨʱ�Ĳ���������Լ���ʹ��������ʱδ������ͻʱҪ���еĲ�����
//	//�������������ʱ�Ѿ�������ͻ�ˣ���ô�����������Ѿ���ɣ���Щ���費������
//	if (!flag)
//	{
//		Node b;
//		strcpy(b.key, a->key);
//		b.data = a->data;
//		b.next = NULL;
//		base[abs((index + num) % MAX_SIZE)] = b;
//	}
//}
//void Hash1(Node*& base, Node* a)//������
//{
//	int index = 0;
//	bool flag = false;
//	int num = ((a->key[1] - '0' + (a->key[2] - '0') * 10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //���������ͻ
//	{
//		//index = 1;
//		//����̽�ⷨ
//		//while(strcmp(base[(index + num) % MAX_SIZE].key,"\0")!=0)
//		//{
//		//	index++;
//		//}
//
//		//ƽ��̽�ⷨ
//		index = 1;
//		while (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		{
//			if (index > 0)
//				index = -index;
//			else if (index < 0)
//				index = (index - 1) * (index - 1);
//		}
//
//		//������
//			//flag = true;
//			//a->next = base[num + index].next;
//			//base[num + index].next = a;
//
//	}
//
//	//��������̽�ⷨ��ƽ��̽�ⷨʱ�Ĳ���������Լ���ʹ��������ʱδ������ͻʱҪ���еĲ�����
//	//�������������ʱ�Ѿ�������ͻ�ˣ���ô�����������Ѿ���ɣ���Щ���費������
//	if (!flag)
//	{
//		Node b;
//		strcpy(b.key, a->key);
//		b.data = a->data;
//		b.next = NULL;
//		base[abs((index + num) % MAX_SIZE)] = b;
//	}
//}
//void Hash2(Node*& base, Node* a)//������
//{
//	int index = 0;
//	bool flag = false;
//	int num = ((a->key[2] - '0' + (a->key[3] - '0') * 10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //���������ͻ
//	{
//		//index = 1;
//		//����̽�ⷨ
//		//while(strcmp(base[(index + num) % MAX_SIZE].key,"\0")!=0)
//		//{
//		//	index++;
//		//}
//
//		//ƽ��̽�ⷨ
//		//index = 1;
//		//while (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		//{
//		//	if (index > 0)
//		//		index = -index;
//		//	else if (index < 0)
//		//		index = (index - 1) * (index - 1);
//		//}
//
//		//������
//			//flag = true;
//			//a->next = base[num + index].next;
//			//base[num + index].next = a;
//
//	}
//
//	//��������̽�ⷨ��ƽ��̽�ⷨʱ�Ĳ���������Լ���ʹ��������ʱδ������ͻʱҪ���еĲ�����
//	//�������������ʱ�Ѿ�������ͻ�ˣ���ô�����������Ѿ���ɣ���Щ���費������
//	if (!flag)
//	{
//		Node b;
//		strcpy(b.key, a->key);
//		b.data = a->data;
//		b.next = NULL;
//		base[abs((index + num) % MAX_SIZE)] = b;
//	}
//}
//int cut = 0;
//void HashSearch(Node*& base, char* a)//������
//{
//	cut++;
//	int index = 0;
//	bool flag = false;
//	int num = ((a[0] - '0' + (a[1] - '0') * 10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, a) != 0&&strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //�����һ���ҵ��Ĳ��ǣ������ҵ��Ĳ��ǿյ�
//	{
//		
//		//����̽�ⷨ
//		//index = 1;
//		//while(strcmp(base[(index + num) % MAX_SIZE].key, a) != 0&&strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0)
//		//{
//		//	cut++;
//		//	index++;
//		//}
//
//		//ƽ��̽�ⷨ
//		// index = 1;
//		//while (strcmp(base[abs((index + num) % MAX_SIZE)].key, a) != 0&&strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		//{
//		// cut++;
//		//	if (index > 0)
//		//		index = -index;
//		//	else if (index < 0)
//		//		index = (index - 1) * (index - 1);
//		//}
//
//		//������
//		flag = true;
//		Node* tmp = base[(index + num) % MAX_SIZE].next;
//		int cnt = 1;	
//		while (tmp != NULL && strcmp(tmp->key, a) != 0)//��tmp�ǿղ��һ�û�ҵ�
//		{
//		  cut++;
//			cnt++;
//			tmp = tmp->next;
//		}
//		if (tmp != NULL)
//		{
//			printf("���ҵ�Ԫ���±���%d����%d������,������Ϣ:\n%s %s %s", (index + num) % MAX_SIZE, cnt,tmp->key, tmp->data.name, tmp->data.home);
//		}
//		else {
//			printf("δ�ҵ�");
//		}
//
//	}
//
//	//��������̽�ⷨ��ƽ��̽�ⷨʱ�Ĳ���������Լ���ʹ��������ʱδ������ͻʱҪ���еĲ�����
//	//�������������ʱ�Ѿ�������ͻ�ˣ���ô�����������Ѿ���ɣ���Щ���費������
//	if (!flag)
//	{
//		if (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") == 0)//����ҵ��յ��ˣ�˵��û�ҵ�
//			printf("δ�ҵ�");
//		else
//		{
//			int tmp = abs((index + num) % MAX_SIZE);
//			printf("����Ԫ���±���%d,������Ϣ:\n%s %s %s", tmp,base[tmp].key,base[tmp].data.name,base[tmp].data.home);
//		}
//	}
//}
///*
//20
//13485975436 ���ɴ� jsaidjonsondosdffgffgdg
//15798453247 ������ xzieuikxomomdoajwer
//14325698645 ����ķ jia9uwwukqwoekqj
//18534267989 ������ asdqwjnmncdopowqkeopqwke
//14256787412 ��ɽ�� cnoioioewjriewjroiwemdad
//15256568743 ������ ceiooajeqwepxmaoqwqwo
//15478523467 �µҿ� ojoewjnjsdjpkoiowioioe
//15547223687 ������ csjdisfeuwhcsiofsdf
//12345789651 ûд�� aksjdijdiqowqwjdq
//14879532164 ˫���� asidiu0qqopkepqkpkq
//14525798462 �ļ��� cxcajdqwpdqwdpoqwkdpoq
//12468792548 �Ӵ��� asddsjhheiwheiorwoeir
//11234678952 �ǶȽ� jjewopropieorkwerkewnk
//12468725982 û��˵ cjpjefjejfweopewoelfm
//17425484223 �쪶� oijweirweirweoklkslfsf
//18452142589 ������ qweoqjwedsfjewrewroewpr
//15259595953 ����� kjodfjopdifopweihehfs
//12549897295 ʷ���� jierjioewjriewnroewn
//15489777856 ������ skokowepirnwejnlkwekmlwe
//12348978719 ���ռ� okofewewrwerm,m,sd.mfdsklfjdsf
//
//*/
//Node* create()
//{
//	Node* base = (Node*)malloc(sizeof(Node) * MAX_SIZE);
//	if (base == NULL)
//		exit(0);
//	for (int i = 0; i < MAX_SIZE; i++)
//	{
//		base[i].next = NULL;
//		strcpy(base[i].key, "\0");
//	}
//	return base;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	Node* base = create();
//	for (int i = 0; i < n; i++)
//	{
//		Node* a = (Node*)malloc(sizeof(Node));
//		if (a == NULL)exit(0);
//		a->next = NULL;
//		strcpy(a->key, "\0");
//		scanf("%s %s %s", a->key, a->data.name, a->data.home);
//		Hash(base, a);
//	}
//	scanf("%d", &n); //��������
//	for (int i = 0; i < n; i++)
//	{
//		char a[15];
//		scanf("%s", a);
//		HashSearch(base, a);
//		puts("");
//	}
//	printf("\n%lf", (double)cut / 25);
//	return 0;
//}
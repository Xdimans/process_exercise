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
//void Hash(Node*& base, Node* a)//余数法
//{
//	int index = 0;
//	bool flag = false;
//	int num = ((a->key[0]-'0'+(a->key[1]-'0')*10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //如果产生冲突
//	{
//		//线性探测法
//		//index = 1;
//		//while(strcmp(base[(index + num) % MAX_SIZE].key,"\0")!=0)
//		//{
//		//	index++;
//		//}
//
//		//平方探测法
//		//index = 1;
//		//while (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		//{
//		//	if (index > 0)
//		//		index = -index;
//		//	else if (index < 0)
//		//		index=(index-1)*(index-1);
//		//}
//
//		//拉链法
//			flag = true;
//			a->next = base[num + index].next;
//			base[num + index].next = a;
//			
//	}
//
//	//采用线性探测法、平方探测法时的插入操作。以及在使用拉链法时未产生冲突时要进行的操作。
//	//但是如果拉链法时已经产生冲突了，那么处理在上面已经完成，这些步骤不用做。
//	if (!flag)
//	{
//		Node b;
//		strcpy(b.key, a->key);
//		b.data = a->data;
//		b.next = NULL;
//		base[abs((index + num) % MAX_SIZE)] = b;
//	}
//}
//void Hash1(Node*& base, Node* a)//余数法
//{
//	int index = 0;
//	bool flag = false;
//	int num = ((a->key[1] - '0' + (a->key[2] - '0') * 10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //如果产生冲突
//	{
//		//index = 1;
//		//线性探测法
//		//while(strcmp(base[(index + num) % MAX_SIZE].key,"\0")!=0)
//		//{
//		//	index++;
//		//}
//
//		//平方探测法
//		index = 1;
//		while (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		{
//			if (index > 0)
//				index = -index;
//			else if (index < 0)
//				index = (index - 1) * (index - 1);
//		}
//
//		//拉链法
//			//flag = true;
//			//a->next = base[num + index].next;
//			//base[num + index].next = a;
//
//	}
//
//	//采用线性探测法、平方探测法时的插入操作。以及在使用拉链法时未产生冲突时要进行的操作。
//	//但是如果拉链法时已经产生冲突了，那么处理在上面已经完成，这些步骤不用做。
//	if (!flag)
//	{
//		Node b;
//		strcpy(b.key, a->key);
//		b.data = a->data;
//		b.next = NULL;
//		base[abs((index + num) % MAX_SIZE)] = b;
//	}
//}
//void Hash2(Node*& base, Node* a)//余数法
//{
//	int index = 0;
//	bool flag = false;
//	int num = ((a->key[2] - '0' + (a->key[3] - '0') * 10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //如果产生冲突
//	{
//		//index = 1;
//		//线性探测法
//		//while(strcmp(base[(index + num) % MAX_SIZE].key,"\0")!=0)
//		//{
//		//	index++;
//		//}
//
//		//平方探测法
//		//index = 1;
//		//while (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") != 0)
//		//{
//		//	if (index > 0)
//		//		index = -index;
//		//	else if (index < 0)
//		//		index = (index - 1) * (index - 1);
//		//}
//
//		//拉链法
//			//flag = true;
//			//a->next = base[num + index].next;
//			//base[num + index].next = a;
//
//	}
//
//	//采用线性探测法、平方探测法时的插入操作。以及在使用拉链法时未产生冲突时要进行的操作。
//	//但是如果拉链法时已经产生冲突了，那么处理在上面已经完成，这些步骤不用做。
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
//void HashSearch(Node*& base, char* a)//余数法
//{
//	cut++;
//	int index = 0;
//	bool flag = false;
//	int num = ((a[0] - '0' + (a[1] - '0') * 10) % 100) % MAX_SIZE;
//	if (strcmp(base[(index + num) % MAX_SIZE].key, a) != 0&&strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0) //如果第一下找到的不是，并且找到的不是空的
//	{
//		
//		//线性探测法
//		//index = 1;
//		//while(strcmp(base[(index + num) % MAX_SIZE].key, a) != 0&&strcmp(base[(index + num) % MAX_SIZE].key, "\0") != 0)
//		//{
//		//	cut++;
//		//	index++;
//		//}
//
//		//平方探测法
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
//		//拉链法
//		flag = true;
//		Node* tmp = base[(index + num) % MAX_SIZE].next;
//		int cnt = 1;	
//		while (tmp != NULL && strcmp(tmp->key, a) != 0)//当tmp非空并且还没找到
//		{
//		  cut++;
//			cnt++;
//			tmp = tmp->next;
//		}
//		if (tmp != NULL)
//		{
//			printf("所找的元素下标是%d，第%d个孩子,具体信息:\n%s %s %s", (index + num) % MAX_SIZE, cnt,tmp->key, tmp->data.name, tmp->data.home);
//		}
//		else {
//			printf("未找到");
//		}
//
//	}
//
//	//采用线性探测法、平方探测法时的插入操作。以及在使用拉链法时未产生冲突时要进行的操作。
//	//但是如果拉链法时已经产生冲突了，那么处理在上面已经完成，这些步骤不用做。
//	if (!flag)
//	{
//		if (strcmp(base[abs((index + num) % MAX_SIZE)].key, "\0") == 0)//如果找到空的了，说明没找到
//			printf("未找到");
//		else
//		{
//			int tmp = abs((index + num) % MAX_SIZE);
//			printf("所找元素下标是%d,具体信息:\n%s %s %s", tmp,base[tmp].key,base[tmp].data.name,base[tmp].data.home);
//		}
//	}
//}
///*
//20
//13485975436 阿松大 jsaidjonsondosdffgffgdg
//15798453247 撒旦吉 xzieuikxomomdoajwer
//14325698645 萨达姆 jia9uwwukqwoekqj
//18534267989 富春江 asdqwjnmncdopowqkeopqwke
//14256787412 鸟山明 cnoioioewjriewjroiwemdad
//15256568743 二甲醚 ceiooajeqwepxmaoqwqwo
//15478523467 陈狄克 ojoewjnjsdjpkoiowioioe
//15547223687 三叠纪 csjdisfeuwhcsiofsdf
//12345789651 没写呢 aksjdijdiqowqwjdq
//14879532164 双极型 asidiu0qqopkepqkpkq
//14525798462 文件下 cxcajdqwpdqwdpoqwkdpoq
//12468792548 加大那 asddsjhheiwheiorwoeir
//11234678952 角度讲 jjewopropieorkwerkewnk
//12468725982 没我说 cjpjefjejfweopewoelfm
//17425484223 飒飒都 oijweirweirweoklkslfsf
//18452142589 哈瓦那 qweoqjwedsfjewrewroewpr
//15259595953 随机数 kjodfjopdifopweihehfs
//12549897295 史蒂文 jierjioewjriewnroewn
//15489777856 第三方 skokowepirnwejnlkwekmlwe
//12348978719 额日记 okofewewrwerm,m,sd.mfdsklfjdsf
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
//	scanf("%d", &n); //搜索次数
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
//单击数字键 1 为 按姓名排序 
//单击数字键 2 为 按学号排序
//单击数字键 3 为 按房号排序
//单击数字键 4 为 按姓名查找
//单击数字键 5 为 按学号查找
//单击数字键 6 为 按房号查找
//单击数字键 7 为 按学号插入 
//单击数字键 8 为 按学号删除
//当输入数字键 0 时，退出操作
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define N 40 //线性表存储空间的初始分配量
#define increase 10 //线性表存储空间的分配量增量

int f , t = 0; //定义全局变量
typedef struct
{
	char name[20];
	int num ;
	int room;
	
 }stu;
 stu stud;
 
typedef struct
{
	int lenth;// 当前长度
	stu *elem; //存储空间基址
	int listsize;//当前分配的存储容量
	 
 } linklist;
 void init(linklist & l)//线性表初始化
 {
 	l.lenth = 0;
 	l.elem = (stu*)malloc(N*sizeof (stu));
 	l.listsize = N;
	   } 
 void menu()//操作菜单
 {
 	printf ("\n");
 	printf (" *************** 请 按 键 选 择 操 作****************\n");
 	printf ("\n");printf("\n"); printf (" 1 按姓名排序 2 按学号排序\n"); 
	printf ("\n"); printf (" 3 按房号排序 4 按姓名查找\n"); 
	printf ("\n"); printf (" 5 按学号查找 6 按房号查找\n"); 
	printf ("\n"); printf (" 7 按学号插入 8 按学号删除\n"); 
	printf ("\n"); 
	printf ("\n"); 
	printf ("\n"); 
	printf ("\n");
	printf ("提示：输入 0 退出系统");
	if (t == 1)
	{
		printf ("请输入数字键 1~8 ：");
		scanf ("%d",&f);
		if (f<0 || f> 9)
		{
			system ("cls");
			printf ("\n");
			printf ("输入的数字不对，请在原处重输");
			printf ("\n");
			menu(); 
		}
	 } 
  } 
 void disp()//返回主界面
 {
 	char c;
 	fflush (stdin);//清除读写缓冲区
 	printf ("\n");
 	printf ("请输入任意键进入主界面：");
 	scanf ("%c",&c);
 	system ("cls");
 	
  } 
 void panduan3()//如果已无学生记录则返回主界面
 {
 	printf ("\n");
 	printf ("已无学生记录\n");
 	printf ("\n");
 	disp();
 	menu();
 	
  } 
 void shuru(linklist l )//输入学生信息
 {
 	printf ("请输入学生姓名：");
 	fflush(stdin); //清除数据缓冲区，得到正确的学生信息数据
	gets (stud.name); //输入一行字符串（姓名）
	printf ("请输入学号：");
	scanf ("%d",&stud.num);
	printf ("请输入房号：");
	scanf ("%d",&stud.room); 
  } 
 void create (linklist &l) //创建学生信息表
 {
 	if (l.lenth >= l.listsize)//判断学生的人数是否超过初始值（N），如果超过，则重新分配
	{
	 	stu *newbase;
	 	newbase = (stu*)realloc(l.elem,(N+increase)*sizeof(stu));
		l.elem = newbase;
		l.listsize += increase ;   
	  } 
	  int i = 2;
	  char ch;
	  printf ("\n");
	  printf ( " ************************** 开 始 创 建***************************\n" ) ;
	  printf ("\n");
	  printf ("请输入第一个学生的信息\n");
	  shuru (l); //调用输入函数
	  ch = getchar();
	  strcpy(l.elem[l.lenth].name,stud.name);
	  l.elem[l.lenth].num = stud.num;
	  l.elem[l.lenth].room = stud.room;
	  l.lenth++;
	  printf("\n");
	  printf("是否继续输入？(请输入y 或者 n):");
	  scanf ("%c",&ch);
	  printf ("\n");
	  printf ("\n");
	  while (ch == 'y')
	  {
	  	printf ("请输入第%d个学生的信息：\n",i);
	  	shuru (l);
	  	strcpy(l.elem[l.lenth].name,stud.name);
	  	l.elem[l.lenth].num = stud.num;
	  	l.elem[l.lenth].room = stud.room;
	  	l.lenth++;
	  	i++;
	  	ch = getchar();
		printf ("\n");
		printf ("是否继续输入？y or n");
		scanf ("%c",&ch);
		printf ("\n") ;
		printf ("\n") ;
		
		   }
	  if(ch == 'n')
	  {
	  	system ("cls");
	  }
	  
  } 
 void sort3 (linklist & l)//按房间号排序（冒泡） 
 {
 	int i,j;
 	stu temp;
 	for (i = 0;i<l.lenth-1;i++)
 		for (j<i+1;j<l.lenth;j++)
 		if(l.elem[i].room>l.elem[j].room)
 		{
 			temp = l.elem[i];
 			l.elem[i] = l.elem[j];
 			l.elem[j] = temp;
		 }
  } 
 
 void sort2 (linklist & l)//按学号排序 （冒泡）
 {
 	int i,j;
 	stu temp;
	for (i = 0;i<l.lenth-1;i++)
 		for (j<i+1;j<l.lenth;j++)
 		if(l.elem[i].num>l.elem[j].num)
 		{
 			temp = l.elem[i];
 			l.elem[i] = l.elem[j];
 			l.elem[j] = temp;
		 } 
		 
 } 
 void sort1 (linklist & l)//按姓名排序 （冒泡）
 {
 	int i,j;
 	stu temp;
	for (i = 0;i<l.lenth-1;i++)
 		for (j<i+1;j<l.lenth;j++)
 		if(strcmp(l.elem[i].name,l.elem[j].name)>0)
 		{
 			temp = l.elem[i];
 			l.elem[i] = l.elem[j];
 			l.elem[j] = temp;
		 } 
		 
 } 
 void print1(linklist & l)//打印学生信息
 {
 	int i ;
 	printf ("\n");
	printf ( "姓名 学号 房号\n" ); 
	printf ("\n");
	for (i = 0; i<l.lenth;i++)
	{
		printf ("%-15s    %-3d    %-5d\n",l.elem[i].name,l.elem[i].num,l.elem[i].room);
		
	 } 
	
}
 void print2(linklist & l,int mid)//打印查找到的学生的信息
 {
 	printf ("查找成功---->该生信息为\n");
 	printf ( "姓名 学号 房号\n" ); 
	printf ( "\n" ); 
	printf ("%-15s %-5d %-5d\n", l.elem[mid].name, l.elem[mid].num, l.elem[mid].room ); 
	
	}	   
 int panduan1 (char ch)//判断是否继续查找 
 {
 	//scanf ("%c",&ch);
 	printf ("是否继续查找 y or n:");
 	fflush (stdin);
 	scanf ("%c",&ch);
 	if (ch == 'y')
 	{
 		system ("cls");
 		return (1);
 		
	 }
	 else 
	  return 0;
	}   
 int panduan2 (char ch) //如果学生不存在，判断是否继续查找
 {
 	scanf ("%c",&ch);
 	printf ("该生不存在，是否继续查找 y or n：");
 	fflush (stdin);
 	scanf ("%c",&ch);
 	if (ch == 'y')
 	{
 		system ("cls");
 		return (1);
	 }
	 else 
	 	return 0;
  } 
 void chazhao3 (linklist & l)//使用二分法查找
 {
 	if(l.lenth == 0) panduan3();//如果没有，就返回主界面
	 else 
	 {
	 	int low = 0 , high = l.lenth, mid , flag = 0;//flag作为标志符，flag为1代表查找成功，0代表失败;
		int m;
		char ch;
		printf ("\n"); 
		printf ("\n"); 
		pritnf ("按房号查找-->请输入要查找的房号:");
		scanf ("%d",&m);
		printf ("\n");
		while (low <= high)
		{
	 		mid =( low + high ) / 2;
			if (m == l.elem[mid].room)
			{
				flag = 1;
				break;
			 } 
			 else if (m>l.elem[mid].room)
			 	low = mid + 1;
		     else
				high = mid - 1;
					
	  	} 
	  	   if (flag == 1 )
	  	   {
	  	   	print2 (l,mid);
	  	   	if (panduan1 (ch))//调用判断函数1
				 chazhao3(l);
			else 
			{
				system ("cls");
				menu ();
				
			 } 
				 
		    }
		    else 
		    {
		    	if(panduan2())//调用判断函数2
				  chazhao3(l);
				else
				{
					system("cls");
					menu();
					
				 } 
			}
		    
	}	
}
 void chazhao2(linklist & l)//按学号查找
 {
 	if (l.lenth == 0)panduan3();
 	else
 	{
 		int low = 0 ,high = l.lenth , mid , flag = 0;
 		int n;
 		char ch ;
 		printf ("\n");
 		printf ("\n");
 		printf ("按学号查找 --> 请输入学号：");
 		scanf ("%d",&n);
 		printf ("\n");
 		while ( low <= high )
		 {
 			mid = ( low + high ) / 2;
 			if (n == l.elem[mid].num)
 			{
 				flag = 1;
 				break;
			 }
			 else
			 	if (n>l.elem[mid].num)
			 		low = mid + 1 ;
			 	else
			 		high = mid -1 ;
		 }
		 if ( flag == 1 )
		 {
		 	print2 (l,mid);
		 	if ( puanduan1(ch) )
		 	chazhao2(l);
		  	else{
		  		system ("cls");
		  		menu();
			    }
		 }
		  
		 else 
		  {
		  	if(panduan2(ch)) chazhao2(l);
		  	else
		  	{
		  		system ("cls");
		  		menu();
			  }
		  }
			  	
	 }
 } 
 void chazhao1 (linklist & l)//按照姓名查找
 {
 	if ( l.lenth == 0 ) panduan3();
 	else
 	{
 		int low = 0 , high = l.lenth , mid , flag = 0;
 		printf ("\n");
 		printf ("\n");
 		printf ("按姓名查找 --> 请输入学生姓名：");
 		char a[15] , ch ;
 		scanf ("%s",a);
 		printf ("\n");
 		while ( low <= high )
 		{
 			mid = ( low + hihg ) / 2;
 			if (strcmp(a,l.elem[mid].name) == 0 )
 			{
 				flag = 1;
 				break;
			 }
			else
				if(strcmp(a,elem[mid].name)>0)
					low = mid + 1;
				else
					high = mid - 1;
		 }
		 if (flag == 1)
		 {
		 	print2(l,mid) //打印找到的学生的信息
			if(panduan1(ch) )	chazhao1(l);
			else
			{
				system ("cls");
				menu();
				
			  }  
		 }
		 else
		 {
		 
		 	if(panduan2(ch))	chazhao1(l);
		 	else
		 	{
		 		system ("cls");
		 		menu();
		 		
			 }
		}
	 }
  } 
 void insert (linklist & l)//按学号从小到大插入学生信息
 {
 	int i,j,k;
 	char ch;
 	printf ("\n");
 	printf ("插入的学生信息为：\n");
 	pritnf ("姓名：");
	fflush(stdin);//清空缓存区,得到正确的输入数据
	gets(stud.name);
	printf ("学号：");
	scanf ("%d",&stud.num);
	printf ("房号：");
	scanf ("%d",&stud.room);
	if (l.lenth == 0)
	{
		strcpy(l.elem[l.lenth].name,stud.name);
		l.elem[l.lenth].num = stud.num;
		l.elem[l.lenth].room = stud.room;
		
 	}
	for( i = 0 ; i < l.lenthl; i++ )
	{
		if(stud.num < l.elem[i].num)
		{
			k = i ;
			for ( j = l.lenth ; j > k; j--)
			l.elem[j] = l.elem[j-1];
			strcpy(l.elem[k].name, stud.name);
			l.elem[k].num = stud.num;
			l.elem[k].room = stud.room;
			break;
		}
		else
		{
			strcpy(l.elem[l.lenth].name,stud.name);
			l.elem[l.lenth].num = stud.num;
			l.elem[l.lenth].room = stud.room;
			
		}
	}
	l.lenth++ ;
	fflush (stdin);
	printf ("\n");
	printf ("是否继续插入 y or n");
	scanf ("%c",&ch);
	if(ch == 'y')
		insert (l);
	else
		system ("cls");
}   
 void Delete (linklist & l)//按学号删除 
 {
 	int i,j,k = -1;
 	char ch ;
 	printf ("\n"); 	
 	printf ("\n"); 	
 	printf ("请输入要删除的学生的学号：");
 	scanf ("%d",&stud.num);
 	for (i = 0;i<l.lenth;i++)
 	{
 		if(stud.num == l.elem[i].num)
 		{
 			printf ("该学生信息为：\n"); printf ("\n");
 			printf("%-15s %-3d %7d\n",l.elem[i].name,l.elem[i].num,l.elem[i].room); 
			k=i; 
			for(j=k;j<l.length-1;j++) 
				l.elem[j]=l.elem[j+1]; 
			printf("\n"); 
			break; 
		 }
	 }
	 if (i > l.lenth)	printf ("该生不存在\n");
	 if (k >= 0) l.lenth--;
	 fflush(stdind);
	 printf ("\n");
	 printf ("是否继续？y or n");
	 scanf ("%c",&ch);
	 system ("cls");
	 if(ch == 'y') Delete(l);
	 else system("cls");
 	
  } 
  void main() //主函数
{ 
	linklist l; //定义线性表 l init(l); //调用初始化函数
	char ch; 
	system("color a"); 
	printf("\n"); printf(" ************************* 欢 迎 进 入 宿 舍 管 理 查 询 系 统*************************\n"); 
	printf("\n"); printf("请按任意键开始操作 :"); 
	scanf("%c", &ch); system("cls");//将屏幕先前显示的内容清理掉 create(l); //调用线性表创建函数
	system("cls"); 
	t=1; menu();  //调用主菜单函数
	while(f!=0) 
	{ 
	 system("cls"); 
	 switch(f) 
	{ 
	case 1: sort1(l); //调用按姓名排序函数
	printf("\n"); 
	if(l.length==0) 
	{ 
		printf(" 已无学生记录 \n"); 
		printf("\n"); 
		disp(); 
		menu(); 
	} 
	else 
	{ 
		printf(" 按姓名排序 :\n"); 
		print1(l);
		disp(); //调用返回主界面
		menu(); 
	} 
	break; 
	case 2: sort2(l); //调用按学号排序函数
	printf("\n"); 
	if(l.length==0) 
	{ 
		printf(" 已无学生记录 \n"); 
		printf("\n"); 
		disp(); 
		menu(); 
	} 
	else 
	{ 
		printf(" 按学号排序 :\n"); 
		print1(l); 
		disp(); 
		menu(); 
	}break; 
	case 3: sort3(l); //调用按房号排序函数
	printf("\n"); 
	if(l.length==0) 
	{ 
		printf(" 已无学生记录 \n"); 
		printf("\n"); 
		disp(); 
		menu(); 
	} 
	else 
	{ 
		printf(" 按房号排序 :\n"); 
		print1(l); 
		disp(); 
		menu(); 
	}break; 
	case 4: sort1(l); //先调用按姓名排序函数进行排序 chazhao1(l); //再调用按姓名查找函数进行（二分）查找
	break; 
	case 5: sort2(l); //先调用按学号排序函数进行排序 chazhao2(l); //再调用按学号查找函数进行（二分）查找
	break; 
	case 6: sort3(l); //先调用按房号排序函数进行排序 chazhao3(l); //再调用按房号查找函数进行（二分）查找
	break; 
	case 7: sort2(l); //调用插入函数
	insert(l); 
	system("cls"); printf(" 显示插入后的学生信息 :\n");print1(l); 
	disp(); 
	menu(); 
	break; 
	case 8: Delete(l); //调用删除函数
	if(l.length==0) 
	{ 
		printf("\n"); 
		printf(" 学生记录已被删除完 \n"); 
		printf("\n"); 
		disp(); 
		menu(); 
	} 
	else 
	{ 
		printf(" 显示删除后的学生信息 :\n"); 
		print1(l); 
		disp(); 
		menu(); 
	}break; 
   } 
 } 
} 
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   

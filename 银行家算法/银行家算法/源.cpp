#include<iostream>
using namespace std;
#define ture 1
#define false 0
#define max_hang 100
#define max_lie 100
int sum[max_hang][max_lie];
int p[max_hang];
int total[max_lie];
int Max[max_hang][max_lie];
int Allocation[max_hang][max_lie];
int Need[max_hang][max_lie];
int table[max_hang];
int Available[max_lie]={0};
int requst[max_hang][max_lie];
int work[max_hang][max_lie];
int finish[max_hang];
int request[max_hang][max_lie];
int a=0;//进程总个数
int b=0;//资源总个数
int ifcout=0;  

void shezhi()
{
	cout<<"请输入你的进程总个数"<<endl;
	cin>>a;
	cout<<"请输入你的资源总类书"<<endl;
	cin>>b;
	cout<<"请输入资源总数目"<<endl;
	for(int i=0;i<b;i++)
	{
		cin>>total[i];
	}
	cout<<"请输入哥哥进程的总个数"<<endl;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			cin>>Max[i][j];
		}
	}
	cout<<"请输入每个进程已经分配的各类资源数目"<<endl;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			cin>>Allocation[i][j];
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}
	for(int i=0;i<b;i++)
	{
		int sum=0;
		for(int j=0;j<a;j++)
		{
			sum+=Allocation[j][i];
		}
		table[i]+=sum;
	}
	for (int i = 0; i < b; i++){
		Available[i]=total[i]-table[i];
	}
	cout<<"进程名              Max                 Allocation              Need            Available"<<endl;
	cout<<endl;
	for (int i = 0; i < a; i++){
		cout<< i;
		cout<<"                  ";
		for (int j = 0; j < b; j++){
			cout<<Max[i][j];
		}
		cout<<"                 ";
		for (int j = 0; j < b; j++){
			cout<<Allocation[i][j];
		}
		cout<<("              ");
		for (int k = 0; k < b; k++){
			cout<<Need[i][k];
		}
		if (i == 0){
			cout<<("              ");
			for (int k = 0; k < b; k++){
				cout<<Available[k];
			}
		}
		cout<<endl;
	}
}


//void MY_cout()
//{
//	cout<<"进程名            Work                Allocation              Need            Available  "<<endl;
//	for (int i = 0; i < ifcout; i++){
//			cout<<p[i];
//			cout<<"                  ";
//			for (int j = 0; j < b; j++){
//				cout<<sum[p[i]][j];
//			}
//			cout<<                 ");
//			for (int j = 0; j < b; j++){
//				cout<<%d ", Allocation[p[i]][j]);
//			}
//			cout<<              ");
//			for (int k = 0; k < b; k++){
//				cout<<%d ", Need[p[i]][k]);
//			}
//			if (i == 0){
//				cout<<              ");
//				for (int k = 0; k < b; k++){
//					cout<<%d ", Available[k]);
//				}
//			}
//			cout<<\n");
//		}
//
//}



void print(){
		printf("进程名            Work                Allocation              Need            Available  ");
		printf("\n");
		for (int i = 0; i < a; i++){
			cout<<p[i];
			cout<<"                  ";
			for (int j = 0; j < b; j++){
				cout<<sum[p[i]][j];
			}
			cout<<"                 ";
			for (int j = 0; j < b; j++){
				cout<< Allocation[p[i]][j];
			}
			cout<<"              ";
			for (int k = 0; k < b; k++){
				cout<< Need[p[i]][k];
			}
			if (i == 0){
				cout<<"              ";
				for (int k = 0; k < b; k++){
					cout<< Available[k];
				}
			}
			cout<<endl;
		}
	}



//工作数组初始化
int aqx(){
{
	for(int m= 0;m<a;m++){
		p[m]=999;

	}
	int i,j,k,l=0;
	int h=1;
	int work[max_lie];
	int finish[max_hang];

	for(i=0;i<b;i++)
	
	{
		work[i]=Available[i];
		sum[0][i]=work[i];
	}

	for( i=0;i<a;i++)
	{
		finish[i]=0;
	}
	for(i=0;i<a;i++)
	{
		if(finish[i]) continue;
		for(j=0;j<b;j++)
		{
			if(Need[i][j]>work[j]) break;
		}
		if(j==b)
		{
			finish[i]=1;

			for(k =0;k<b;k++)
			{
                    work[k]+=Allocation[i][k];
					sum[i][k]=work[k];
			 
		    }

			p[l++]=i;//记录安全序列
			i=-1;
			ifcout=1;
	   }
		else continue;
		if(l==a)
		{
			cout<<"进程是安全的"<<endl;
			cout<<"安全序列为："<<endl;
			for(k=0;k<l-1;k++)
			{
				cout<<p[k]<<"--->";
			}
			cout<<p[l-1]<<endl;
			return ture;
		}
}

	//不安全
	int arr[10];
		for (int z = 0; z < 10; z++){
			arr[z] = 66;
		}
		int z;
		int count = 0;
		for (int x = 0; x < a; x++){
			for (z = 0; z < a; z++){
				if (x == p[z]){
					break;	
				}
			}
			if (z >= a){
				arr[count++] = x;
			}
		}
		cout<<"系统是不安全的，没有完成的进程序列为"<<endl;
		for (int m = 0; m < count; m++){
			cout<<arr[m];
		}
		cout<<endl;
		return false;

}
}



int my_bank()
		{
			int i,num;
			while(1)
			{
				cout<<"请输入要申请的进程号"<<endl;
				cin>>num;
				cout<<"请输入申请该类资源的个数"<<endl;
				for(i=0;i<b;i++)               //课本第一步，判断requst<need;
				{
					cin>>requst[num][i];
					if(requst[num][i]>Need[num][i])
					{
					cout<<"亲，你的请求超过自身最大的需要，非法！！ 请重新输入";
					i--;
					return 0;
					}
                   if(requst[num][i]>Available[i])
				{
				     cout<<"你的请求超过这个系统的总资源，请重新输入!";
					i--;
					return 0;
				}
				
				

				
				//合法继续试着分配
				Available[i]-=requst[num][i];
				Allocation[num][i]+=requst[num][i];
				Need[num][i]-=requst[num][i];
}
				if(aqx())
				{
					cout<<"同意分配需求"<<endl;
					int judgement = 0;
			for (int i = 0; i < b; i++){
				if (Need[num][i] != 0){
					judgement = 1;
					break;
				}
			}
			if (judgement == 0){
				for (int i = 0; i < b; i++){
					Available[i] = sum[num][i];
					Allocation[num][i] = 0;
				}
			}
			return 1;
		}
		else
		{
			cout<<"您的请求被拒绝!"<<endl;
			for (i = 0; i<b; i++)
			{
				Available[i] +=requst[num][i];
				Allocation[num][i] -= requst[num][i];
				Need[num][i] += requst[num][i];
			}
			return 0;




				}
			}
		}


int main()
{






	 system("color 3F");//设置控制台界面背景颜色和前景颜色
	while (ture){
		printf("*----------**********----------*******************\n");
		printf("*----------********1.设置初始资源分配情况----------********\n");
		printf("*----------********2.分配并验证----------********\n");
		printf("*----------********3.验证安全性----------********\n");
		printf("*----------********4.退出----------------*********\n");
		printf("请输入你的请求");
		int choice = 0;
		cin>>choice;
		if (choice == 1){
			shezhi();
		}
		else if (choice == 2){
			int tem = my_bank();
			if (tem){
				print();
			}
		}
		else if (choice == 3){
			aqx();
			print();
		}
		else if (choice == 4){
			break;
		}
		/*else if(choice==5)
		{
			print();
		}*/
	}
	return 0;
}
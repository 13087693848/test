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
int a=0;//�����ܸ���
int b=0;//��Դ�ܸ���
int ifcout=0;  

void shezhi()
{
	cout<<"��������Ľ����ܸ���"<<endl;
	cin>>a;
	cout<<"�����������Դ������"<<endl;
	cin>>b;
	cout<<"��������Դ����Ŀ"<<endl;
	for(int i=0;i<b;i++)
	{
		cin>>total[i];
	}
	cout<<"����������̵��ܸ���"<<endl;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			cin>>Max[i][j];
		}
	}
	cout<<"������ÿ�������Ѿ�����ĸ�����Դ��Ŀ"<<endl;
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
	cout<<"������              Max                 Allocation              Need            Available"<<endl;
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
//	cout<<"������            Work                Allocation              Need            Available  "<<endl;
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
		printf("������            Work                Allocation              Need            Available  ");
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



//���������ʼ��
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

			p[l++]=i;//��¼��ȫ����
			i=-1;
			ifcout=1;
	   }
		else continue;
		if(l==a)
		{
			cout<<"�����ǰ�ȫ��"<<endl;
			cout<<"��ȫ����Ϊ��"<<endl;
			for(k=0;k<l-1;k++)
			{
				cout<<p[k]<<"--->";
			}
			cout<<p[l-1]<<endl;
			return ture;
		}
}

	//����ȫ
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
		cout<<"ϵͳ�ǲ���ȫ�ģ�û����ɵĽ�������Ϊ"<<endl;
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
				cout<<"������Ҫ����Ľ��̺�"<<endl;
				cin>>num;
				cout<<"���������������Դ�ĸ���"<<endl;
				for(i=0;i<b;i++)               //�α���һ�����ж�requst<need;
				{
					cin>>requst[num][i];
					if(requst[num][i]>Need[num][i])
					{
					cout<<"�ף�������󳬹�����������Ҫ���Ƿ����� ����������";
					i--;
					return 0;
					}
                   if(requst[num][i]>Available[i])
				{
				     cout<<"������󳬹����ϵͳ������Դ������������!";
					i--;
					return 0;
				}
				
				

				
				//�Ϸ��������ŷ���
				Available[i]-=requst[num][i];
				Allocation[num][i]+=requst[num][i];
				Need[num][i]-=requst[num][i];
}
				if(aqx())
				{
					cout<<"ͬ���������"<<endl;
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
			cout<<"�������󱻾ܾ�!"<<endl;
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






	 system("color 3F");//���ÿ���̨���汳����ɫ��ǰ����ɫ
	while (ture){
		printf("*----------**********----------*******************\n");
		printf("*----------********1.���ó�ʼ��Դ�������----------********\n");
		printf("*----------********2.���䲢��֤----------********\n");
		printf("*----------********3.��֤��ȫ��----------********\n");
		printf("*----------********4.�˳�----------------*********\n");
		printf("�������������");
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
#include<stdio.h>
#include<stdlib.h>
 
typedef struct TreeNode *HuffmanTree;
typedef struct TreeNode{
	int Weight;  //Ȩֵ
	HuffmanTree Left;
	HuffmanTree Right; 
}HuffmanNode;
 
#define MinData -1  //���Ŷ�Ԫ�صľ���ֵ���ı� 
 
typedef struct HeapStruct *MinHeap;
struct HeapStruct{
	HuffmanTree *data;  //�洢��Ԫ�ص�����  �洢ʱ���±�1��ʼ 
	int Size;  //�ѵĵ�ǰԪ�صĸ���
	int Capacity;  //�ѵ�������� 
};
 
HuffmanTree NewHuffmanNode();
MinHeap CreateMinHeap(int MaxSize);
bool Insert(MinHeap H,HuffmanTree item);
HuffmanTree DeleteMin(MinHeap H);
MinHeap BuildMinHeap(MinHeap H);
HuffmanTree Huffman(MinHeap H);
void PreOrderTraversal(HuffmanTree BST);
 
int main()
{
	int i,N;
	MinHeap h;
	HuffmanTree T,BT = NULL;
	
	printf("������Ҷ�ӽ��ĸ���:\n"); 
	scanf("%d",&N);
	h = CreateMinHeap(2*N);  //������С�� 
	printf("������%d��Ҷ�ӽ���Ӧ��Ȩֵ:\n",N);
	for(i=1; i<=N; i++){/*��С��Ԫ�ظ�ֵ*/ 
		T = NewHuffmanNode();
		scanf("%d",&(T->Weight));
		h->data[++(h->Size)] = T;
	}
	
	BT = Huffman(h);  //����������� 
	printf("��������˹���������Ȩֵ:\n"); 
	PreOrderTraversal(BT);  //��������˹������� 
	
	return 0;
 } 
 
 /*�������������㷨*/
 HuffmanTree Huffman(MinHeap H)
 {/*����H->Size��Ȩֵ�Ѿ�����H->data[]->Weight��*/
 	int i,num;
	HuffmanTree T;
	
	BuildMinHeap( H );  //��H->data[]��Ȩֵ����Ϊ��С��
	/*�˴����뽫H->Size��ֵ����num,��Ϊ������DeleteMin()�� Insert()������ı�H->Size��ֵ*/
	num = H->Size;     
	for(i=1; i<num; i++){  //�� H->Size-1�κϲ�   //�˴��̿��������⣡ԭ��ֱ��ΪH->Size
		T = NewHuffmanNode();  //����һ���µĸ���� 
		T->Left = DeleteMin(H);  //����С����ɾ��һ���ڵ㣬��Ϊ��T�����ӽ��
		T->Right = DeleteMin(H);  //����С����ɾ��һ���ڵ㣬��Ϊ��T�����ӽ�� 
		T->Weight = T->Left->Weight+T->Right->Weight;  //������Ȩֵ 
		//printf("%3d 0x%x 0x%x\n",T->Weight,T->Left,T->Right);
		Insert(H,T);  //����T���뵽��С�� 
	} 
	T = DeleteMin(H);
	
	return T; 
  } 
  
/*****�������*****/ 
void PreOrderTraversal(HuffmanTree BST)
{
	if( BST ){
		printf("%d ",BST->Weight);     //�ȷ��ʸ��ڵ� 
		PreOrderTraversal(BST->Left);  //�ٷ��������� 
		PreOrderTraversal(BST->Right); //������������ 
	}
}
 
HuffmanTree NewHuffmanNode()
{
	HuffmanTree BST = (HuffmanTree)malloc(sizeof(HuffmanNode));
	BST->Weight = 0;
	BST->Left = BST->Right = NULL;
	
	return BST;
 } 
  
MinHeap CreateMinHeap(int MaxSize)
{  /*��������ΪMaxSize����С��*/
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
	H->data = (HuffmanTree *)malloc((MaxSize+1) * sizeof(HuffmanTree));
	H->Size = 0;
	H->Capacity = MaxSize;
	HuffmanTree T = NewHuffmanNode();
	T->Weight = MinData;  /*�����ڱ�-ΪС�ڶ������п���Ԫ��Ȩֵ��ֵ�������Ժ�������*/
	H->data[0] = T;
	
	return H;
}
 
bool  IsFull(MinHeap H)
{
	return (H->Size == H->Capacity);
}
 
bool IsEmpty(MinHeap H)
{
	return (H->Size == 0);
}
 
/*�����㷨-�����������뵽���丸��㵽����������������*/
bool Insert(MinHeap H,HuffmanTree item)
{/*��Ԫ��item���뵽��С��H�У�����H->data[0]�ѱ�����Ϊ�ڱ�*/
	int i;
	if( IsFull(H) ){
		printf("��С������\n");
		return false;
	}
	i = ++H->Size;  //iָ��������е����һ��Ԫ�ص�λ��
	for(; H->data[i/2]->Weight > item->Weight; i/=2)  //���ڱ����������о����� i>1 
	    H->data[i] = H->data[i/2];  //���¹��˽�� 
	H->data[i] = item;   //��item���� 
	
	return true;
 }
 
HuffmanTree DeleteMin(MinHeap H)
{/*����С��H��ȡ��ȨֵΪ��С��Ԫ�أ���ɾ��һ�����*/
	int parent,child;
	HuffmanTree MinItem,temp = NULL;
	if( IsEmpty(H) ){
		printf("��С��Ϊ��\n");
		return NULL;
	}
	MinItem = H->data[1];  //ȡ�������-��С��Ԫ��-��¼����
	/*����С���е����һ��Ԫ�شӸ���㿪ʼ���Ϲ����²���*/
	temp = H->data[H->Size--];  //��С�������һ��Ԫ�أ���ʱ������Ϊ�����˸����
	for(parent=1; parent*2<=H->Size; parent=child){
		child = parent*2;
		if((child != H->Size) && (H->data[child]->Weight > H->data[child+1]->Weight)){/*���Ҷ��ӣ����������Ȩֵ�����Ҷ���*/
			child++; //childָ�����Ҷ����н�С�� 
		}
		if(temp->Weight > H->data[child]->Weight){
			H->data[parent] = H->data[child];  //���Ϲ��˽��-temp���λ�����Ƶ�childλ�� 
		}else{
			break;  //�ҵ��˺��ʵ�λ��
		}
	} 
	H->data[parent] = temp;  //temp��ŵ��˴�
	
	return MinItem; 
}
 
MinHeap BuildMinHeap(MinHeap H)
{/*����������е�H->Size��Ԫ���Ѿ�����H->data[]��*/
 /*��������H->data[]�е�Ԫ�ص�����ʹ������ѵ�������*/ 
	int i,parent,child;
	HuffmanTree temp;
	for(i=H->Size/2;i>0;i--){  //�����һ������㿪ʼ��ֱ������� 
		temp = H->data[i];
		for(parent=i; parent*2<=H->Size; parent=child){
		    /*���¹���*/
			child = parent*2;
		    if((child != H->Size) && (H->data[child]->Weight > H->data[child+1]->Weight)){/*���Ҷ��ӣ����������Ȩֵ�����Ҷ���*/
			    child++; //childָ�����Ҷ����н�С�� 
		    }
		    if(temp->Weight > H->data[child]->Weight){
			    H->data[parent] = H->data[child];  //���Ϲ��˽��-temp���λ�����Ƶ�childλ�� 
		    }else{
			    break;  //�ҵ��˺��ʵ�λ�� 
		    }
	    }/*�����ڲ�forѭ������H->data[i]Ϊ���������ĵ���*/
		
		H->data[parent] = temp;  //temp��ԭH->data[i]����ŵ��˴�  
	} 
	return H; 
}
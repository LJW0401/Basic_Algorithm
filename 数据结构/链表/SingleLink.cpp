#include<stdio.h>
#include<stdlib.h>

typedef struct Data{
	int value;
}DATA;

typedef struct Node{
	struct Data data;
	struct Node* next; 
}NODE;

typedef struct Single_Link{
	struct Node* head;
	struct Node* end;
	long length;
}SingleLink;

/*链表内部基础操作*/
SingleLink LinkCreat();//创建一个空链表
void LinkPrint(SingleLink* link);//打印链表
void LinkAdd(SingleLink* link,DATA data);//在尾部添加数据
void LinkInsert(SingleLink* link,long pos,DATA data);//插入数据
void LinkDelete_Pos(SingleLink* link,long pos);//删除指定位置的数据
void NodeChange(NODE* Node1,NODE* Node2);//交换2个节点的数据
void DataPring(DATA data);//打印数据

/*链表的外部操作*/
void Sort(SingleLink* link);
DATA Find(SingleLink* link,long pos);


int main(){
	SingleLink link=LinkCreat();
	LinkPrint(&link);
	LinkAdd(&link,{3});//LinkPrint(&link);
	LinkAdd(&link,{9});//LinkPrint(&link);
	LinkAdd(&link,{4});//LinkPrint(&link);
	LinkAdd(&link,{0});//LinkPrint(&link);
	LinkAdd(&link,{5});LinkPrint(&link);
	
	LinkInsert(&link,0,{100});//LinkPrint(&link);
	LinkInsert(&link,2,{100});//LinkPrint(&link);
	LinkInsert(&link,100,{100});LinkPrint(&link);
	
	LinkDelete_Pos(&link,100);//LinkPrint(&link);
	LinkDelete_Pos(&link,0);//LinkPrint(&link);
	LinkDelete_Pos(&link,1);LinkPrint(&link);
	
	Sort(&link);LinkPrint(&link);
	DataPring(Find(&link,3));
	return 0;
}

void LinkPrint(SingleLink* link){//打印链表
	if(link->head==NULL){
		printf("空链表\n");return;
	}
	NODE* node=link->head;
	while(node!=NULL){
		printf("%d->",node->data.value);
		node = node->next;
	}
	printf("NULL\n");
}

SingleLink LinkCreat(){//创建一个空链表
	SingleLink link;
	link.head=NULL;
	link.end=link.head;
	link.length=0;
	return link;
}

void LinkAdd(SingleLink* link,DATA data){//在尾部添加数据
	NODE* NewNode=(NODE*) malloc (sizeof(NODE));//创建一个新节点
	NewNode->data=data;
	NewNode->next=NULL;
	if(link->head==NULL){
		link->head=NewNode;
		link->end=link->head;
	}else{
		link->end->next=NewNode;
		link->end=link->end->next;
	}
	link->length++;
}

void LinkInsert(SingleLink* link,long pos,DATA data){//插入数据
	if(pos >= link->length){//超出链表长度时在末尾添加
		LinkAdd(link,data);
		return;
	}
	NODE* NewNode=(NODE*) malloc (sizeof(NODE));
	NewNode->data=data;
	NODE* node=link->head;
	if(pos==0){//在头位置时单独操作
		NewNode->next=link->head;
		link->head=NewNode;
		link->length++;
		return;
	}
	long i=0;
	while(i<pos-1){
		node=node->next;
		i++;
	}//此时node的位置在被插入位置的前方
	NewNode->next=node->next;
	node->next=NewNode;
	link->length++;
}

void LinkDelete_Pos(SingleLink* link,long pos){//删除指定位置的数据
	NODE* p;
	if(pos==0){//在头位置时单独处理
		p=link->head;
		link->head=link->head->next;
		free(p);
		link->length--;
		return;
	}
	if(pos>=link->length){//超出范围时删除最后一个节点
		pos=link->length-1;
	}
	long i=0;
	NODE* node=link->head;
	while(i<pos-1 && node->next!=NULL){
		node=node->next;
		i++;
	}
	p=node->next;
	node->next=node->next->next;
	free(p);
	link->length--;
}

void NodeChange(NODE* Node1,NODE* Node2){
	DATA tmpdata=Node1->data;
	Node1->data=Node2->data;Node2->data=tmpdata;
}

void DataPring(DATA data){
	printf("==========\n");
	printf("%8s\n","value");
	printf("----------\n");
	printf("%8d\n",data.value);
	printf("==========\n");
}

void Sort(SingleLink* link){//排序(升序)
	/*冒泡排序*/
	for(int i=link->length-1;i>0;i--){
		NODE* node=link->head;
		for(int j=0;j<i;j++){
			if(node->data.value>node->next->data.value){
				NodeChange(node,node->next);
			}
			node=node->next;
		}
	}
	
	/*选择排序*/
//	NODE* WaitNode=link->head;
//	while(WaitNode->next!=NULL){
//		NODE* node1=WaitNode;//记录选项
//		NODE* node2=node1->next;//动态变化
//		while(node2!=NULL){
//			if(node1->data.value > node2->data.value){
//				node1=node2;
//			}
//			node2=node2->next;
//		}
//		if(WaitNode!=node1){
//			NodeChange(WaitNode,node1);
//		}
//		WaitNode=WaitNode->next;
//	}
}

DATA Find(SingleLink *link,long pos){//查找
	if (pos>=link->length){
		printf("位置不存在\n");
		DATA data={-1};
		return data;
	}
	long i;
	NODE *node=link->head;
	while(i<pos){
		node=node->next;
		i++;
	}
	return node->data;
}

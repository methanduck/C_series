#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct TreeNode
{
	int weight;
	char symbol;
	struct TreeNode *left_child;
	struct TreeNode *right_child;
	
}TreeNode;

typedef struct
{
	TreeNode *ptree;
	int key;
}element;

typedef struct
{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h)
{
	h->heap_size=0;
}

void insert_min_heap(HeapType *h,element item)
{
	int i;
	i=++(h->heap_size);
	
	while((i!=1)&&(item.key<h->heap[i/2].key))
	{
		h->heap[i]=h->heap[i/2];
		i/=2;
	}
	h->heap[i]=item;
}

element delete_min_heap(HeapType *h)
{
	int parent,child;
	element item,temp;
	item=h->heap[1];
	temp=h->heap[(h->heap_size)--];
	parent=1;
	child=2;
	
	while(child<=h->heap_size)
	{
		if((child<h->heap_size)&&(h->heap[child].key>h->heap[child+1].key))
		child++;
		if(temp.key<=h->heap[child].key)break;
		h->heap[parent]=h->heap[child];
		parent=child;
		child*=2;
	}
	h->heap[parent]=temp;
	return item;	
}

TreeNode *make_tree(TreeNode *left,TreeNode *right)
{
	TreeNode *node=(TreeNode*)malloc(sizeof(TreeNode));
	
	if(node==NULL)
	{
		fprintf(stderr,"메모리 에러\n");
		exit(1);
	}
	node->left_child=left;
	node->right_child=right;
	return node;
}

void destroy_tree(TreeNode *root)
{
	if(root==NULL)return;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	
	free(root);
}

/*void print_tree(TreeNode * p, int n, char* code,HeapType *p2)
{
	if (!(n==p2->heap_size)) 
	{
		n++;    // 트리의 깊이를 표시

		code[n] = '0';    // 트리의 좌측
		print_tree(p->left_child, n, code,p2);

		code[n] = '1';    // 트리의 우측
		print_tree(p->right_child, n, code,p2);

		code[n] = '\0';   // 찌꺼기 제거
			
	}
}*/
TreeNode *search(TreeNode *node, int key,int *arr,int n)
{
	n++;
	if (node == NULL)
	{
		return NULL;
	}
	if (key == node->weight)
	{
		return NULL;
	}
	else if (key < node->weight)
	{
		arr[n] = 0;
		return search(node->left_child, key,arr,n);
	}
	else
	{
		arr[n] = 1;
		return search(node->right_child, key,arr,n);
	}
}
void huffman_tree(int freq[],int n,char sym[])
{
	int code[5] = { NULL };
	int i,a,b;
	TreeNode *node,*x;
	HeapType heap;
	element e,e1,e2;
	
	init(&heap);
	
	for(i=0;i<n;i++)
	{
		
		node=make_tree(NULL,NULL);
		e.key=node->weight=freq[i];
		node->symbol = sym[i];
		e.ptree=node;
		insert_min_heap(&heap,e);

	//	printf("%d\t", e.key);
	//	printf("%c\n", e.ptree->symbol);
	}

	for ( a = 1; a < heap.heap_size+1; a++)
	{
		printf("%d \t", heap.heap[a].ptree->weight);
		printf("%c \n", heap.heap[a].ptree->symbol);
		search(node, heap.heap[a].ptree->weight, code,0);
		for ( b = 0; b < 5; b++)
		{
printf("%d  ", code[b]);
		}
		
	}
	

	
	
for(i=1;i<n;i++)
{		e1=delete_min_heap(&heap);
		e2=delete_min_heap(&heap);
		
		x=make_tree(e1.ptree,e2.ptree);
		e.key=x->weight=e1.key+e2.key;
		e.ptree=x;
		insert_min_heap(&heap,e);
}

e=delete_min_heap(&heap);
destroy_tree(e.ptree);
}
int main(void)
{
	int freq[]={15,12,8,6,4};
	char sym[] = { 'e','t','n','i','s' };
	huffman_tree(freq,5,sym);
}

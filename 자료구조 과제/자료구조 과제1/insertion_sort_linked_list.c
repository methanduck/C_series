#include <stdio.h>


#include <stdlib.h>

#define MAX_ENTRY       
typedef struct node_t {
        int val;
        struct node_t *next;
} node_t;
void print_list(node_t *head)
{
        node_t *tmp;
        tmp = head;
        while(tmp) {
                printf("%d(%p) ", tmp->val, tmp);
                tmp = tmp->next;
        }
        printf("\n");
}
node_t *insert(node_t *head, node_t *prev_tgt, node_t *tgt, node_t *tmp){
        /* �����ؾ� �� ��ġ�� ����Ʈ�� ó���ΰ�? */
        if(head == tgt) {
                /* 5) ó���̶��, key�� next�� head�� ����,
                   ��, ����Ʈ�� ���� �տ� ���� */
                tmp->next = head;
                /* tmp�� ����Ʈ�� ���� �տ� ���ԵǾ����Ƿ�,
                   new_head�� �� */
                return tmp;
        }
        /* �����ؾ� �� ��ġ�� �߰��̶��(tmp�� �߰��̶��)
           tmp ���� ����� next�� tmp�� ��������� �� */
        tmp->next = tgt;
        prev_tgt->next = tmp;
        /* �߰��� ���������Ƿ� head�� ���Ծ��� */
        return head;
}
node_t *insertion_sort(node_t *old_head)
{

        node_t *new_head = old_head;
        node_t *key = old_head;
        node_t *tgt, *tmp;
        node_t *prev_tgt = NULL;

        int round = 0;

        while(key->next != NULL) {
                tgt = new_head;
                /* tgt�� key->next�� �ٸ���,
                   tgt�� ���� key->next�� ������ �۰ų� ���� ������ ��� ���� */
                while(tgt != key->next && tgt->val <= key->next->val) {
                        prev_tgt = tgt;
                        tgt = tgt->next;
                }
                /* key->next�� tgt�� �ٸ��� while���� ����Ǿ��ٴ� ��
                   tgt�� ���� key->next�� ������ ũ�ٴ� �ǹ�
                   ����, tgt �տ� ��������� �� */
                if(key->next != tgt) {
                        tmp = key->next;
                        key->next = key->next->next;
                        new_head = insert(new_head, prev_tgt, tgt, tmp);
                }
                /* key->next�� tgt�� ���ٴ�(�����ٴ�) ��
                   tgt ��ο��� key->next���� ū ���� �����ٴ� �ǹ�
                   ��, ��������� ����� ���ĵǾ��ٴ� �� */
                else {
                        key = key->next;
                }
                printf("[%d] ", ++round);
                print_list(new_head);
        }



        return new_head;
}


int main( )
{
        int i;
        node_t node_list[MAX_ENTRY];
        node_t *head = node_list;
        node_t *prev_node = NULL;
        /* Init */


        for(i=0; i<MAX_ENTRY; i++) 
		{
                node_list[i].val = rand() % MAX_ENTRY;
                if (prev_node)
				{
                        prev_node->next = &node_list[i];
                }
                node_list[i].next = NULL;
                prev_node = &node_list[i];
        }
        printf("���� ��\n");
        print_list(node_list);

        head = insertion_sort(node_list);

        printf("���� ��\n");
        print_list(head);
}

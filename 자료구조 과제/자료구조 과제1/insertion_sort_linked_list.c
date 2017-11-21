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
        /* 삽입해야 할 위치가 리스트의 처음인가? */
        if(head == tgt) {
                /* 5) 처음이라면, key의 next를 head로 변경,
                   즉, 리스트의 제일 앞에 삽입 */
                tmp->next = head;
                /* tmp가 리스트의 제일 앞에 삽입되었으므로,
                   new_head가 됨 */
                return tmp;
        }
        /* 삽입해야 할 위치가 중간이라면(tmp가 중간이라면)
           tmp 이전 노드의 next를 tmp로 변경해줘야 함 */
        tmp->next = tgt;
        prev_tgt->next = tmp;
        /* 중간에 삽입했으므로 head는 변함없음 */
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
                /* tgt가 key->next와 다르고,
                   tgt의 값이 key->next의 값보다 작거나 같은 동안은 계속 진행 */
                while(tgt != key->next && tgt->val <= key->next->val) {
                        prev_tgt = tgt;
                        tgt = tgt->next;
                }
                /* key->next와 tgt가 다른데 while문이 종료되었다는 건
                   tgt의 값이 key->next의 값보다 크다는 의미
                   따라서, tgt 앞에 삽입해줘야 함 */
                if(key->next != tgt) {
                        tmp = key->next;
                        key->next = key->next->next;
                        new_head = insert(new_head, prev_tgt, tgt, tmp);
                }
                /* key->next와 tgt가 같다는(만났다는) 건
                   tgt 경로에서 key->next보다 큰 값은 없었다는 의미
                   즉, 현재까지는 제대로 정렬되었다는 뜻 */
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
        printf("정렬 전\n");
        print_list(node_list);

        head = insertion_sort(node_list);

        printf("정렬 후\n");
        print_list(head);
}

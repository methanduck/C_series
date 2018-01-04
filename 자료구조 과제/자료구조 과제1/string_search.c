#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_NAME_SIZE	10

typedef struct node_t {
	char 			data;
	struct node_t 	*left_child;
	struct node_t	*right_child;
} node_t;
node_t *root;

typedef struct student_t {
	char 	name[10];
	char 	gender;
	int 	age;
} student_t;
/* 	John	M		20
Jo		M		21
Joan	F		20  */
student_t student[] = {
	{ "John", 'M', 20 },
	{ "Jo", 'M', 21 },
	{ "Joan", 'F', 20 }
};

int search_tree(char *key)
{
	printf("%s(): key=%s  ", __func__, key);
	int i;
	char digit;
	node_t *node = root;
	while (*key) {
		for (i = 7; i >= 0; i--) {
			digit = (*key) >> i & 1;
			printf("%d", digit);
			if (digit == 0) {
				if (!node->left_child) {
					printf("\nNot Found:%c(i=%d)\n", *key, i);
					return -1;
				}
				node = node->left_child;
			}
			else {
				if (!node->right_child) {
					printf("\nNot Found:%c(i=%d)\n", *key, i);
					return -1;
				}
				node = node->right_child;
			}

		}
		key++;
	}
	printf("\n");
	if (node->data >= 0) {
		printf("Found ");
	}
	else {
		printf("Not Found");
	}
	printf("%c(i=%d)\n", *key, i);
	return node->data;
}
void print_tree1(node_t *node)
{
	if (node->left_child) {
		printf("0");
		print_tree1(node->left_child);
	}
	if (node->right_child) {
		printf("1");
		print_tree1(node->right_child);
	}
}
int init_tree()
{
	root = (node_t *)malloc(sizeof(node_t));
	if (root == NULL) {
		return -1;
	}
	root->left_child = NULL;
	root->right_child = NULL;
}
void add_tree(char *key, int index)
{
	int i;
	char digit;
	node_t *node = root;
	printf("key=%s, index=%d\n", key, index);
	while (*key) {
		printf("ADD:%c(%d) ", *key, *key);
		for (i = 7; i >= 0; i--) {
			digit = (*key) >> i & 1;
			printf("%d", digit);
			if (digit == 0) {
				if (!node->left_child) {
					node->left_child = (node_t *)malloc(sizeof(node_t));
					if (node == NULL) {
						fprintf(stderr, "메모리 할당 에러\n");
						exit(1);
					}
					node->left_child->data = -1;
					node->left_child->left_child = NULL;
					node->left_child->right_child = NULL;
				}
				node = node->left_child;
			}
			else {
				if (!node->right_child) {
					node->right_child = (node_t *)malloc(sizeof(node_t));
					if (node == NULL) {
						fprintf(stderr, "메모리 할당 에러\n");
						exit(1);
					}
					node->right_child->data = -1;
					node->right_child->left_child = NULL;
					node->right_child->right_child = NULL;
				}
				node = node->right_child;
			}
		}	/* end of for */
		printf("\n");
		key++;
	}	/*end of while */
	node->data = index;
}
int main()
{
	int i, arr_size, res;
	if (init_tree() < 0) {
		fprintf(stderr, "Fail: init_tree()\n");
		exit(1);
	}
	for (i = 0; i<sizeof(student) / sizeof(student_t); i++) {
		add_tree(student[i].name, i);
	}
	printf("#############\n");
	res = search_tree("Joa");
	if (res >= 0) {
		printf("\n[%d] %s %c %d\n", res, student[res].name, student[res].gender, student[res].age);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3
#define MAX_ELEMENT 100

int free_seats = 10;

double profit = 0.0;

typedef struct {

	int type;	// �̺�Ʈ�� ����

	int time;	// �̺�Ʈ�� �Ͼ �ð�

	int client;	// ���� ����

} element;

typedef struct {

	element heap[MAX_ELEMENT];

	int heap_size;

} HeapType;
// �ʱ�ȭ �Լ�

void init(HeapType *h)

{

	h->heap_size = 0;

}

int is_empty(HeapType *h)

{

	if (h->heap_size == 0)

		return 1;

	else

		return 0;

}

// ���� �Լ�

void insert_min_heap(HeapType *h, element item)

{

	int i;

	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����



	while ((i != 1) && (item.time < h->heap[i / 2].time)) {

		h->heap[i] = h->heap[i / 2];

		i /= 2;

	}

	h->heap[i] = item; // ���ο� ��带 ����

}

// ���� �Լ�

element delete_min_heap(HeapType *h)

{

	int parent, child;

	element item, temp;

	item = h->heap[1];

	temp = h->heap[(h->heap_size)--];

	parent = 1;

	child = 2;

	while (child <= h->heap_size)

	{

		if ((child < h->heap_size) &&

			(h->heap[child].time) > h->heap[child + 1].time)

			child++;

		if (temp.time <= h->heap[child].time) break;

		h->heap[parent] = h->heap[child];

		parent = child;

		child *= 2;

	}

	h->heap[parent] = temp;

	return item;

}

// 0���� n������ ���� ���� ���� �Լ�

int random(int n)

{

	srand(time(NULL));

	return rand() % n;

}

// �ڸ��� �����ϸ� �� �ڸ����� �������ŭ ���ҽ�Ų��.

int is_seat_available(int client)

{

	printf("%d���� �� ����\n", client);

	if (free_seats >= client) {

		free_seats -= client;

		return 1;

	}

	else {

		printf("�ڸ��� ��� ����\n");

		return 0;

	}

}

// �ֹ��� ������ ������ ��Ÿ���� ������ ������Ų��.

void order(int scoops)

{

	printf("���̽�ũ�� %d�� �ֹ� ����\n", scoops);

	profit += 0.35 * scoops;

}

// ���� ������ ���ڸ����� ������Ų��.

void leave(int client)

{

	printf("%d���� ������ ����\n", client);

	free_seats += client;

}

// �̺�Ʈ�� ó���Ѵ�.

void process_event(HeapType *heap, element e)

{

	int i = 0;

	element new_event;



	printf("���� �ð�=%d\n", e.time);

	switch (e.type) {

	case ARRIVAL:

		// �ڸ��� �����ϸ� �ֹ� �̺�Ʈ�� �����.

		if (is_seat_available(e.client)) {

			new_event.type = ORDER;

			new_event.time = e.time + 1 + random(4);

			new_event.client = e.client;

			insert_min_heap(heap, new_event);

		}

		break;

	case ORDER:

		// �������ŭ �ֹ��� �޴´�.

		for (i = 0; i < e.client; i++) {

			order(1 + random(3));

		}

		// ������ ������ �̺�Ʈ�� �����Ѵ�.

		new_event.type = LEAVE;

		new_event.time = e.time + 1 + random(10);

		new_event.client = e.client;

		insert_min_heap(heap, new_event);

		break;

	case LEAVE:

		// ���� ������ ���ڸ����� ������Ų��.

		leave(e.client);

		break;

	}

}

int main()

{

	element event;

	HeapType heap;

	unsigned int t = 0;

	init(&heap);

	// ó���� ��� �ʱ� �̺�Ʈ�� ������Ų��.

	while (t < 5) {

		t += random(6);

		event.type = ARRIVAL;

		event.time = t;

		event.client = 1 + random(4);

		insert_min_heap(&heap, event);

	}

	while (!is_empty(&heap)) {

		event = delete_min_heap(&heap);

		process_event(&heap, event);

	}

	printf("��ü �������� =%f�Դϴ�.\n ", profit);

}




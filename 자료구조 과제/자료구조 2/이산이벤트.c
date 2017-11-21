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

	int type;	// 이벤트의 종류

	int time;	// 이벤트가 일어난 시각

	int client;	// 고객의 숫자

} element;

typedef struct {

	element heap[MAX_ELEMENT];

	int heap_size;

} HeapType;
// 초기화 함수

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

// 삽입 함수

void insert_min_heap(HeapType *h, element item)

{

	int i;

	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정



	while ((i != 1) && (item.time < h->heap[i / 2].time)) {

		h->heap[i] = h->heap[i / 2];

		i /= 2;

	}

	h->heap[i] = item; // 새로운 노드를 삽입

}

// 삭제 함수

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

// 0에서 n사이의 정수 난수 생성 함수

int random(int n)

{

	srand(time(NULL));

	return rand() % n;

}

// 자리가 가능하면 빈 자리수를 사람수만큼 감소시킨다.

int is_seat_available(int client)

{

	printf("%d명의 고객 도착\n", client);

	if (free_seats >= client) {

		free_seats -= client;

		return 1;

	}

	else {

		printf("자리가 없어서 떠남\n");

		return 0;

	}

}

// 주문을 받으면 순익을 나타내는 변수를 증가시킨다.

void order(int scoops)

{

	printf("아이스크림 %d개 주문 받음\n", scoops);

	profit += 0.35 * scoops;

}

// 고객이 떠나면 빈자리수를 증가시킨다.

void leave(int client)

{

	printf("%d명이 매장을 떠남\n", client);

	free_seats += client;

}

// 이벤트를 처리한다.

void process_event(HeapType *heap, element e)

{

	int i = 0;

	element new_event;



	printf("현재 시간=%d\n", e.time);

	switch (e.type) {

	case ARRIVAL:

		// 자리가 가능하면 주문 이벤트를 만든다.

		if (is_seat_available(e.client)) {

			new_event.type = ORDER;

			new_event.time = e.time + 1 + random(4);

			new_event.client = e.client;

			insert_min_heap(heap, new_event);

		}

		break;

	case ORDER:

		// 사람수만큼 주문을 받는다.

		for (i = 0; i < e.client; i++) {

			order(1 + random(3));

		}

		// 매장을 떠나는 이벤트를 생성한다.

		new_event.type = LEAVE;

		new_event.time = e.time + 1 + random(10);

		new_event.client = e.client;

		insert_min_heap(heap, new_event);

		break;

	case LEAVE:

		// 고객이 떠나면 빈자리수를 증가시킨다.

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

	// 처음에 몇개의 초기 이벤트를 생성시킨다.

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

	printf("전체 순이익은 =%f입니다.\n ", profit);

}




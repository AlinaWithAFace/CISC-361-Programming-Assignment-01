#include <stdio.h>
#include <stdlib.h>

//int main() {
//	printf("Hello, World!\n");
//	return 0;
//}

typedef struct mp3 {
	char *name;
	struct mp3 *next;
} mp3_t;

struct node {
	struct mp3 data;
	struct node *next;
} *head;

void append(struct mp3 music) {
	struct node *temp, *right;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = music;
	right = head;
	while (right->next != NULL)
		right = right->next;
	right->next = temp;
	right = temp;
	right->next = NULL;
}


void add(struct mp3 music) {
	struct node *temp;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = music;
	if (head == NULL) {
		head = temp;
		head->next = NULL;
	} else {
		temp->next = head;
		head = temp;
	}
}

void addafter(struct mp3 music, int loc) {
	int i;
	struct node *temp, *left = NULL, *right = NULL;
	right = head;
	for (i = 1; i < loc; i++) {
		left = right;
		right = right->next;
	}
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = music;
	left->next = temp;
	left = temp;
	left->next = right;
}


int count() {
	struct node *n;
	int c = 0;
	n = head;
	while (n != NULL) {
		n = n->next;
		c++;
	}
	return c;
}

void insert(struct mp3 music) {
	int c = 0;
	struct node *temp;
	temp = head;
	if (temp == NULL) {
		add(music);
	} else {
		while (temp != NULL) {
			if (temp->data.name < music.name)
				c++;
			temp = temp->next;
		}
		if (c == 0)
			add(music);
		else if (c < count())
			addafter(music, ++c);
		else
			append(music);
	}
}


int delete(struct mp3 music) {
	struct node *temp = NULL, *prev = NULL;
	temp = head;
	while (temp != NULL) {
		if (temp->data.name == music.name) {
			if (temp == head) {
				head = temp->next;
				free(temp);
				return 1;
			} else {
				prev->next = temp->next;
				free(temp);
				return 1;
			}
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
	return 0;
}


void display(struct node *r) {
	r = head;
	if (r == NULL) {
		return;
	}
	while (r != NULL) {
		printf("%d ", r->data);
		r = r->next;
	}
	printf("\n");
}


int main() {
	int i;
	struct mp3 music;
	struct node *n;
	head = NULL;
	while (1) {
		printf("\nList Operations\n");
		printf("===============\n");
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Size\n");
		printf("4.Delete\n");
		printf("5.Exit\n");
		printf("Enter your choice : ");
		if (scanf("%d", &i) <= 0) {
			printf("Enter only an Integer\n");
			exit(0);
		} else {
			switch (i) {
				case 1:
					printf("Enter the number to insert : ");
					scanf("%d", &music);
					insert(music);
					break;
				case 2:
					if (head == NULL) {
						printf("List is Empty\n");
					} else {
						printf("Element(s) in the list are : ");
					}
					display(n);
					break;
				case 3:
					printf("Size of the list is %d\n", count());
					break;
				case 4:
					if (head == NULL)
						printf("List is Empty\n");
					else {
						printf("Enter the number to delete : ");
						scanf("%d", &music);
						if (delete(music))
							printf("%d deleted successfully\n", music);
						else
							printf("%d not found in the list\n", music);
					}
					break;
				case 5:
					return 0;
				default:
					printf("Invalid option\n");
			}
		}
	}
}
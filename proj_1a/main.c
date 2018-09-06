#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "main.h"

void bufferTest() {
	char buffer[BUFFERSIZE];
	printf("Enter a message: \n");
	while ((fgets(buffer, BUFFERSIZE, stdin) != NULL) & (buffer[0] != '\n')) // empty string ???
	{
		getchar();
		gets(buffer);
		printf("String is %s", buffer);
	}
}

void append(struct mp3 *music) {
	struct node *temp, *right;
	temp = (struct node *) malloc(sizeof(struct node));
	temp->data = music;
	right = (struct node *) head;
	while (right->next != NULL)
		right = right->next;
	right->next = temp;
	right = temp;
	right->next = NULL;
}


void add(struct mp3 *music) {
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

void addafter(struct mp3 *music, int loc) {
	int i;
	struct node *temp, *left, *right;
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
	return;
}


void insert(struct mp3 *music) {
	int c = 0;
	struct node *temp;
	temp = head;
	if (temp == NULL) {
		add(music);
	} else {
		while (temp != NULL) {
			if (temp->data->title < music->title)
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


int delete(char *title) {
	struct node *temp, *prev;
	temp = head;
	while (temp != NULL) {
		if (temp->data->title == title) {
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
		//printf("%d ", r->data);
		printf("\n\"%s\" by %s, %d, %d", r->data->title, r->data->artist, r->data->year, r->data->duration);
		r = r->next;
	}
	printf("\n");
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

int main() {
	int i;
	struct mp3 *music;
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
					music = malloc(sizeof(struct mp3));
					printf("Making song...\n");
					int len;

					getchar();
					printf("Enter Song Title: \n");
					char titleBuffer[BUFFERSIZE];
					if (fgets(titleBuffer, BUFFERSIZE, stdin) != NULL) {
						len = (int) strlen(titleBuffer);
						titleBuffer[len - 1] = '\0';
						music->title = (char *) malloc(len);
						strcpy(music->title, titleBuffer);
					}

					printf("Enter the song artist : ");
					char artistBuffer[BUFFERSIZE];
					if (fgets(artistBuffer, BUFFERSIZE, stdin) != NULL) {
						len = (int) strlen(artistBuffer);
						artistBuffer[len - 1] = '\0';
						music->artist = (char *) malloc(len);
						strcpy(music->artist, artistBuffer);
					}

					printf("Enter the song year then press enter : ");
					int tempYear = 0;
					scanf("%d", &tempYear);
					music->year = tempYear;

					printf("Enter the song duration then press enter : ");
					int tempDuration = 0;
					scanf("%d", &tempDuration);
					music->duration = tempDuration;


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
						char titleToDeleteBuffer[BUFFERSIZE];
						if (fgets(titleToDeleteBuffer, BUFFERSIZE, stdin) != NULL) {
							len = (int) strlen(titleToDeleteBuffer);
							titleToDeleteBuffer[len - 1] = '\0';
							music->title = (char *) malloc(len);
							strcpy(music->title, titleToDeleteBuffer);
						}
						if (delete(music->title))
							printf("%s deleted successfully\n", titleToDeleteBuffer);
						else
							printf("%s not found in the list\n", titleToDeleteBuffer);
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

// an empty string terminates the program
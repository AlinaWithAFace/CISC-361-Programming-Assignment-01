//
// Created by Alina on 2018-09-05.
//

#ifndef PROGRAMMING_ASSIGNMENT_01_MAIN_H
#define PROGRAMMING_ASSIGNMENT_01_MAIN_H

#define BUFFERSIZE 128

typedef struct mp3 {
	char *title;
	char *artist;
	int year;
	int duration;
} mp3_t;


struct node {
	struct mp3 *data;
	struct node *next;
	struct node *prev;
} *head;

//bool debug = TRUE;

#endif //PROGRAMMING_ASSIGNMENT_01_MAIN_H

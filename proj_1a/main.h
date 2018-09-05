//
// Created by Alina on 2018-09-05.
//

#ifndef PROGRAMMING_ASSIGNMENT_01_MAIN_H
#define PROGRAMMING_ASSIGNMENT_01_MAIN_H


typedef struct mp3 {
	char *name;
	struct mp3 *next;
} mp3_t;


struct node {
	struct mp3 data;
	struct node *next;
} *head;

void append(struct mp3 music);

void add(struct mp3 music);

void addafter(struct mp3 music, int loc);

int count();

void insert(struct mp3 music);

int delete(struct mp3 music);

void display(struct node *r);

int main();

#endif //PROGRAMMING_ASSIGNMENT_01_MAIN_H

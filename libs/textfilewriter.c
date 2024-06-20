// textfilewriter.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"
#include "textfilewriter.h"

extern Node* _head;
extern Node* _tail;
extern char** Input_command;

void create_music_titles(FILE* stream){
    
    printf("Test\n");
}

void read_file(char* file_name){
    FILE *readfile = fopen(file_name, "r");

    char* current_string; char line[MAX_TITLE_SIZE];
    int i = 0;
    while ((current_string = fgets(line, MAX_TITLE_SIZE, readfile)) != EOF) {
        if (i)
            append_left(MAX_TITLE_SIZE, current_string);
        i++;
    }
    fclose(readfile);
}

void write_file(char* file_name){
    FILE *writefile = fopen(file_name, "w");
    Node* current = _tail;

    fprintf(writefile, "%ld\n", size());
    while (current != NULL) {
        fprintf(writefile, "%s", "\n");
        fprintf(writefile, "%s", current->data);
        current = current->prev;
    }
    fclose(writefile);
}

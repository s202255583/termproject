#ifndef LINKEDLIST_TEXTFILEWRITER_H
#define LINKEDLIST_TEXTFILEWRITER_H
#include <stdio.h>
#define MAX_TITLE_SIZE 50

#ifdef __cplusplus
extern "C" {
#endif

void create_music_titles(FILE* stream);
void read_file(char* file_name);
void write_file(char* file_name);

#ifdef __cplusplus
}
#endif

#endif //LINKEDLIST_TEXTFILEWRITER_H


#ifndef FS_H
#define FS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_CONTENT 1024

// Structure pour un fichier
typedef struct File {
    char name[MAX_NAME];
    char content[MAX_CONTENT];
    struct File* next;
} File;

// Structure pour un répertoire
typedef struct Directory {
    char name[MAX_NAME];
    struct Directory* parent;
    struct Directory* subdirs;
    struct Directory* next;
    File* files;
} Directory;

void read_file(Directory* dir, const char* name);
void delete_file(Directory* dir, const char* name);

// Prototypes
Directory* create_directory(const char* name, Directory* parent);
void create_file(Directory* dir, const char* name, const char* content);
void list_content(Directory* dir);
Directory* change_directory(Directory* current, const char* name);x

#endif
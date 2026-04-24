#ifndef FS_H
#define FS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_CONTENT 1024
#define DISK_SIZE 5000 // Taille totale simulée en octets

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

// Prototypes des fonctionnalités
Directory* create_directory(const char* name, Directory* parent);
void create_file(Directory* dir, const char* name, const char* content);
void list_content(Directory* dir);
Directory* change_directory(Directory* current, const char* name);
void read_file(Directory* dir, const char* name);
void write_to_file(Directory* dir, const char* name, const char* new_content);
void delete_file(Directory* dir, const char* name);
void check_space(Directory* root);

#endif
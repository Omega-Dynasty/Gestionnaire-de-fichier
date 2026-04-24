#include "fs.h"

Directory* create_directory(const char* name, Directory* parent) {
    Directory* new_dir = (Directory*)malloc(sizeof(Directory));
    strcpy(new_dir->name, name);
    new_dir->parent = parent;
    new_dir->subdirs = NULL;
    new_dir->files = NULL;
    new_dir->next = (parent) ? parent->subdirs : NULL;
    if (parent) parent->subdirs = new_dir;
    return new_dir;
}

void create_file(Directory* dir, const char* name, const char* content) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    strcpy(new_file->content, content);
    new_file->next = dir->files;
    dir->files = new_file;
}

void list_content(Directory* dir) {
    printf("\n--- Dossier actuel : %s ---\n", dir->name);
    Directory* d = dir->subdirs;
    while (d) {
        printf(" [DIR]  %s\n", d->name);
        d = d->next;
    }
    File* f = dir->files;
    while (f) {
        printf(" [FILE] %s\n", f->name);
        f = f->next;
    }
}

Directory* change_directory(Directory* current, const char* name) {
    if (strcmp(name, "..") == 0) {
        return (current->parent) ? current->parent : current;
    }
    Directory* d = current->subdirs;
    while (d) {
        if (strcmp(d->name, name) == 0) return d;
        d = d->next;
    }
    printf("Erreur : répertoire introuvable.\n");
    return current;
}
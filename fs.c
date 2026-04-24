#include "fs.h"

Directory* create_directory(const char* name, Directory* parent) {
    Directory* new_dir = (Directory*)malloc(sizeof(Directory));
    if (!new_dir) return NULL;
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
    if (!new_file) return;
    strcpy(new_file->name, name);
    strncpy(new_file->content, content, MAX_CONTENT);
    new_file->next = dir->files;
    dir->files = new_file;
    printf("Fichier '%s' cree.\n", name);
}

void list_content(Directory* dir) {
    if (!dir) return;
    printf("\n--- Contenu de %s ---\n", dir->name);
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
    printf("Erreur : Repertoire '%s' introuvable.\n", name);
    return current;
}

void read_file(Directory* dir, const char* name) {
    File* f = dir->files;
    while (f) {
        if (strcmp(f->name, name) == 0) {
            printf("\nContenu de %s :\n%s\n", f->name, f->content);
            return;
        }
        f = f->next;
    }
    printf("Erreur : Fichier introuvable.\n");
}

void write_to_file(Directory* dir, const char* name, const char* new_content) {
    File* f = dir->files;
    while (f) {
        if (strcmp(f->name, name) == 0) {
            strncpy(f->content, new_content, MAX_CONTENT);
            printf("Fichier '%s' mis a jour.\n", name);
            return;
        }
        f = f->next;
    }
}

void delete_file(Directory* dir, const char* name) {
    File *curr = dir->files, *prev = NULL;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            if (prev) prev->next = curr->next;
            else dir->files = curr->next;
            free(curr);
            printf("Fichier '%s' supprime.\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Erreur : Fichier introuvable.\n");
}

void check_space(Directory* root) {
    int used = 0;
    // Calcul simple sur le dossier actuel pour l'exemple
    File* f = root->files;
    while(f) {
        used += strlen(f->content);
        f = f->next;
    }
    printf("\n--- Espace Disque ---\nUtilise : %d / %d octets\n", used, DISK_SIZE);
}
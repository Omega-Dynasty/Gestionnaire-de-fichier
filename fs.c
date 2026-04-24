#include "fs.h"

// Créer un répertoire
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

// Créer un fichier
void create_file(Directory* dir, const char* name, const char* content) {
    File* new_file = (File*)malloc(sizeof(File));
    if (!new_file) return;
    strcpy(new_file->name, name);
    strncpy(new_file->content, content, MAX_CONTENT);
    new_file->next = dir->files;
    dir->files = new_file;
    printf("Fichier '%s' cree.\n", name);
}

// Lister le contenu
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

// Naviguer entre répertoires
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

// Lire un fichier
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

// Modifier un fichier
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

// Supprimer un fichier et libérer la mémoire
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

// Suivi de l'espace disque
void check_space(Directory* root) {
    int used = 0;
    File* f = root->files;
    while(f) {
        used += strlen(f->content);
        f = f->next;
    }
    printf("\n--- Espace Disque ---\nUtilise : %d / %d octets\n", used, DISK_SIZE);
}
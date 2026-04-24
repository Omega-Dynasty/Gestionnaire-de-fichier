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
    // RESOLUTION BUG : On ajoute une sécurité si le pointeur est NULL
    if (dir == NULL) {
        printf("Erreur : Impossible de lister un répertoire inexistant.\n");
        return;
    }

    printf("\n--- Dossier actuel : %s ---\n", dir->name);
    
    // Lister les sous-dossiers
    Directory* d = dir->subdirs;
    while (d) {
        printf(" [DIR]  %s\n", d->name);
        d = d->next;
    }
    
    // Lister les fichiers
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

void read_file(Directory* dir, const char* name) {
    File* f = dir->files;
    while (f) {
        if (strcmp(f->name, name) == 0) {
            printf("\n--- Contenu de : %s ---\n%s\n------------------\n", f->name, f->content);
            return;
        }
        f = f->next;
    }
    printf("Erreur : Le fichier '%s' n'existe pas dans ce repertoire.\n", name);
}

void delete_file(Directory* dir, const char* name) {
    File* current = dir->files;
    File* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            // On recoud la liste chaînée
            if (prev == NULL) {
                dir->files = current->next;
            } else {
                prev->next = current->next;
            }
            
            // On libère la mémoire
            free(current);
            printf("Fichier '%s' supprime avec succes.\n", name);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Erreur : Impossible de supprimer '%s' (introuvable).\n", name);
}
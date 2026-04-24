#include "fs.h"

int main() {
    Directory* root = create_directory("root", NULL);
    Directory* current = root;
    char command[20], arg1[MAX_NAME], arg2[MAX_CONTENT];

    printf("--- Bienvenue dans votre Gestionnaire de Fichiers C ---\n");
    printf("Tapez 'help' pour voir la liste des commandes.\n");

    while (1) {
        printf("\n%s > ", current->name);
        if (scanf("%s", command) == EOF) break;

        if (strcmp(command, "help") == 0) {
            printf("\nCommandes disponibles :\n");
            printf("  ls              : Lister le contenu actuel\n");
            printf("  mkdir <nom>     : Creer un repertoire\n");
            printf("  touch <n> <c>   : Creer un fichier <n> avec contenu <c>\n");
            printf("  cd <nom>        : Naviguer (.. pour remonter)\n");
            printf("  read <nom>      : Lire un fichier\n");
            printf("  rm <nom>        : Supprimer un fichier\n");
            printf("  space           : Voir l'espace disque\n");
            printf("  help            : Afficher ce menu\n");
            printf("  exit            : Quitter le programme\n");
        } 
        else if (strcmp(command, "ls") == 0) {
            list_content(current);
        } 
        else if (strcmp(command, "mkdir") == 0) {
            scanf("%s", arg1);
            create_directory(arg1, current);
        } 
        else if (strcmp(command, "touch") == 0) {
            scanf("%s %s", arg1, arg2);
            create_file(current, arg1, arg2);
        } 
        else if (strcmp(command, "cd") == 0) {
            scanf("%s", arg1);
            current = change_directory(current, arg1);
        } 
        else if (strcmp(command, "read") == 0) {
            scanf("%s", arg1);
            read_file(current, arg1);
        } 
        else if (strcmp(command, "rm") == 0) {
            scanf("%s", arg1);
            delete_file(current, arg1);
        } 
        else if (strcmp(command, "space") == 0) {
            check_space(root);
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Fermeture...\n");
            break;
        } 
        else {
            printf("Commande inconnue. Tapez 'help'.\n");
        }
    }
    return 0;
}
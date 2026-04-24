#include "fs.h"

int main() {
    Directory* root = create_directory("root", NULL);
    Directory* current = root;
    char command[20], arg1[MAX_NAME], arg2[MAX_CONTENT];

    printf("--- Bienvenue dans votre Gestionnaire de Fichiers C ---\n");
    printf("Commandes : ls, mkdir <nom>, touch <nom> <contenu>, cd <nom>, read <nom>, rm <nom>, space, exit\n");

    while (1) {
        printf("\n%s > ", current->name); // Affiche le prompt interactif
        if (scanf("%s", command) == EOF) break;

        if (strcmp(command, "ls") == 0) {
            list_content(current);
        } else if (strcmp(command, "mkdir") == 0) {
            scanf("%s", arg1);
            create_directory(arg1, current);
        } else if (strcmp(command, "touch") == 0) {
            scanf("%s %s", arg1, arg2);
            create_file(current, arg1, arg2);
        } else if (strcmp(command, "cd") == 0) {
            scanf("%s", arg1);
            current = change_directory(current, arg1);
        } else if (strcmp(command, "read") == 0) {
            scanf("%s", arg1);
            read_file(current, arg1);
        } else if (strcmp(command, "rm") == 0) {
            scanf("%s", arg1);
            delete_file(current, arg1);
        } else if (strcmp(command, "space") == 0) {
            check_space(current);
        } else if (strcmp(command, "exit") == 0) {
            printf("Fermeture du gestionnaire...\n");
            break;
        } else if (strcmp(command, "help") == 0) {
            printf("Commandes : ls, mkdir <nom>, touch <nom> <contenu>, cd <nom>, read <nom>, rm <nom>, space, exit\n");
        }else {
            printf("Commande inconnue.\n");
        }
        
    }
    return 0;
}
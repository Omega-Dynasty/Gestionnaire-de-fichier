#include "fs.h"

int main() {
    Directory* root = create_directory("root", NULL);
    Directory* current = root;

    // Création de base
    create_directory("Documents", current);
    create_directory("Images", current);
    create_file(current, "info.txt", "Systeme initialise.");

    list_content(current);

    // Test de navigation
    printf("\nEntree dans 'Documents'...\n");
    current = change_directory(current, "Documents");
    create_file(current, "secret.txt", "Ceci est dans Documents");
    list_content(current);

    return 0;
}
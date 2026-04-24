#include "fs.h"

int main() {
    Directory* root = create_directory("root", NULL);
    
    create_file(root, "test.txt", "A supprimer");
    create_file(root, "garde.txt", "A garder");
    
    list_content(root);

    printf("\nSuppression de 'test.txt'...\n");
    delete_file(root, "test.txt");

    list_content(root);

    return 0;
}
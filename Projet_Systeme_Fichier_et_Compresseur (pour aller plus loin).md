# Projet : Création d'un Système de Fichier Simplifié en C

## Introduction au Projet
Ce projet consiste à développer un système de fichier simplifié en langage C. Il couvre les concepts fondamentaux 
de gestion des fichiers, manipulation de structures de données, allocation dynamique de mémoire, et introduction 
à la gestion de systèmes de fichiers. Les étudiants devront créer, lire, écrire et supprimer des fichiers, ainsi 
que gérer des répertoires, tout en assurant une organisation en arborescence.

## Structures de Données
Le projet utilise plusieurs structures de données pour représenter les fichiers et les répertoires. Chaque fichier 
est représenté par une structure contenant le nom, la taille et le contenu du fichier. De même, un répertoire est 
une structure qui contient des pointeurs vers d'autres répertoires et fichiers, formant une arborescence.

## Fonctionnalités

- **Créer un Fichier** : Permet de créer un fichier avec un nom unique et un contenu initial.
- **Lire un Fichier** : Affiche le contenu d'un fichier spécifique.
- **Écrire dans un Fichier** : Permet de modifier le contenu d'un fichier existant.
- **Supprimer un Fichier** : Supprime un fichier en libérant l'espace mémoire associé.
- **Créer un Répertoire** : Crée un répertoire pour structurer l'organisation des fichiers.
- **Lister le Contenu** : Affiche le contenu d'un répertoire donné (fichiers et sous-répertoires).
- **Naviguer dans les Répertoires** : Permet de naviguer entre les répertoires pour simuler une arborescence.
- **Gestion de l’Espace Mémoire** : Suit la quantité d'espace utilisé et disponible dans le système de fichier.

## Interface en Ligne de Commande
L'interface utilisateur est une interface en ligne de commande (CLI) où l'utilisateur peut entrer des commandes pour 
créer, lire, écrire, supprimer des fichiers et naviguer entre les répertoires. Chaque commande est associée à une 
fonction spécifique dans le programme.

---

# Projet : Compresseur de Fichier avec l'Algorithme de Huffman

## Introduction au Projet
Ce projet consiste à développer un compresseur de fichier en langage C, en utilisant l'algorithme de Huffman pour 
compresser des fichiers texte. L'algorithme de Huffman est un algorithme de compression sans perte, permettant de 
réduire la taille d'un fichier en fonction de la fréquence d’apparition des caractères.

## Concepts Clés
- **Arbres Binaires** : Construction d’un arbre de Huffman pour encoder les données.
- **Table de Fréquence** : Analyser le fichier pour déterminer la fréquence de chaque caractère.
- **Codage Binaire** : Associer des codes binaires aux caractères, les plus fréquents recevant les codes les plus courts.
- **Manipulation de Fichiers** : Lire et écrire des données binaires.

## Fonctionnalités Requises

1. **Lecture et Analyse du Fichier**
   - Lire un fichier texte et compter la fréquence de chaque caractère.
   - Stocker les fréquences dans une table de hachage ou un tableau pour construire l’arbre de Huffman.

2. **Construction de l’Arbre de Huffman**
   - Construire un arbre binaire de Huffman en utilisant les fréquences des caractères.
   - Assigner des codes binaires à chaque caractère en fonction de sa position dans l’arbre.

3. **Encodage du Fichier**
   - Parcourir le fichier d'origine et encoder chaque caractère selon le code de Huffman.
   - Écrire le résultat dans un fichier compressé, en utilisant un format binaire pour minimiser la taille du fichier.

4. **Décodage du Fichier**
   - Lire le fichier compressé et décoder les données en utilisant l’arbre de Huffman.
   - Reconstituer le fichier d'origine.

5. **Interface Utilisateur en Ligne de Commande**
   - Proposer un menu permettant de choisir entre la compression et la décompression.

## Étapes de Réalisation

1. **Création des Structures de Données**
   - Définir une structure pour les nœuds de l’arbre de Huffman, contenant un caractère, une fréquence, et des pointeurs vers les nœuds fils.
   - Une table de fréquence pour stocker les occurrences de chaque caractère.

2. **Implémentation des Fonctions**
   - **Analyser le Fichier** : Lire le fichier et remplir la table de fréquence.
   - **Construire l’Arbre** : Utiliser un algorithme de priorité pour créer l’arbre de Huffman (par exemple, un tas min).
   - **Encoder les Caractères** : Assigner des codes binaires en parcourant l’arbre.
   - **Compression** : Lire le fichier d'origine, encoder les caractères, et écrire dans le fichier compressé.
   - **Décompression** : Lire le fichier compressé, décoder les données et reconstruire le fichier d'origine.

3. **Gestion de la Mémoire**
   - Assurer la libération de la mémoire allouée pour l’arbre et les buffers.

4. **Tests et Débogage**
   - Tester avec différents fichiers texte pour s’assurer de la qualité de compression et de la précision de la décompression.

---

E.SABAHI MP2I Informatique

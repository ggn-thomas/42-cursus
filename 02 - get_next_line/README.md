# Get Next Line - Lecture ligne par ligne

## 📋 Description

Get_Next_Line est un projet du dexuième du cursus de l'École 42 qui consiste à développer une fonction capable de lire un fichier ligne par ligne depuis un descripteur de fichier. Ce projet introduit un concept fondamental de la programmation C : **les variables statiques**.

## 🎯 Objectifs d'apprentissage

- Découvrir et maîtriser les **variables statiques** en C
- Comprendre la gestion des **descripteurs de fichiers**
- Apprendre à gérer un **buffer de lecture** dynamique
- Optimiser la lecture de fichiers (lire le minimum nécessaire)
- Gérer la mémoire de manière efficace avec des allocations dynamiques

## ⚙️ Fonctionnement

La fonction `get_next_line()` lit un fichier ligne par ligne à chaque appel, en conservant l'état de lecture grâce aux variables statiques.

### Prototype
```c
char *get_next_line(int fd);
```

### Valeurs de retour
- **Ligne lue** : La ligne actuelle terminée par `\n` (sauf dernière ligne du fichier)
- **NULL** : Plus rien à lire ou erreur

### Exemple d'utilisation
```c
#include "get_next_line.h"

int main()
{
    int fd = open("fichier.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🛠️ Compilation

### Avec BUFFER_SIZE personnalisé
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## 📁 Structure du projet

```
get_next_line/
├── gnl/
|   ├── get_next_line.h
|   ├── get_next_line.c
|   ├── get_next_line_utils.c
├── gnl_bonus/
|   ├── get_next_line_bonus.h
|   ├── get_next_line_bonus.c 
|   ├── get_next_line_utils_bonus.c 
└── README.md
```

## 🔧 Fonctions implémentées

### Fichier principal : `get_next_line.c`
- `get_next_line(int fd)` - Fonction principale qui lit ligne par ligne

### Fichier utilitaire : `get_next_line_utils.c`
Fonctions d'aide nécessaires au bon fonctionnement (exemples) :
- `ft_strlen()` - Calculer la longueur d'une chaîne
- `ft_strchr()` - Trouver un caractère dans une chaîne  
- `ft_strjoin()` - Joindre deux chaînes
- `ft_substr()` - Extraire une sous-chaîne
- `ft_strdup()` - Alloue de la mémorie dans la stack pour stocker une string


## 🎖️ Partie Bonus

### Fonctionnalités bonus :
1. **Une seule variable statique** au lieu de plusieurs
2. **Gestion de plusieurs fd simultanément**
   - Possibilité de lire alternativement sur différents descripteurs
   - Chaque fd conserve son état de lecture indépendamment

### Exemple bonus multi-fd :
```c
char *line1 = get_next_line(fd1);  // Lit fd1
char *line2 = get_next_line(fd2);  // Lit fd2  
char *line3 = get_next_line(fd1);  // Reprend fd1 où on l'avait laissé
```

## ⚠️ Contraintes techniques

### ✅ Autorisé
- `read()`, `malloc()`, `free()`
- Variables statiques
- Macro `BUFFER_SIZE` définie à la compilation

### ❌ Interdit
- **Libft** (pas autorisée pour ce projet)
- `lseek()` - repositionnement dans le fichier interdit
- **Variables globales**
- Lecture de l'intégralité du fichier en une fois
